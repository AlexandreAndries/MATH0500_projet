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
/**
 * \fn void skip_banner(FILE *file)
 * \brief Ignore la première ligne ("banière") du fichier MatrixMarket en input.
 *
 * \param file, path vers le fichier contenant la matrice. (!= NULL)
 *
 */
static void skip_banner(FILE *file){
  assert(file != NULL);

  char c ;
  fscanf(file, "%c", &c);
  if(c == '%'){
    fscanf(file, "%*[^\n]\n");
  }
}// fin skip_banner()
/*----------------------------------------------------------------------------*/
/**
 * \fn void get_dimensions(FILE *file, Mtx *mtx)
 * \brief Enregistre les données concernant les dimensions de la matrice creuse
 *        et le nombre d'éléments non-nuls qu'elle possède.
 *        Ces données sont enregistrées dans une structure Mtx non-initialisée.
 *
 * \param file, path vers le fichier contenant la matrice. (!= NULL)
 * \param mtx, structure Mtx existante mais non-initialisée. (!= NULL)
 *
 */
static void get_dimensions(FILE *file, Mtx *mtx){
  assert(mtx != NULL && file!= NULL);

  fscanf(file, "%u %*u %u", &mtx->dim, &mtx->nz);
}// fin get_dimensions()
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
}// fin manage_inputs()
/*----------------------------------------------------------------------------*/
Mtx *read_mtx_file(char *filename){
  assert(filename != NULL);

  Mtx *mtx = NULL;
  mtx = create_sparse_matrix();

  FILE *fp = fopen(filename, "r");

  skip_banner(fp);
  get_dimensions(fp, mtx);
  init_sparse_matrix(mtx);
  //get_data -->lecture des données sur les NZ dans le fichier en entrée,
  //            pour remplir les 3 vecteurs de la matrice et avoir le format CSC
  //            de l matrice contenue dans le fichier.


  fclose(fp);
  return mtx;
}// fin read_mtx_file()
/*----------------------------------------------------------------------------*/

























/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
