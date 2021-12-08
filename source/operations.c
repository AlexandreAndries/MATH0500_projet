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
// static void fusion(Mtx *mtx, unsigned int start1, unsigned int end1,
//                   unsigned int end2){
//   assert(mtx != NULL);
//
//   /*------Var Init------*/
//   unsigned int *tableRows;
//   double *tableVals;
//   unsigned int start2 = end1 + 1;
//   unsigned int count1 = start1, count2 = start2;
//
//   tableRows = (unsigned int *)malloc((end1 - start1 + 1)*sizeof(unsigned int));
//   tableVals = (double *)malloc((end1 - start1 + 1)*sizeof(double));
//
//   if(tableRows == NULL || tableVals == NULL){
//     printf("Erreur d'allocation mémoire\n");
//     exit(-2);
//   }
//   /*----End Var Init----*/
//   /*--------------------*/
//   /*---Sort Procedure---*/
//   for(unsigned int i = start1; i <= end1; i++){
//     tableRows[i-start1] = mtx->iRows->vals[i];
//     tableVals[i-start1] = mtx->xVals->vals[i];
//   }
//
//   for(unsigned int i = start1; i<= end2; i++){
//     if(count1==start2){
//       break;
//     }else if(count2 == (end2 + 1)){
//       mtx->iRows->vals[i] = tableRows[count1 - start1];
//       mtx->xVals->vals[i] = tableVals[count1 - start1];
//       count1++;
//     }else if(tableRows[count1 - start1] < mtx->iRows->vals[count2]){
//       mtx->iRows->vals[i] = tableRows[count1 - start1];
//       mtx->xVals->vals[i] = tableVals[count1 - start1];
//       count1++;
//     }else{
//       mtx->iRows->vals[i] = mtx->iRows->vals[count2];
//       mtx->xVals->vals[i] = mtx->xVals->vals[count2];
//       count2++;
//     }
//   }
//   /*-End Sort Procedure-*/
//   /*--------------------*/
//   /*------Free Tabs-----*/
//   free(tableRows);
//   free(tableVals);
//   /*---End Free Tabs----*/
// }// fin fusion()
// /*----------------------------------------------------------------------------*/
// static void merge_sort(Mtx *mtx, unsigned int start, unsigned int end,
//                         unsigned int length){
//   assert(mtx != NULL && length>0 && start != end);
//
//   unsigned int middle = (start+end)/2;
//   merge_sort(mtx, start, middle, middle-start);
//   merge_sort(mtx, middle+1, end, end-(middle+1));
//   fusion(mtx, start, middle, end);
// }// fin merge_sort()
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
// void sort_mtx_iRows(Mtx *mtx, unsigned int start, unsigned int end,
//                         unsigned int length){
//   assert(mtx != NULL && length>0 && start != end);
//
//   merge_sort(mtx, start, end, length);
// }// fin merge_sort()
/*----------------------------------------------------------------------------*/
void convert(Mtx *mtx, Mtx *matrix_t){
  assert(mtx != NULL);

  /*-------------Var Init--------------*/
  unsigned int nRows = get_matrix_dimensions(mtx);
  unsigned int nz = get_matrix_nz_size(mtx);
  unsigned int tmp = 0, cumSum = 1 , temp, idx, end;

  unsigned int *colCount = (unsigned int*)calloc(nRows, sizeof(unsigned int));
  unsigned int *sortRow = (unsigned int*)calloc(nz, sizeof(unsigned int));
  if(colCount == NULL || sortRow == NULL){
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
  //--------Code above works -------------------------------
  //--------Test zone --------------------------------------
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
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
