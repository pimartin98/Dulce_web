#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void affiche(int *tab, int nb);
int *chargement_aleatoire(int *tab, int nb);
int place(int T[], int n, int X);
void insertind(int T[], int *n, int X, int ind);
int *bulle(int T[], int n);



int main()

{
    int nb, X, ind;
    
    printf("Quelle valeur entiere souhaitez-vous ajouter au tableau ?");
    scanf("%d", &X);
    printf("Quelle est la taille de votre tableau ?\n");
    scanf("%d", &nb);
    int T[nb];
    if(nb==0)
    {
        nb=1;
        T[0]=X;
        affiche(T, nb);
    }
    else
    {


        int *P;
        int *TS;

        P=chargement_aleatoire(T, nb);
        
        TS=bulle(P,nb);
        ind=place(TS,nb,X);
        printf("\nApres ordonnancement\n");
        affiche(TS, nb);
        insertind (TS, &nb, X, ind);
         printf("\nApres insertion\n");
        affiche(TS, nb);
    }
    return (0);
}

void affiche(int *tab, int nb)
{
    printf("Les éléments du tableau sont les suivants :\n[ ");

            for(int i=0; i<nb; i++)
            {
                printf("%d ",tab[i]);
            }
            printf("]\n");
}
   
int *chargement_aleatoire(int *tab, int nb)
//on retourne l'adresse du tableau tab
{
  int i;
  
  if(nb>0)
    {
        tab=malloc((nb) * sizeof(int));
       
        if (tab == NULL) //si l'allocation dynamique n'a pas fonctionne
        {
            printf("Echec d'allocation de place memoire");
            exit(-1);
        }
        else
        {
            srand(time(NULL));
            // srand(time(NULL)) initialise la fonction srand sur le temps actuel et donc, avec une valeur différente a 
            //chaque execution du programme. Elle permet grace à rand d'obtenir des nombres différents à chaque exécution du programme
            for(i=0; i<nb; i++)

            {
                tab[i]= (rand()%(70))+1;
                // Si on souhaite des reels aleatoires entre 0 et 1 il faut ecrire  (double)rand()/RAND_MAX 
                //où rand() et RAND_MAX retourne des entiers
                 
            }
            affiche(tab,nb);
   

        }
    free(tab); // 3eme etape : On libere l'espace memoire qu'occupe tab

    } 
    return(tab);
    
}

int place(int T[], int n, int X)
{
    int i;
    if(T[n-1]<=X)
    {
        return(n);
    }
    else
    {
        i=0;
        while(T[i]<=X)
        {
            i=i+1;
        }
    }
     return(i);
}


void insertind(int T[], int *n, int X, int ind)
{
    int i;
    *n=*n+1;
    i=*n;
    while(i>ind)
    {
        T[i]=T[i-1];
        i=i-1;
    }

    T[ind]=X;
   
}
/*

int *bulle(int T[], int n)
{
  int i, j, t;
  i=n-1;
  while(i>0)
  {
    for (j = 0 ; j< i; j++)
    {
       if (T[j] > T[j+1])
       {
            t= T[j];
            T[j]=T[j+1];
            T[j+1]=t; 
       }
    }
    i=i-1;
  }

  return(T);
}
*/

int *bulle(int T[], int n)
{
  int i, j, t;
  int perm;
  perm=1;
  i=n-1;
  while(perm==1)
  {
    perm=0;
    for (j = 0 ; j< i; j++)
    {
       if (T[j] > T[j+1])
       {
            t= T[j];
            T[j]=T[j+1];
            T[j+1]=t; 
            perm=1;
       }
    }
    i=i-1;
  }

  return(T);
}



