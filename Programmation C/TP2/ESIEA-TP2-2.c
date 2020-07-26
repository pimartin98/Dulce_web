#include <stdio.h>
#include <stdlib.h>
/*


*/
void TPTN(double T[], int n, double *Tp, double *Tn, int *np, int *nn);

int main()
{
    
    int i,taille, taillep,taillen;
    double *T,*tabp,*tabn;
        
    printf("Veuillez entrez l'ordre du tableau\n");
    if(scanf("%d", &taille)==1)
    {
        double T[taille];
         tabp=malloc(taille * sizeof(double));
         tabn=malloc(taille * sizeof(double));
        for (i = 0; i < taille; i++) 
            {
                printf("Veuillez entrer T[%d]\n",i);
                scanf("%lf", &T[i]);
            }

        
        TPTN(T,taille,tabp,tabn,&taillep,&taillen);
        
    }
    else 
        {
        printf("erreur de saisie\n");
        exit(-1); // pour quitter le programme proprement
     }
 
  return 0;
}

void TPTN(double T[], int n, double *Tp, double *Tn, int *np, int *nn)
{
    int i;
     *np=*nn=0;
            
    for (i = 0; i < n; i++) 
        {
            
            if(T[i]>=0)
            {
                
                Tp[*np]=T[i];
                *np = *np + 1;
            }
            else
            {
                Tn[*nn]=T[i];
                *nn = *nn + 1;
                
            }
        }
 printf("Le tableau extrait des positifs est donc  [");

    for (i = 0; i < *np; i++) 
        {

            printf("%.2f ",Tp[i]);
            // on affiche 2 chiffres apres la virgule
        }

    printf("] et son nombre d'elements vaut \t%d\n",*np);
        
    printf("Le tableau extrait des negatifs est donc  [");

        for (i = 0; i < *nn; i++) 
        {

            printf("%.2f ",Tn[i]);
        }
    printf("] et son nombre d'elements vaut \t%d\n",*nn);
        
}