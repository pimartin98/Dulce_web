#include <stdio.h>
#include <stdlib.h>


/*

Ecrivez dans le langage C une fonction récursive de nom NBM qui retourne
 le nombre de majuscules dans une chaine de caractères.

*/

int NBM(char T[], int i); // ou encore *T

int main(void)
{
	char ch[100] ;
    printf("Veuillez entrer votre chaine de caracteres\n"); 
    fgets(ch, 50,stdin);
    //afin de remedier au pb des espaces avec le scanf, on utilise fgets
    // stdin permet de signifier que le texte saisi est lu sur l'entree standard
    // qu'est le clavier

    printf("%d\n",NBM(ch, 0));	
	return(0);
}


int NBM(char T[], int i)
{
	if(T[i]==0) // c-a-d si le code ascii du carctere de fin de chaine de caracteres est 0 ou encore if(T[i]=='\0')
	{
		return(0);
	}
	else if(T[i]>='A' && T[i]<='Z')
		{
			return(1+NBM(T, i+1));
		}
		else
		{
			return(NBM(T, i+1));
		}

}