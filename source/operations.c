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
// WORK IN PROGRESS !!!! DO NOT MODIFY UNLESS THIS BANNER HAS BEEN REMOVED
Mtx *transpose(Mtx *mtx){
  assert(mtx != NULL);

  /*-------------Var Init--------------*/
  unsigned int nCols = get_matrix_pCols_size(mtx);
  unsigned int nLines = get_matrix_dimensions(mtx);
  unsigned int nz = get_matrix_nz_size(mtx);
  unsigned int index = 0, tmp = 0, end = 0;

  /*-----------Tables Init-------------*/
  unsigned int *occ = (unsigned int *)calloc(nLines, sizeof(unsigned int));
  if(occ == NULL){
    return NULL;
  }

  Mtx *matrix_t = create_sparse_matrix();
  matrix_t->dim = nLines;
  matrix_t->nz = nz;
  init_sparse_matrix(matrix_t);

  // init new transposed matrix with appropriate sizes (work in progress)


  return mtx;
}
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
