/*		===== Informations sur le fichier =====
Fichier : menu.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les définitions des fonctions annexes au programme ainsi que les types
composés utiles. Ces données sont indispensable au fonctionnement du programme. Elles permmettent :
- Les manipulations de fichiers texte et images : récupération, sauvegarde, affichage, libération
- La détection du type d'image entré par l'utilisateur (pgm ou ppm)
- Le controle de l'exactitude des noms de fichiers
*/

/*Entêtes préprocesseur*/
#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des commandes system pour Windows

#include "menu.h" // Fichier header pour les menus (voir le fichier pour description détaillées)
#include "annexe.h" // Fichier header pour les annexes (voir le fichier pour description détaillées)
#include "cryptage.h" // Fichier header pour les fonctions de cryptage (voir le fichier pour description détaillées)
#include "decryptage.h" // Fichier header pour les fonctions de decryptage (voir le fichier pour description détaillées)

/*FONCTION : menu_cesar_crypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_cesar_crypt(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage cesar et redirige vers les fonctions associées*/
int menu_cesar_crypt(void)
{
	int choix = 0;

	system("cls");

	while (choix < 1 || choix > 3)
	{
		// Menu
		printf("Voulez vous entrer le chiffre de Cesar ?\n");
		printf("1 - Oui\n");
		printf("2 - Non, je laisse le programme choisir\n");
		printf("3 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies

		if (choix < 1 || choix > 3)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	return choix;
}

/*FONCTION : menu_clef
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_clef(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par clé et redirige vers les fonctions associées*/
int menu_clef(void)
{
	int choix = 0;

	system("cls");

	while (choix < 1 || choix > 2)
	{
		// Menu
		printf("Veulliez entrer un choix :\n");
		printf("1- Entrez votre clef\n");
		printf("2- Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies 

		if (choix < 1 || choix > 2)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	return choix;
}

/*FONCTION : menu_image_crypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_image_crypt(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier à crypter)
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par image et redirige vers les fonctions associées*/
int menu_image_crypt(const char *str)
{
	int choix = 0;
	char nom_image[255]; //Limite pour un nom de fichier depuis Win95
	char* nom_image_default = "default.ppm"; // Nom de l'image par défaut en dur
	int detection = 3; //detection = 3 car 3 est le cas default
	int checkpoint = -1; // Valeur de test pour savoir si le cryptage s'est bien dérouler (-1 est le cas erreur)
	int fichier_correct = -1; // Valeur de test pour savoir si le nom du fichier entré est correct (-1 est le cas erreur)

	while (choix < 1 || choix > 3)
	{
		system("cls");
		printf("Voulez vous choisir une image ?\n");
		printf("1 - Oui\n");
		printf("2 - Non, je laisse le programme choisir\n");
		printf("3 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies 

		if (choix < 1 || choix > 3)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	system("cls");

	switch (choix)
	{
	case 1:
		while (fichier_correct != 0) // Force l'utilisateur à entrer un fichier correct
		{
			printf("Entrer le nom de votre image au format nom_image.format :\nATTENTION : Les espaces et les carateres speciaux ne sont pas autorises dans le nom de l'image.\nSeules les images .pgm et .ppm sont autorisees.\n");
			scanf("%s", nom_image);
			system("cls");
			fichier_correct = detection_fichier(nom_image); // Test l'exactitude du nom de fichier
		}

		detection = detection_ppm_pgm(nom_image); // Detection de la nature de l'image entrée

		switch (detection)
		{
		case 1:
			system("cls");
			checkpoint = cryptage_image_ppm(nom_image, str); // Cryptage PPM
			if (checkpoint != 0)
			{
				printf("Erreur : le cryptage n'a pas abouti\n"); // Cas où le cryptage n'aboutit pas
				system("pause");
				return -1;
			}
			else
			{
				printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_ppm.txt' et la cle 'key.txt'\n"); // Cas favorable
				system("pause");
				return 0;
			}
			break;
		case 2:
			system("cls");
			checkpoint = cryptage_image_pgm(nom_image, str); // Cryptage PGM
			if (checkpoint != 0)
			{
				printf("Erreur : le cryptage n'a pas abouti\n"); // Cas où le cryptage n'aboutit pas
				system("pause");
				return 0;
			}
			else
			{
				printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_pgm.txt' et la cle 'key.txt'\n"); // Cas favorable
				system("pause");
				return 0;
			}
			break;
		default:
			printf("Erreur default / break"); // Cas d'erreur sur le switch
			return -1;
			break;
		}
		break;
	case 2:
		system("cls");
		checkpoint = cryptage_image_ppm(nom_image_default, str); // Cas où l'image choisie est l'image par défaut
		if (checkpoint != 0)
		{
			printf("Erreur : le cryptage n'a pas abouti\n"); // Cas où le cryptage n'aboutit pas
			system("pause");
			return -1;
		}
		else
		{
			printf("Succes : le cryptage est termine.\nVotre fichier crypte est 'fichier_crypt_image_ppm.txt' et la cle 'key.txt'\n"); // Cas favorable
			system("pause");
			return 0;
		}
		break;
	case 3:
		return 0; // Retour au menu principal
		break;
	default:
		printf("Erreur default / break"); // Cas d'erreur sur le switch
		return -1;
		break;
	}
}

/*FONCTION : menu_image_decrypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_image_decrypt(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier à crypter)
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du decryptage par image et redirige vers les fonctions associées*/
int menu_image_decrypt(const char *str)
{
	int choix = 0;
	char nom_image[255]; //Limite pour un nom de fichier depuis Win95
	char nom_cle[255]; //Limite pour un nom de fichier depuis Win95
	char* nom_image_default = "default.ppm"; // Nom de l'image par défaut en dur
	int detection = 3; //detection = 3 car 3 est le cas default
	int checkpoint = -1; // Valeur de test pour savoir si le cryptage s'est bien dérouler (-1 est le cas erreur)
	int fichier_correct = -1; // Valeur de test pour savoir si le nom du fichier entré est correct (-1 est le cas erreur)

	while (choix < 1 || choix > 3)
	{
		// Menu
		printf("Avez vous choisi une image lors du cryptage ?\n");
		printf("1 - Oui\n");
		printf("2 - Non, j'ai laisse le programme choisir\n");
		printf("3 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies

		if (choix < 1 || choix > 3)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	switch (choix)
	{
	case 1:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur à entrer un fichier correct
		{
			printf("Entrer le nom de votre image au format nom_image.format :\nATTENTION : Les espaces et les carateres speciaux ne sont pas autorises dans le nom de l'image.\nSeules les images .pgm et .ppm sont autorisees.\n");
			scanf("%s", nom_image);

			fichier_correct = detection_fichier(nom_image); // Test l'exactitude du nom de fichier
		}

		fichier_correct = -1;

		while (fichier_correct != 0) // Force l'utilisateur à entrer un fichier correct
		{
			printf("Entrer le nom de votre fichier cle au format nom_fichier.txt :\n");
			scanf("%s", nom_cle);

			fichier_correct = detection_fichier(nom_cle); // Test l'exactitude du nom de fichier
		}

		detection = detection_ppm_pgm(nom_image); // Detection de la nature de l'image entrée

		switch (detection)
		{
		case 1:
			checkpoint = decryptage_image_ppm(nom_image, str, nom_cle); // Decryptage image PPM
			if (checkpoint != 0)
			{
				printf("Erreur : le decryptage n'a pas abouti\n"); // Cas erreur sur le decryptage
				system("pause");
				return -1;
			}
			else
			{
				printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_decrypt_image_ppm.txt'\n"); // Succes sur le decryptage
				system("pause");
				return 0;
			}
			break;
		case 2:
			checkpoint = decryptage_image_pgm(nom_image, str, nom_cle); // Decryptage image PGM
			if (checkpoint != 0)
			{
				printf("Erreur : le decryptage n'a pas abouti\n"); // Cas erreur
				system("pause");
				return 0;
			}
			else
			{
				printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_decrypt_image_pgm.txt'\n"); // Succes sur le decryptage
				system("pause");
				return 0;
			}
			break;
		default:
			printf("Erreur default / break"); // Erreur sur le switch
			system("pause");
			return -1;
			break;
		}
		break;
	case 2:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur à entrer un fichier correct
		{
			printf("Entrer le nom de votre fichier cle au format nom_fichier.txt :\n");
			scanf("%s", nom_cle);

			fichier_correct = detection_fichier(nom_cle); // Test l'exactitude du nom de fichier
		};

		checkpoint = decryptage_image_ppm(nom_image_default, str, nom_cle); // Decryptage PPM
		if (checkpoint != 0)
		{
			printf("Erreur : le decryptage n'a pas abouti\n"); // Cas erreur
			system("pause");
			return -1;
		}
		else
		{
			printf("Succes : le decryptage est termine.\nVotre fichier decrypte est 'fichier_decrypt_image_ppm.txt'\n"); // Succes sur le decryptage
			system("pause");
			return 0;
		}
		break;
	case 3:
		return 0; // Retour au menu principal
		break;
	default:
		printf("Erreur default / break"); // Erreur sur le switch
		system("pause");
		return -1;
		break;
	}
}

/*FONCTION : menu_annexe
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_annexe(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu annexe et redirige vers les fonctions ou les programmes associées*/
int menu_annexe(void)
{
	int choix = 0;

	while (choix < 1 || choix > 4)
	{
		// Menu
		printf("Menu annexe :\n");
		printf("1 - Ecrire du texte\n");
		printf("2 - A propos de...\n");
		printf("3 - Acceder au Github\n");
		printf("4 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies

		if (choix < 1 || choix > 4)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	switch (choix)
	{
	case 1:
		printf("IMPORTANT : penser a enregistrer votre travail avant de fermer Notepad.\n Le nom du fichier est 'mon_fichier.txt'\n");
		system("notepad.exe mon_fichier"); // Création d'un nouveau fichier sous notepad
		system("pause");

		return 0;
		break;
	case 2:
		system("notepad.exe README"); // Ouverture du README

		return 0;
		break;
	case 3:
		system("start iexplore.exe https://github.com/gadelain/FISA1_projet_c"); // Ouverture du Github

		return 0;
		break;
	case 4:
		return 0; // Retour au menu principal
		break;
	default:
		printf("Erreur default / break"); // Erreur sur le switch
		system("pause");
		return -1;
		break;
	}

	return choix;
}

/*FONCTION : menu_cryptage
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_cryptage(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de cryptage et redirige vers les fonctions associées*/
int menu_cryptage(void)
{
	int choix = 0;
	int retour = -1; // Retour de la fonction (-1 est le cas erreur)
	int fichier_correct = -1; // Valeur de controle sur l'exactitude du nom du fichier (-1 est le cas erreur)
	char nom_fichier[255]; // Limite dans les nom de fichier depuis Win95

	while (choix < 1 || choix > 4)
	{
		// Menu
		printf("Menu Cryptage :\n");
		printf("1 - Cryptage Cesar\n");
		printf("2 - Cryptage Clef\n");
		printf("3 - Cryptage Image\n");
		printf("4 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Evite les boucles infinies

		if (choix < 1 || choix > 4)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n"); // Cas erreur
		}
	}

	switch (choix)
	{
	case 1:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a crypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		
		retour = cryptage_cesar(nom_fichier); // Cryptage Cesar

		if (retour != 0)
		{
			printf("Erreur dans le cryptage\n"); // Cas erreur dans le cryptage
			system("pause");
		}

		return 0;
		break;
	case 2:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a crypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		retour = cryptage_clef(nom_fichier); // Cryptage par clé

		if (retour != 0)
		{
			printf("Erreur dans le cryptage\n"); // Cas erreur
			system("pause");
		}

		return 0;
		break;
	case 3:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a crypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		retour = menu_image_crypt(nom_fichier); // Menu du cryptage par image

		if (retour != 0)
		{
			printf("Erreur dans le cryptage\n"); // Erreur dans le cryptage
			system("pause");
		}

		return 0;
		break;
	case 4:
		return 0; // Retour	au menu principal
		break;
	default:
		printf("Erreur default / break\n"); // Erreur dans le switch
		return -1;
		break;
	}

	return choix;
}

/*FONCTION : menu_decryptage
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_decryptage(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de decryptage et redirige vers les fonctions associées*/
int menu_decryptage(void)
{
	int choix = 0;
	int retour = -1; // Retour de la fonction (-1 est le cas erreur)
	int fichier_correct = -1; // Valeur de controle sur l'exactitude du nom du fichier (-1 est le cas erreur)
	char nom_fichier[255]; // Limite dans les nom de fichier depuis Win95

	while (choix < 1 || choix > 4)
	{
		// Menu
		printf("Menu Decryptage :\n");
		printf("1 - Decryptage Cesar\n");
		printf("2 - Decryptage Clef\n");
		printf("3 - Decryptage Image\n");
		printf("4 - Retour au menu principal\n\n");
		scanf("%d", &choix);
		getchar(); // Pour éviter les boucles infinies

		if (choix < 1 || choix > 4)
		{
			system("cls");
			printf("Erreur : vous n'avez pas entre un choix correct\n");
		}
	}

	switch (choix)
	{
	case 1:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a decrypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		system("cls");

		retour = decryptage_cesar(nom_fichier); // Decryptage Cesar

		if (retour != 0)
		{
			printf("Erreur dans le decryptage\n");
			system("pause");
			return -1;
		}

		return 0;
		break;
	case 2:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a decrypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		retour = decryptage_clef(nom_fichier); // Décryptage par clef

		if (retour != 0)
		{
			printf("Erreur dans le decryptage\n"); // Cas erreur
			system("pause");
			return -1;
		}

		return 0;
		break;
	case 3:
		system("cls");

		while (fichier_correct != 0) // Force l'utilisateur a entrer un nom de fichier correct
		{
			printf("Entrer le nom du fichier a decrypter :\n");
			scanf("%s", nom_fichier);
			system("cls");

			fichier_correct = detection_fichier(nom_fichier); // Test le nom de fichier entré
		}

		retour = menu_image_decrypt(nom_fichier); // Menu de decryptege image

		if (retour != 0)
		{
			printf("Erreur dans le decryptage\n"); // Cas erreur
			system("pause");
			return -1;
		}

		return 0;
		break;
	case 4:
		return 0; // Retour au menu principal
		break;
	default:
		printf("Erreur default / break"); // Erreur dans le switch
		return -1;
		break;
	}

	return choix;
}