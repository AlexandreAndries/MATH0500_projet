/**
 * \file manager.h
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les déclarations de types et les prototypes des
 * fonctions utilisées dans la gestion des arguments du programme, et au
 * déroulement des opérations du programmes.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "array.h"
#include "sparse-matrix.h"
#include "sparse-vector.h"
#include "operations.h"

/*----------------------------------------------------------------------------*/
/*--------------------------------INCLUDE GUARD-------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef __MANAGER__
#define __MANAGER__
/*----------------------------------------------------------------------------*/
/*-----------------------------------MACROS-----------------------------------*/
/*----------------------------------------------------------------------------*/
#define INITIAL_POS 1
/*----------------------------------------------------------------------------*/
/*----------------------------STRUCTURES DE DONNEES---------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
/**
 * \fn void manage_inputs(int argc, char *argv[], const char *optstring,
 *                 char **lFile, char **uFile, char **aFile, char **xFile,
 *                 unsigned short *operation, unsigned short **toOperation);
 *
 * \brief Fonction permettant la gestion des options et arguments passés au
 *        programme principal. La fonction permet également la gestion des
 *        erreurs d'input en renvoyant des messages informatifs sur la sortie
 *        standard.
 *
 * \param argc, nombre d'arguments passés au programme.
 * \param *argv[], tableau contenant les arguments passés au programme.
 * \param *optstring, string contenant les options possibles du programme.
 * \param **lFile, pointeur sur string qui contiendra le nom du fichier
 *                 représentant la matrice creuse L en input.
 * \param **uFile, pointeur sur string qui contiendra le nom du fichier
 *                 représentant la matrice creuse U en input.
 * \param **aFile, pointeur sur string qui contiendra le nom du fichier
 *                 représentant le vecteur creux a en input.
 * \param **xFile, pointeur sur string qui contiendra le nom du fichier
 *                 représentant le vecteur dense x en input.
 * \param *operation, pointeur sur unsigned short qui contiendra l'opération à
 *                    effectuer selon le chox de l'utilisateur.
 * \param **toOperation, pointeur sur pointeur qui pointera sur operation.
 *
 */
void manage_inputs(int argc, char *argv[], const char *optstring,
                  char **lFile, char **uFile, char **aFile, char **xFile,
                  unsigned short *operation, unsigned short **toOperation);
/*----------------------------------------------------------------------------*/
/**
 * \fn Mtx *read_mtx_file(char *filename)
 * \brief Lit un fichier .mtx représentant une matrice creuse et enregistre
 *        les données du fichier dans une structure Mtx.
 *
 * \param filename, path vers le fichier contenant la matrice creuse. (!= NULL)
 *
 * \return Un pointeur vers la structure Mtx représentant la matrice creuse
 *         contenue dans le fichier en argument.  NULL en cas d'échec.
 */
Mtx *read_mtx_file(char *filename);
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_mtx_file(Mtx *mtx, char *filename)
 * \brief Ecrit les données d'une structure Mtx dans un fichier .mtx
 *        représentant une matrice creuse.
 *
 * \param filename, path vers le fichier où écrire la matrice creuse. (!= NULL)
 * \param mtx, la matrice creuse à écrire dans un fichier. (!= NULL)
 *
 */
void write_mtx_file(Mtx *mtx, char *filename);
/*----------------------------------------------------------------------------*/
/**
 * \fn Vctr *read_vctr_file(char *filename)
 * \brief Lit un fichier .mtx représentant un vecteur creux et enregistre
 *        les données du fichier dans une structure Vctr.
 *
 * \param filename, path vers le fichier contenant le vecteur creux. (!= NULL)
 *
 * \return Un pointeur vers la structure Vctr représentant le vecteur creux
 *         contenu dans le fichier en argument.  NULL en cas d'échec.
 */
Vctr *read_vctr_file(char *filename);
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_mtx_file(Mtx *mtx, char *filename)
 * \brief Ecrit les données d'une structure Vctr dans un fichier .mtx
 *        représentant un vecteur creux.
 *
 * \param filename, path vers le fichier où écrire le vecteur creux. (!= NULL)
 * \param vctr, le vecteur creux à écrire dans un fichier. (!= NULL)
 *
 */
void write_vctr_file(Vctr *vctr, char *filename);
/*----------------------------------------------------------------------------*/
/**
 * \fn void manage_operations(unsigned int op, Mtx *L, Mtx *U, Vctr *a, Vctr *x)
 * \brief Permet la gestion des opérations à effectuer par le programme en
 *        fonction du choix d'option de l'utilisateur.
 *        Les options sont au choix :
 *          1. Résolution des équations Lb = a et Lb = x (b vecteur inconnu).
 *          2. Résolution du produit L*U.
 *          3. Résolutions successives des options 1 et 2.
 *
 * \param op, l'option choisie par l'utilisateur (1/2/3).
 * \param L, matrice L triangulaire inférieure creuse.
 * \param U, matrice U triangulaire supérieure creuse.
 * \param a, vecteur creux.
 * \param x, vecteur dense.
 *
 */
void manage_operations(unsigned int op, Mtx *L, Mtx *U, Vctr *a, Vctr *x);
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __MANAGER__
