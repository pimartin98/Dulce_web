#include <stdio.h>
#include <stdlib.h>

                            /*
                             Les Fichiers Textes - Ecriture
                            */


            // Il existe deux types de fichiers. Les fichiers textes et les 
                             //fichiers binaires



int main (void)
{
	
    
	FILE *fich ;  //on déclare fich comme un  pointeur de type fichier
	char prenom[25];

	fich=fopen("text1.txt", "r+"); 
	//pour pouvoir manipuler un fichier, il faut l'ouvrir.
	//ici, on ouvre le fichier fich en lecture et en ecriture. fich est donc un 
	//pointeur sur text1.txt.
	//Donc, fich contient l'adresse du fichier text1.txt

	/*

	Le deuxième parametre de fopen en mode texte peut etre soit,

	- r pour uniquement pouvoir lire dans un fichier existant ;
	- w pour uniquement pouvoir ecrire dans un fichier existant ou pas ;
	- r+ pour pouvoir lire et ecrire (par dessus) dans un fichier existant ;
	- w+ pour  pouvoir lire et ecrire dans un fichier existant ou pas qui 
	    est prealablement vide de son contenu ;
	- a  pour uniquement pouvoir ecrire a la fin d'un fichier existant ou pas ;
	- a+ pour pouvoir lire et ecrire ecrire a la fin d'un fichier existant ou pas ;

	*/

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
        // ou encore return(EXIT_FAILURE);
	}

		printf("Le fichier en question existe \n");

		fputs("Mes sincères salutations ", fich); 
		// fputs permet l'ecriture d'une chaine de caracteres (string) dans le fichier fich.
		// ELLe retourne un pointeur de type char. En cas d'erreur, fputs retourne la constante EOF qui denote fin de fichier

		fputc('a', fich); 
		// fputc permet l'ecriture d'un caractere (char) dans le fichier fich. Ici, on ecrit le caractere a
		//En cas d'erreur, fputc retourne la constante EOF qui denote fin de fichier sinon, elle retourne un int qui
		// dénote le caractere qui a ete ecrit

		printf("votre prenom\n");
		scanf("%25s", prenom);

		fprintf(fich, " %s\n ",prenom);
		// fprintf permet l'ecriture d'une chaine de caracteres (3 eme parametre) formatee (2eme parametre) 
		// dans le fichier fich (1er parametre)

		fclose(fich); 
		// A la fin de traitement, on ferme le fichier en question afin de liberer la memoire
    return (0);
}
