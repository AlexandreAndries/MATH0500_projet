/**
 * \file main.c
 *
 *
 * \brief MATH0500 - Projet
 * \author Andries Alexandre s196948
 * \author Khaliphi Abdelilah s204896
 * \version 0.1
 * \date 10/11/2021
 *
 * Ce fichier contient le programmme principal (main)
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "manager.h"
#include "array.h"
#include "sparse-matrix.h"
#include "sparse-vector.h"
/*----------------------------------------------------------------------------*/
/*---------------------------------MAIN PROGRAM-------------------------------*/
/*----------------------------------------------------------------------------*/
int main(int argc, char *argv[]){

  /*
   *
   * -o operation
   * -l matrice creuse L
   * -u matrice creuse U
   * -a vecteur creux a
   * -x vecteur dense x
   * -h help
   *
   */
  const char *optstring = ":ho:l:u:a:x:";

  unsigned short tmp = 0;
  unsigned short *operation = &tmp;
  unsigned short *toOperation = NULL;

  char *lFile = NULL;
  char *uFile = NULL;
  char *aFile = NULL;
  char *xFile = NULL;

  Mtx *L = NULL;
  // Mtx *U = NULL;
  //vector a
  //vector x

  manage_inputs(argc, argv, optstring, &lFile, &uFile, &aFile, &xFile,
                operation, &toOperation);
  //operations ... switch case sur l'option -o, différencier les input !! to do

  L = read_mtx_file(lFile); //test

  free_sparse_matrix(L); //test
  return 0;
} //fin main()
/*----------------------------------------------------------------------------*/
/*----------------------------------FIN DU MAIN-------------------------------*/
/*----------------------------------------------------------------------------*/
