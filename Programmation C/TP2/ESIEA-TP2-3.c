#include <stdio.h>
#include <stdlib.h>
#include <time.h>

   
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
                tab[i]= (rand()%(99))+1;
                // Si on souhaite des reels aleatoires entre 0 et 1 il faut ecrire  (double)rand()/RAND_MAX 
                //où rand() et RAND_MAX retourne des entiers
                 
            }
            printf("Les éléments du tableau sont les suivants :\n\n[ ");

            for(i=0; i<nb; i++)
            {
                printf("%d ",tab[i]);
            }
            printf("]\n");
   

            free(tab); // 3eme etape : On libere l'espace memoire qu'occupe tab
        }
    } 
    return(tab);
    
}

void tabmax_place(int T[], int n, int *max, int *place)
{
    int i;
    *max=T[0];
    *place=0;
    for(i=0;i<n;i++)
    {
        if(T[i]>*max)
        {
            *max=T[i];
            *place=i;
        }
    }
     printf("%d\n",*max);
     printf("%d\n",*place);
}
int main()

{
    int nb, pl, maximum;
    
    
	printf("Quelle est la taille de votre tableau ?");
    scanf("%d", &nb);
    int T[nb];
    int *P;

    P=chargement_aleatoire(T, nb);
   
    tabmax_place(P,nb,&maximum,&pl);
    // on peut utiliser directement chargement_aleatoire(T, nb) sans pour autant passer par P


    return (0);
}

