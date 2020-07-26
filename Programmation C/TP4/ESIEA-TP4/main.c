#include "liste.h"

int main()
{
	Ptliste L = initialiser();
	if(listevide(L))
	{
		printf("votre liste est vide\n");
	}
	else
	{
		printf("votre liste est pleine \n");
	}

	afficheordrerec (L);
	printf("\n\n");

	L=(Liste*)malloc(sizeof(Liste)); //comme L=NULL, on stocke dans L l'adresse d'une Liste

	if(L==NULL)
	{
            printf("Echec d'allocation de place memoire");
            exit(-1);
        }
	L->valeur = 11;
	L->suivant = NULL;

	printf("%5d %5d %5d %5d \n", L->valeur, (int)(L->suivant), (int)L,(int)&(L->valeur));
	printf("%5d %5d %5d %5d \n", P->valeur, (int)(P->suivant), (int)L, (int)P);
	printf("\n\n");

	afficheordrerec (L);
	printf("\n\n");
	
	L=insertentete (L, 15);
	L=insertentete (L, 17);
	L=insertentete (L, 24);
	afficheordrerec (L);
	printf("\n\n");



	L=insertqueue (L, 3);
	L=insertqueue (L, 1);
	afficheordrerec (L);
	printf("\n\n");

	L=supprentete (L);
	afficheordrerec (L);
	printf("\n\n");

	L=supprqueue (L);
	afficheordrerec (L);
	printf("\n\n");

    L=insertiondecroissant(L, 24);
    L=insertiondecroissant(L, 5);
    afficheordrerec (L);
	printf("\n\n");

	L=suppressiondecroissant(L,5);
	afficheordrerec (L);
	printf("\n\n");


}
