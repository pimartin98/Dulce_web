#include <stdio.h>
#include <stdlib.h>

/*

Ecrivez dans le langage C une fonction récursive de nom OCCU qui retourne 
le nombre de fois où X apparaît dans le tableau T[1 … n].

*/

int OCCU(double *T, int n, double X, int i);



int main(void)
{
	int i, n;
	double x;
	printf("Veuillez entrer votre reel recherche");
	scanf("%lf", &x);
	printf("Veuillez entrer l'odre du tableau");
	if(scanf("%d", &n)==1)
	{
		double T[n];
		// on saisit les elements du tableau

		for (i = 0; i < n; i++) 
			{
				printf("Veuillez entrer T[%d]\n",i);
				scanf("%lf", &T[i]);
			}

		printf("\n%d\n",OCCU(T,n,x,0));
	}
	else
	{
		 printf("erreur de saisie\n");
	    exit(-1); // pour quitter le programme proprement
	}


	return(0);
}

int OCCU(double *T, int n, double X, int i)
{

	if(i>=n)

		return(0);

	else if (T[i]==X)

		{ 
			return(1+OCCU(T,n,X,i+1));
		}
		
		else

			return(OCCU(T,n,X,i+1));

}

