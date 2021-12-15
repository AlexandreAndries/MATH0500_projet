# MATH0500_projet
Projet d'algorithmique numérique

Auteurs : Alexandre Andries & Abdelilah Khaliphi
Date de dernière modification : 15/12/2021
Version : 0.1

Utiliser la commande "make" pour compiler le code dans le répertoire contenant
le Makefile.

Une fois compilé, lancer le programme avec la commande ./mtxSolver [...]
dans ce même répertoire.

Lancer le programme avec l'option '-h' pour obtenir de l'aide.



Questions du projet:
--------------------------------------------------------------------------------

Pour résoudre la question 2 du projet :
"Résoudre un système triangulaire creux avec respectivement un membre de droite
dense, et un membre de droite creux"

Utiliser la commande:

"./mtxSolver -o 1 -l [path vers L.mtx] -a [path vers a.mtx] -x [path vers x.mtx]"

--------------------------------------------------------------------------------

Pour résoudre la question 3 du projet :
"Calculer le produit de deux matrices creuses"

Utiliser la commande:

"./mtxSolver -o 2 -l [path vers L.mtx] -u [path vers u.mtx]"

--------------------------------------------------------------------------------

Pour résoudre la question 4 du projet :
"Calculer le produit de deux matrices creuses"

Utiliser la commande:

"./mtxSolver -o 3 -l [path vers L.mtx] -u [path vers u.mtx] -a [path vers a.mtx] -x [path vers x.mtx]"

--------------------------------------------------------------------------------

ATTENTION: le code fonctionne sans erreurs pour la résolution de systèmes
triangulaires (membres de droite dense ET creux). CEPENDANT, le produit L*U
est instable et provoque parfois des "segmentation fault". Nous n'avons pas
pu résoudre ce problème par manque de temps.

L'erreur se situe au niveau de la résolutions des produits de la dernière
colonne de C. Le reste des solutions est correct, et sur des petits exemples
vérifiables manuellement, la fonction de résolution donne des résultats corrects
à la dernière colonne près. Nous vous prions d'excuser cette erreur.
