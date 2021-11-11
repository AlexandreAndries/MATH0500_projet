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
 * Ce fichier contient contient les définitions des fonctions pour la lecture
 * de matrices en input du programme. La lecture des fichiers .mtx entrés
 * permets de créer la matrice creuse et le vecteur creux correspondants.
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "matrix-reader.h"

/*----------------------------------------------------------------------------*/
/*----------------------------FONCTIONS & PROCEDURES--------------------------*/
/*----------------------------------------------------------------------------*/
// void manage_arguments(int argc, char *argv[], const char *optstring){};
/*----------------------------------------------------------------------------*/
void ignore_com(FILE *filename){
  assert(filename != NULL);

  char c ;
  fscanf(filename, "%c", &c);
  if(c == '%'){
    fscanf(filename, "%*[^\n]\n");
  }
}
/*----------------------------------------------------------------------------*/
void get_mtx_dimensions(Mtx *mtx, FILE *fp){
  assert(mtx != NULL && fp != NULL);

  while(fscanf(fp, "%d %d %d", &mtx->nRows, &mtx->nCols, &mtx->nonZeros)!=3){
    ignore_com(fp);
  }
}
/*----------------------------------------------------------------------------*/
int read_mtx(Mtx **matrix, char *filename){
  assert(filename != NULL);

  FILE *fp;
  fp = fopen(filename, "r");
  if(fp == NULL){
    return -1;
  }

  Mtx *mtx = (Mtx*)malloc(sizeof(Mtx));
  if(mtx == NULL){
    fclose(fp);
    return -2;
  }

  get_mtx_dimensions(mtx, fp);

  *matrix = mtx;
  fclose(fp);
  return 0;
}
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
