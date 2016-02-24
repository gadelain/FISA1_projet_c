#pragma once
#define INC_ANNEXE_

typedef struct tableau {
	int  taille;
	char* data;
} TABLEAU;

TABLEAU calloc_tableau(int n);
void free_tableau(TABLEAU *pt);
void affichage_tableau(char tab[], int n);

TABLEAU recup_fichier(const char *str);
void sauv_fichier(const char *str, TABLEAU tab);