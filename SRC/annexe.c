#include <stdio.h>
#include <stdlib.h>

#include "annexe.h"

TABLEAU calloc_tableau(int n)
{
	TABLEAU t = { 0, NULL }; 

	t.taille = n;
	t.data = (char*)calloc(n, sizeof(char));

	return t;
}

void free_tableau(TABLEAU *pt)
{
	if (pt->data != NULL)
	{
		free(pt->data);
	}
	pt->data = NULL;
	pt->taille = 0;
}

TABLEAU recup_fichier(const char *str)
{
	FILE* F;
	TABLEAU t = { 0, NULL };

	char car;
	char car2;
	int taille = 0;
	int i = 0;

	if ((F = fopen(str, "r")) == NULL) 
	{
		printf("Erreur à l'ouverture");
	}
	else
	{
		while (fscanf(F, "%c", &car) != EOF)
		{
			taille++;
		}

		t = calloc_tableau(taille);

		fclose(F);
	}

	if ((F = fopen(str, "r")) == NULL)
	{
		printf("Erreur à l'ouverture");
	}
	else
	{

		while (fscanf(F, "%c", &car2) != EOF)
		{
			t.data[i] = car2;
			++i;
		}
		fclose(F);
	}


	return t;
}

void sauv_fichier(const char *str, TABLEAU tab)
{
	FILE* F;
	TABLEAU t = { 0, NULL };

	char car;
	char car2;
	int taille = 0;
	int i = 0;

	if ((F = fopen(str, "w")) == NULL)
	{
		printf("Erreur à l'ouverture");
	}
	else
	{
		for (i = 0; i < tab.taille; i++)
		{
			fprintf(F, "%c", tab.data[i]);
		}
		fclose(F);
	}
}


void affichage_tableau(char tab[], int n)
{
	int i, sautLigne;

	printf("\n-----\n");
	for (i = 0, sautLigne = 1; i<n; i++, sautLigne++)
	{
		printf("%c", tab[i]);
		if (sautLigne % 10 != 0)
			printf("\t");
		else
			printf("\n");
	}
	printf("\n-----\n");
}

IMAGERGB recup_imageRGB(const char *in)
{
	FILE *F = NULL;
	IMAGERGB img = {0,0,NULL};
	int dynamique = 0;

	if ( (F = fopen(in,"r")) == NULL)
		{
			printf("ERREUR : l'image selectionnee ne correspond pas aux criteres\n");
		}
	else 
		{
			char type[3];

			fgets(type,3,F);
			fclose (F);
			/* selon le type ouverture binaire ou texte */
			if (strcmp(type,"P3") == 0)  /* cas ASCII couleur */
					{
						char tmp[255]="";
						char buf;
						
						F = fopen(in,"r");

						/* lecture caractère après caractère compte-tenu de la diversité des entêtes possibles */
						fscanf(F,"%c",&type[0]); 
						fscanf(F,"%c",&type[1]); 
						fscanf(F,"%c",&buf); /* caractère espacement */

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilité d'utiliser également isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							img.Nblig = img.Nblig*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}
						
						/* début des data */

						printf("Lecture image RGB type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = allocationImageRGB(img.Nblig,img.Nbcol);

						/* lecture pixel par pixel */
						{
						int i,j;
						int tmp;

						for (i=0;i<img.Nblig;i++)
							for (j=0;j<img.Nbcol;j++)
							{
								fscanf(F,"%d",&tmp);
								img.pixel[i][j].R =(unsigned char)tmp;
								fscanf(F,"%d",&tmp);
								img.pixel[i][j].G =(unsigned char)tmp;
								fscanf(F,"%d",&tmp);
								img.pixel[i][j].B =(unsigned char)tmp;
							}
						}
					}
				else
					if (strcmp(type,"P6") == 0)  /* cas brut couleur */
						{
						char buf;
						
						F = fopen(in,"rb");

						/* lecture caractère après caractère compte-tenu de la diversité des entêtes possibles */
						type[0] = fgetc(F); 
						type[1] = fgetc(F);  
						buf = fgetc(F); /* caractère espacement */

						buf = fgetc(F);  
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilité d'utiliser également isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							img.Nblig = img.Nblig*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							buf = fgetc(F); 
						}
						
						/* début des data */

						printf("Lecture image RGB type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = allocationImageRGB(img.Nblig,img.Nbcol);

						/* lecture d'un bloc */
						fread(img.data,sizeof(RGB),img.Nbcol*img.Nblig,F);
						}
					else
						printf("Format non supporte pour l'instant...\n");
		fclose(F);
		}
	return img;
}

void free_imageRGB(IMAGERGB *m)
{
	if (m->data != NULL) {
		free(m->data);
		m->data = NULL;
	}
	if (m->pixel != NULL) {
		free(m->pixel);
		m->pixel = NULL;
	}
}

IMAGERGB malloc_imageRGB(int Nblig, int Nbcol)
{
	IMAGERGB mat = {0,0,NULL,NULL};
	int i;

	mat.Nblig = Nblig;
	mat.Nbcol = Nbcol;
	mat.data = (RGB*)malloc(Nblig*Nbcol*sizeof(RGB));
	if (mat.data == NULL)
		return(mat);
	mat.pixel = (RGB**)malloc(Nblig*sizeof(RGB*));
	if (mat.pixel == NULL) {
		free(mat.data);
		mat.data = NULL;
		return(mat);
	}
	for (i=0;i<Nblig;i++)
		mat.pixel[i] = &(mat.data[i*Nbcol]);

	return(mat);
}

IMAGE recup_image(const char *in)
{
	FILE *F = NULL;
	IMAGE img = {0,0,NULL};
	int dynamique = 0;

	if ( (F = fopen(in,"r")) == NULL)
		{
			printf("Pb image inexistante");
		}
	else 
		{
			char type[3];

			fgets(type,3,F);
			fclose (F);
			/* selon le type ouverture binaire ou texte */
			if (strcmp(type,"P2") == 0)  /* cas ASCII niveaux de gris */
					{
						char buf;
						
						F = fopen(in,"r");

						/* lecture caractère après caractère compte-tenu de la diversité des entêtes possibles */
						fscanf(F,"%c",&type[0]); 
						fscanf(F,"%c",&type[1]); 
						fscanf(F,"%c",&buf); /* caractère espacement */

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilité d'utiliser également isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							img.Nblig = img.Nblig*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}
						
						/* début des data */

						printf("Lecture image NG type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = allocationImage(img.Nblig,img.Nbcol);

						/* lecture pixel par pixel */
						{
						int i,j;
						int tmp;

						for (i=0;i<img.Nblig;i++)
							for (j=0;j<img.Nbcol;j++)
							{
								fscanf(F,"%d",&tmp);
								img.pixel[i][j] =(unsigned char)tmp;
							}
						}
					}
				else
					if (strcmp(type,"P5") == 0)  /* cas brut niveaux de gris */
						{
						char buf;
						
						F = fopen(in,"rb");

						/* lecture caractère après caractère compte-tenu de la diversité des entêtes possibles */
						type[0] = fgetc(F); 
						type[1] = fgetc(F);  
						buf = fgetc(F); /* caractère espacement */

						buf = fgetc(F);  
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilité d'utiliser également isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							img.Nblig = img.Nblig*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'à trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							buf = fgetc(F); 
						}
						
						/* début des data */

						printf("Lecture image NG type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = allocationImage(img.Nblig,img.Nbcol);

						/* lecture d'un bloc */
						fread(img.data,sizeof(unsigned char),img.Nbcol*img.Nblig,F);
						}
					else
						printf("Format non supporte pour l'instant...\n");
		fclose(F);
		}
	return img;
}

void free_image(IMAGE *m)
{
	if (m->data != NULL) {
		free(m->data);
		m->data = NULL;
	}
	if (m->pixel != NULL) {
		free(m->pixel);
		m->pixel = NULL;
	}
}

IMAGE malloc_image(int Nblig, int Nbcol)
{
	IMAGE mat = {0,0,NULL,NULL};
	int i;

	mat.Nblig = Nblig;
	mat.Nbcol = Nbcol;
	mat.data = (unsigned char*)malloc(Nblig*Nbcol*sizeof(unsigned char));
	if (mat.data == NULL)
		return(mat);
	mat.pixel = (unsigned char**)malloc(Nblig*sizeof(unsigned char*));
	if (mat.pixel == NULL) {
		free(mat.data);
		mat.data = NULL;
		return(mat);
	}
	for (i=0;i<Nblig;i++)
		mat.pixel[i] = &mat.data[i*Nbcol];

	return(mat);
}

int detection_ppm_pgm(const char *in)
{
	int i = 0;
	
	for(i=0; in[i] != "."; i++)
	
	if(in[i+2] == "g")
	{
		return 1;
	}
	else if(in[i+2] == "p")
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
