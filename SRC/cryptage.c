#include <stdio.h>
#include <stdlib.h>

#include "cryptage.h"


void cryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL };

	int choix = 0;
	int chiffre_cesar = 0;

	cesar = recup_fichier(str);

	while (choix < 1 || choix > 3)
	{
		printf("Voulez vous entrer le chiffre de Cesar ?\n");
		printf("1 - Oui\n");
		printf("2 - Non, je laisse le programme choisir\n");
		printf("3 - Retour au menu principal\n\n");
		scanf("%d", &choix);

		if (choix < 1 || choix > 3)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n");
		}
	}

	switch (choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le chiffre de Cesar compris entre 1 et :\n");
		scanf("%d", &chiffre_cesar);
		break;
	default:
		break;
	}



}