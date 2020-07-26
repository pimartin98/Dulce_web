#include <stdio.h>
#include <stdlib.h>
#define max 100


/*
1- Ecrivez une programme recursif qui affiche le contenu d'un fichier texte caractere par caractere

2- Ecrivez une programme recursif qui affiche le contenu d'un fichier texte caractere par caractere,
et ce, en commencant par la fin du fichier

3- Ecrivez une programme recursif qui affiche le contenu d'un fichier texte ligne par ligne

4- Ecrivez une programme recursif qui affiche le contenu d'un fichier texte ligne par ligne
et ce, en commencant par la fin du fichier

*/

void lirecroissant(FILE *f)
{
	char car;
	if((car=fgetc(f)) !=EOF)
	{
		printf("%c", car);
		lirecroissant(f);
	}

}
void liredecroissant(FILE *f)
{
	char car;
	if((car=fgetc(f)) !=EOF)
	{

		liredecroissant(f);
		printf("%c", car);
	}

}

void lirelignecroissant(FILE *f)
{
	char ch[max];
	if (fgets(ch,max,f)!=NULL)
	{

		printf("%s",ch);
		lirelignecroissant(f);
	}
}
void lirelignedecroissant(FILE *f)
{
	char ch[max];
	if (fgets(ch,max,f)!=NULL)
	{
		lirelignedecroissant(f);
		printf("%s\n",ch);
	}
}
int main ()
{
	FILE *fich ;
	fich= fopen ("text1.txt", "r");
	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}

	printf("\nLecture dans l'ordre croissant\n");
	lirecroissant(fich);
	fseek(fich, 0, SEEK_SET);
    // on positionne le curseur au début du fichier fich

	// fseek(fich, 0, SEEK_END) permet de se positionner à la fin du fichier

	printf("\nLecture dans l'ordre decroissant\n");
	liredecroissant(fich);
	rewind(fich);
	// on positionne le curseur au début du fichier fich. Donc rewind(fich) est pareille que
	//fseek(fich, 0, SEEK_SET)


	printf("\nLecture dans l'ordre croissant\n");
	lirelignecroissant(fich);
	fseek(fich, 0, SEEK_SET);

	printf("\nLecture dans l'ordre decroissant\n");
	lirelignedecroissant(fich);
	fclose(fich);


	return (0);

}
