#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "annexe.h"
#include "cryptage.h"

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

int menu_image_crypt(const char *str)
{
	int choix = 0;
	char nom_image[255]; //Limite pour un nom de fichier depuis Win95
	char* nom_image_default = "default.ppm";
	int detection = 3; //detection = 3 car 3 est le cas default
	int checkpoint = -1;

	while (choix < 1 || choix > 3)
	{
		printf("Voulez vous choisir une image ?\n");
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
	case 1:
		system("cls");
		printf("Entrer le nom de votre image au format nom_image.format :\nATTENTION : Les espaces et les carateres speciaux ne sont pas autorises dans le nom de l'image.\nSeules les images .pgm et .ppm sont autorisees.\n");
		scanf("%s", nom_image);

		detection = detection_ppm_pgm(nom_image);

		switch (detection)
		{
		case 1:
			checkpoint = cryptage_image_ppm(nom_image, str);
			if (checkpoint != 0)
			{
				printf("Erreur : le cryptage n'a pas abouti\n");
				return -1;
			}
			else
			{
				printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_ppm.txt' et la cle 'key.txt'\n");
				return 0;
			}
			break;
		case 2:
			checkpoint = cryptage_image_pgm(nom_image, str);
			if (checkpoint != 0)
			{
				printf("Erreur : le cryptage n'a pas abouti\n");
				return 0;
			}
			else
			{
				printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_pgm.txt' et la cle 'key.txt'\n");
				return 0;
			}
			break;
		default:
			printf("Erreur default / break");
			return -1;
			break;
		}
		break;
	case 2:
		checkpoint = cryptage_image_ppm(nom_image_default, str);
		if (checkpoint != 0)
		{
			printf("Erreur : le cryptage n'a pas abouti\n");
			return -1;
		}
		else
		{
			printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_ppm.txt' et la cle 'key.txt'\n");
			return 0;
		}
		break;
	case 3:
		return 0;
		break;
	default:
		printf("Erreur default / break");
		return -1;
		break;
	}
}
