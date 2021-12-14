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
#include "sparse-vector.h"

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
 * \fn void convert(Mtx *mtx, Mtx *matrix_t)
 * \brief Convertit la matrice en entrée du format CSR au format CSC
 *        et vice-versa.
 *
 * \param mtx, pointeur sur matrice creuse à convertir(!= NULL).
 * \param matrix_t, pointeur sur matrice creuse, qui contiendra le résultat de
 *                  la conversion.
 *
 */
void convert(Mtx *mtx, Mtx *matrix_t);
/*----------------------------------------------------------------------------*/
Vctr *solve_dense_system(Mtx *L, Vctr *b);
/*----------------------------------------------------------------------------*/
Vctr *solve_sparse_system(Mtx *L, Vctr *b);
/*----------------------------------------------------------------------------*/
/**
 * \fn Mtx *product_of_sparse_matrices(Mtx *A, Mtx *B)
 * \brief Effectue le produit des deux matrices creuses entrées en arguments.
 *
 * \param A, pointeur sur matrice creuse (!= NULL).
 * \param B, pointeur sur matrice creuse (!= NULL).
 *
 * \return une nouvelle matrice creuse, égale au produit des matrices A et B.
 *
 */
Mtx *product_of_sparse_matrices(Mtx *A, Mtx *B);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __OPERATIONS__
