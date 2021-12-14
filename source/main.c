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

  unsigned short op = 0;
  unsigned short *operation = &op;
  unsigned short *toOperation = NULL;

  char *lFile = NULL;
  char *uFile = NULL;
  char *aFile = NULL;
  char *xFile = NULL;

  Mtx *L = NULL;
  Mtx *U = NULL;
  Vctr *A = NULL;
  Vctr *X = NULL;

  manage_inputs(argc, argv, optstring, &lFile, &uFile, &aFile, &xFile,
                operation, &toOperation);

  if(lFile != NULL){L = read_mtx_file(lFile);}
  if(uFile != NULL){U = read_mtx_file(uFile);}
  if(aFile != NULL){A = read_vctr_file(aFile); set_vector_density(A, False);}
  if(xFile != NULL){X = read_vctr_file(xFile); set_vector_density(X, True);}

  manage_operations(op, L, U, A, X); //not finished

  if(lFile != NULL){free_sparse_matrix(L);}
  if(uFile != NULL){free_sparse_matrix(U);}
  if(aFile != NULL){free_sparse_vector(A);}
  if(xFile != NULL){free_sparse_vector(X);}
  return 0;
} //fin main()
/*----------------------------------------------------------------------------*/
/*----------------------------------FIN DU MAIN-------------------------------*/
/*----------------------------------------------------------------------------*/
