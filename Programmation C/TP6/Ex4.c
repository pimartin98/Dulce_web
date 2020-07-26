#include <stdio.h>
#include <stdlib.h>
#define max 100
// on recherche max dans tout le fichier et on remplace max par la valeur 100 et ce, contrairement à const, sans occupation de la place memoire
// const int max=100 ; remplace max par la valeur 100, mais occupe de la memoire



                            /*
                             Les Fichiers Textes- Lecture d'une chaine de caracteres
                            */


/*

Pour lire une chaines de caracteres, on utilise la fonction fgets dont le prototype est le suivant

             char* fgets(char *chaine,int nbcaracteresalire,FILE *pointeursurfichier)

fgets lit une ligne de caracteres et ce, tant que le nombre de caracteres lus est inferieur ou egal à 
nbcaracteresalire - 1.

fgets affecte la ligne lue à la chaine passee en parametre et à laquelle elle ajoute le caractere de 
fin de chaine '\0'

En cas d'erreur ou de fin de fichier, fgets retourne NULL

 */






                            // on va copier un fichier dans un autre

int main (void)
{
    
    FILE *fich, *fich2;
	char ch[max]; // ou encore *ch
	int x;
	fich=fopen("text1.txt", "r"); //on ouvre le fichier fich en lecture
	fich2=fopen("text2.txt", "w"); //on ouvre le fichier fich2 en ecriture

	if((fich==NULL) || (fich2==NULL))
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}
	
	while (fgets(ch,max,fich)!=NULL) 
	// On lit une ligne de fich et on affecte les max-1 caracteres lus à la chaine de caracteres ch
    // et ce, tant qu'on n'a pas atteint la fin de fichier ou qu'il n'y a pas d'erreur
	{

		fprintf(fich2,"%s", ch);// on affiche ch dans text2.txt d'adresse fich2
        
		printf("%s", ch); // on affiche ch dans la sortie standard

		x =ftell(fich); //ftell retourne la position actuelle du curseur
		printf("\n%d\n", x);
        

	}


	fclose(fich); // A la fin de traitement, on ferme le fichier en question afin de liberer la memoire
	fclose(fich2);
    
	return (0);

}
