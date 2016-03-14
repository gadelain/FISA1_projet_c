/*		===== Informations sur le fichier =====
Fichier : annexe.h (Header)
Repertoire : .../Include/
Description : Fichier contenant les d�clarations des fonctions annexes au programme ainsi que les types
compos�s utiles. Ces donn�es sont indispensable au fonctionnement du programme. Elles permmettent :
	- Les manipulations de fichiers texte et images : r�cup�ration, sauvegarde, affichage, lib�ration
	- La d�tection du type d'image entr� par l'utilisateur (pgm ou ppm)
	- Le controle de l'exactitude des noms de fichiers
*/

/*Ent�tes pr�processeur*/
#pragma once
#define INC_ANNEXE_ // Flag pour la compilation

/*Types compos�s*/

/*TYPE COMPOSE : tableau
	Inditifiant / nom du type : TABLEAU
	Types de base utilis�s et variables associ�es :
		- unsigned int taille : taille du tableau data
		- char* data : tableau � une dimension de caract�res
	Utilisation : Stockage du texte issu de fichiers texte (.txt)*/
typedef struct tableau {
	unsigned int  taille;
	char* data;
} TABLEAU;

/*TYPE COMPOSE : tableau_int
	Inditifiant / nom du type : TABLEAU_int
	Types de base utilis�s et variables associ�es :
		- unsigned int taille : taille du tableau data
		- unisigned int* data : tableau � une dimension d'entiers
	Utilisation : Stockage d'entiers (coordonn�es des pixels) pour le cryptage / decryptage � l'aide
	d'images pgm / ppm (voir les fonctions cryptage_image_pgm, cryptage_image_ppm, decryptage_image_pgm
	et decryptage_image_ppm)*/
typedef struct tableau_int {
	unsigned int  taille;
	unsigned int* data;
} TABLEAU_int;

/*TYPE COMPOSE : rgb
	Inditifiant / nom du type : RBG
	Types de base utilis�s et variables associ�es :
		- unsigned int R : Valeur du canal rouge
		- unsigned int G : Valeur du canal vert
		- unsigned int B : Valeur du canal bleu
	Utilisation : Repr�sent� les intensit�s des caneaux RGB dans le cas d'images ppm*/
typedef struct rgb {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

/*TYPE COMPOSE : imageRGB
	Inditifiant / nom du type : IMAGERBG
	Types de base utilis�s et variables associ�es :
		- unsigned int Nblig : Valeur du nombre de lignes de l'image
		- unsigned int Nbcol : Valeur du nombre de colonnes de l'image
		- RGB* data : tableau � une dimension permettant le stockage lin�aire des donn�es des diff�rents
		cannaux de l'image RGB
		- RGB** pixels : tableau � deux dimensions (matrice) permettant le stockage bi-dimensionnel des
		donn�es des diff�rents cannaux de l'image RGB pour y acc�der comme � l'aide des coordonn�es
	Utilisation : Stockage d'images ppm (couleur)*/
typedef struct imageRGB {
	unsigned int   Nblig;
	unsigned int   Nbcol;
	RGB*  data;
	RGB** pixel;
} IMAGERGB;

/*TYPE COMPOSE : image
	Inditifiant / nom du type : IMAGE
	Types de base utilis�s et variables associ�es :
		- unsigned int Nblig : Valeur du nombre de lignes de l'image
		- unsigned int Nbcol : Valeur du nombre de colonnes de l'image
		- unsigned char* data : tableau � une dimension permettant le stockage lin�aire des donn�es 
		de l'image NDG
		- unsigend char** pixels : tableau � deux dimensions (matrice) permettant le stockage 
		bi-dimensionnel des donn�es de l'image NDG pour y acc�der comme � l'aide des coordonn�es
	Utilisation : Stockage d'images pgm (niveau de gris)*/
typedef struct image {
	unsigned int   Nblig;
	unsigned int   Nbcol;
	unsigned char*  data;
	unsigned char** pixel;
} IMAGE;

/*D�clarations des fonctions*/

/*FONCTION : calloc_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU calloc_tableau(int n)
	Param�tre(s) d'entr�e : 
		- unsigned int n (taille du tableau)
	Param�tre de retour : 
		- TABLEAU (tableau allou� dynamiquement)
	Description : Permet l'allocation dynamique � 0 de tableaux destin�s au texte*/
TABLEAU calloc_tableau(unsigned int n);

/*FONCTION : calloc_tableau_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU_int calloc_tableau_int(int n)
	Param�tre(s) d'entr�e : 
		- unsigned int n (taille du tableau)
	Param�tre de retour : 
		- TABLEAU_int (tableau allou� dynamiquement)
	Description : Permet l'allocation dynamique � 0 de tableaux destin�s � des entiers*/
TABLEAU_int calloc_tableau_int(unsigned int n);

/*FONCTION : free_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_tableau(TABLEAU *pt)
	Param�tre(s) d'entr�e : 
		- TABLEAU *pt (adresse de la variable de type TABLEAU)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type TABLEAU*/
void free_tableau(TABLEAU *pt);

/*FONCTION : affichage_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void affichage_tableau(char tab[], int n)
	Param�tre(s) d'entr�e : 
		- char tab[] (donn�es, contenues dans un tableau � une dimension)
		- unsigned int n (taille du tableau)
	Param�tre de retour : void
	Description : Affichage d'un tableau de caract�res � des fins d'information ou de controle*/
void affichage_tableau(char tab[], unsigned int n);

/*FONCTION : affichage_tableau_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void affichage_tableau_int(int tab[], int n)
	Param�tre(s) d'entr�e : 
		- int tab[] (donn�es, contenues dans un tableau � une dimension)
		- unsigned int n (taille du tableau)
	Param�tre de retour : void
	Description : Affichage d'un tableau d'entiers � des fins d'information ou de controle*/
void affichage_tableau_int(int tab[], unsigned int n);

/*FONCTION : recup_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU recup_fichier(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- TABLEAU (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es (caract�res) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU*/
TABLEAU recup_fichier(const char *str);

/*FONCTION : recup_fichier_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU_int recup_fichier_int(const char *str)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- TABLEAU_int (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es (entiers) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU_int*/
TABLEAU_int recup_fichier_int(const char *str);

/*FONCTION : sauv_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void sauv_fichier(const char *str, TABLEAU tab)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier o� l'on va sauvegarder le TABLEAU)
		- TABLEAU tab (donn�es, carat�res � enregistrer)
	Param�tre de retour : void
	Description : Permet d'enregistrer les donn�es (caract�res) contenues dans un TABLEAU dans un fichier
	texte au format .txt*/
void sauv_fichier(const char *str, TABLEAU tab);

/*FONCTION : sauv_fichier_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void sauv_fichier_int(const char *str, TABLEAU_int tab)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier o� l'on va sauvegarder le TABLEAU_int)
		- TABLEAU_int tab (donn�es, entiers � enregistrer)
	Param�tre de retour : void
	Description : Permet d'enregistrer les donn�es (entiers) contenues dans un TABLEAU_int dans un fichier
	texte au format .txt*/
void sauv_fichier_int(const char *str, TABLEAU_int tab);

/*FONCTION : recup_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB recup_imageRGB(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- IMAGERGB (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es contenues dans un fichier image de type ppm et de les
	renseigner dans un IMAGERGB*/
IMAGERGB recup_imageRGB(const char *in);

/*FONCTION : free_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_imageRGB(IMAGERGB *m)
	Param�tre(s) d'entr�e :
		- IMAGERGB *m (adresse de la variable de type IMAGERGB)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type IMAGERGB*/
void free_imageRGB(IMAGERGB *m);

/*FONCTION : malloc_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB malloc_imageRGB(int Nblig, int Nbcol)
	Param�tre(s) d'entr�e :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Param�tre de retour :
		- IMAGERGB (image couleur allou�e dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destin�s a des images couleurs*/
IMAGERGB malloc_imageRGB(unsigned int Nblig, unsigned int Nbcol);

/*FONCTION : recup_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGE recup_image(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- IMAGE (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es contenues dans un fichier image de type pgm et de les
	renseigner dans un IMAGE*/
IMAGE recup_image(const char *in);

/*FONCTION : free_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_image(IMAGE *m)
	Param�tre(s) d'entr�e :
		- IMAGE *m (adresse de la variable de type IMAGE)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type IMAGE*/
void free_image(IMAGE *m);

/*FONCTION : malloc_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB malloc_image(int Nblig, int Nbcol)
	Param�tre(s) d'entr�e :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Param�tre de retour :
		- IMAGE (image couleur allou�e dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destin�s a des images niveau de gris*/
IMAGE malloc_image(unsigned int Nblig, unsigned int Nbcol);

/*FONCTION : detection_ppm_pgm
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : int detection_ppm_pgm(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � analyser)
	Param�tre de retour :
		- unsigned int (valeur retourn�e par la fonction d�pend du type d'image (pgm, ppm ou erreur))
	Description : Permet de detecter le type d'image entr� par l'utilisateur et si ce type est pris en
	charge par l'ordinateur*/
unsigned int detection_ppm_pgm(const char *in);

/*FONCTION : detection_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : int detection_fichier(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � analyser)
	Param�tre de retour :
		- int (valeur retourn�e par la fonction d�pend de l'existance du fichier)
	Description : Permet de detecter que le fichier entr� par l'utilisateur existe*/
int detection_fichier(const char *in);