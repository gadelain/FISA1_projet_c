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
#define INC_MENU_ // Flag pour la compilation

/*Déclarations des fonctions*/

/*FONCTION : menu_cryptage
	Fichier : (déclaration) annexe.h, (définition) annexe.c
	Prototype : TABLEAU calloc_tableau(int n)
	Paramètre(s) d'entrée : 
		- unsigned int n (taille du tableau)
	Paramètre de retour : 
		- TABLEAU (tableau alloué dynamiquement)
	Description : Permet l'allocation dynamique à 0 de tableaux destinés au texte*/
int menu_cryptage(void);
int menu_decryptage(void);

int menu_cesar_crypt(void);

int menu_clef(void);

int menu_image_crypt(const char *str);
int menu_image_decrypt(const char *str);

int menu_annexe(void);