#include "recursive.h"


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

int NBM(char T[], int i)
{
	if(T[i]==0) 
	// c-a-d si le code ascii du carctere de fin de chaine 
	//de caracteres est 0 ou encore if(T[i]=='\0')
		return(0);
	else if (T[i]>='A' && T[i]<='Z')
		(return(1+NBM(T,i+1)));
	else
		(return(NBM(T,i+1)));

}

boolean PALINDROME (char *T, int i, int j)
{
	
	if(i>=j) // les compteurs se sont croises sans retourner de faux
	{
		printf("Mon mot est un palindrome\t");
		return(true);
	}
	else if(T[i]!=T[j])
		{
			printf("Mon mot n'est pas un palindrome\t");
			return(false);
			
		}
		else
			return(PALINDROME(T,i+1, j-1));

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


int EGYPT(int a, int b)
{
	if ((b == 0)||(a==0))
			return 0;
		else if (b%2 == 0)
				return (2* EGYPT(a,b/2));
			else
				return (EGYPT(a, b-1) + a);		

}