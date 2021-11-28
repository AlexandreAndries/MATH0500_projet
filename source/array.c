/**
 * \file array.c
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les définitions des fonctions utilisées
 * pour représenter un vecteur (array). Les arrays sont utilisés
 * pour représenter les matrices creuses en format "Compressed Sparse Column".
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "array.h"
#include "boolean.h"
/*----------------------------------------------------------------------------*/
/*------------------------------FONCTIONS STATIQUES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *realloc_array(Array *array)
 * \brief Augmente (i.e. double) la capacité du vecteur (reallocation dynamique)
 *
 * \param array, le vecteur à augmenter (!= NULL).
 *
 * \return Un pointeur vers le nouveau vecteur, Null en cas d'échec.
 */
static Array *realloc_array(Array *array){
  assert(array != NULL);

  array->cap *= REALLOC_FACTOR;
  array->vals = (double*)realloc(array->vals, array->cap*sizeof(double));

  return array;
}// fin realloc_array()
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *shift_right(Array *array, unsigned int start)
 * \brief Décale d'une position vers la droite les éléments du vecteur à partir
 * de 'start' vers la fin vecteur. Si besoin, on augmente la taille du vecteur.
 *
 * \param array, le vecteur à manipuler (!= NULL)
 * \param start, la position de départ du décalage
 *
 * \return Un pointeur vers le nouveau vecteur, Null en cas d'échec.
 */
static Array *shift_right(Array *array, unsigned int start){
  assert(array != NULL && start <= array->size);

  if(array->size + 1 >= array->cap){
    array = realloc_array(array);
  }

  for(unsigned int i=array->size; i>=start; i--){
    array->vals[i+1] = array->vals[i];
  }

  return array;
}// fin shift_right()
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *shift_left(Array *array, unsigned int start)
 * \brief Décale d'une position vers la gauche les éléments du vecteur à partir
 * de 'start' vers la fin vecteur.
 *
 * \param array, le vecteur à manipuler (!= NULL)
 * \param start, la position de départ du décalage
 *
 * \return Un pointeur vers le nouveau vecteur, Null en cas d'échec.
 */
static Array *shift_left(Array *array, unsigned int start){
  assert(array != NULL && 0 < start && start <= array->size);

  for(unsigned int i=start; i<array->size; i++){
    array->vals[i-1] = array->vals[i] ;
  }

  return array;
}// fin shift_left()
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
Array *create_array(unsigned int size){
  assert(size > 0);

  Array *array = (Array *)malloc(sizeof(Array));
  if(array == NULL){
    return NULL;
  }

  array->cap = size ;
  array->size = 0 ;

  array->vals = (double *)malloc(size*sizeof(double));
  if(array->vals == NULL){
    free(array);
    return NULL;
  }

  return array;
}// fin create_array()
/*----------------------------------------------------------------------------*/
unsigned int get_array_size(Array *array){
  assert(array != NULL);

  return array->size;
}// fin get_array_size()
/*----------------------------------------------------------------------------*/
Boolean is_empty(Array *array){
  assert(array != NULL);

  if(array->size == 0){
    return True;
  }else{
    return False;
  }
}// fin is_empty()
/*----------------------------------------------------------------------------*/
Array *add_at(Array *array, unsigned int i, double val){
  assert(array != NULL && i <= array->size);

  if(array->size + 1 >= array->cap){
    array =  realloc_array(array);
  }

  if(array->vals[i] != 0){ 
    array = shift_right(array, i);
  }

  array->vals[i] = val;
  array->size++;

  return array;
}// fin add_at()
/*----------------------------------------------------------------------------*/
Array *remove_at(Array *array, unsigned int i){
  assert(array != NULL && i < array->size);

  array = shift_left(array, i+1);
  array->size--;

  return array;
}// fin remove_at()
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
