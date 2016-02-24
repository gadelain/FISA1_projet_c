#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cryptage.h"
#include "annexe.h"


int cryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL };

	int choix = 0;
	int chiffre_cesar = 0;

	cesar = recup_fichier(str);

	choix = menu_cesar_crypt();

	switch (choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le chiffre de Cesar :\n");
		scanf("%d", &chiffre_cesar);

		for (int i = 0; i < cesar.taille; i++)
		{
			cesar.data[i] = cesar.data[i] + chiffre_cesar;
		}

		sauv_fichier("fichier_crypt.txt", cesar);

		system("pause");

		return 0;
		break;
	case 2:
		system("cls");
		srand(time(NULL));
		chiffre_cesar = rand() % 11000;

		for (int i = 0; i < cesar.taille; i++)
		{
			cesar.data[i] = cesar.data[i] + chiffre_cesar;
		}

		printf("Votre chiffre de Cesar est : %d .  Noter le il vous sera demande pour le decryptage\n", chiffre_cesar);
		sauv_fichier("fichier_crypt.txt", cesar);

		system("pause");

		return 0;
		break;
	case 3:
		return 0;
		break;
	default:
		return -1;
		break;
	}



}