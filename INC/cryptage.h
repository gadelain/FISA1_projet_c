/*		===== Informations sur le fichier =====
Fichier : cryptage.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les déclaration des fonctions de cryptage
*/

/*Entête préprocesseur*/

#pragma once
#define INC_CRYPTAGE_ // Flag compilation

/*FONCTION : cryptage_cesar
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_cesar(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage cesar : chaque lettre est décalée d'un offset constant*/
int cryptage_cesar(const char *str);

/*FONCTION : cryptage_clef
	Fichier : (déclaration) cryptage.h, (définition) cryptage.c
	Prototype : int cryptage_clef(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (nom du fichier)
	Paramètre de retour : 
		- int
	Description : Fonction de cryptage clef : chaque lettre est décalée d'un offset qui dépend de la 
	clé entrée. Le texte est ensuite inverse.*/
int cryptage_clef(const char *str);

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
int cryptage_image_ppm(const char *str, const char *fichier);

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
int cryptage_image_pgm(const char *str, const char *fichier);
