/*		===== Informations sur le fichier =====
Fichier : menu.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les d�clarations des fonctions annexes au programme ainsi que les types
compos�s utiles. Ces donn�es sont indispensable au fonctionnement du programme. Elles permmettent :
- Les manipulations de fichiers texte et images : r�cup�ration, sauvegarde, affichage, lib�ration
- La d�tection du type d'image entr� par l'utilisateur (pgm ou ppm)
- Le controle de l'exactitude des noms de fichiers
*/

/*Ent�tes pr�processeur*/
#pragma once
#define INC_MENU_ // Flag pour la compilation

/*D�clarations des fonctions*/

/*FONCTION : menu_cryptage
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_cryptage(void)
	Param�tre(s) d'entr�e : 
		- void
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de cryptage et redirige vers les fonctions associ�es*/
int menu_cryptage(void);

/*FONCTION : menu_decryptage
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_decryptage(void)
	Param�tre(s) d'entr�e : 
		- void
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu de decryptage et redirige vers les fonctions associ�es*/
int menu_decryptage(void);

/*FONCTION : menu_cesar_crypt
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_cesar_crypt(void)
	Param�tre(s) d'entr�e : 
		- void
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage cesar et redirige vers les fonctions associ�es*/
int menu_cesar_crypt(void);

/*FONCTION : menu_clef
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_clef(void)
	Param�tre(s) d'entr�e : 
		- void
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par cl� et redirige vers les fonctions associ�es*/
int menu_clef(void);

/*FONCTION : menu_image_crypt
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_image_crypt(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier � crypter)
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du cryptage par image et redirige vers les fonctions associ�es*/
int menu_image_crypt(const char *str);

/*FONCTION : menu_image_decrypt
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_image_decrypt(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier � crypter)
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu du decryptage par image et redirige vers les fonctions associ�es*/
int menu_image_decrypt(const char *str);

/*FONCTION : menu_annexe
	Fichier : (d�claration) menu.h, (d�finition) menu.c
	Prototype : int menu_annexe(void)
	Param�tre(s) d'entr�e : 
		- void
	Param�tre de retour : 
		- int (acc�s aux fonctions et reotur en cas d'erreur)
	Description : Affiche le menu annexe et redirige vers les fonctions ou les programmes associ�es*/
int menu_annexe(void);