/*		===== Informations sur le fichier =====
Fichier : cryptage.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les d�finitions des fonctions de cryptage
*/

/*Ent�tes pr�proc�sseur*/

#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des fonctions system
#include <time.h> // Pour l'alea
#include <string.h> // Pour la gestion du texte

#include "cryptage.h" // Fichier header pour les cryptage (voir le fichier pour description d�taill�es)
#include "annexe.h" // Fichier header pour les annexes (voir le fichier pour description d�taill�es)
#include "menu.h" // Fichier header pour les menus (voir le fichier pour description d�taill�es)

/*FONCTION : cryptage_cesar
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_cesar(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage cesar : chaque lettre est d�cal�e d'un offset constant*/
int cryptage_cesar(const char *str)
{
	TABLEAU texte = { 0, NULL }; // TABLEAU pour le texte

	int choix = 0;
	int chiffre_cesar = 0; // Variable pour le chiffre de cesar
	int i = 0;

	texte = recup_fichier(str); // R�cup�ration du fichier

	choix = menu_cesar_crypt(); // Affichage du menu

	switch (choix)
	{
	case 1 :
		system("cls");
		printf("Entrer le chiffre de Cesar :\n");
		scanf("%d", &chiffre_cesar); // R�cup�ration du chiffre de cesar

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
		chiffre_cesar = rand() % 11000; // Car il n'est pas n�cessaire d'aller plus loin il y a assez de possibilit�

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
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_clef(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage clef : chaque lettre est d�cal�e d'un offset qui d�pend de la 
	cl� entr�e. Le texte est ensuite inverse.*/
int cryptage_clef(const char *str)
{
	TABLEAU txt_clef = { 0, NULL }; // Texte a crypt�
	TABLEAU clef = { 0, NULL };  // Cl�

	char* tmp; // pour le d�callage
	int choix = 0;

	choix = menu_clef(); // Affichage du menu

	switch (choix)
	{
	case 1:

		system("cls");

		txt_clef = recup_fichier(str); // R�cup�ration du fichier

		int a = 0;
		int b = 1;
		
		system("notepad.exe cle"); // On demande a l'utilisateur d'entrer une cl� ou de charger le fichier si il existe d�j�
		printf("Appuyer sur ENTREE pour lancer le cryptage apres avoir enregistre et ferme le fichier\n");
		system("pause");
		clef = recup_fichier("cle.txt"); // On r�cup�re la cl�
		system("del cle.txt"); // On supprime le fichier par s�curit�

		for (int i = 0; i < clef.taille; ++i)
		{
			a = a + clef.data[i]; // On cr�e une variable de d�callage a
		}

		for (int i = 0; i < clef.taille; ++i)
		{
			b = b*clef.data[i]; // On cr�e une variable de d�callage b
		}

		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) != 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + a; // On d�calle de a les indices impairs
			}
		}
		for (int i = 0; i < txt_clef.taille; ++i)
		{
			if ((i / 2) == 0)
			{
				txt_clef.data[i] = txt_clef.data[i] + b; // On d�calle de b les indices pairs
			}
		}
		for (int i = 0; i < (txt_clef.taille / 2); i++) // On inverses les caract�res, le premier devient le dernier, le second l'avant dernier ...
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
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_image_ppm(const char *str, const char *fichier)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage pour une image PPM, chaque lettre du fichier est d�call� d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilis�s sont stock�s dans une cl�*/
int cryptage_image_ppm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL }; // Texte a crypt�
	TABLEAU_int key = { 0, NULL }; // Cl� ou seront stock� les valeurs des pixels utilis�s
	IMAGERGB image_rgb = { 0, 0, NULL, NULL }; // Stockage de l'image

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;
	int j = 0;

	texte = recup_fichier(fichier); // On r�cup�re le texte
	key = calloc_tableau_int(texte.taille); // On alloue la place n�cessaire pour la cl�
	image_rgb = recup_imageRGB(str); // On r�cup�re l'image

	srand(time(NULL));

	for (int i = 0; i < texte.taille; i++)
	{
		col = rand() % image_rgb.Nbcol; // On choisi au hasar un num�ro de colonne
		lig = rand() % image_rgb.Nblig; // On choisi au hasar un num�ro de ligne

		if (i % 2 == 0)
		{
			offset = image_rgb.pixel[col][lig].R + image_rgb.pixel[col][lig].B; // On choisi les canneaux du rouge et du bleu pour cr�er l'offet si l'indice est pair

			texte.data[i] = texte.data[i] + offset; // On somme l'offset
		}
		else
		{
			offset = image_rgb.pixel[col][lig].G - image_rgb.pixel[col][lig].B; // On choisi les canneaux du bleu et du vert pour cr�er l'offet si l'indice est impair

			texte.data[i] = texte.data[i] - offset; // On d�duit l'offset
		}

		key.data[j] = col; // On enregistre les coordonn�es du pixels
		j++;
		key.data[j] = lig;
		j++;
	}

	for (int i = 0; i < (texte.taille / 2); i++) // On r�alise l'inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i + 1)];
		texte.data[texte.taille - (i + 1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_ppm.txt", texte); // On enregistre le fichier crypt�
	sauv_fichier_int("key.txt", key); // On enregistre la cl�

	free_imageRGB(&image_rgb); // On lib�re l'image
	free_tableau(&texte); // On lib�re le texte
	free_tableau_int(&key); // On lib�re la cl�

	return 0;
}

/*FONCTION : cryptage_image_pgm
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_image_pgm(const char *str, const char *fichier)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier image), const char *fichier (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage pour une image PGM, chaque lettre du fichier est d�call� d'un
	offset qui est choisi au hasard parmis les pixels de l'image. Le texte est ensuite inverse.
	Les pixels utilis�s sont stock�s dans une cl�*/
int cryptage_image_pgm(const char *str, const char *fichier)
{
	TABLEAU texte = { 0, NULL }; // Texte � crypt�
	TABLEAU_int key = { 0, NULL }; // Cl� pour stocker les coordonn�es des pixels utilis�s
	IMAGE image = { 0, 0, NULL, NULL }; // Stockage de l'image

	unsigned int choix = 0;
	unsigned int i = 0;
	unsigned int lig = 0;
	unsigned int col = 0;
	char* tmp;
	int offset = 0;
	int j = 0;

	texte = recup_fichier(fichier); // On r�cup�re le fichier
	key = calloc_tableau_int(texte.taille); // On alloue l'espace pour le cl�
	image = recup_image(str); // On r�cup�re l'image

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

		key.data[j] = col; // On sauvegarde les coordonn�es dans la cl�
		j++;
		key.data[j] = lig;
		j++;

	}

	for (int i = 0; i < (texte.taille / 2); i++) // On r�alise l'inversion
	{
		tmp = texte.data[i];
		texte.data[i] = texte.data[texte.taille - (i+1)];
		texte.data[texte.taille - (i+1)] = tmp;
	}

	sauv_fichier("fichier_crypt_image_pgm.txt", texte); // Sauvegarde du fichier crypt�
	sauv_fichier_int("key.txt", key); // Sauvegarde de la cl�

	free_image(&image); // Free image
	free_tableau(&texte); // Free texte 
	free_tableau_int(&key); // Free cl�

	return 0;
}