/*		===== Informations sur le fichier =====
Fichier : decryptage.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les définitions des fonctions de decryptage
*/

/*Entêtes préprocesseur*/

#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des fonctions system

#include "decryptage.h" // Fichier header pour les fonctions de decryptage (voir le fichier pour description détaillées)
#include "annexe.h" // Fichier header pour les fonctions d'annexes (voir le fichier pour description détaillées)

/*FONCTION : decryptage_cesar
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_cesar(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage cesar : chaque lettre est décalée d'un offset constant*/
int decryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL }; // Texte à decrypter

	int chiffre_cesar = 0;
	int i = 0;

	cesar = recup_fichier(str); // Récupération du texte

	system("cls");
	printf("Entrer le chiffre de Cesar :\n"); // Entrer le chiffre utilisé lors du cryptage
	scanf("%d", &chiffre_cesar);

	for (i = 0; i < cesar.taille; i++)
	{
		cesar.data[i] = cesar.data[i] - chiffre_cesar; // retrait de l'offset
	}

	sauv_fichier("fichier_cesar_decrypt.txt", cesar); // Eregistrement

	printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_cesar_decrypt.txt'\n");

	system("pause");

	free_tableau(&cesar); // Free

	return 0;
}

/*FONCTION : decryptage_clef
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_clef(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage clef : chaque lettre est décalée d'un offset qui dépend de la 
	clé entrée. Le texte est ensuite inverse.*/
int decryptage_clef(const char *std)

{
	TABLEAU txt_clef = { 0, NULL }; // Texte a decrypté
	TABLEAU clef = { 0, NULL }; // Stockage de clé

	int a = 0;
	int b = 1;
	int choix = 0;
	int retour = -1;
	char* tmp;

	choix = menu_clef(); // Menu


	switch (choix)
	{
	case 1:

		system("cls");

		txt_clef = recup_fichier(std); // Récupération du texte

		system("notepad.exe cle"); // Demande de la clé ou cérification de la clé dispo

		printf("Appuyer sur ENTREE pour lancer le decryptage apres avoir enregistre et ferme le fichier\n");
		system("pause");

		clef = recup_fichier("cle.txt"); // Récupération de clé
		system("del cle.txt"); // Suppression de la clé

		for (int i = 0; i < (txt_clef.taille / 2); i++) // Inversion du texte crypté
		{
			tmp = txt_clef.data[i];
			txt_clef.data[i] = txt_clef.data[txt_clef.taille - (i + 1)];
			txt_clef.data[txt_clef.taille - (i + 1)] = tmp;
		}

		for (int i = 0; i < clef.taille; ++i)
		{
			a = a + clef.data[i]; // Calcul de a
		}

		for (int i = 0; i < clef.taille; ++i)
		{
			b = b*clef.data[i]; // Calcul de b
		}

		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) != 0)
			{
				txt_clef.data[i] = txt_clef.data[i] - a; // On retire l'offset a
			}
		}
		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) == 0)
			{
				txt_clef.data[i] = txt_clef.data[i] - b; // On retire l'offset b
			}
		}

		sauv_fichier("fichier_decrypt_clef.txt", txt_clef); // Sauvegarde du fichier decrypté

		printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_decrypt_clef.txt'\n");

		system("pause");

		free_tableau(&txt_clef); // Free texte 
		free_tableau_int(&clef); // Free clé

		return 0;
		break;
		
	case 2:
		return 0; // retour menu principal
		break;
	}



}

/*FONCTION : decryptage_image_pgm
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_image_pgm(const char *str, const char *fichier)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier), const char *key_crypt (nom du fichier cle)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage pour une image PGM, chaque lettre du fichier est décallé d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilisés sont stockés dans une clé*/
int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL }; // stockage du texte
	TABLEAU_int key = { 0, NULL }; // stoackage de la clé
	IMAGE image = { 0, 0, NULL, NULL }; // stockage de l'image

	char* tmp;
	int j = 0;
	int offset = 0;

	texte = recup_fichier(fichier_crypt); // Récupération du fichier texte
	key = recup_fichier_int(key_crypt); // Récupération de la clé
	image = recup_image(str); // Récupération de l'image

	for (int i = 0; i < (texte.taille / 2); i++) // Inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	for (int i = 0; i < texte.taille; i++)
	{
		offset = image.pixel[key.data[j]][key.data[j + 1]]; // Création de l'offset 
		j = j + 2;
		if (i % 2 == 0) // Cas par
		{
			texte.data[i] = texte.data[i] - offset; // On retranche l'offset
		}
		else // Cas impar
		{
			texte.data[i] = texte.data[i] + offset; // On ajoute l'offset
		}
	}

	sauv_fichier("fichier_decrypt_image_pgm.txt", texte); // Sauvegarde du fichier decrypte
	
	free_image(&image); // Free image
	free_tableau(&texte); // Free texte
	free_tableau_int(&key); // Free clé

	return 0;
}

/*FONCTION : decryptage_image_ppm
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_image_ppm(const char *str, const char *fichier)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier), const char *key_crypt (nom du fichier cle)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage pour une image PPM, chaque lettre du fichier est décallé d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilisés sont stockés dans une clé*/
int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL }; // Stockage du texte
	TABLEAU_int key = { 0, NULL }; // Stockage de clé
	IMAGERGB image_rgb = { 0, 0, NULL, NULL }; // Stockage de l'image

	char* tmp;
	int j = 0;
	int offset = 0;
	int col = 0;
	int lig = 0;

	texte = recup_fichier(fichier_crypt); // Récupération du fichier crypté
	key = recup_fichier_int(key_crypt); // Récupération de clé de décryptage
	image_rgb = recup_imageRGB(str); // Récupération de l'image

	for (int i = 0; i < (texte.taille / 2); i++) // Inversion
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
			offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B; // Calcul de l'offset

			texte.data[i] = texte.data[i] - offset; // Retrait de l'offset
		}
		else
		{
			col = key.data[j];
			j++;
			lig = key.data[j];
			j++;
			offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B; // Calcul de l'offset

			texte.data[i] = texte.data[i] + offset; // ajout de l'offset
		}
	}

	sauv_fichier("fichier_decrypt_image_ppm.txt", texte); // Sauvegarde du fichier decrypté

	free_imageRGB(&image_rgb); // Free image
	free_tableau(&texte); // Free texte
	free_tableau_int(&key); // Free clé

	return 0;
}