/**
 * \file matrix-reader.h
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient contient les déclarations de types
 * et les prototypes des fonctions pour la lecture de matrices en input
 * du programme. La lecture des fichiers .mtx entrés permets de créer la
 * matrice creuse et le vecteur creux correspondants.
 */
#include <stdlib.h>
#include <stdio.h>
/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __MTXREADER__
#define __MTXREADER__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/
#define SHIFT 1
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \struct Array
 * \brief Structure de données représentant un vecteur contenant les données
 *        d'une matrice creuse sous forme "column compressed".
 *        Array contient trois informations :
 *
 *        - cap : la capacité du vecteur (nombre max d'éléments qu'il peut
 *                contenir dans la mémoire). Peut être augmenter par realloc.
 *        - size : le nombre d'éléments contenu dans le vecteur.
 *        - *val : le tableau représentant le vecteur en tant que tel.
 *
 */
typedef struct{
  unsigned int cap;
  unsigned int size;
  double *val;
}Array;
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
void ignore_com(FILE *filename);
/*----------------------------------------------------------------------------*/
void get_mtx_dimensions(Mtx *mtx, FILE *fp);
/*----------------------------------------------------------------------------*/
int read_mtx(Mtx **matrix, char *filename);
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __MTXREADER__
