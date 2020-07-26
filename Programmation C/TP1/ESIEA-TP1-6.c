#include <stdio.h>
#include <stdlib.h>


/*

  Reprendre l’exercice face à un tableau dynamique de dimension 2 
  qui est trié dans l’ordre croissant.

*/

void Deplacer(char x, char y);
void Hanoi (int n, char A, char B, char C );

int main (void)
{
	int nb;
	printf("Veuillez entrer le nombre souhaite de disques\n");
	scanf("%d", &nb);
	Hanoi(nb, 'D', 'I', 'A');
	return(0);
}


void Deplacer(char x, char y)
{
	printf("Le deplacement se fait de %c vers %c\n", x, y);

}


void Hanoi (int n, char A, char B, char C)
{
	if (n > 0)
			{
			Hanoi(n -1, A, C, B);
			Deplacer(A,C);
			Hanoi(n -1, B, A, C);
			printf("\n");
			}
}