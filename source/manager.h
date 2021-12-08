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
/*--------------------------------FIN DU HEADER-------------------------------*/
/*----------------------------------------------------------------------------*/
#endif // __MANAGER__
