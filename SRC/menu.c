#include "menu.h"

int menu_cesar_crypt(void)
{
	int choix = 0;

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

	return choix;
}