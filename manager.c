/**
 * \file manager.c
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient les définitions des fonctions utilisées
 * dans la gestion des arguments du programme, et au déroulement des
 * opérations du programmes.
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
#include "manager.h"

/*----------------------------------------------------------------------------*/
/*------------------------------FONCTIONS STATIQUES---------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
void manage_inputs(int argc, char *argv[], const char *optstring,
                  char **lFile, char **uFile, char **aFile, char **xFile,
                  unsigned short *operation, unsigned short **toOperation){

  int val;

  while((val = getopt(argc, argv, optstring))!= EOF){
    switch(val){

      case 'h':
        printf("HELP: \n\n");
        printf("Ce programme permet, au choix, : \n");
        printf("\t1) de résoudre un système triangulaire de type Ax = b.\n");
        printf("\t2) de calculer le produit de deux matrices creuses.\n");
        printf("\t3) de résoudre un système de type LUx = b avec b creux,\n");
        printf("\t   de résoudre un système de type LUx = c avec c dense\n");
        printf("\t   ET de calculer le produit de L et U tel que A = LU\n\n");
        printf("Options: \n\n");
        printf("\t- Entrer l'opération souhaitée avec l'option -o (1/2/3)\n");
        printf("\t- Entrer la matrice creuse L avec l'option -l\n");
        printf("\t- Entrer la matrice creuse U avec l'option -u\n");
        printf("\t- Entrer le vecteur creux a avec l'option -a\n");
        printf("\t- Entrer le vecteur dense x avec l'option -x\n\n");
        break;

      case 'o':
        *operation = (unsigned short)atoi(optarg);
        *toOperation = operation;
        break;

      case 'l':
        *lFile = optarg;
        break;

      case 'u':
        *uFile = optarg;
        break;

      case 'a':
        *aFile = optarg;
        break;

      case 'x':
        *xFile = optarg;
        break;

      case '?':
        printf("Option inconnue: %c\n", optopt);
        break;

      case ':':
        printf("Argument manquant: %c\n", optopt);
        break;
    }
  }
}
/*----------------------------------------------------------------------------*/
Mtx *read_mtx_file(char *filename){
  assert(filename != NULL);

  Mtx *mtx = NULL;

  FILE *file = fopen(filename, "r");

  fclose(file);
  return mtx;
}


























/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
