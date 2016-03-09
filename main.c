#include <stdio.h>
#include <stdlib.h>

#include "menu.h"


int main(void)
{
	char choix = '0';
	char retour_menu = '0';
	char watchdog = '0';

	while (watchdog != '1')
	{
		while (choix != '1' || choix != '2' || choix != '3' || choix != '4')
		{
			printf("===== Projet C FISA 1 : Cryptage / Decryptage =====\n");
			printf("1 - Cryptage\n");
			printf("2 - Decryptage\n");
			printf("3 - Annexe / aide\n");
			printf("4 - Quitter le programme\n\n");
			scanf("%c", &choix);

			if (choix != '1' || choix != '2' || choix != '3' || choix != '4')
			{
				system("cls");
				printf("Erreur : vous n'avez pas entre un choix correct\n");
			}
		}

		switch (choix)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
			retour_menu = menu_annexe();
			if (retour_menu != 0)
			{
				printf("Erreur dans l'execution du programme");
			}
			break;
		case '4':
			watchdog = '1';
			break;
		default:
			break;
		}

	}

	return 0;
}