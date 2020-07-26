#include <stdio.h>
#include <stdlib.h>


// Duree d'un vol ne depassant pas une journee

void dureevol(int hd, int md, int sd, int *ha, int *ma, int *sa, int *h, int *m, int *s);

int main()
{
    int x,y,z,a,b,c;
    int u,v,w; // on declare les variable resultat
    printf("Entrez votre horaire de depart\n");
    scanf("%d%d%d", &x,&y,&z);
    printf("Entrez votre horaire d'arrivee\n");
    scanf("%d%d%d", &a,&b,&c);
    dureevol(x,y,z,&a,&b,&c,&u,&v,&w);
    

    return (0);
}


void dureevol(int hd, int md, int sd, int *ha, int *ma, int *sa, int *h, int *m, int *s)
{
    
    if(*sa<sd)
    {
        *sa = *sa + 60;
        *ma = *ma - 1;
    }

    if(*ma<md)
    {
        *ma = *ma + 60;
        *ha = *ha - 1;
    }

    if(*ha<hd)
    {
        *ha = *ha + 24;
        
    }

    *h = *ha - hd;
    *m = *ma - md;
    *s = *sa - sd;

    printf("La duree du vol est de\t%dh %dmn %ds\n", *h,*m, *s);

}
