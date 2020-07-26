#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200


void affichedic();
void ajoutemot();
void recherchemot();
void supprmot();



int main (void)
{
	int choix ;
	do
	{

		printf("\n***********    Menu :   ***********\n");
		printf("\n 0 : Quitter");
		printf("\n 1 : Afficher le dictionnaire des synonymes ");
		printf("\n 2 : Ajouter un mot accompagne de ses synonymes ");
		printf("\n 3 : Rechercher un mot");
		printf("\n 4 : Supprimer un mot");


		printf("\n Veuillez entrer votre choix ?\n ");

		if(scanf("%d", &choix)==1)
		{

			switch (choix)
			{
                case 0 :
                    break;
				case 1 :
                    affichedic();
                    break;
				case 2 :
                    ajoutemot ();
                    break;
				case 3 :
                    recherchemot();
                    break;
				case 4 :
                    supprmot();
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


void affichedic()
{
	FILE *fich; 
	char ch[max]; 
	fich=fopen("dic.txt", "r"); //on ouvre le fichier fich en lecture

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}

	while (fgets(ch,max,fich)!=NULL) 
		// tant qu'on n'a pas atteint la fin de fichier ou qu'il n'y a pas d'erreur
	{

		printf("%s", ch); // on affiche dans la sortie standard

	}

	fclose(fich); 

}

void ajoutemot()
{
	FILE *fich; 
	char mot[max]; 
	char syn[max]; 
	int nb,i;

	fich=fopen("dic.txt", "a");
	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	} 

	printf("Tapez votre mot\t");
	scanf("%s", mot);
	printf("Entrez le nombre de synonymes que vous souhaitez entrer \t");
	scanf("%d", &nb);
	fprintf(fich, "\n%s %d", mot, nb);
	for (i=1; i<=nb; i++)
	{
		printf("Entrez le synonyme %d\t", i);
		scanf("%s", syn);
		fprintf(fich, "  %s", syn);
	}
	fprintf(fich, "\n"); // on affiche dans dic.txt d'adresse fich
	fclose(fich);	
}



/*void recherchemot()
{

	FILE *fich;
	char mot[max];
    char ch[max];
	char rech[max];
	int nbs, i;
	char syn[max];
 

	printf("\nEntrez le mot recherche\n");
	scanf("%s", rech);
	fich=fopen("dic.txt", "r"); //on ouvre le fichier fich en lecture

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}

	while (fgets(ch,max,fich)!=NULL)
	{
        sscanf(ch, "%s%d",mot,&nbs);

		if(strcmp(mot, rech) == 0)
		{
			printf("\nVotre mot recherche %s existe dans le dictionnaire\n", rech);
            
            
            for(i = 1 ; i <= nbs ; i++)
                
            {
                fscanf(fich, "%s", syn);
                printf("Synonyme : %s\n", syn);
                
            }
			
            
		}


	}

	fclose(fich);

}
 */

void recherchemot()
{
    
    FILE *fich;
    char mot[max];
    char str[max];
    char rech[max];
    char *ch;
    
    printf("\nEntrez le mot recherche\n");
    scanf("%s", rech);
    fich=fopen("dic.txt", "r"); //on ouvre le fichier fich en lecture
    
    if(fich==NULL)
    {
        printf("Le fichier en question est inexistant !\n");
        exit(-1);
    }
    
    while (fgets(str,max,fich)!=NULL)
    {
        ch = strtok(str, " ");
        /*
         
        strtok coupe la premiere chaine de caractere (1er parametre) en les séparant par les 
        caractères de la deuxième
        chaine de caractères (2eme parametre). En fait, elle remplace les caractères de 1ere chaîne par des caractères nuls
        dans la seconde chaine et renvoie les différentes sous-chaînes ainsi créées au fur et à mesure de ses appels.
        Lors des appels, la premiere chaine doit être un pointeur nul afin de signaler à strtok qu'on souhaite
        la sous-chaine qui suit. S’il n’y a plus de sous-chaine strtok retourne un pointeur nul.
        
         */
        if((strcmp(ch, rech)==0) && (ch != NULL) )
        {
            printf("\nVotre mot recherche %s existe dans le dictionnaire\n", rech);
            ch = strtok(NULL, " ");
            ch = strtok(NULL, " ");
            
            while (ch != NULL)
            {
                //ch = strtok(NULL, " ");
                
                printf("Synonyme : %s\n", ch);
                ch = strtok(NULL, " ");
            }
            
            
        }
        
    }
    
    fclose(fich);
    
}

void supprmot()
{
	FILE *fich;
	char mot[max];
	char rech[max];
	int l;



	printf("\nEntrez le mot a supprimer\n");
	scanf("%s", rech);
	fich=fopen("dic.txt", "r+"); //on ouvre le fichier fich en lecture

	l = strlen (rech);

	if(fich==NULL)
	{
		printf("Le fichier en question est inexistant !\n");
		exit(-1);
	}

	while(!feof(fich))

	{
		fscanf(fich, "%s", mot); // on lit dans le fichier fich le mot
		
		

		if(strcmp(mot, rech) == 0)
		{
			for (int i=1; i<=l; i++)
			{
			int x =ftell(fich); //ftell retourne la position actuelle du curseur
			printf("\n%d\n", x);
			fseek(fich,x-1,0);
			printf("\n%d\n", x-1);
			fprintf(fich,"\b");
			fseek(fich,x-1,0);
			}
			
		}

	}
		//fprintf(fich, "\n"); // on affiche dans dic.txt d'adresse fich

	fclose(fich);
}

