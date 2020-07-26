#include "recursive.h"

int i, n;
	double x;
	printf("Veuillez entrer votre reel recherche");
	scanf("%lf", &x);
	printf("Veuillez entrer l'odre du tableau");
	if(scanf("%d", &n)==1)
	{
		double T[n];
		// on saisit les elements du tableau

		for (i = 0; i < n; i++) 
			{
				printf("Veuillez entrer T[%d]\n",i);
				scanf("%lf", &T[i]);
			}

		printf("\n%d\n",OCCU(T,n,x,0));
	}
	else
	{
		 printf("erreur de saisie\n");
	    exit(-1); // pour quitter le programme proprement
	}
//Exo2
	char ch[100] ;
    printf("Veuillez entrer votre chaine de caracteres\n"); 
    putchar();
    fgets(ch, 50,stdin);
    //afin de remedier au pb des espaces avec le scanf, on utilise fgets
    // stdin permet de signifier que le texte saisi est lu sur l'entree standard
    // qu'est le clavier


    //exo3

   int l;
	l=strlen(ch);
	printf("%d\n",l);	
	printf("%d\n",PALINDROME(ch, 0, l-2));	
	// ici, comme ch est saisie au clavier via fgets, strlen compte egalement le caractere de fin de chaîne '\0'

    printf("%d\n",NBM(ch, 0));	

// exo4

    int i,nb,rech; 
  printf("Entrez la taille de votre tableau ");

	if(scanf("%d", &nb)==1)
	{

		int T[nb];

		for (i = 0; i < nb; i++) 
		{

			printf("Veuillez entrer T[%d]\n",i);
			scanf("%d", &T[i]);
	
		}

		printf("Entrez l'element recherche ");
		scanf("%d", &rech);

		printf("La place dans le tableau de l'element recherche %d vaut %d\n",
			rech,dichrec(T,rech, 0, nb-1));

	}
	
	else
	{
		printf("erreur de saisie");
		exit(-1);
	}

	//exo5

	int x,y;
	printf("Veuillez entrer vos deux entiers\n");
	if(scanf("%d%d", &x, &y)==2)
	{
		printf("La multiplication egyptienne de %d par %d vaut\t%d\n", x,
		 y, EGYPT(x,y));
	}
	else
	{
		printf("erreur de saisie\n");
	    exit(-1); // pour quitter le programme proprement
	}

	//exo6

	int nb;
	printf("Veuillez entrer le nombre souhaite de disques\n");
	scanf("%d", &nb);
	Hanoi(nb, 'D', 'I', 'A');
	return(0);

}
