#include <stdio.h>
#include <stdlib.h>


/*
Ecrivez dans le langage C une fonction récursive de nom DICHREC qui recherche
 par dichotomie l’élément X dans le tableau T[l ... n] dont les éléments sont
 triés en ordre croissant. DICHREC doit délivrer la valeur de la place de
 l’élément X dans le tableau T[l ... n] ; C'est -1 si X ∉ T[l ... n], 
 et c'est i ∈ {l, ... ,n} si X ∈ T[l ... n]
*/

int dichrec(int Tab[],int x, int inf, int sup);



int main (void)
{
  int i,nb,rech; 
  printf("Entrez la taille de votre tableau ");

	if(scanf("%d", &nb)==1)
	{

		int T[nb];

		for (i = 0; i < nb; i++) 
		{

			printf("Veuillez entrer T[%d]\n",i);
			scanf("%d", &T[i]);
	
		}

		printf("Entrez l'element recherche ");
		scanf("%d", &rech);

		printf("La place dans le tableau de l'element recherche %d vaut %d\n",rech,dichrec(T,rech, 0, nb-1));

	}
	
	else
	{
		printf("erreur de saisie");
		exit(-1);
	}

}
	int dichrec(int Tab[],int x, int inf, int sup)
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
