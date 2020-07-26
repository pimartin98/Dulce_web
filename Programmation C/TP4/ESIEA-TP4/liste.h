/*
Pour eviter des erreurs de compilation face à une declaration multiple 
(par exemple, face au cas où xxx.h serait inclus dans plusieurs modules.c
du meme projet), il convient d'operer comme suit.
*/

							#ifndef LISTE_H_INCLUDED
							#define LISTE_H_INCLUDED

							typedef enum 
							{
								false,
								true
								
							}boolean;

							typedef struct 
							{
								int valeur ;
								struct Liste *suivant;


							}Liste, *Ptliste;

					Ptliste initialiser(void);
					boolean listevide(Ptliste L);
					void afficheordrerec (Ptliste L);
					Ptliste insertentete (Ptliste L, int X);
					Ptliste insertqueue (Ptliste L, int X);
					Ptliste supprentete (Ptliste L);
					Ptliste supprqueue (Ptliste L);
					Ptliste insertiondecroissant (Ptliste L, int X);
					Ptliste insertioncroissant (Ptliste L, int X);
					Ptliste suppressiondecroissant (Ptliste L, int X);
					Ptliste suppressioncroissant (Ptliste L, int X);

							#endif

							#include <stdio.h>

							#include <stdlib.h>
