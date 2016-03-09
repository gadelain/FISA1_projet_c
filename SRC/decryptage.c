#include <stdio.h>
#include <stdlib.h>

#include "decryptage.h"
#include "annexe.h"

int decryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL };

	int chiffre_cesar = 0;
	int i = 0;

	cesar = recup_fichier(str);

	system("cls");
	printf("Entrer le chiffre de Cesar :\n");
	scanf("%d", &chiffre_cesar);

	for (i = 0; i < cesar.taille; i++)
	{
		cesar.data[i] = cesar.data[i] - chiffre_cesar;
	}

	sauv_fichier("fichier_cesar_decrypt.txt", cesar);

	printf("Succes : le cryptage est termine.\nVotre fichier decrypte est 'fichier_cesar_decrypt.txt'\n");

	system("pause");

	return 0;
}

int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU_int key = { 0, NULL };
	IMAGE image = { 0, 0, NULL, NULL };

	char* tmp;
	int j = 0;
	int offset = 0;

	texte = recup_fichier(fichier_crypt);
	key = recup_fichier_int(key_crypt);
	image = recup_image(str);

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	for (int i = 0; i < texte.taille; i++)
	{
		offset = image.pixel[key.data[j]][key.data[j + 1]];
		j = j + 2;
		if (i % 2 == 0)
		{
			texte.data[i] = texte.data[i] - offset;
		}
		else
		{
			texte.data[i] = texte.data[i] + offset;
		}
	}

	sauv_fichier("fichier_decrypt_image_pgm.txt", texte);
	
	return 0;
}

int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU_int key = { 0, NULL };
	IMAGERGB image_rgb = { 0, 0, NULL, NULL };

	char* tmp;
	int j = 0;
	int offset = 0;
	int col = 0;
	int lig = 0;

	texte = recup_fichier(fichier_crypt);
	key = recup_fichier_int(key_crypt);
	image_rgb = recup_imageRGB(str);

	for (int i = 0; i < (texte.taille / 2); i++)
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	for (int i = 0; i < texte.taille; i++)
	{
		if (i % 2 == 0)
		{
			col = key.data[j];
			j++;
			lig = key.data[j];
			j++;
			offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B;

			texte.data[i] = texte.data[i] - offset;
		}
		else
		{
			col = key.data[j];
			j++;
			lig = key.data[j];
			j++;
			offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B;

			texte.data[i] = texte.data[i] + offset;
		}
	}

	sauv_fichier("fichier_decrypt_image_ppm.txt", texte);

	return 0;
}