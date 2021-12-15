/**
 * \file operations.h
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les les définitions des fonctions utilisées
 * dans la gestion des calculs et opérations sur une matrice creuse,
 * entre deux matrices creuses, entre une matrice creuse et
 * un vecteur creux (resp. un vecteur dense).
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "array.h"
#include "sparse-matrix.h"
#include "operations.h"

/*----------------------------------------------------------------------------*/
/*------------------------------FONCTIONS STATIQUES---------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
void convert(Mtx *mtx, Mtx *matrix_t){
  assert(mtx != NULL);

  /*-------------Var Init--------------*/
  unsigned int nRows = get_matrix_dimensions(mtx);
  unsigned int nz = get_matrix_nz_size(mtx);
  unsigned int tmp = 0, cumSum = 1 , temp, idx, end;

  unsigned int *colCount = (unsigned int*)calloc(nRows, sizeof(unsigned int));
  if(colCount == NULL){
    printf("Erreur d'allocation mémoire\n");
    exit(-2);
  }

  for(unsigned int i=0; i<nz; i++){
    tmp = mtx->iRows->vals[i]-1;
    colCount[tmp]++;
  }

  add_at(matrix_t->pCols, 0, 1);
  for(unsigned int j=1; j<nRows; j++){
    cumSum += colCount[j-1];
    add_at(matrix_t->pCols, j, cumSum);
  }

  for(unsigned int k=0; k<nRows; k++){
    colCount[k] = 0;
  }

  for(unsigned int k=0; k<nRows; k++){
    if(k == nRows - 1){
      end = nz+SHIFT;
    }else{
      end = (unsigned int)mtx->pCols->vals[k+SHIFT];
    }

    for(unsigned int l=mtx->pCols->vals[k]; l<end; l++){
      temp =(unsigned int)mtx->iRows->vals[l-SHIFT];
      idx =(unsigned int)matrix_t->pCols->vals[temp-SHIFT]+colCount[temp-SHIFT];
      colCount[temp-SHIFT]++;

      add_at(matrix_t->xVals, idx-SHIFT, mtx->xVals->vals[l-SHIFT]);
      add_at(matrix_t->iRows, idx-SHIFT, k+SHIFT);
    }
  }

  free(colCount);
}// fin convert()
/*----------------------------------------------------------------------------*/
Vctr *solve_dense_system(Mtx *L, Vctr *b){
  assert(L != NULL && b != NULL && get_vector_density(b) == True
          && get_vector_dimension(b) == get_matrix_dimensions(L));

  /*---- Initialisation vecteur solution + variables utiles ----*/
  time_t start, stop;
  start = time(NULL);

  Vctr *x = create_sparse_vector();
  x->nz = get_vector_dimension(b) ;
  x->dim = get_vector_dimension(b) ;
  x->isDense = get_vector_density(b) ;
  init_sparse_vector(x);

  unsigned int column_number, place=0, m=0, n=0, count=0 ;
  unsigned int dim = get_matrix_dimensions(L), nz = get_matrix_nz_size(L);

  while(m < get_vector_nz_size(b)){
    if(L->iRows->vals[n] == b->iRows->vals[m]){
      x->xVals->vals[(unsigned int)L->iRows->vals[n]-SHIFT] = b->xVals->vals[m];
      n = 0;
      m++ ;
    }else if(L->iRows->vals[n] != b->iRows->vals[m] && n == nz){
      n = 0;
      m++ ;
    }else{
      n++ ;
    }
  }

  /*----------------- Résolution du système --------------------*/
  for(unsigned int i=0; i<dim; i++){
    add_at(x->iRows, i, i+SHIFT);

    if(i>0 && x->xVals->vals[i-SHIFT]!=0){count++;}

    x->xVals->vals[i] /= L->xVals->vals[(unsigned int)L->pCols->vals[i]-SHIFT];

    if(i == dim-1){
      column_number = nz - (unsigned int)L->pCols->vals[i]+SHIFT;
    }else{
      column_number = (unsigned int)(L->pCols->vals[i+1] - L->pCols->vals[i]);
    }

    for(unsigned int j = place+1 ; j < column_number+place; j++){
      x->xVals->vals[(unsigned int)L->iRows->vals[j]-SHIFT] -=
                                            L->xVals->vals[j]*x->xVals->vals[i];
    }

    place += column_number;
  }

  set_vector_nz_size(x, count);

  stop = time(NULL);
  printf("The elapsed time is %ld seconds (dense)\n", (stop - start));

  return x;
}// solve_dense_system()
/*----------------------------------------------------------------------------*/
Vctr *solve_sparse_system(Mtx *L, Vctr *b){
  assert(L != NULL && b != NULL && get_vector_density(b) == False
          && get_vector_dimension(b) == get_matrix_dimensions(L));

  /*---- Initialisation vecteur solution + variables utiles ----*/
  time_t start, stop;
  start = time(NULL);

  Vctr *x = create_sparse_vector();
  x->nz = get_vector_dimension(b) ;
  x->dim = get_vector_dimension(b) ;
  x->isDense = get_vector_density(b) ;
  init_sparse_vector(x);

  unsigned int column_number, place=0, m=0, n=0, count=0 ;
  unsigned int dim = get_matrix_dimensions(L), nz = get_matrix_nz_size(L);

  while(m < get_vector_nz_size(b)){
    if(L->iRows->vals[n] == b->iRows->vals[m]){
      x->xVals->vals[(unsigned int)L->iRows->vals[n]-SHIFT] = b->xVals->vals[m];
      n = 0;
      m++ ;
    }else if(L->iRows->vals[n] != b->iRows->vals[m] && n == nz){
      n = 0;
      m++ ;
    }else{
      n++ ;
    }
  }

  /*----------------- Résolution du système --------------------*/
  for(unsigned int i=0; i<dim; i++){
    add_at(x->iRows, i, i+SHIFT);

    if(i>0 && x->xVals->vals[i-SHIFT]!=0){count++;}

    x->xVals->vals[i] /= L->xVals->vals[(unsigned int)L->pCols->vals[i]-SHIFT];

    if(i == dim-1){
      column_number = nz - (unsigned int)L->pCols->vals[i]+SHIFT;
    }else{
      column_number = (unsigned int)(L->pCols->vals[i+1] - L->pCols->vals[i]);
    }

    for(unsigned int j = place+1 ; j < column_number+place; j++){
      if(x->xVals->vals[(unsigned int)L->iRows->vals[j]-SHIFT] != 0
        || (L->xVals->vals[j]!=0 && x->xVals->vals[i]!=0)){
          x->xVals->vals[(unsigned int)L->iRows->vals[j]-SHIFT] -=
                                            L->xVals->vals[j]*x->xVals->vals[i];
        }
    }

    place += column_number;
  }

  set_vector_nz_size(x, count);

  stop = time(NULL);
  printf("The elapsed time is %ld seconds (sparse)\n", (stop - start));

  return x;
}// fin solve_sparse_system()
/*----------------------------------------------------------------------------*/
Mtx *product_of_sparse_matrices(Mtx *A, Mtx *B){
  assert(A != NULL && B != NULL &&
          (get_matrix_dimensions(A) == get_matrix_dimensions(B)));

  /*--- Création et init. de la matrice C pour résoudre C = A*B ---*/
  Mtx *C = create_sparse_matrix();
  if(C == NULL){return NULL;}

  unsigned int nz_A = get_matrix_nz_size(A), nz_B = get_matrix_nz_size(B);
  C->dim = get_matrix_dimensions(A) ;
  C->nz = (nz_A > nz_B) ? nz_A : nz_B ;
  init_sparse_matrix(C);
  add_at(C->pCols, 0, 1);

  unsigned int dim = get_matrix_dimensions(A);;
  unsigned int idx, nextCol;
  unsigned int nz = 0, rowPos, index, count=0;

  unsigned int *w = (unsigned int *)calloc(dim, sizeof(unsigned int));
  unsigned int *x = (unsigned int *)calloc(dim, sizeof(unsigned int));

  /*---- Création et init. des variables nécessaires au calcul ----*/
  /*--- Calcul de la colonne de C -----------*/
  /*--- 1. Déterminer les non-nuls de C -----*/
  for(unsigned int i = 0; i < dim; i++){

    if(i == dim-1){
      idx = B->pCols->vals[i] -SHIFT;
      nextCol = nz_B ;
    }else{
      idx = B->pCols->vals[i] -SHIFT;
      nextCol = B->pCols->vals[i+1] -SHIFT;
    }

    for(unsigned int j = idx; j< nextCol; j++){
      rowPos = B->iRows->vals[j]-SHIFT;

      for(unsigned int l = A->pCols->vals[rowPos];
        l<A->pCols->vals[rowPos+1]; l++){

        index = A->iRows->vals[l];
        if(w[index] == 0){
          w[index] = 1;
          nz++;
          count++;
        }
      }
    }

    add_at(C->pCols, i+1, count+C->pCols->vals[i]-SHIFT);
    count = 0;
    for(unsigned int l=0; l<dim; l++){
      if(w[l] != 0){w[l] =0;}
    }
  }

  /*--- 2. Calculs --------------------------*/
  C->nz = nz;
  printf("nz de C = %u\n", nz);
  count = 0;







  /*------------ Renvoit du résultat final tq C = A*B -------------*/
  free(w);
  free(x);
  return C;
}





































/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
