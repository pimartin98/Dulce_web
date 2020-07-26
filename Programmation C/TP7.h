#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

char ** lecturegraphe(int *ordre);
// on retourne un double pointeur de type char 
// on construit un graphe a partir de données stockées dans un fichier texte dont le nom est
//  graphe.txt
// la premiere ligne de graphe.txt donne le nombre de sommets 
// Ensuite, chaque ligne de graphe.txt est un arc (i,j) code sous forme i j 

void affcihematrice(int ordre, char **adjance);
//Procedure qui affiche la matrice d'adjacence


void affichesuccesseurs(int ordre, char **adjacence);
// Procedure qui affiche pour chaques sommet ses successeurs 

void affichepredecesseurs(int ordre, char **adjacence);
//Procedure qui affiche pour chaques sommets ses predecesseurs

void affichesarcs(int ordre, char **adjacence);
//procedure qui affiche les arcs du graphe 


int nbchemin2(int ordre, char **adjacence);
// on compte le nombre de chemins de longueur 2 dans le graphe


void saisiegraphe();
//on construit un grahe à partir d'éléments saisis au clavier 
