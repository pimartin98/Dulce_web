#include <stdio.h>
#include <stdlib.h>

                            /*
                             Les Fichiers Textes- Lecture par acces direct
                            */


int main ()
{
	    
	FILE *fich ;  
	int car;
	fich=fopen("text1.txt", "r"); 
	//on ouvre le fichier fich en lecture

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}

	fseek(fich, 0, SEEK_END);
	// on positionne le curseur a la fin du fichier fich
	// fseek(fich, 0, SEEK_SET) permet de se positionner au début du fichier
	// fseek(fich, 0, SEEK_CUR) permet de se positionner a partir de la position courante
    
    printf("\nLe nombre de caracteres de votre fichier vaut %ld\n",ftell(fich));
    //ftell qui est de type long retourne la position actuelle du curseur et donc, ici, le nombre de caracteres du fichier

	fclose(fich);		
	
	

	return (0);
}
