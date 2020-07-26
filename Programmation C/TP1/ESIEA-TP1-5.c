#include <stdio.h>
#include <stdlib.h>


/*

  La multiplication Egyptienne de deux entiers naturels a et b est fondée sur les relations suivantes :
•	Si b = 0, alors a * b = 0
•	Si b est impair, alors a * b = a * (b – 1) + a 
•	Si b est pair, alors a * b = 2 * a * (b / 2) 
Ecrivez dans le langage C la Fonction Récursive correspondante.


*/

int EGYPT(int a, int b);



int main (void)
{
	int x,y;
	printf("Veuillez entrer vos deux entiers\n");
	if(scanf("%d%d", &x, &y)==2)
	{
		printf("La multiplication egyptienne de %d par %d vaut\t%d\n", x, y, EGYPT(x,y));
	}
	else
	{
		printf("erreur de saisie\n");
	    exit(-1); // pour quitter le programme proprement
	}

	return(0);
}


int EGYPT(int a, int b)
{
	if ((b == 0)||(a==0))
			return 0;
		else if (b%2 == 0)
				return (2* EGYPT(a,b/2));
			else
				return (EGYPT(a, b-1) + a);		

}