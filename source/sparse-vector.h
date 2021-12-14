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
#define COL 1
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \struct Vctr
 * \brief Structure de données représentant un vecteur creux sous forme
 *        comprimée. On ne reprend que ses éléments non nuls et leurs coords.
 *        Vctr contient deux structures Array et trois informations:
 *
 *        - *iRows : les indices de lignes de chaque élément dans xVals.
 *        - *xVals : les valeurs des éléments non-nuls du vecteur.
 *        - nz : le nombre d'éléments non-nuls dans le vecteur creux.
 *        - dim : la longueur du vecteur creux.
 *        - isDense : False si le vecteur est très creux, True si le vecteur
 *                    "dense" (i.e. moins creux).
 *
 */
typedef struct{
  Array *iRows ;
  Array *xVals ;
  unsigned int nz ;
  unsigned int dim ;
  Boolean isDense ;
}Vctr;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Vctr *create_sparse_vector(void)
 * \brief Crée une structure Vctr représentant un vecteur creux.
 *
 * \return Un pointeur vers un nouveau vecteur creux non-initialisé.
 *         NULL en cas d'échec.
 */
Vctr *create_sparse_vector(void);
/*----------------------------------------------------------------------------*/
/**
 * \fn void init_sparse_vector(Vctr *vctr)
 * \brief Initialise le vecteur creux vctr.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 *
 */
void init_sparse_vector(Vctr *vctr);
/*----------------------------------------------------------------------------*/
/**
 * \fn void free_sparse_vector(Vctr *vctr)
 * \brief Libère la mémoire allouée à la structure vctr.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 *
 */
void free_sparse_vector(Vctr *vctr);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_vector_dimension(Vctr *vctr)
 * \brief Renvoie la dimension du vecteur creux.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 *
 * \return Le nombre de lignes du vecteur creux.
 *         (NB: le vecteur creux n'a qu'une unique colonne).
 */
unsigned int get_vector_dimension(Vctr *vctr);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_vector_nz_size(Vctr *vctr)
 * \brief Renvoie la quantitée d'éléments non-nuls contenu dans le vecteur.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 *
 * \return La quantitée d'éléments non-nuls du vecteur creux.
 */
unsigned int get_vector_nz_size(Vctr *vctr);
/*----------------------------------------------------------------------------*/
/**
 * \fn void set_vector_nz_size(Vctr *vctr, unsigned int nz)
 * \brief Modifie la quantitée d'éléments non-nuls contenu dans le vecteur.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 * \param nz, nouveau nombre d'éléments non-nuls.
 *
 */
void set_vector_nz_size(Vctr *vctr, unsigned int nz);
/*----------------------------------------------------------------------------*/
/**
 * \fn void set_vector_density(Vctr *vctr, Boolean density)
 * \brief Définit l'attribut "isDense" du vecteur sur base de l'argument entré.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 * \param density, booléen détemerninant si le vecteur est dense (True)
 *                ou creux (False).
 *
 */
void set_vector_density(Vctr *vctr, Boolean density);
/*----------------------------------------------------------------------------*/
/**
 * \fn Boolean get_vector_density(Vctr *vctr)
 * \brief Renvoie la valeur de l'attribut "isDense" du vecteur.
 *
 * \param vctr, pointeur sur vecteur creux (!= NULL).
 *
 * \return True si le vecteur est dense.
 *          False sinon.
 */
Boolean get_vector_density(Vctr *vctr);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __SPARSEVCTR__
