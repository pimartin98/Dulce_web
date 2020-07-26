#include <stdio.h>
#include <stdlib.h>
#include <string.h>




				/*Pour eviter des erreurs de compilation face à une declaration multiple 
				(par exemple, face au cas où xxx.h serait dans plusieurs modules.c
				du meme projet), il convient d'operer comme suit.
				*/




#ifndef RECURSIVE_H_INCLUDED
#define RECURSIVE_H_INCLUDED
		
		typedef enum 
		{
			
			true=1,
			false=0,
			
		}boolean;




		int OCCU(double *T, int n, double X, int i);
		int NBM(char T[], int i);
		boolean PALINDROME (char *T, int i, int j);
		int dichrec(int Tab[],int x, int inf, int sup);
		int EGYPT(int a, int b);
		void Deplacer(char x, char y);
		void Hanoi (int n, char A, char B, char C );


#endif



