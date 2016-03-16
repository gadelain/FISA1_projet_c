/*		===== Informations sur le fichier =====
Fichier : decryptage.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les déclarations des fonctions de decryptage
*/

/*Entête préprocesseur*/

#pragma once
#define INC_DECRYPTAGE_ // Flag compilation

/*FONCTION : decryptage_cesar
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_cesar(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage cesar : chaque lettre est décalée d'un offset constant*/
int decryptage_cesar(const char *str);

/*FONCTION : decryptage_clef
	Fichier : (déclaration) decryptage.h, (définition) decryptage.c
	Prototype : int decryptage_clef(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de decryptage clef : chaque lettre est décalée d'un offset qui dépend de la 
	clé entrée. Le texte est ensuite inverse.*/
int decryptage_clef(const char *std);

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
int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt);

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
int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt);