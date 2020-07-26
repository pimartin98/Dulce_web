#include "liste.h"
							

Ptliste initialiser(void)
{
	return(NULL);
}


boolean listevide(Ptliste  L)
{
	if(L==NULL)
	{
		return(true);
	}
	
		return(false);
}

void afficheordrerec (Ptliste L)
{
	if(L==NULL)
	{
		printf("Il n'y a rien à afficher\n");
	}
	else
	{
		printf("%5d\n", L->valeur);
		
		afficheordrerec ((Ptliste)L->suivant);
	}
}


Ptliste insertentete (Ptliste L, int X)
{
	

	Ptliste P;

	P=(Liste*)malloc(sizeof(Liste)); // on stocke dans P l'adresse d'une Liste

	if(P==NULL)

		{
            printf("Echec d'allocation de place memoire");
            exit(-1);
        }

	P->valeur = X;

	P->suivant = L;

	return(P);
	
}


Ptliste insertqueue (Ptliste L, int X)
{

	Ptliste P, Q, tete;

	P=(Liste*)malloc(sizeof(Liste)); // on stocke dans P l'adresse d'une Liste

	if(P==NULL)

		{
            printf("Echec d'allocation de place memoire");
            exit(-1);
        }

	P->valeur = X;

	P->suivant = NULL;

	if(L==NULL)

		{
            return(P);
        }
    
     else

	     {
	     	tete=L; // tete sert a preserver les elements deja presents dans L
	     	Q = L;
	     	
	     	while(((Ptliste)Q->suivant) != NULL)
	     	{
	     		Q = ((Ptliste)Q->suivant);
	     	}

	     	Q->suivant = P;
	     }
	 return(tete);


}


Ptliste supprentete (Ptliste L)
{

	Ptliste P;
	P=L;
	if(L!=NULL)
	{
		P=L->suivant;
		free(L);
	}
	return(P);

	
}


Ptliste supprqueue (Ptliste L)
{
	Ptliste courant, successeur, Ltemp;
	if(L==NULL)

		{
            return(NULL);
        }
    
     else if(L->suivant==NULL)
	    {
	     	free(L);
	     	return(NULL);
	    }
     	else
     	{
     		Ltemp=L;
     		courant=Ltemp;
     		successeur=Ltemp;
			while (successeur->suivant !=NULL)
			{ 
				courant=successeur;
				successeur=successeur->suivant;
			}
				courant->suivant=NULL;
				free(successeur);
				 return(Ltemp);

     	}
}

Ptliste insertiondecroissant (Ptliste L, int X)
{
	Ptliste P;
	P=L;

	if((L==NULL) || (X > L->valeur))
	{
		return(insertentete(L, X));
	}
	else if (X == L->valeur)
	{
		return(L); //une liste ne peut comporter qu’une seule occurrence d’un élément donné
	}
	     else
	     {
			P->suivant=insertiondecroissant(((Ptliste)P->suivant), X);
	     }
	return(P);

}


Ptliste insertioncroissant (Ptliste L, int X)
{
	Ptliste P;
	P=L;

	if((L==NULL) || (X < L->valeur))
	{
		return(insertentete(L, X));
	}
	else if (X == L->valeur)
	{
		return(L); //une liste ne peut comporter qu’une seule occurrence d’un élément donné
	}
	     else
	     {
			P->suivant= insertioncroissant(((Ptliste)P->suivant), X);
	     }
	return(P);
}

Ptliste suppressiondecroissant (Ptliste L, int X)
{
	Ptliste P;
	P=L;

	if((L==NULL) || (X > L->valeur))
	{
		return(L);
	}
	else if (X == L->valeur)
	{
		return(supprentete(L)); 
	}
		else
	     {
			P->suivant=suppressiondecroissant(((Ptliste)L->suivant), X);
	     }
	return(P);
}

Ptliste suppressioncroissant (Ptliste L, int X)
{
	Ptliste P;
	P=L;

	if((L==NULL) || (X < L->valeur))
	{
		return(L);
	}
	else if (X == L->valeur)
	{
		return(supprentete(L)); 
	}
		else
	     {
			P->suivant=suppressioncroissant(((Ptliste)L->suivant), X);
	     }
	return(P);
}


