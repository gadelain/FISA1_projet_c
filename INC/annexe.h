/*		===== Informations sur le fichier =====
Fichier : annexe.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les déclarations des fonctions annexes au programme ainsi que les types
composés utiles. Ces données sont indispensable au fonctionnement du programme. Elles permmettent :
	- Les manipulations de fichiers texte et images : récupération, sauvegarde, affichage, libération
	- La détection du type d'image entré par l'utilisateur (pgm ou ppm)
	- Le controle de l'exactitude des noms de fichiers
*/

/*Entêtes préprocesseur*/
#pragma once
#define INC_ANNEXE_ // Flag pour la compilation

/*Types composés*/

/*TYPE COMPOSE : tableau
	Inditifiant / nom du type : TABLEAU
	Types de base utilisés et variables associées :
		- unsigned int taille : taille du tableau data
		- char* data : tableau à une dimension de caractères
	Utilisation : Stockage du texte issu de fichiers texte (.txt)*/
typedef struct tableau {
	unsigned int  taille;
	char* data;
} TABLEAU;

/*TYPE COMPOSE : tableau_int
	Inditifiant / nom du type : TABLEAU_int
	Types de base utilisés et variables associées :
		- unsigned int taille : taille du tableau data
		- unisigned int* data : tableau à une dimension d'entiers
	Utilisation : Stockage d'entiers (coordonnées des pixels) pour le cryptage / decryptage à l'aide
	d'images pgm / ppm (voir les fonctions cryptage_image_pgm, cryptage_image_ppm, decryptage_image_pgm
	et decryptage_image_ppm)*/
typedef struct tableau_int {
	unsigned int  taille;
	unsigned int* data;
} TABLEAU_int;

/*TYPE COMPOSE : rgb
	Inditifiant / nom du type : RBG
	Types de base utilisés et variables associées :
		- unsigned int R : Valeur du canal rouge
		- unsigned int G : Valeur du canal vert
		- unsigned int B : Valeur du canal bleu
	Utilisation : Représenté les intensités des caneaux RGB dans le cas d'images ppm*/
typedef struct rgb {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

/*TYPE COMPOSE : imageRGB
	Inditifiant / nom du type : IMAGERBG
	Types de base utilisés et variables associées :
		- unsigned int Nblig : Valeur du nombre de lignes de l'image
		- unsigned int Nbcol : Valeur du nombre de colonnes de l'image
		- RGB* data : tableau à une dimension permettant le stockage linéaire des données des différents
		cannaux de l'image RGB
		- RGB** pixels : tableau à deux dimensions (matrice) permettant le stockage bi-dimensionnel des
		données des différents cannaux de l'image RGB pour y accéder comme à l'aide des coordonnées
	Utilisation : Stockage d'images ppm (couleur)*/
typedef struct imageRGB {
	unsigned int   Nblig;
	unsigned int   Nbcol;
	RGB*  data;
	RGB** pixel;
} IMAGERGB;

/*TYPE COMPOSE : image
	Inditifiant / nom du type : IMAGE
	Types de base utilisés et variables associées :
		- unsigned int Nblig : Valeur du nombre de lignes de l'image
		- unsigned int Nbcol : Valeur du nombre de colonnes de l'image
		- unsigned char* data : tableau à une dimension permettant le stockage linéaire des données 
		de l'image NDG
		- unsigend char** pixels : tableau à deux dimensions (matrice) permettant le stockage 
		bi-dimensionnel des données de l'image NDG pour y accéder comme à l'aide des coordonnées
	Utilisation : Stockage d'images pgm (niveau de gris)*/
typedef struct image {
	unsigned int   Nblig;
	unsigned int   Nbcol;
	unsigned char*  data;
	unsigned char** pixel;
} IMAGE;

/*Déclarations des fonctions*/

/*FONCTION : calloc_tableau
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : TABLEAU calloc_tableau(int n)
	Paramètre(s) d'entrée : 
		- unsigned int n (taille du tableau)
	Paramètre de retour : 
		- TABLEAU (tableau alloué dynamiquement)
	Description : Permet l'allocation dynamique à 0 de tableaux destinés au texte*/
TABLEAU calloc_tableau(unsigned int n);

/*FONCTION : calloc_tableau_int
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : TABLEAU_int calloc_tableau_int(int n)
	Paramètre(s) d'entrée : 
		- unsigned int n (taille du tableau)
	Paramètre de retour : 
		- TABLEAU_int (tableau alloué dynamiquement)
	Description : Permet l'allocation dynamique à 0 de tableaux destinés à des entiers*/
TABLEAU_int calloc_tableau_int(unsigned int n);

/*FONCTION : free_tableau
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void free_tableau(TABLEAU *pt)
	Paramètre(s) d'entrée : 
		- TABLEAU *pt (adresse de la variable de type TABLEAU)
	Paramètre de retour : void
	Description : Libération de l'espace mémoire pour le type TABLEAU*/
void free_tableau(TABLEAU *pt);

/*FONCTION : affichage_tableau
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void affichage_tableau(char tab[], int n)
	Paramètre(s) d'entrée : 
		- char tab[] (données, contenues dans un tableau à une dimension)
		- unsigned int n (taille du tableau)
	Paramètre de retour : void
	Description : Affichage d'un tableau de caractères à des fins d'information ou de controle*/
void affichage_tableau(char tab[], unsigned int n);

/*FONCTION : affichage_tableau_int
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void affichage_tableau_int(int tab[], int n)
	Paramètre(s) d'entrée : 
		- int tab[] (données, contenues dans un tableau à une dimension)
		- unsigned int n (taille du tableau)
	Paramètre de retour : void
	Description : Affichage d'un tableau d'entiers à des fins d'information ou de controle*/
void affichage_tableau_int(int tab[], unsigned int n);

/*FONCTION : recup_fichier
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : TABLEAU recup_fichier(const char *str)
	Paramètre(s) d'entrée : 
		- const char *str (chaine de caractères, nom du fichier à récupérer)
	Paramètre de retour : 
		- TABLEAU (dimensionné et rempli avec les données issues du fichier)
	Description : Permet de récupérer les données (caractères) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU*/
TABLEAU recup_fichier(const char *str);

/*FONCTION : recup_fichier_int
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : TABLEAU_int recup_fichier_int(const char *str)
	Paramètre(s) d'entrée :
		- const char *str (chaine de caractères, nom du fichier à récupérer)
	Paramètre de retour : 
		- TABLEAU_int (dimensionné et rempli avec les données issues du fichier)
	Description : Permet de récupérer les données (entiers) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU_int*/
TABLEAU_int recup_fichier_int(const char *str);

/*FONCTION : sauv_fichier
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void sauv_fichier(const char *str, TABLEAU tab)
	Paramètre(s) d'entrée :
		- const char *str (chaine de caractères, nom du fichier où l'on va sauvegarder le TABLEAU)
		- TABLEAU tab (données, caratères à enregistrer)
	Paramètre de retour : void
	Description : Permet d'enregistrer les données (caractères) contenues dans un TABLEAU dans un fichier
	texte au format .txt*/
void sauv_fichier(const char *str, TABLEAU tab);

/*FONCTION : sauv_fichier_int
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void sauv_fichier_int(const char *str, TABLEAU_int tab)
	Paramètre(s) d'entrée :
		- const char *str (chaine de caractères, nom du fichier où l'on va sauvegarder le TABLEAU_int)
		- TABLEAU_int tab (données, entiers à enregistrer)
	Paramètre de retour : void
	Description : Permet d'enregistrer les données (entiers) contenues dans un TABLEAU_int dans un fichier
	texte au format .txt*/
void sauv_fichier_int(const char *str, TABLEAU_int tab);

/*FONCTION : recup_imageRGB
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : IMAGERGB recup_imageRGB(const char *in)
	Paramètre(s) d'entrée :
		- const char *in (chaine de caractères, nom du fichier à récupérer)
	Paramètre de retour : 
		- IMAGERGB (dimensionné et rempli avec les données issues du fichier)
	Description : Permet de récupérer les données contenues dans un fichier image de type ppm et de les
	renseigner dans un IMAGERGB*/
IMAGERGB recup_imageRGB(const char *in);

/*FONCTION : free_imageRGB
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void free_imageRGB(IMAGERGB *m)
	Paramètre(s) d'entrée :
		- IMAGERGB *m (adresse de la variable de type IMAGERGB)
	Paramètre de retour : void
	Description : Libération de l'espace mémoire pour le type IMAGERGB*/
void free_imageRGB(IMAGERGB *m);

/*FONCTION : malloc_imageRGB
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : IMAGERGB malloc_imageRGB(int Nblig, int Nbcol)
	Paramètre(s) d'entrée :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Paramètre de retour :
		- IMAGERGB (image couleur allouée dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destinés a des images couleurs*/
IMAGERGB malloc_imageRGB(unsigned int Nblig, unsigned int Nbcol);

/*FONCTION : recup_image
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : IMAGE recup_image(const char *in)
	Paramètre(s) d'entrée :
		- const char *in (chaine de caractères, nom du fichier à récupérer)
	Paramètre de retour : 
		- IMAGE (dimensionné et rempli avec les données issues du fichier)
	Description : Permet de récupérer les données contenues dans un fichier image de type pgm et de les
	renseigner dans un IMAGE*/
IMAGE recup_image(const char *in);

/*FONCTION : free_image
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : void free_image(IMAGE *m)
	Paramètre(s) d'entrée :
		- IMAGE *m (adresse de la variable de type IMAGE)
	Paramètre de retour : void
	Description : Libération de l'espace mémoire pour le type IMAGE*/
void free_image(IMAGE *m);

/*FONCTION : malloc_image
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : IMAGERGB malloc_image(int Nblig, int Nbcol)
	Paramètre(s) d'entrée :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Paramètre de retour :
		- IMAGE (image couleur allouée dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destinés a des images niveau de gris*/
IMAGE malloc_image(unsigned int Nblig, unsigned int Nbcol);

/*FONCTION : detection_ppm_pgm
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : int detection_ppm_pgm(const char *in)
	Paramètre(s) d'entrée :
		- const char *in (chaine de caractères, nom du fichier à analyser)
	Paramètre de retour :
		- unsigned int (valeur retournée par la fonction dépend du type d'image (pgm, ppm ou erreur))
	Description : Permet de detecter le type d'image entré par l'utilisateur et si ce type est pris en
	charge par l'ordinateur*/
unsigned int detection_ppm_pgm(const char *in);

/*FONCTION : detection_fichier
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : int detection_fichier(const char *in)
	Paramètre(s) d'entrée :
		- const char *in (chaine de caractères, nom du fichier à analyser)
	Paramètre de retour :
		- int (valeur retournée par la fonction dépend de l'existance du fichier)
	Description : Permet de detecter que le fichier entré par l'utilisateur existe*/
int detection_fichier(const char *in);