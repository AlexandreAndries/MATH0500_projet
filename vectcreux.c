Vecteur *produit_matrice_creuse_vecteur_dense(Creuse *mat, Vecteur *v) {
   assert(mat && v);
   assert(vect_taille(mat->startCol) == vect_taille(v));

   size_t tailleVect = vect_taille(v);
   size_t debut = 0, fin = 0;
   size_t indice = 0; // indice courrant du vecteur
   size_t nbLignes = mat->nbLignes;
   double valDansVect = 0.0; // valeur courrante dans le vecteur vect
   double valDansMat = 0.0; // valeur courrante dans la matrice

   Vecteur *prod = vect_nul_de_taille(nbLignes); // Vecteur produit
   if(!prod)
      return NULL;

   // multiplie en parcourant les colonnes de la matrice
   for(size_t j = 0; j < tailleVect; ++j) {
      // Calcul des indices du sous-tableau à parcourir
      debut = vect_prend(mat->startCol, j);
      fin = (j == tailleVect - 1) ? mat->nz : vect_prend(mat->startCol, j+1);

      valDansVect = vect_prend(v, j);

      for(size_t i = debut; i < fin; ++i) {
         valDansMat = vect_prend(mat->values, i);
         indice = vect_prend(mat->rows, i);
         vect_change(prod, indice, vect_prend(prod, indice) + valDansVect * valDansMat);
      }
   }
   return prod;
}
