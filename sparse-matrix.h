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
 * Ce fichier contient les déclarations de types et les prototypes des
 * fonctions utilisées pour représenter une matrice creuse en format
 * "Compressed Sparse Column".
 */
#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "array.h"
/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __SPARSEMTX__
#define __SPARSEMTX__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \struct Mtx
 * \brief Structure de données représentant une matrice creuse sous forme
 *        "column compressed".
 *        Mtx contient trois structures Array et deux informations:
 *
 *        - *pCols : les indices de début de chaque colonnes dans iLines.
 *        - *iLines : les indices de lignes de chaque élément dans xVals.
 *        - *xVals : les valeurs des éléments non-nuls de la matrice.
 *        - nz : le nombre d'élément non-nul dans la matrice creuse.
 *        - dim : la dimension de la matrice creuse (matrice carrée).
 *
 */
typedef struct{
  Array *pCols ;
  Array *iLines ;
  Array *xVals ;
  unsigned int nz;
  unsigned int dim;
}Mtx;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
// Mtx *create_sparse_matrix(unsigned int dimensions);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __SPARSEMTX__
