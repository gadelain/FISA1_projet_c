/*		===== Informations sur le fichier =====
Fichier : decryptage.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les d�finitions des fonctions de decryptage
*/

/*Ent�tes pr�processeur*/

#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des fonctions system

#include "decryptage.h" // Fichier header pour les fonctions de decryptage (voir le fichier pour description d�taill�es)
#include "annexe.h" // Fichier header pour les fonctions d'annexes (voir le fichier pour description d�taill�es)

/*FONCTION : decryptage_cesar
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_cesar(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage cesar : chaque lettre est d�cal�e d'un offset constant*/
int decryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL }; // Texte � decrypter

	int chiffre_cesar = 0;
	int i = 0;

	cesar = recup_fichier(str); // R�cup�ration du texte

	system("cls");
	printf("Entrer le chiffre de Cesar :\n"); // Entrer le chiffre utilis� lors du cryptage
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
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_clef(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage clef : chaque lettre est d�cal�e d'un offset qui d�pend de la 
	cl� entr�e. Le texte est ensuite inverse.*/
int decryptage_clef(const char *std)

{
	TABLEAU txt_clef = { 0, NULL }; // Texte a decrypt�
	TABLEAU clef = { 0, NULL }; // Stockage de cl�

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

		txt_clef = recup_fichier(std); // R�cup�ration du texte

		system("notepad.exe cle"); // Demande de la cl� ou c�rification de la cl� dispo

		printf("Appuyer sur ENTREE pour lancer le decryptage apres avoir enregistre et ferme le fichier\n");
		system("pause");

		clef = recup_fichier("cle.txt"); // R�cup�ration de cl�
		system("del cle.txt"); // Suppression de la cl�

		for (int i = 0; i < (txt_clef.taille / 2); i++) // Inversion du texte crypt�
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

		sauv_fichier("fichier_decrypt_clef.txt", txt_clef); // Sauvegarde du fichier decrypt�

		printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_decrypt_clef.txt'\n");

		system("pause");

		free_tableau(&txt_clef); // Free texte 
		free_tableau_int(&clef); // Free cl�

		return 0;
		break;
		
	case 2:
		return 0; // retour menu principal
		break;
	}



}

/*FONCTION : decryptage_image_pgm
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_image_pgm(const char *str, const char *fichier)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier), const char *key_crypt (nom du fichier cle)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage pour une image PGM, chaque lettre du fichier est d�call� d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilis�s sont stock�s dans une cl�*/
int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL }; // stockage du texte
	TABLEAU_int key = { 0, NULL }; // stoackage de la cl�
	IMAGE image = { 0, 0, NULL, NULL }; // stockage de l'image

	char* tmp;
	int j = 0;
	int offset = 0;

	texte = recup_fichier(fichier_crypt); // R�cup�ration du fichier texte
	key = recup_fichier_int(key_crypt); // R�cup�ration de la cl�
	image = recup_image(str); // R�cup�ration de l'image

	for (int i = 0; i < (texte.taille / 2); i++) // Inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	for (int i = 0; i < texte.taille; i++)
	{
		offset = image.pixel[key.data[j]][key.data[j + 1]]; // Cr�ation de l'offset 
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
	free_tableau_int(&key); // Free cl�

	return 0;
}

/*FONCTION : decryptage_image_ppm
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_image_ppm(const char *str, const char *fichier)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier), const char *key_crypt (nom du fichier cle)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage pour une image PPM, chaque lettre du fichier est d�call� d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilis�s sont stock�s dans une cl�*/
int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL }; // Stockage du texte
	TABLEAU_int key = { 0, NULL }; // Stockage de cl�
	IMAGERGB image_rgb = { 0, 0, NULL, NULL }; // Stockage de l'image

	char* tmp;
	int j = 0;
	int offset = 0;
	int col = 0;
	int lig = 0;

	texte = recup_fichier(fichier_crypt); // R�cup�ration du fichier crypt�
	key = recup_fichier_int(key_crypt); // R�cup�ration de cl� de d�cryptage
	image_rgb = recup_imageRGB(str); // R�cup�ration de l'image

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

	sauv_fichier("fichier_decrypt_image_ppm.txt", texte); // Sauvegarde du fichier decrypt�

	free_imageRGB(&image_rgb); // Free image
	free_tableau(&texte); // Free texte
	free_tableau_int(&key); // Free cl�

	return 0;
}