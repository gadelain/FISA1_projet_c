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
#define INC_MENU_ // Flag pour la compilation

/*D�clarations des fonctions*/

/*FONCTION : menu_cryptage
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU calloc_tableau(int n)
	Param�tre(s) d'entr�e : 
		- unsigned int n (taille du tableau)
	Param�tre de retour : 
		- TABLEAU (tableau allou� dynamiquement)
	Description : Permet l'allocation dynamique � 0 de tableaux destin�s au texte*/
int menu_cryptage(void);
int menu_decryptage(void);

int menu_cesar_crypt(void);

int menu_clef(void);

int menu_image_crypt(const char *str);
int menu_image_decrypt(const char *str);

int menu_annexe(void);