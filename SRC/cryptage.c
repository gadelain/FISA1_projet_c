/*		===== Informations sur le fichier =====
Fichier : cryptage.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les définitions des fonctions de cryptage
*/

/*Entêtes préprocésseur*/

#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des fonctions system
#include <time.h> // Pour l'alea
#include <string.h> // Pour la gestion du texte

#include "cryptage.h" // Fichier header pour les cryptage (voir le fichier pour description détaillées)
#include "annexe.h" // Fichier header pour les annexes (voir le fichier pour description détaillées)
#include "menu.h" // Fichier header pour les menus (voir le fichier pour description détaillées)

/*FONCTION : cryptage_cesar
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_cesar(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage cesar : chaque lettre est décalée d'un offset constant*/
int cryptage_cesar(const char *str)
{
	TABLEAU texte = { 0, NULL }; // TABLEAU pour le texte

	int choix = 0;
	int chiffre_cesar = 0; // Variable pour le chiffre de cesar
	int i = 0;

	texte = recup_fichier(str); // Récupération du fichier

	choix = menu_cesar_crypt(); // Affichage du menu

	switch (choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le chiffre de Cesar :\n");
		scanf("%d", &chiffre_cesar); // Récupération du chiffre de cesar

		for (i = 0; i < texte.taille; i++)
		{
			texte.data[i] = texte.data[i] + chiffre_cesar; // Decalage de l'offset
		}

		sauv_fichier("fichier_crypt_cesar.txt", texte); // Enregistremement du fichier

		printf("Succes : Votre chiffre de Cesar est : %d .  Noter le il vous sera demande pour le decryptage\nLe fichier est 'fichier_crypt_cesar.txt'\n", chiffre_cesar);

		system("pause");

		free_tableau(&texte); // Free

		return 0;
		break;
	case 2:
		system("cls");
		srand(time(NULL));
		chiffre_cesar = rand() % 11000; // Car il n'est pas nécessaire d'aller plus loin il y a assez de possibilité

		for (i = 0; i < texte.taille; i++)
		{
			texte.data[i] = texte.data[i] + chiffre_cesar; // decalage
		}

		printf("Votre chiffre de Cesar est : %d .  Noter le il vous sera demande pour le decryptage\nLe fichier est 'fichier_crypt_cesar.txt'\n", chiffre_cesar);
		sauv_fichier("fichier_crypt_cesar.txt", texte); // Enregistrement

		free_tableau(&texte); // Free

		system("pause");

		return 0;
		break;
	case 3:
		return 0; // Retour au menu principal
		break;
	default:
		return -1;
		break;
	}
}

/*FONCTION : cryptage_clef
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_clef(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage clef : chaque lettre est décalée d'un offset qui dépend de la 
	clé entrée. Le texte est ensuite inverse.*/
int cryptage_clef(const char *str)
{
	TABLEAU txt_clef = { 0, NULL }; // Texte a crypté
	TABLEAU clef = { 0, NULL };  // Clé

	char* tmp; // pour le décallage
	int choix = 0;

	choix = menu_clef(); // Affichage du menu

	switch (choix)
	{
	case 1:

		system("cls");

		txt_clef = recup_fichier(str); // Récupération du fichier

		int a = 0;
		int b = 1;
		
		system("notepad.exe cle"); // On demande a l'utilisateur d'entrer une clé ou de charger le fichier si il existe déjà
		printf("Appuyer sur ENTREE pour lancer le cryptage apres avoir enregistre et ferme le fichier\n");
		system("pause");
		clef = recup_fichier("cle.txt"); // On récupére la clé
		system("del cle.txt"); // On supprime le fichier par sécurité

		for (int i = 0; i < clef.taille; ++i)
		{
			a = a + clef.data[i]; // On crée une variable de décallage a
		}

		for (int i = 0; i < clef.taille; ++i)
		{
			b = b*clef.data[i]; // On crée une variable de décallage b
		}

		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) != 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + a; // On décalle de a les indices impairs
			}
		}
		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) == 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + b; // On décalle de b les indices pairs
			}
		}
		for (int i = 0; i < (txt_clef.taille / 2); i++) // On inverses les caractères, le premier devient le dernier, le second l'avant dernier ...
		{
			tmp = txt_clef.data[i];
			txt_clef.data[i] = txt_clef.data[txt_clef.taille - (i + 1)];
			txt_clef.data[txt_clef.taille - (i + 1)] = tmp;
		}

		sauv_fichier("fichier_crypt_clef.txt", txt_clef);

		printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_clef.txt'\n");

		system("pause");

		free_tableau(&txt_clef); // Free
		free_tableau_int(&clef); // Free

		return 0;
		break;

	case 2:
		return 0; // Retour au menu principal
		break;
	}

	return 0;
}

/*FONCTION : cryptage_image_ppm
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_image_ppm(const char *str, const char *fichier)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage pour une image PPM, chaque lettre du fichier est décallé d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilisés sont stockés dans une clé*/
int cryptage_image_ppm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL }; // Texte a crypté
	TABLEAU_int key = { 0, NULL }; // Clé ou seront stocké les valeurs des pixels utilisés
	IMAGERGB image_rgb = { 0, 0, NULL, NULL }; // Stockage de l'image

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;
	int j = 0;

	texte = recup_fichier(fichier); // On récupére le texte
	key = calloc_tableau_int(texte.taille); // On alloue la place nécessaire pour la clé
	image_rgb = recup_imageRGB(str); // On récupére l'image

	srand(time(NULL));

	for (int i = 0; i < texte.taille; i++)
	{
		col = rand() % image_rgb.Nbcol; // On choisi au hasar un numéro de colonne
		lig = rand() % image_rgb.Nblig; // On choisi au hasar un numéro de ligne

		if (i % 2 == 0)
		{
			offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B; // On choisi les canneaux du rouge et du bleu pour créer l'offet si l'indice est pair

			texte.data[i] = texte.data[i] + offset; // On somme l'offset
		}
		else
		{
			offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B; // On choisi les canneaux du bleu et du vert pour créer l'offet si l'indice est impair

			texte.data[i] = texte.data[i] - offset; // On déduit l'offset
		}

		key.data[j] = col; // On enregistre les coordonnées du pixels
		j++;
		key.data[j] = lig;
		j++;
	}

	for (int i = 0; i < (texte.taille / 2); i++) // On réalise l'inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_ppm.txt", texte); // On enregistre le fichier crypté
	sauv_fichier_int("key.txt", key); // On enregistre la clé

	free_imageRGB(&image_rgb); // On libère l'image
	free_tableau(&texte); // On libère le texte
	free_tableau_int(&key); // On libère la clé

	return 0;
}

/*FONCTION : cryptage_image_pgm
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_image_pgm(const char *str, const char *fichier)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage pour une image PGM, chaque lettre du fichier est décallé d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilisés sont stockés dans une clé*/
int cryptage_image_pgm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL }; // Texte à crypté
	TABLEAU_int key = { 0, NULL }; // Clé pour stocker les coordonnées des pixels utilisés
	IMAGE image = { 0, 0, NULL, NULL }; // Stockage de l'image

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;
	int j = 0;

	texte = recup_fichier(fichier); // On récupère le fichier
	key = calloc_tableau_int(texte.taille); // On alloue l'espace pour le clé
	image = recup_image(str); // On récupère l'image

	srand(time(NULL));

	for (int i = 0; i < texte.taille; i++)
	{
		col = rand() % image.Nbcol; // On choisi un colonne au hasard
		lig = rand() % image.Nblig; // On choisi un ligne au hasard

		offset = image.pixel[col][lig]; // On pointe sur une valeur de pixel

		if (i % 2 == 0)
		{
			texte.data[i] = texte.data[i] + offset; // On ajoute l'offset si l'indice est pair
		}
		else
		{
			texte.data[i] = texte.data[i] - offset; // On retranche si l'indice est impaire
		}

		key.data[j] = col; // On sauvegarde les coordonnées dans la clé
		j++;
		key.data[j] = lig;
		j++;

	}

	for (int i = 0; i < (texte.taille / 2); i++) // On réalise l'inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i+1)];
		texte.data[texte.taille - (i+1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_pgm.txt", texte); // Sauvegarde du fichier crypté
	sauv_fichier_int("key.txt", key); // Sauvegarde de la clé

	free_image(&image); // Free image
	free_tableau(&texte); // Free texte 
	free_tableau_int(&key); // Free clé

	return 0;
}