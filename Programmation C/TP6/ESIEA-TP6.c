#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200



/*

                        Gestion des livres : Structures et fichiers
 

*/


/*
 
 Il est plus que souhaitable d'utiliser fgets, suivi éventuellement de sscanf, que 
 d'utiliser fscanf.
 La raison en est que fgets retourne une chaine de caracteres et de ce fait, elle permet 
 d'utiliser les fonctions relatives au traitement des chaines de caracteres.
 */


typedef struct 
{
	
    int id;
    char titre[25];
    int nbpages;
	
}Livre;



Livre lv;


void affiche();
int test(int ident);
void ajouter();
void rechercher();
void supprimer();





int main (void)
{
    int choix ;
    do
    {

        printf("\n***********    Menu :   ***********\n");
        printf("\n 0 : Quitter");
        printf("\n 1 : Afficher les livres ");
        printf("\n 2 : Ajouter un livre ");
        printf("\n 3 : Rechercher un livre");
        printf("\n 4 : Supprimer un livre");


        printf("\n Veuillez entrer votre choix ?\n ");

        if(scanf("%d", &choix)==1)
        {

            switch (choix)
            {
                case 0 :
                    break;
                case 1 :
                    affiche();
                    break;
                case 2 :
                    ajouter();
                    break;
                case 3 :
                    rechercher();
                    break;
                case 4 :
                    supprimer();
                     break;
            }
        }
        else

        {
            printf("erreur de saisie\n");
            exit(-1); // pour quitter le programme proprement
        }

    }while (choix !=0);
    return (0);
}


void affiche()
{
    
    FILE *fich;
    char ch[max]; // ou encore *ch
    fich=fopen("bdlivre.txt", "r"); //on ouvre le fichier fich en lecture
    
    if(fich==NULL)
    {
        printf("Le fichier en question est inexistant !\n");
        exit(-1);
    }
    
    while (fgets(ch,max,fich)!=NULL) 
    // On lit une ligne de fich et on affecte les max-1 caracteres lus à la chaine de caracteres
    // ch
    // et ce, tant qu'on n'a pas atteint la fin de fichier ou qu'il n'y a pas d'erreur
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
    fich=fopen("bdlivre.txt", "r");
    if(fich==NULL)
    {
        printf("Le fichier en question est inexistant !\n");
        exit(-1);
        //return(EXIT_FAILURE);
    }
        
    while(fgets(ligne, max, fich) !=NULL)
    {
        if(sscanf(ligne, "%d%s%d",&lv.id,lv.titre,&lv.nbpages) ==3)
            
        {
            if (lv.id == ident)
            {
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
    int ident;
	FILE *fich;
	fich=fopen("bdlivre.txt", "a");
    char *p = NULL;
	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}
	printf("Tapez l'identifiant du livre a ajouter\t");
    scanf("%d", &ident);
    rewind(stdin);
    printf("%d\n",ident);
    while(test(ident)==1)
    {
        printf("l'identifiant tape %d existe deja.\n", ident);
        printf("Veuillez ressaisir l'identifiant du livre a ajouter\n");
        scanf("%d", &ident);
        rewind(stdin);
    }
    lv.id=ident;
    printf("Tapez le titre du livre à ajouter\t");
    
    //gets(lv.titre);
    fgets(lv.titre, 25,stdin);
    p = strchr( lv.titre , '\n' );
    if( p ) *p = '\0';
    //comme fgets cree un retour à la ligne, on utilise les deux lignes qui precedent pour 
    //remplacer le retour
    // a la ligne stocke dans la chaine de caracteres 1er parametre par le carctere de fin 
    //de chaine 
    //scanf((lv.titre) non car ne permet pas de prendre en compte les noms composes
    
    rewind(stdin);
    // on libere la memoire
    printf("Tapez le nombre de pages du livre à ajouter\t");
	scanf("%d", &lv.nbpages);

	fprintf(fich,"%d %s %d\n",lv.id,lv.titre,lv.nbpages);
     // on affiche dans bdlivre.txt d'adresse fich
 
	fclose(fich);	
}

void rechercher()
{
    char tt[25];
    FILE *fich;
    fich=fopen("bdlivre.txt", "r");
    if(fich==NULL)
    {
        printf("Le fichier en question est inexistant !\n");
        exit(-1);
    }
   
    printf("Tapez le titre du livre à rechercher\t");
   
     scanf("%25s", tt);
     rewind(stdin);
    while(!feof(fich))
    {
        fscanf(fich,"%d %s %d\n",&lv.id,lv.titre,&lv.nbpages);
            if (strcmp(lv.titre, tt)==0)
         {
             printf("\nLe livre recherche a pour caracteristiques :\n");
             printf("Son titre :%s\n", lv.titre);
             printf("Son identifiant :%d\n", lv.id);
             printf("Son nombre de pages :%d\n", lv.nbpages);
             
         }
         
    }
    
    fclose(fich);
    
}

void supprimer()
{
    
    FILE *fich, *fich2;
    int ident;
    printf("Tapez l'identifiant du livre a supprimer\t");
    scanf("%d", &ident);
    if(test(ident)==1)
    {
        fich=fopen("bdlivre.txt", "r"); //on ouvre le fichier fich en lecture
        fich2=fopen("temp.txt", "w"); //on ouvre le fichier fich2 en ecriture
        if((fich==NULL) || (fich2==NULL))
        {
            printf("Le fichier en question est inexistant !\n");
            exit(-1);
        }
        
        while(!feof(fich))
        {
            fscanf(fich,"%d %s %d\n",&lv.id,lv.titre,&lv.nbpages);
            if (lv.id != ident)
            {
                fprintf(fich2,"%d %s %d\n",lv.id,lv.titre,lv.nbpages);
            }
        }
        
        
        fclose(fich);
        fclose(fich2);
        remove("bdlivre.txt");
        rename("temp.txt","bdlivre.txt");
        printf("\nVotre livre d'identifiant %d a ete supprime\n", ident);
    }
    else
        printf("\nVotre livre d'identifiant %d n'existe pas dans la base de donnee\n", ident);
}



