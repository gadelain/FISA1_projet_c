#pragma once
#define INC_ANNEXE_

typedef struct tableau {
	int  taille;
	char* data;
} TABLEAU;

typedef struct rgb {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

typedef struct imageRGB {
	int   Nblig;
	int   Nbcol;
	RGB*  data;
	RGB** pixel;
} IMAGERGB;

typedef struct image {
	int   Nblig;
	int   Nbcol;
	unsigned char*  data;
	unsigned char** pixel;
} IMAGE;


TABLEAU calloc_tableau(int n);
void free_tableau(TABLEAU *pt);
void affichage_tableau(char tab[], int n);

TABLEAU recup_fichier(const char *str);
void sauv_fichier(const char *str, TABLEAU tab);

IMAGERGB recup_imageRGB(const char *in);
void free_imageRGB(IMAGERGB *m);
IMAGERGB malloc_imageRGB(int Nblig, int Nbcol);

IMAGE recup_image(const char *in);
void free_image(IMAGE *m);
IMAGE malloc_image(int Nblig, int Nbcol);

int detection_ppm_pgm(const char *in);
