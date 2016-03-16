/*		===== Informations sur le fichier =====
Fichier : menu.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les déclarations des fonctions annexes au programme ainsi que les types
composés utiles. Ces données sont indispensable au fonctionnement du programme. Elles permmettent :
- Les manipulations de fichiers texte et images : récupération, sauvegarde, affichage, libération
- La détection du type d'image entré par l'utilisateur (pgm ou ppm)
- Le controle de l'exactitude des noms de fichiers
*/

/*Entêtes préprocesseur*/
#pragma once
#define INC_MENU_ // Flag pour la compilation

/*Déclarations des fonctions*/

/*FONCTION : menu_cryptage
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_cryptage(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de cryptage et redirige vers les fonctions associées*/
int menu_cryptage(void);

/*FONCTION : menu_decryptage
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_decryptage(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de decryptage et redirige vers les fonctions associées*/
int menu_decryptage(void);

/*FONCTION : menu_cesar_crypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_cesar_crypt(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage cesar et redirige vers les fonctions associées*/
int menu_cesar_crypt(void);

/*FONCTION : menu_clef
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_clef(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par clé et redirige vers les fonctions associées*/
int menu_clef(void);

/*FONCTION : menu_image_crypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_image_crypt(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier à crypter)
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par image et redirige vers les fonctions associées*/
int menu_image_crypt(const char *str);

/*FONCTION : menu_image_decrypt
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_image_decrypt(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier à crypter)
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du decryptage par image et redirige vers les fonctions associées*/
int menu_image_decrypt(const char *str);

/*FONCTION : menu_annexe
	Fichier : (déclaration) menu.h, (définition) menu.c
	Prototype : int menu_annexe(void)
	Paramètre(s) d'entrée : 
		- void
	Paramètre de retour : 
		- int (accés aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu annexe et redirige vers les fonctions ou les programmes associées*/
int menu_annexe(void);