/**
 * \file sparse-vector.h
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les déclarations de types et les prototypes des
 * fonctions pour représenter un vecteur creux ou dense. Les vecteurs sont
 * utilisés lors des résolutions de systèmes triangulaires.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "array.h"

/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __SPARSEVCTR__
#define __SPARSEVCTR__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/
#define COL 1;
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct{
  Array *iRows ;
  Array *xVals ;
  unsigned int nz ;
  unsigned int dim ;
  unsigned int col ;
}Vctr;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __SPARSEVCTR__