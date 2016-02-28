#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

//int cryptage_image(const char *str)
//{
//	TABLEAU texte = { 0, NULL };
//	TABLEAU_int key = { 0, NULL};
//	IMAGE image = { 0, 0, NULL, NULL};
//	IMAGERGB image_rgb = { 0, 0, NULL, NULL};
//
//	unsigned int choix = 0;
//	unsigned int i = 0;
//	unsigned int lig = 0;
//	unsigned int col = 0;
//	char* tmp;
//	char nom_image[255];
//	int detection = -1;
//	int offset = 0;
//
//	texte = recup_fichier(str);
//	key = calloc_tableau_int(texte.taille);
//
//	choix = menu_image_crypt();
//	
//	switch(choix)
//	{
//	case 1 :
//		system("cls");
//		printf("Entrer le nom de votre image au format nom_image.format :\nATTENTION : Les espaces et les carateres speciaux ne sont pas autorises dans le nom de l'image.\nSeules les images .pgm et .ppm sont autorisees.\n");
//		scanf("%s", &nom_image);
//		
//		detection = detection_ppm_pgm(nom_image);
//		
//		switch(detection)
//		{
//		case 1:
//			automatique:
//			image_rgb = recup_imageRGB(&nom_image);
//			
//			for(int i = 0; i < texte.taille; i++)
//			{
//				srand(time(NULL));
//				col = rand() % image_rgb.Nbcol;
//				lig = rand() % image_rgb.Nblig;
//				
//				if (i%2==0)
//				{
//					offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B;
//
//					texte.data[i] = texte.data[i] + offset;
//				}
//				else
//				{
//					offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B;
//
//					texte.data[i] = texte.data[i] - offset;
//				}
//
//				key.data[i] = offset + 7;
//			}
//
//			for (int i = 0; i < (texte.taille / 2); i++)
//			{
//				texte.data[i] = texte.data[texte.taille - i];
//			}
//
//			for (int i = 0; i < (texte.taille - 1); i++)
//			{
//				tmp = texte.data[i];
//				texte.data[i] = texte.data[i + 1];
//				texte.data[i + 1] = tmp;
//			}
//			break;
//		case 2:
//			break;
//		case 3:
//			printf("Erreur : vous n'avez pas entre un format de fichier correct !");
//			return -1;
//			break;
//		}
//		
//		sauv_fichier("fichier_crypt_image.txt", texte);
//		sauv_fichier_int("key.txt", key);
//
//		system("pause");
//
//		return 0;
//		break;
//	case 2:
//		goto automatique;
//		break;
//	case 3:
//		return 0;
//		break;
//	default:
//		return -1;
//		break;
//	}
//}

int cryptage_image_ppm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU_int key = { 0, NULL };
	IMAGERGB image_rgb = { 0, 0, NULL, NULL };

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;

	texte = recup_fichier(fichier);
	key = calloc_tableau_int(texte.taille);
	image_rgb = recup_imageRGB(str);

	for (int i = 0; i < texte.taille; i++)
	{
		srand(time(NULL));
		col = rand() % image_rgb.Nbcol;
		lig = rand() % image_rgb.Nblig;

		if (i % 2 == 0)
		{
			offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B;

			texte.data[i] = texte.data[i] + offset;
		}
		else
		{
			offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B;

			texte.data[i] = texte.data[i] - offset;
		}

		key.data[i] = offset + 7;
	}

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		texte.data[i] = texte.data[texte.taille - i];
	}

	for (int i = 0; i < (texte.taille - 1); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[i + 1];
		texte.data[i + 1] = tmp;
	}

	sauv_fichier("fichier_crypt_image_ppm.txt", texte);
	sauv_fichier_int("key.txt", key);
}

int cryptage_image_pgm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU_int key = { 0, NULL };
	IMAGE image = { 0, 0, NULL, NULL };

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;

	texte = recup_fichier(fichier);
	key = calloc_tableau_int(texte.taille);
	image = recup_image(str);

	for (int i = 0; i < texte.taille; i++)
	{
		srand(time(NULL));
		col = rand() % image.Nbcol;
		lig = rand() % image.Nblig;

		offset = image.pixel[col][lig];

		if (i % 2 == 0)
		{
			texte.data[i] = texte.data[i] + offset;
		}
		else
		{
			texte.data[i] = texte.data[i] - offset;
		}

		key.data[i] = offset + 7;
	}

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		texte.data[i] = texte.data[texte.taille - i];
	}

	for (int i = 0; i < (texte.taille - 1); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[i + 1];
		texte.data[i + 1] = tmp;
	}

	sauv_fichier("fichier_crypt_image_pgm.txt", texte);
	sauv_fichier_int("key.txt", key);
}