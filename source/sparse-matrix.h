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
#define INITIAL_SIZE 1
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \struct Mtx
 * \brief Structure de données représentant une matrice creuse sous forme
 *        "column compressed".
 *        Mtx contient trois structures Array et deux informations:
 *
 *        - *pCols : les indices de début de chaque colonnes dans iRows.
 *        - *iRows : les indices de lignes de chaque élément dans xVals.
 *        - *xVals : les valeurs des éléments non-nuls de la matrice.
 *        - nz : le nombre d'éléments non-nuls dans la matrice creuse.
 *        - dim : la dimension de la matrice creuse (matrice carrée).
 *
 */
typedef struct{
  Array *pCols ;
  Array *iRows ;
  Array *xVals ;
  unsigned int nz;
  unsigned int dim;
}Mtx;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Mtx *create_sparse_matrix(void)
 * \brief Crée une structure Mtx représentant une matrice creuse.
 *
 * \return Un pointeur vers une nouvelle matrice creuse non-initialisée.
 *         NULL en cas d'échec.
 */
Mtx *create_sparse_matrix(void);
/*----------------------------------------------------------------------------*/
/**
 * \fn void init_sparse_matrix(Mtx *mtx)
 * \brief Initialise la matrice creuse mtx.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 */
void init_sparse_matrix(Mtx *mtx);
/*----------------------------------------------------------------------------*/
/**
 * \fn void free_sparse_matrix(Mtx *mtx)
 * \brief Libère la mémoire allouée à la structure mtx.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 */
void free_sparse_matrix(Mtx *mtx);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_matrix_dimensions(Mtx *mtx)
 * \brief Renvoie la dimension de la matrice creuse.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 * \return Les dimensions (nombre de lignes/colonnes) de la matrice creuse.
 *         (NB: la matrice creuse est carrée).
 */
unsigned int get_matrix_dimensions(Mtx *mtx);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_matrix_pCols_size(Mtx *mtx)
 * \brief Renvoie la taille du vecteur pCols de la matrice creuse.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 * \return La taille du vecteur pCols contenu dans la matrice creuse.
 */
unsigned int get_matrix_pCols_size(Mtx *mtx);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_matrix_nz_size(Mtx *mtx)
 * \brief Renvoie la quantitée d'éléments non-nuls contenu dans la matrice.
 *
 * \param mtx, pointeur sur matrice creuse (!= NULL).
 *
 * \return La quantitée d'éléments non-nuls de la matrice creuse.
 */
unsigned int get_matrix_nz_size(Mtx *mtx);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __SPARSEMTX__
