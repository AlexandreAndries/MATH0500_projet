/**
 * \file sparse-vector.c
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les définitions des fonctions utilisées
 * pour représenter un vecteur creux ou dense. Les vecteurs sont
 * utilisés lors des résolutions de systèmes triangulaires.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "boolean.h"
#include "array.h"
#include "sparse-vector.h"
/*----------------------------------------------------------------------------*/
/*------------------------------FONCTIONS STATIQUES---------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
Vctr *create_sparse_vector(void){

  Vctr *vctr = (Vctr*)malloc(sizeof(Vctr));
  if(vctr == NULL){
    return NULL;
  }

  vctr->iRows = NULL;
  vctr->xVals = NULL;
  vctr->nz = 0;
  vctr->dim = 0;
  vctr->isDense = False;

  return vctr;
}// fin create_sparse_vector()
/*----------------------------------------------------------------------------*/
void init_sparse_vector(Vctr *vctr){
  assert(vctr != NULL && vctr->dim != 0 && vctr->nz != 0);

  vctr->iRows = create_array(vctr->nz);
  vctr->xVals = create_array(vctr->nz);
}// fin init_sparse_vector()
/*----------------------------------------------------------------------------*/
void free_sparse_vector(Vctr *vctr){
  assert(vctr != NULL);

  free(vctr->iRows->vals);
  free(vctr->iRows);
  free(vctr->xVals->vals);
  free(vctr->xVals);
  free(vctr);
}// fin free_sparse_vector()
/*----------------------------------------------------------------------------*/
unsigned int get_vector_dimension(Vctr *vctr){
  assert(vctr != NULL);

  return vctr->dim;
}// fin get_vector_dimension()
/*----------------------------------------------------------------------------*/
unsigned int get_vector_nz_size(Vctr *vctr){
  assert(vctr != NULL);

  return vctr->nz;
}// fin get_vector_nz_size()
/*----------------------------------------------------------------------------*/
void set_vector_density(Vctr *vctr, Boolean density){
  assert(vctr != NULL && (density==True || density==False));

  vctr->isDense = density;
}// fin set_vector_density()
/*----------------------------------------------------------------------------*/
Boolean get_vector_density(Vctr *vctr){
  assert(vctr != NULL);

  return vctr->isDense;
}// fin get_vector_density()
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
