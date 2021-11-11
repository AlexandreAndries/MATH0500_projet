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
 * \struct NZ_Element
 * \brief Structure de données représentant les informations d'un élément
 *        non-nul d'une matrice.
 *        NZ_Element contient trois informations :
 *
 *        - row : le numéro de la ligne de l'élément dans la matrice.
 *        - col : le numéro de la colonne de l'élément dans la matrice.
 *        - val : la valeur de l'élément.
 *
 */
typedef struct{
  unsigned int row;
  unsigned int col;
  long val;
}NZ_Element;
/*----------------------------------------------------------------------------*/
/**
 * \struct Mtx
 * \brief Structure de données représentant une matrice creuse
 *        Mtx contient trois informations et un tableau:
 *
 *        - nRows : le nombre de lignes de la matrice.
 *        - nCols : le nombre de colonnes de la matrice.
 *        - nonZeros : le nombre d'éléments non-nuls dans la matrice.
 *        - **elements : tableau contenant les éléments non-nuls de la matrice
 *
 */
typedef struct{
  unsigned int nRows;
  unsigned int nCols;
  unsigned int nonZeros;
  NZ_Element **elements;
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
