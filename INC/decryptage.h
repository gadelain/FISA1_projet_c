/*		===== Informations sur le fichier =====
Fichier : decryptage.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les d�clarations des fonctions de decryptage
*/

/*Ent�te pr�processeur*/

#pragma once
#define INC_DECRYPTAGE_ // Flag compilation

/*FONCTION : decryptage_cesar
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_cesar(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage cesar : chaque lettre est d�cal�e d'un offset constant*/
int decryptage_cesar(const char *str);

/*FONCTION : decryptage_clef
	Fichier : (d�claration) decryptage.h, (d�finition) decryptage.c
	Prototype : int decryptage_clef(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de decryptage clef : chaque lettre est d�cal�e d'un offset qui d�pend de la 
	cl� entr�e. Le texte est ensuite inverse.*/
int decryptage_clef(const char *std);

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
int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt);

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
int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt);