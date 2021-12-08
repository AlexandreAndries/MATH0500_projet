/**
 * \file array.h
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les définitions des fonctions utilisées
 * pour représenter une matrice creuse en format "Compressed Sparse
 * Column".
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "boolean.h"
#include "array.h"
#include "sparse-matrix.h"
/*----------------------------------------------------------------------------*/
/*------------------------------FONCTIONS STATIQUES---------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
Mtx *create_sparse_matrix(void){

  Mtx *mtx = (Mtx*)malloc(sizeof(Mtx));
  if(mtx == NULL){
    return NULL;
  }

  mtx->pCols = NULL;
  mtx->iRows = NULL;
  mtx->xVals = NULL;
  mtx->nz = 0;
  mtx->dim = 0;

  return mtx;
}// fin create_sparse_matrix()
/*----------------------------------------------------------------------------*/
void init_sparse_matrix(Mtx *mtx){
  assert(mtx != NULL && mtx->dim != 0);

  mtx->pCols = create_array(mtx->dim);
  mtx->iRows = create_array(mtx->nz);
  mtx->xVals = create_array(mtx->nz);
}// fin init_sparse_matrix()
/*----------------------------------------------------------------------------*/
void free_sparse_matrix(Mtx *mtx){
  assert(mtx != NULL);

  free(mtx->pCols->vals);
  free(mtx->pCols);
  free(mtx->iRows->vals);
  free(mtx->iRows);
  free(mtx->xVals->vals);
  free(mtx->xVals);
  free(mtx);
}// fin free_sparse_matrix()
/*----------------------------------------------------------------------------*/
unsigned int get_matrix_dimensions(Mtx *mtx){
 assert(mtx != NULL);

 return mtx->dim;
}// fin get_matrix_dimensions()
/*----------------------------------------------------------------------------*/
unsigned int get_matrix_pCols_size(Mtx *mtx){
  assert(mtx != NULL);

  return get_array_size(mtx->pCols);
}// fin get_matrix_pCols_size()
/*----------------------------------------------------------------------------*/
unsigned int get_matrix_nz_size(Mtx *mtx){
  assert(mtx != NULL);

  return mtx->nz;
}// fin get_matrix_nz_size()
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
