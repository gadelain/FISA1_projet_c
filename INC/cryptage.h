/*		===== Informations sur le fichier =====
Fichier : cryptage.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les d�claration des fonctions de cryptage
*/

/*Ent�te pr�processeur*/

#pragma once
#define INC_CRYPTAGE_ // Flag compilation

/*FONCTION : cryptage_cesar
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_cesar(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage cesar : chaque lettre est d�cal�e d'un offset constant*/
int cryptage_cesar(const char *str);

/*FONCTION : cryptage_clef
	Fichier : (d�claration) cryptage.h, (d�finition) cryptage.c
	Prototype : int cryptage_clef(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (nom du fichier)
	Param�tre de retour : 
		- int
	Description : Fonction de cryptage clef : chaque lettre est d�cal�e d'un offset qui d�pend de la 
	cl� entr�e. Le texte est ensuite inverse.*/
int cryptage_clef(const char *str);

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
int cryptage_image_ppm(const char *str, const char *fichier);

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
int cryptage_image_pgm(const char *str, const char *fichier);
