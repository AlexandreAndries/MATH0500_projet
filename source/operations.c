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
  unsigned int tmp = 0, cumSum = 1, curr, inc=0, prev, row=1;

  unsigned int *colCount = (unsigned int*)calloc(nRows, sizeof(unsigned int));
  // unsigned int *rowCount = (unsigned int*)calloc(nz, sizeof(unsigned int));
  if(colCount == NULL /*|| rowCount == NULL*/){
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
  //--------Code above works --------------------------------













  //--------Work in progress below ------------------------
  // prev = mtx->pCols->vals[0];
  // // rowCount[0] = prev;
  // for(unsigned int k=0; k<nRows; k++){
  //   curr = mtx->pCols->vals[k];
  //
  //   inc = curr-prev;
  //
  //   while(curr > (curr - inc)){
  //     rowCount[curr-inc] = row;
  //     inc--;
  //     printf("%u\n", prev);
  //   }
  //
  //   prev = curr;
  //   row++;
  // }
  //
  // printf("\n\n");
  // printf("rowCount:\n");
  // for(unsigned int k = 0; k < nz; k++){
  //   printf("%u\n", rowCount[k]);
  // }



  // for(unsigned int j=0; j<nz; j++){
  //   col = mtx->iRows->vals[j]-1;
  //   row = -1;
  //   val = mtx->xVals->vals[j];
  //
  //   idx = matrix_t->pCols->vals[dest];
  //
  //   add_at(matrix_t->iRows, idx, /**/);
  //
  // }

  free(colCount);
}// fin convert()


































/*----------------------------------------------------------------------------*/
// WORK IN PROGRESS !!!! DO NOT MODIFY UNLESS THIS BANNER HAS BEEN REMOVED
// Mtx *transpose(Mtx *mtx){
//   assert(mtx != NULL);
//
//   /*-------------Var Init--------------*/
//   unsigned int nCols = get_matrix_pCols_size(mtx);
//   unsigned int nRows = get_matrix_dimensions(mtx);
//   unsigned int nz = get_matrix_nz_size(mtx);
//   unsigned int index = 0, tmp = 0, end = 0;
//
//   /*-----------Tables Init-------------*/
//   unsigned int *occ = (unsigned int *)calloc(nRows, sizeof(unsigned int));
//   if(occ == NULL){
//     return NULL;
//   }
//
//   Mtx *matrix_t = create_sparse_matrix();
//   matrix_t->dim = nRows;
//   matrix_t->nz = nz;
//   init_sparse_matrix(matrix_t);
//
//   // init new transposed matrix with appropriate sizes (work in progress)
//
//   // for(unsigned int i = 0; i < nRows; i++){
//   //   add_at(matrix_t->pCols, i, 0);
//   // }
//   // for(unsigned int j = 0; j < nz; j++){
//   //   printf("ok\n");
//   //   add_at(matrix_t->iRows, j, 0);
//   //   add_at(matrix_t->xVals, j, 0);
//   // }
//   //
//   // for(unsigned int idx = 0; idx < nz; idx++){
//   //   matrix_t->pCols->vals[(unsigned int)mtx->iRows->vals[idx]]++;
//   // }
//   //
//   // for(col = 0; col < nCols; col++){
//   //   tmp = matrix_t->pCols->vals[col];
//   //   matrix_t->pCols->vals[col] = cumsum;
//   //   cumsum += tmp;
//   // }
//   //
//   // matrix_t->pCols->vals[nCols] = nz;
//   //
//   // for(unsigned int row = 0; row < nRows; row++){
//   //   for(unsigned int k = mtx->pCols->vals[row]; k < mtx->pCols->vals[row+1]; k++){
//   //     col = mtx->iRows->vals[k];
//   //     dest = matrix_t->pCols->vals[col];
//   //
//   //     matrix_t->iRows->vals[dest] = row;
//   //     matrix_t->xVals->vals[dest] = mtx->xVals->vals[k];
//   //
//   //     matrix_t->pCols->vals[col]++;
//   //   }
//   // }
//   //
//   // for(unsigned int col = 0; col <= nCols; col++){
//   //   tmp = matrix_t->pCols->vals[col];
//   //   matrix_t->pCols->vals[col] = last;
//   //   last = tmp;
//   // }
//
//   return mtx;
// }
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
