#include <stdio.h>
#include <stdlib.h>

                            /*
                             Les Fichiers Textes- Lecture séquentielle de caracteres
                            */


int main ()
{
	    
	FILE *fich ;  
	int car;
	int nbc;
	nbc=0;
	fich=fopen("text1.txt", "r"); 
	//on ouvre le fichier fich en lecture

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}
		

	while((car=fgetc(fich)) !=EOF)
	// fgetc permet la lecture d'un caractere dans le fichier fich. Elle retourne un int qui
	// dénote le caractere qui a ete lu. En cas d'erreur ou de fin de fichier, elle retourne la constante EOF
	// A chaque appel de fgetc, car passe au caractere suivant
	{
		if(car =='\n')
		{
			printf("\nje suis sur le caractere retour à la ligne. Donc, je ne vais pas le compter\n");
			
		}
		else
		{
			printf("%c",car);
			nbc=nbc+1;
		}
		
	}
	printf("\nLe nombre de caracteres de votre fichier vaut %d\n",nbc-1);

	fclose(fich); // A la fin de traitement, on ferme le fichier en question afin de liberer la memoire

	return (0);
}
