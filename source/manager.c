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
#include "operations.h"
#include "sparse-vector.h"

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
 * \fn void write_banner(FILE *file)
 * \brief Ecrit la première ligne ("banière") du fichier MatrixMarket en input.
 *
 * \param file, path vers le fichier où écrire la matrice. (!= NULL)
 *
 */
static void write_banner(FILE *file){
  assert(file != NULL);

  fprintf(file, "%%%%MatrixMarket matrix coordinate real general\n");
}// fin write_banner()
/*----------------------------------------------------------------------------*/
/**
 * \fn void get_dimensions_mtx(FILE *file, Mtx *mtx)
 * \brief Enregistre les données concernant les dimensions de la matrice creuse
 *        et le nombre d'éléments non-nuls qu'elle possède.
 *        Ces données sont enregistrées dans une structure Mtx non-initialisée.
 *
 * \param file, path vers le fichier contenant la matrice. (!= NULL)
 * \param mtx, structure Mtx existante mais non-initialisée. (!= NULL)
 *
 */
static void get_dimensions_mtx(FILE *file, Mtx *mtx){
  assert(mtx != NULL && file!= NULL);

  fscanf(file, "%u %*u %u", &mtx->dim, &mtx->nz);
}// fin get_dimensions_mtx()
/*----------------------------------------------------------------------------*/
/**
 * \fn void get_dimensions_vctr(FILE *file, Mtx *mtx)
 * \brief Enregistre les données concernant la longeur du vecteur creux
 *        et le nombre d'éléments non-nuls qu'il possède.
 *        Ces données sont enregistrées dans une structure vctr non-initialisé.
 *
 * \param file, path vers le fichier contenant la matrice. (!= NULL)
 * \param vctr, structure Vctr existante mais non-initialisée. (!= NULL)
 *
 */
static void get_dimensions_vctr(FILE *file, Vctr *vctr){
  assert(vctr != NULL && file!= NULL);

  fscanf(file, "%u %*u %u", &vctr->dim, &vctr->nz);
}// fin get_dimensions_vctr()
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_dimensions_mtx(FILE *file, Mtx *mtx)
 * \brief Ecrit les données concernant les dimensions de la matrice creuse
 *        et le nombre d'éléments non-nuls qu'elle possède.
 *        Ces données sont écrites dans le fichier en entrée.
 *
 * \param file, path vers le fichier où écrire la matrice. (!= NULL)
 * \param mtx, structure Mtx existante. (!= NULL)
 *
 */
static void write_dimensions_mtx(FILE *file, Mtx *mtx){
  assert(mtx != NULL && file!= NULL);

  fprintf(file, "%u %u %u\n", mtx->dim, mtx->dim, mtx->nz);
}// fin write_dimensions_mtx()
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_dimensions_vctr(FILE *file, Vctr *vctr)
 * \brief Ecrit les données concernant les dimensions du vecteur creux
 *        et le nombre d'éléments non-nuls qu'il possède.
 *        Ces données sont écrites dans le fichier en entrée.
 *
 * \param file, path vers le fichier où écrire le vecteur. (!= NULL)
 * \param vctr, structure Vctr existante. (!= NULL)
 *
 */
static void write_dimensions_vctr(FILE *file, Vctr *vctr){
  assert(vctr != NULL && file!= NULL);

  fprintf(file, "%u %u %u\n", vctr->dim, COL, vctr->nz);
}// fin write_dimensions_vctr()
/*----------------------------------------------------------------------------*/
/**
 * \fn void get_data_mtx(FILE *file, Mtx *mtx)
 * \brief Enregistre les données contenues dans un fichier MatrixMarket dans une
 *        structure de données Mtx.
 *
 *
 * \param file, path vers le fichier contenant la matrice. (!= NULL)
 * \param mtx, structure Mtx existante et initialisée. (!= NULL)
 *
 */
static void get_data_mtx(FILE *file, Mtx *mtx){
  assert(file != NULL && mtx != NULL);

  /*-------------Var Init--------------*/
  unsigned int idx = 0;                 /*-index des vecteurs iRows et xVals--*/
  unsigned int pIdx = 0;                /*-index du vecteur pCols ------------*/

  unsigned int row = INITIAL_POS;       /*-var de lecture des lignes----------*/
  unsigned int col = INITIAL_POS;       /*-var de lecture des colonnes--------*/
  double val = 0;                       /*-var de lecture des valeurs---------*/

  unsigned int comp = INITIAL_POS;      /*-comparateur de lignes--------------*/
  unsigned int pCol = INITIAL_POS;      /*-pointeur/indice stocké dans pCols--*/

  unsigned int zCase = 0;               /*-différencie le 1er nz du reste-----*/

  /*-------------Read Loop--------------*/
  /*- WATCH OUT, data in the file is initially saved in CSR (R for Row) -*/
  /*- format, which can be confusing. Because the stucture Mtx is -------*/
  /*- designed for CSC, it is necessary to save the lines of the matrix -*/
  /*- in the file as columns. This error is later corrected by ----------*/
  /*- transposing the saved data to have a correct CSC structure. -------*/
  /*- DO NOT MISINTERPRET the code below as an error! See it as a -------*/
  /*- temporary measure to read the file efficiently. -------------------*/
  while(fscanf(file, "%u %u %lf", &row, &col, &val) != EOF){
    mtx->xVals = add_at(mtx->xVals, idx, (double)val);
    mtx->iRows = add_at(mtx->iRows, idx, (double)col);

    if(!zCase){               /*-First case, first nz in the file--------*/
      mtx->pCols = add_at(mtx->pCols, pIdx, pCol);
      pIdx++;
      comp = row;
      zCase++;
    }else if(comp != row){    /*-Every other nz in the file--------------*/
      mtx->pCols = add_at(mtx->pCols, pIdx, pCol);
      pIdx++;
      comp = row;
    }

    idx++;
    pCol++;
  }
}// fin get_data_mtx()
/*----------------------------------------------------------------------------*/
/**
 * \fn static void get_data_vctr(FILE *file, Vctr *vctr)
 * \brief Enregistre les données contenues dans un fichier MatrixMarket dans une
 *        structure de données Vctr.
 *
 *
 * \param file, path vers le fichier contenant le vecteur. (!= NULL)
 * \param vctr, structure Vctr existante et initialisée. (!= NULL)
 *
 */
static void get_data_vctr(FILE *file, Vctr *vctr){
  assert(file != NULL && vctr != NULL);

  unsigned int row, idx = 0;
  double val;

  while(fscanf(file, "%u %*u %lf", &row, &val) != EOF){
    vctr->xVals = add_at(vctr->xVals, idx, (double)val);
    vctr->iRows = add_at(vctr->iRows, idx, (double)row);
    idx++;
  }
}
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_data_mtx(FILE *file, Mtx *mtx)
 * \brief Ecrit les données contenues dans une structure de données
 *        mtx dans un fichier MatrixMarket.
 *
 *
 * \param file, path vers le fichier où écrire la matrice. (!= NULL)
 * \param mtx, structure Mtx existante. (!= NULL)
 *
 */
static void write_data_mtx(FILE *file, Mtx *mtx){
  assert(file != NULL && mtx != NULL);

  unsigned int nz = get_matrix_nz_size(mtx);
  unsigned int row=1, col, idx=1;
  double val;

  for(unsigned int i = 0; i < nz; i++){

    val = mtx->xVals->vals[i];
    col = mtx->iRows->vals[i];

    if(i + SHIFT == mtx->pCols->vals[idx]){
      row++;
      idx++;
    }

    fprintf(file, "%u %u %lf\n", row, col, val);
  }
}// fin write_data_mtx()
/*----------------------------------------------------------------------------*/
/**
 * \fn void write_data_vctr(FILE *file, Vctr *vctr)
 * \brief Ecrit les données contenues dans une structure de données
 *        vctr dans un fichier MatrixMarket.
 *
 *
 * \param file, path vers le fichier où écrire le vecteur. (!= NULL)
 * \param mtx, structure Vctr existante. (!= NULL)
 *
 */
static void write_data_vctr(FILE *file, Vctr *vctr){
  assert(file != NULL && vctr != NULL);

  unsigned int row, dim;
  double val;

  dim = get_vector_dimension(vctr);
  for(unsigned int i = 0; i < dim; i++){
    val = vctr->xVals->vals[i];
    row = (unsigned int)vctr->iRows->vals[i];

    if(val != 0){
      fprintf(file, "%u %u %lf\n", row, COL, val);
    }
  }
}// fin write_data_vctr()
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
  Mtx *mtx_t = NULL;

  mtx = create_sparse_matrix();
  mtx_t = create_sparse_matrix();

  /*--------Lecture des données du fichier---------*/
  FILE *fp = fopen(filename, "r");
  skip_banner(fp);
  get_dimensions_mtx(fp, mtx);
  init_sparse_matrix(mtx);
  get_data_mtx(fp, mtx);
  fclose(fp);

  /*----------Init mtx_t sur base de mtx-----------*/
  mtx_t->dim = get_matrix_dimensions(mtx);
  mtx_t->nz = get_matrix_nz_size(mtx);
  init_sparse_matrix(mtx_t);

  /*----Conversion de mtx CSR vers CSC -> mtx_t----*/
  convert(mtx, mtx_t);

  /*------On libère mtx (CSR), devenue inutile-----*/
  free_sparse_matrix(mtx);

  return mtx_t;
}// fin read_mtx_file()
/*----------------------------------------------------------------------------*/
void write_mtx_file(Mtx *mtx, char *filename){
  assert(mtx != NULL && filename != NULL);

  Mtx *mtx_t = NULL;
  mtx_t = create_sparse_matrix();
  mtx_t->dim = get_matrix_dimensions(mtx);
  mtx_t->nz = get_matrix_nz_size(mtx);
  init_sparse_matrix(mtx_t);
  convert(mtx, mtx_t);

  FILE *fp = fopen(filename, "w");
  write_banner(fp);
  write_dimensions_mtx(fp, mtx_t);
  write_data_mtx(fp, mtx_t);
  fclose(fp);

  free_sparse_matrix(mtx_t);
}// fin write_mtx_file()
/*----------------------------------------------------------------------------*/
Vctr *read_vctr_file(char *filename){
  assert(filename != NULL);

  Vctr *vctr = NULL;
  vctr = create_sparse_vector();

  /*--------Lecture des données du fichier---------*/
  FILE *fp = fopen(filename, "r");
  skip_banner(fp);
  get_dimensions_vctr(fp, vctr);
  init_sparse_vector(vctr);
  get_data_vctr(fp, vctr);
  fclose(fp);

  return vctr;
}// fin read_vctr_file()
/*----------------------------------------------------------------------------*/
void write_vctr_file(Vctr *vctr, char *filename){
  assert(vctr != NULL && filename != NULL);

  FILE *fp = fopen(filename, "w");
  write_banner(fp);
  write_dimensions_vctr(fp, vctr);
  write_data_vctr(fp, vctr);
  fclose(fp);
}
/*----------------------------------------------------------------------------*/
void manage_operations(unsigned int op, Mtx *L, Mtx *U, Vctr *a, Vctr *x){
  assert(op == 1 || op == 2 || op == 3);

  Vctr *outputDense = NULL;
  char otptDenseFile[] = "dense.result.mtx" ;

  Vctr *outputSparse = NULL;
  char otptSparseFile[] = "sparse.result.mtx" ;

  switch(op){
    case 1 :
      assert(L != NULL && a != NULL && x != NULL);
      printf("Résolution système triangulaire inférieur - dense\n");
      outputDense = solve_dense_system(L, x);
      write_vctr_file(outputDense, otptDenseFile);
      free_sparse_vector(outputDense);

      printf("Résolution système triangulaire inférieur - creux\n");
      outputSparse = solve_sparse_system(L, a);
      write_vctr_file(outputDense, otptSparseFile);
      free_sparse_vector(outputSparse);

      break;

    default :
      break;
  }
}
/*----------------------------------------------------------------------------*/
/*--------------------------------FIN DU MODULE-------------------------------*/
/*----------------------------------------------------------------------------*/
