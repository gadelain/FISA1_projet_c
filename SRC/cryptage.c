#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "cryptage.h"
#include "annexe.h"
#include "menu.h"


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

int cryptage_clef(const char *str)
{
	TABLEAU txt_clef = { 0, NULL };
	TABLEAU clef = { 0, NULL };

	char* tmp;
	int choix = 0;

	choix = menu_clef();

	switch (choix)
	{
	case 1:

		system("cls");

		txt_clef = recup_fichier(str);

		int a = 0;
		int b = 1;
		
		system("notepad.exe cle");
		printf("Appuyer sur ENTREE pour lancer le cryptage apres avoir enregistre et ferme le fichier\n");
		system("pause");
		clef = recup_fichier("cle.txt");
		system("del cle.txt");

		for (int i = 0; i < clef.taille; ++i)
		{
			a = a + clef.data[i];
		}

		for (int i = 0; i < clef.taille; ++i)
		{
			b = b*clef.data[i];
		}

		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) != 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + a;
			}
		}
		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) == 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + b;
			}
		}
		for (int i = 0; i < (txt_clef.taille / 2); i++)
		{
			tmp = txt_clef.data[i];
			txt_clef.data[i] = txt_clef.data[txt_clef.taille - (i + 1)];
			txt_clef.data[txt_clef.taille - (i + 1)] = tmp;
		}

		sauv_fichier("fichier_crypt_clef.txt", txt_clef);

		printf("Succes : le cryptage est termine.\nVotre fichier decrypte est 'fichier_crypt_clef.txt'\nVotre cle est 'cle.txt' penser a supprmier le fichier pour ne laisser aucune trace.\n");

		system("pause");
		return 0;
		break;

	case 2:
		return 0;
		break;
	}

	return 0;
}

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
	int j = 0;

	texte = recup_fichier(fichier);
	key = calloc_tableau_int(texte.taille);
	image_rgb = recup_imageRGB(str);

	srand(time(NULL));

	for (int i = 0; i < texte.taille; i++)
	{
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

		key.data[j] = col;
		j++;
		key.data[j] = lig;
		j++;
	}

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_ppm.txt", texte);
	sauv_fichier_int("key.txt", key);

	return 0;
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
	int j = 0;

	texte = recup_fichier(fichier);
	key = calloc_tableau_int(texte.taille);
	image = recup_image(str);

	srand(time(NULL));

	for (int i = 0; i < texte.taille; i++)
	{
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

		key.data[j] = col;
		j++;
		key.data[j] = lig;
		j++;

	}

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i+1)];
		texte.data[texte.taille - (i+1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_pgm.txt", texte);
	sauv_fichier_int("key.txt", key);

	return 0;
}