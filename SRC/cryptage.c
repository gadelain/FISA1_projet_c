#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "cryptage.h"
#include "annexe.h"


int cryptage_cesar(const char *str)
{
	TABLEAU texte = { 0, NULL };

	int choix = 0;
	int chiffre_cesar = 0;
	int i = 0;

	texte = recup_fichier(str);

	choix = menu_cesar_crypt();

	switch (choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le chiffre de Cesar :\n");
		scanf("%d", &chiffre_cesar);

		for (i = 0; i < texte.taille; i++)
		{
			texte.data[i] = texte.data[i] + chiffre_cesar;
		}

		sauv_fichier("fichier_crypt.txt", texte);

		system("pause");

		return 0;
		break;
	case 2:
		system("cls");
		srand(time(NULL));
		chiffre_cesar = rand() % 11000;

		for (i = 0; i < texte.taille; i++)
		{
			texte.data[i] = texte.data[i] + chiffre_cesar;
		}

		printf("Votre chiffre de Cesar est : %d .  Noter le il vous sera demande pour le decryptage\n", chiffre_cesar);
		sauv_fichier("fichier_crypt.txt", texte);

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

int cryptage_image(const char *str)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU key = { 0, NULL};
	IMAGE image = { 0, 0, NULL, NULL};
	IMAGERGB image_rgb = { 0, 0, NULL, NULL};

	unsigned int choix = 0;
	char *nom_image;
	unsigned int i = 0;
	int detection = -1;
	int lig = 0;
	int col = 0;
	int valeur_pxl = 0;
	

	texte = recup_fichier(str);
	key = calloc_tableau(texte.taille);

	choix = menu_image_crypt();
	
	switch(choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le nom de votre image au format nom_image.format :\nATTENTION : Les espaces et les carateres speciaux ne sont pas autorises dans le nom de l'image.\nSeules les images .pgm et .ppm sont autorisees.\n");
		scanf("%s", &nom_image);
		
		detection = detection_ppm_pgm(nom_image);
		
		switch(detection)
		{
		case 1:
			image_rgb = recup_imageRGB(nom_image);
			
			for(i = 0; i < texte.taille; i++)
			{
				srand(time(NULL));
				col = rand() % image_rgb.Nbcol;
				lig = rand() % image_rgb.Nblig;				
			}
			
			break;
		case 2:
			break;
		case 3;
			printf("Erreur : vous n'avez pas entre un format de fichier correct !");
			return -1;
			break;
		}
		
		sauv_fichier("fichier_crypt.txt", cesar);

		system("pause");

		return 0;
		break;
	case 2:
		break;
	case 3:
		return 0;
		break;
	default:
		return -1;
		break;
	}
}
