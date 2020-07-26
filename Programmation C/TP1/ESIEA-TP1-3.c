#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

Ecrivez une fonction booléenne récursive de nom PALINDROME qui 
permette de savoir si un mot donné est un mot palindrome.

*/

typedef enum 
{
	
	true=1,
	false=0,
	
}boolean;


boolean PALINDROME (char *T, int i, int j);

int main(void)
 {
 

    char ch[100] ; int l;
    printf("Veuillez entrer votre chaine de caracteres\n"); 
	fgets(ch, 45,stdin); //fgets lits egalement le caractere de fin de chaîne '\0'
	l=strlen(ch);
	printf("%d\n",l);	
	printf("%d\n",PALINDROME(ch, 0, l-2));	
	// ici, comme ch est saisie au clavier via fgets, strlen compte egalement le caractere de fin de chaîne '\0'
  return 0;
	
	 
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
 
