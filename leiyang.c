MATRICE *multiplication(MATRICE *A, MATRICE *B)
{
    if(A == NULL || B == NULL)
    {
        printf("Erreur de pointeur ! avec les matrices A et B \n");
        return NULL;
    }
    if(A->nb_colonne != B->nb_ligne)
    {
        printf("Mupltiplication impossible \n");
        return NULL;
    }
    MATRICE *C;
    C = malloc(sizeof(MATRICE));
    C->nb_ligne = A->nb_ligne;
    C->nb_colonne = B->nb_colonne;
    C->colonne = malloc((C->nb_colonne+1)*sizeof(int));
    C->colonne[0] = 0;
    int nz = 0;
    int count2 = 0;
    int z = 0;
    int *w = malloc(C->nb_ligne*sizeof(int));
    float *x = malloc(C->nb_ligne*sizeof(float));
    for(int i = 0; i < C->nb_ligne ; i++)
    {
        w[i] = 0;
        x[i] = 0;
    }
    for(int i=0; i < B->nb_colonne;i++)
    {
        for(int j = B->colonne[i]; j < B->colonne[i+1];j++)
        {
            int ligne_postion = B->ligne[j];
            printf(" ligne_position %d \n", ligne_postion);
            for(int k = A->colonne[ligne_postion]; k < A->colonne[ligne_postion + 1]; k++)
            {
                printf("Valeur k %d\n", k);
                 z = A->ligne[k];
                printf("Valeur z %d \n", z);
                if(w[z] == 0)
                {
                    w[z] = 1;
                    nz++;
                    count2++;
                }
            }
        }
        C->colonne[i+1] = count2 + C->colonne[i];
        count2 = 0;
        for(int ii = 0; ii < C->nb_ligne ; ii++)
        {
            if(w[ii] != 0)
                w[ii] = 0;
        }
    }
    printf("%d \n", C->nb_colonne);
    for(int i= 0;i < C->nb_colonne;i++)
        printf("Valeur colonne %d\n", C->colonne[i]);
    C->nz = nz;
    printf("Valeur nz %d\n", nz);
    int comptage = 0;
    C->ligne = malloc(C->nz*sizeof(int));
    C->valeur = malloc(C->nz*sizeof(float));


    //--------------------------------------------------------------------------




    for(int i = 0; i < B->nb_colonne;i++)
    {
        for(int j = B->colonne[i]; j<B->colonne[i+1];j++)
        {
            float valeur = B->valeur[j];
            printf(" Valeur de B->valeur %f\n", valeur);
            int ligne_position = B->ligne[j];
            for(int k = A->colonne[ligne_position];k < A->colonne[ligne_position + 1]; k++)
            {
                z = A->ligne[k];
                float valeur2 = A->valeur[k];
                printf(" Valeur de A->valeur %f\n", valeur2);
                x[z] += valeur * valeur2;
                    printf("Valeur x  %f==%f \n", x[z],valeur * valeur2);

            }
        }
        for(int a = 0; a < C->nb_ligne;a++)
        {
            if(x[a] != 0)
            {
                C->ligne[comptage] = a;
                C->valeur[comptage] = x[a];
                comptage++;
            }
        }
        for(int a = 0; a < C-> nb_ligne; a++)
        {
            if( x[a] != 0)
                x[a] = 0;
        }

    }
    for(int i = 0 ; i < C->nz ;i++)
    {
        printf("Valeur %f Ligne %d \n", C->valeur[i],C->ligne[i]);
    }
    return C;
}
