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

  /*---- Création et init. des variables nécessaires au calcul ----*/





  /*------------ Renvoit du résultat final tq C = A*B -------------*/
  return C;
}





































/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
