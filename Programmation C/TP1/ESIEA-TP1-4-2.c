#include <stdio.h>
#include <stdlib.h>


/*

  Reprendre l’exercice face à un tableau dynamique de dimension 2 
  qui est trié dans l’ordre croissant.

*/

int dichrec(int *Tab,int x, int inf, int sup);



int main (void)
{

	int nl,nc,i,j,rech;

    int **tab; 
    // 1ere etape : On definit un double pointeur.

    printf("Quelle est le nombre de lignes et de colonnes de votre tableau ?\n");

    if(scanf("%d%d", &nl, &nc)==2)
        {
            tab=malloc(nl * sizeof(int*));
            // 2eme etape : On alloue de la memoire aux lignes du tableau
            //malloc retourne une adresse qui est affectee a tab
             printf ("allocation des ignes du tableau à l'adresse %p\n", tab) ;
            
            if (tab == NULL) //si l'allocation dynamique n'a pas fonctionnee
            {
                printf("Echec d'allocation de place memoire");
                exit(-1);
            }
            else
            {
            	for(i=0; i<nl; i++)
    	        {
                    tab[i]=malloc(nc * sizeof(int));
                    // 3eme etape : pour chaque ligne, on alloue de la memoire à ses colonnes

    				for(j=0; j<nc; j++)
                    {
                    	printf("Veuillez entrer tab[%d][%d]\n",i,j);
						scanf("%d", &tab[i][j]);
                        printf("%3d ",tab[i][j]);
                    }
                    printf("\n");
    	        }
    	        printf("Entrez l'element recherche ");
				scanf("%d", &rech);

				for(i=0; i<nl; i++)
    	        {
					printf("La place dans la ligne %d du tableau de l'element recherche %d vaut %d\n",i, rech,dichrec(tab[i],rech, 0, nc-1));

    	        }

    	        for(i=0; i<nl; i++)
                {
                    free(tab[i]); // 4eme etape : On libere l'espace memoire qu'occupe chaque ligne du tableau
                }

            	free(tab); // 5eme etape : On libere l'espace memoire qu'occupe tab
            }
        }

    else 
        {
        printf("erreur de saisie\n");
        exit(-1); // pour quitter le programme proprement
        }

    return (0);
}


	int dichrec(int *Tab,int x, int inf, int sup)
	{
		int m;
		if(inf<sup)
		{
			m=(inf+sup)/2;
			if(x<=Tab[m])
			{
				return(dichrec(Tab,x,inf,m));
			}
			else
				return(dichrec(Tab,x,m+1,sup));		}
		if(x==Tab[inf])
		{
			return(inf);
		}
		else
		{
			return(-1);
		}

	}
