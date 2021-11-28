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
 * Ce fichier contient les déclarations de types et les prototypes des
 * fonctions utilisées dans la gestion des calculs et opérations sur une
 * matrice creuse, entre deux matrices creuses, entre une matrice creuse et
 * un vecteur creux (resp. un vecteur dense).
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "array.h"
#include "sparse-matrix.h"

/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __OPERATIONS__
#define __OPERATIONS__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Mtx *transpose(Mtx *mtx)
 * \brief Calcule et retourne la transposée de la matrice CSC en input.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 * \return Un pointeur vers une structure Mtx représentant la matrice creuse
 *         transposée.
 */
Mtx *transpose(Mtx *mtx);
/*----------------------------------------------------------------------------*/
void convert(Mtx *mtx, Mtx *matrix_t);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __OPERATIONS__
