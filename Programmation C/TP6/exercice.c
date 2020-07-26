#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200

/* Gestion des livres : Structures et fichiers
 *
 *il est plus que souhaitable d'utiliser fgets, suivi eventuellment de sscanf, que d'utiliser fscanf
 La raison en est que fgets retourne une chaine de caracteres et de ce fait, elle permet d utiliser les fonctions relatives au traitement des chaines de caracteres
 * */

typedef struct
{
	int id; 
	char titre[25];
	int nbpages; 
}Livre; 

livre lv; 


void affiche();
int test (int ident);
void ajouter();
void rechercher();
void supprimer();

int main()
{
	int choix; 
	do 
	{
		printf("\n *******Menu*********\n");
		pintf("\n 0 : quitter\n");
		printf("\n 1 : Afficher les livres\n");
		printf("\n 2\n");
	       	printf("\n 3\n");
		printf("\n4\n");
		printf(Veuillez entrez votre choix);

	}	
	if(scanf("%d",&choix)==1)
	{
		switch(choix)
		{
			case 0 : break;
			case 1 : affiche; break;
			case 2 : ajouter();  break;
			case 3 : rechercher(); break;
			case 4 : supprimer();  break;

		}
	}
	else
	{
		printf("erreur de saisie ");
	}
}

void affiche()
{
	FILE *fich; 
	char ch[max];// ou encore *ch
	fich = fopen("bdlivre.txt", "r"); // on ouvre le fichier fich en lecture 

	if(fich == NULL )
	{
		printf("le fichier en question est inexistant");
		exit(-1);

	}
	while(fgets(ch,max,fich)!= NULL)
	// On lit une ligne de fich et on affecte les max-1 carcteres lus à la chaine de caracteres
	// ch
	// et ce, trant qu'on na pas atteint la fin de fichier ou qu il  n y a pas d erreur
	{
		printf("%s", ch); // on affiche ch dans la sortie standard 
	}	
	fclose(fich);
	// A la fin de traitement, on ferme le fichier en question afin de liberer la memoire
}

int test(int ident)
{
	char ligne[max];
	FILE *fich;
	fich = fopen("bdlivre.txt", "r");
	if(fich == NULL)
	{
		printf("le fichier en question est inexistant !\n");
		exit(-1);
		// return(EXIT_FAILURE)

	}
	while(fgets(ligne, max, fich) != NULL)
	{
		if(sscanf(ligne, "%d%s%d",&lv.id, lv.titre, &lv.nbpages)==3)
		{
			if(lv, id==ident);
			return(1);

		}
	}
	printf("%s\n", lv.titre);
}

fclose(fich);
return(0);
}

void ajouter()
{

}

