#include <stdio.h>
#define nz 7 //just to define element != 0
#define size 5 // thz size of our A.p



int main(){

  //initialisation of our matrix L you can find this exemple on cours slides

  int ap[size] ={0,2,3,5,6};
  int ai[nz]   ={0,2,1,2,4,3,4};
  int ax[nz]   ={1,1,2,1,1,1,2};
// our b vector
  int bp[1]    = {0};
  int bi[size] = {0,1,2,3,4};
  float bx[size] = {1,2,3,4,5};

/*first of all we creat our victor in our case we use your fonctions to creat an empty one
then we put b values in it
*/

//this is my x vector i don't know why i caal it v (not important)
  int vi[size];
  float vx[size];

  for(int i=0 ;i<size ;i++){
    vi[i]=bi[i];
    vx[i]=bx[i];
  }


  int t = 0;
  float nb_column;

  for(int i=0 ; i<size ; i++){

    //vx[i] is our pivot

    vx[i]= vx[i]/ax[ap[i]];

    //this one we use it to know how many numbers we have in our column so we use A.p
    nb_column = ap[i+1]-ap[i];

    for(int j = t+1 ; j < nb_column+t ; j++){
      //i can't comment this one if you didn't get it i'll givee an exemple on discord
      vx[ai[j]] -= (ax[j]*vx[i]);

    }
    //le t c'est la valeur de j dans chaque iteration de boucle pour savoir ou on est dans le A.i comme ça on sait qu'on va commence de la
    t +=nb_column;

  }

for(int i = 0 ; i < size ; i++){
  printf("%.2f\n", vx[i]);
}


  return 0;
}
