#include <stdio.h>
#include <string.h>


/*

Gestion des élèves

*/



typedef struct 
{
	char nom[25];
	char prenom[25];
    float moyenne;
	
}Eleve;

#define MAX 2000
// on recherche max dans tout le fichier et on remplace max par la valeur 2000 et ce,
// contrairement à const, sans occupation de la place memoire
// const int MAX=2000; remplace max par la valeur 2000, mais occupe de la memoire

static int i; // on definit i comme une variable globale

void afficher(Eleve *T, int nbel);
void saisir(Eleve *T, int *nb);
void ajouter(Eleve *T, int *nb);
int recherche(Eleve *T, int nb, int i, char nm[20]);
void supprime(Eleve *T, int *nb,double moy);



int main(void)
{
    int choix;
	Eleve tab[MAX]; 
	int nbel;
	int *p;
	p=&nbel; // ainsi à travers la valeur du pointeur p, *p, on peut changer la valeur de la variable nbel
	double moy;
    
    afficher(tab,nbel);
    printf("le nombre d'eleves vaut %d\n\n", nbel);
    printf("________ La saisie de votre tableau d'eleves ________\n");
    saisir(tab, p);
	do
	{
		printf("_____ Mon Menu ________");
		printf("\n\n0- Pour Quitter\n");
		printf("1- Pour Afficher\n");
        printf("2- Pour Ajouter\n");
        printf("3- Pour Recherche\n");
        printf("4- Pour Supprimer\n\n");

		do
		{
			printf("Entrez votre choix\n");
			scanf("%d", &choix);
			if(choix >4)
			{
				printf("votre choix est incorrect");
			}
		}
		while(choix >4);

		switch(choix)
		{
			case 0:
			
			break;

			case 1:
			{
				afficher(tab,nbel);
                printf("le nombre vaut %d\n\n", nbel);

			}
			break;
                
            case 2:
            {
                ajouter(tab, p);
            }
                break;

            
            case 3:
            {
            	char nm[20];
  				printf("Donnez le nom de l'eleve\n");
        		scanf("%s",nm);
                //printf("%s\n\n",recherche(tab, nbel, 0, moy));
                printf("%d\n\n",recherche(tab, nbel, 0, nm));

            }
                break;

            case 4:
            {
            	double moy;
  				printf("Donnez la moyenne\n");
        		scanf("%lf",&moy);
                supprime(tab,p,moy);

            }
                break;

		}
	}
	while(choix !=0);

}

void afficher(Eleve *T, int nbel)
{
	for(i=0;i<nbel; i++)
	{
		printf("L'eleve %s de prenom %s a pour moyenne %f\n\n", T[i].nom,T[i].prenom, T[i].moyenne);
	}
}

void saisir(Eleve *T, int *nb)
{
	printf("Donnez le nombre d'eleves a saisir\n");
	scanf("%d", nb);
	for(i=0; i<*nb; i++)
	{
		printf("Donnez le nom de l'eleve %d\n",i+1);
		scanf("%s", T[i].nom);
		printf("Son prenom\n");
		scanf("%s", T[i].prenom);
		printf("Sa moyenne\n");
		scanf("%f", &T[i].moyenne);

	}
    
}

void ajouter(Eleve *T, int *nb)
{
  
        printf("Donnez le nom de l'eleve %d\n",(*nb)+1);
        scanf("%s", T[*nb].nom);
        printf("Son prenom\n");
        scanf("%s", T[*nb].prenom);
        printf("Sa moyenne\n");
        scanf("%f", &T[*nb].moyenne);
        *nb=(*nb)+1;
    
    
}


int recherche(Eleve *T, int nb, int i, char nm[20])
{
	
	if(i>nb)
		return(0);
	else
		if (strcmp(T[i].nom, nm)==0)
		{
			return(1);

		}
		else 
		{
			return(recherche(T,nb,i+1, nm));
		}    
   
}

void supprime(Eleve *T, int *nb,double moy)
{
	int j;

	
	for (i=0; i<*nb; i++)
	{
		if (T[i].moyenne != moy)
		{
			T[j]=T[i];
			j=j+1;
		}
	}
	if(j==*nb)
	{
		printf("Cette moyenne est inexistante\n\n");
	}
	else
	{
		*nb=j;
		printf("Le tableau des élèves ne comporte plus que %d eleves\n\n", *nb);

	}
   
}

