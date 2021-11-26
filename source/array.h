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
 * fonctions pour représenter un vecteur (array). Les arrays sont utilisés
 * pour représenter les matrices creuses en format "Compressed Sparse Column".
 */
#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __ARRAY__
#define __ARRAY__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/
#define REALLOC_FACTOR 2
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
 *        - *vals : le tableau représentant le vecteur en tant que tel.
 *
 */
typedef struct{
  unsigned int cap;
  unsigned int size;
  double *vals;
}Array;
/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *create_array(unsigned int size)
 * \brief Crée une structure Array représentant un vecteur de taille "size"
 *
 * \param size, taille du vecteur (> 0)
 *
 * \return Un pointeur vers un nouveau vecteur.  NULL en cas d'échec.
 */
Array *create_array(unsigned int size);
/*----------------------------------------------------------------------------*/
/**
 * \fn unsigned int get_array_size(Array *array)
 * \brief Retourne le nombre d'éléments que contient le vecteur.
 *
 * \param array, pointeur sur vecteur (!= NULL).
 *
 * \return le nombre d'éléments contenu dans le vecteur.
 */
unsigned int get_array_size(Array *array);
/*----------------------------------------------------------------------------*/
/**
 * \fn Boolean is_empty(Array *array)
 * \brief Détermine si le vecteur est vide ou non.
 *
 * \param array, pointeur sur vecteur (!= NULL).
 *
 * \return True si le vecteur est vide, False sinon.
 */
Boolean is_empty(Array *array);
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *add_at(Array *array, unsigned int i, double val)
 * \brief Ajoute un nouvel élément au vecteur.
 *
 * \param array, pointeur sur vecteur (!= NULL).
 * \param i, le rang auquel ajouter le nouvel élément. (0 <= i <= array->size)
 * \param val, l'élément à ajouter.
 *
 * \return Le vecteur modifié, le nouvel élément ajouté au rang i.
 */
Array *add_at(Array *array, unsigned int i, double val);
/*----------------------------------------------------------------------------*/
/**
 * \fn Array *remove_at(Array *array, unsigned int i)
 * \brief Supprime un élément du vecteur.
 *
 * \param array, pointeur sur vecteur (!= NULL).
 * \param i, le rang de l'élément à supprimer.
 *
 * \return La vecteur modifié, l'élément au rang i a été supprimé.
 */
Array *remove_at(Array *array, unsigned int i);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __ARRAY__
