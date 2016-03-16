/*		===== Informations sur le fichier =====
Fichier : annexe.c (Source)
Repertoire : .../SRC/
Description : Fichier contenant les d�clarations des fonctions annexes au programme. Ces donn�es sont
indispensables au fonctionnement du programme. Elles permmettent :
	- Les manipulations de fichiers texte et images : r�cup�ration, sauvegarde, affichage, lib�ration
	- La d�tection du type d'image entr� par l'utilisateur (pgm ou ppm)
	- Le controle de l'exactitude des noms de fichiers
*/

/*Ent�tes pr�processeur*/
#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des commandes system pour Windows

#include "annexe.h" // Fichier header pour les annexes (voir le fichier pour description d�taill�es)

/*D�finition des fonctions*/

/*FONCTION : calloc_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU calloc_tableau(int n)
	Param�tre(s) d'entr�e : 
		- unsigned int n (taille du tableau)
	Param�tre de retour : 
		- TABLEAU (tableau allou� dynamiquement)
	Description : Permet l'allocation dynamique � 0 de tableaux destin�s au texte*/
TABLEAU calloc_tableau(unsigned int n)
{
	TABLEAU t = { 0, NULL }; 

	t.taille = n; // On reseigne le champ taille
	t.data = (char*)calloc(n, sizeof(char)); // On alloue dynamiquement le TABLEAU

	return t;
}

/*FONCTION : calloc_tableau_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU_int calloc_tableau_int(int n)
	Param�tre(s) d'entr�e : 
		- unsigned int n (taille du tableau)
	Param�tre de retour : 
		- TABLEAU_int (tableau allou� dynamiquement)
	Description : Permet l'allocation dynamique � 0 de tableaux destin�s � des entiers*/
TABLEAU_int calloc_tableau_int(unsigned int n)
{
	TABLEAU_int t = { 0, NULL }; // TABLEAU_int de retour allou� dynamiquement

	t.taille = 2*n; // Dans notre cas le champ data contiendra l'abscisse et l'ordonn�e de chacun des pixels 
					// utilis�s pour le cryptage. On dois donc avoir une taille deux fois plus grande que
					// le TABLEAU contenant notre texte. La taille de ce TABLEAU est pass� en param�tre.
	t.data = (int*)calloc((2*n), sizeof(int)); // On alloue dynamiquement le TABLEAU_int

	return t;
}

/*FONCTION : free_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_tableau(TABLEAU *pt)
	Param�tre(s) d'entr�e : 
		- TABLEAU *pt (adresse de la variable de type TABLEAU)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type TABLEAU*/
void free_tableau(TABLEAU *pt)
{
	if (pt->data != NULL)
	{
		free(pt->data); // On lib�re le champ data
	}
	pt->data = NULL;
	pt->taille = 0; // On met le champ taille � 0
}

/*FONCTION : free_tableau_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_tableau_int(TABLEAU_int *pt)
	Param�tre(s) d'entr�e :
		- TABLEAU *pt (adresse de la variable de type TABLEAU_int)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type TABLEAU_int*/
void free_tableau_int(TABLEAU_int *pt)
{
	if (pt->data != NULL)
	{
		free(pt->data); // On lib�re le champ data
	}
	pt->data = NULL;
	pt->taille = 0; // On met le champ taille � 0
}

/*FONCTION : recup_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU recup_fichier(const char *str)
	Param�tre(s) d'entr�e : 
		- const char *str (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- TABLEAU (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es (caract�res) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU*/
TABLEAU recup_fichier(const char *str)
{
	FILE* F;
	TABLEAU t = { 0, NULL }; // TABLEAU pour la r�cup�ration du fichier

	char car;
	char car2;
	unsigned int taille = 0;
	unsigned int i = 0;

	if ((F = fopen(str, "r")) == NULL)  // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{
		while (fscanf(F, "%c", &car) != EOF) // EOF : End Of File, on parcours le fichier jusqu'au caract�re non imprimable de fin
		{
			taille++; // On determine le nombre exact de caract�res
		}

		// On alloue dynamiquement notre variable t en fonction de la taille trouv�e pr�c�dement
		t = calloc_tableau(taille);

		fclose(F); // On ferme le flux
	}

	if ((F = fopen(str, "r")) == NULL) // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{

		while (fscanf(F, "%c", &car2) != EOF) // On parcours le fichier jusqu'au caract�re non imprimable de fin
		{
			t.data[i] = car2; // On rempli le tableau t.data avec les donn�es issu du fichier
			++i;
		}
		fclose(F); // On ferme le flux
	}


	return t;
}

/*FONCTION : recup_fichier_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : TABLEAU_int recup_fichier_int(const char *str)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- TABLEAU_int (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es (entiers) contenues dans un fichier texte et de les
	renseigner dans un TABLEAU_int*/
TABLEAU_int recup_fichier_int(const char *str)
{
	FILE* F;
	TABLEAU_int t = { 0, NULL }; // TABLEAU_int pour la r�cup�ration du fichier

	int car;
	int car2;
	unsigned int taille = 0;
	unsigned int i = 0;

	if ((F = fopen(str, "r")) == NULL) // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{
		while (fscanf(F, "%d;", &car) != EOF) // EOF : End Of File, on parcours le fichier jusqu'au caract�re non imprimable de fin
		{
			taille++; // On determine le nombre exact de caract�res
		}

		// On alloue dynamiquement notre variable t en fonction de la taille trouv�e pr�c�dement
		t = calloc_tableau_int(taille); 

		fclose(F); // On ferme le flux
	}

	if ((F = fopen(str, "r")) == NULL) // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{

		while (fscanf(F, "%d;", &car2) != EOF) // On parcours le fichier jusqu'au caract�re non imprimable de fin
		{
			t.data[i] = car2; // On rempli le tableau t.data avec les donn�es issu du fichier
			++i;
		}
		fclose(F); // On ferme le flux
	}

	return t;
}

/*FONCTION : sauv_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void sauv_fichier(const char *str, TABLEAU tab)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier o� l'on va sauvegarder le TABLEAU)
		- TABLEAU tab (donn�es, carat�res � enregistrer)
	Param�tre de retour : void
	Description : Permet d'enregistrer les donn�es (caract�res) contenues dans un TABLEAU dans un fichier
	texte au format .txt*/
void sauv_fichier(const char *str, TABLEAU tab)
{
	FILE* F;

	unsigned int taille = 0;
	unsigned int i = 0;

	if ((F = fopen(str, "w")) == NULL) // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{
		for (i = 0; i < tab.taille; i++)
		{
			fprintf(F, "%c", tab.data[i]); // On ecrit chaque caract�re dans le fichier
		}
		fclose(F); // On ferme le flux
	}
}

/*FONCTION : sauv_fichier_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void sauv_fichier_int(const char *str, TABLEAU_int tab)
	Param�tre(s) d'entr�e :
		- const char *str (chaine de caract�res, nom du fichier o� l'on va sauvegarder le TABLEAU_int)
		- TABLEAU_int tab (donn�es, entiers � enregistrer)
	Param�tre de retour : void
	Description : Permet d'enregistrer les donn�es (entiers) contenues dans un TABLEAU_int dans un fichier
	texte au format .txt*/
void sauv_fichier_int(const char *str, TABLEAU_int tab)
{
	FILE* F;

	unsigned int taille = 0;
	unsigned int i = 0;

	if ((F = fopen(str, "w")) == NULL) // On teste le flux
	{
		printf("Erreur � l'ouverture"); // Cas erreur
	}
	else
	{
		for (i = 0; i < tab.taille; i++)
		{
			fprintf(F, "%d;", tab.data[i]); // On �crit chaque entier s�par� par un point virgule
		}
		fclose(F); // On ferme le flux
	}
}

/*FONCTION : affichage_tableau
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void affichage_tableau(char tab[], int n)
	Param�tre(s) d'entr�e : 
		- char tab[] (donn�es, contenues dans un tableau � une dimension)
		- unsigned int n (taille du tableau)
	Param�tre de retour : void
	Description : Affichage d'un tableau de caract�res � des fins d'information ou de controle*/
void affichage_tableau(char tab[], int n)
{
	int i, sautLigne;

	printf("\n-----\n");
	for (i = 0, sautLigne = 1; i<n; i++, sautLigne++)
	{
		printf("%c", tab[i]);
		if (sautLigne % 100 != 0)
			printf(""); // Evite les espaces entres les lettres
		else
			printf("\n");
	}
	printf("\n-----\n");
}

/*FONCTION : affichage_tableau_int
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void affichage_tableau_int(int tab[], int n)
	Param�tre(s) d'entr�e : 
		- int tab[] (donn�es, contenues dans un tableau � une dimension)
		- unsigned int n (taille du tableau)
	Param�tre de retour : void
	Description : Affichage d'un tableau d'entiers � des fins d'information ou de controle*/
void affichage_tableau_int(int tab[], int n)
{
	int i, sautLigne;

	printf("\n-----\n");
	for (i = 0, sautLigne = 1; i<n; i++, sautLigne++)
	{
		printf("%d", tab[i]);
		if (sautLigne % 10 != 0)
			printf("\t"); // Tabulation
		else
			printf("\n");
	}
	printf("\n-----\n");
}

/*FONCTION : recup_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB recup_imageRGB(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- IMAGERGB (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es contenues dans un fichier image de type ppm et de les
	renseigner dans un IMAGERGB*/
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

						/* lecture caract�re apr�s caract�re compte-tenu de la diversit� des ent�tes possibles */
						fscanf(F,"%c",&type[0]); 
						fscanf(F,"%c",&type[1]); 
						fscanf(F,"%c",&buf); /* caract�re espacement */

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilit� d'utiliser �galement isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf);
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
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
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}
						
						/* d�but des data */

						printf("Lecture image RGB type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = malloc_imageRGB(img.Nblig,img.Nbcol);

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

						/* lecture caract�re apr�s caract�re compte-tenu de la diversit� des ent�tes possibles */
						type[0] = fgetc(F); 
						type[1] = fgetc(F);  
						buf = fgetc(F); /* caract�re espacement */

						buf = fgetc(F);  
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilit� d'utiliser �galement isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
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
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							buf = fgetc(F); 
						}
						
						/* d�but des data */

						printf("Lecture image RGB type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = malloc_imageRGB(img.Nblig,img.Nbcol);

						/* lecture d'un bloc */
						fread(img.data,sizeof(RGB),img.Nbcol*img.Nblig,F);
						}
					else
						printf("Format non supporte pour l'instant...\n");
		fclose(F);
		}
	return img;
}

/*FONCTION : free_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_imageRGB(IMAGERGB *m)
	Param�tre(s) d'entr�e :
		- IMAGERGB *m (adresse de la variable de type IMAGERGB)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type IMAGERGB*/
void free_imageRGB(IMAGERGB *m)
{
	if (m->data != NULL) {
		free(m->data); // On lib�re le champ data
		m->data = NULL;
	}
	if (m->pixel != NULL) {
		free(m->pixel); // On lib�re le champ pixel
		m->pixel = NULL;
	}
}

/*FONCTION : malloc_imageRGB
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB malloc_imageRGB(int Nblig, int Nbcol)
	Param�tre(s) d'entr�e :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Param�tre de retour :
		- IMAGERGB (image couleur allou�e dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destin�s a des images couleurs*/
IMAGERGB malloc_imageRGB(unsigned int Nblig, unsigned int Nbcol)
{
	IMAGERGB mat = {0,0,NULL,NULL};
	int i;

	mat.Nblig = Nblig; // On renseigne le champ nombre de lignes
	mat.Nbcol = Nbcol; // On renseigne le champ nombre de colonnes
	// On alloue dynamiquement le champ data en fonction du nombre de lignes et du nombres de colonnes
	mat.data = (RGB*)malloc(Nblig*Nbcol*sizeof(RGB));
	if (mat.data == NULL)
		return(mat);
	// On alloue dynamiquement le champ pixel en fonction du nombre de lignes et du nombres de colonnes
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

/*FONCTION : recup_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGE recup_image(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � r�cup�rer)
	Param�tre de retour : 
		- IMAGE (dimensionn� et rempli avec les donn�es issues du fichier)
	Description : Permet de r�cup�rer les donn�es contenues dans un fichier image de type pgm et de les
	renseigner dans un IMAGE*/
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

						/* lecture caract�re apr�s caract�re compte-tenu de la diversit� des ent�tes possibles */
						fscanf(F,"%c",&type[0]); 
						fscanf(F,"%c",&type[1]); 
						fscanf(F,"%c",&buf); /* caract�re espacement */

						fscanf(F,"%c",&buf); 
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilit� d'utiliser �galement isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}

						fscanf(F,"%c",&buf);
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
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
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								fscanf(F,"%c",&buf);
							fscanf(F,"%c",&buf);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							fscanf(F,"%c",&buf); 
						}
						
						/* d�but des data */

						printf("Lecture image NG type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = malloc_image(img.Nblig,img.Nbcol);

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

						/* lecture caract�re apr�s caract�re compte-tenu de la diversit� des ent�tes possibles */
						type[0] = fgetc(F); 
						type[1] = fgetc(F);  
						buf = fgetc(F); /* caract�re espacement */

						buf = fgetc(F);  
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) { /* possibilit� d'utiliser �galement isdigit de la librairie standard <ctype.h> */
							img.Nbcol = img.Nbcol*10 + (buf -'0');
							buf = fgetc(F); 
						}

						buf = fgetc(F);
						if (buf == '#') {
							/* on ignore tout jusqu'� trouver '\n' */
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
							/* on ignore tout jusqu'� trouver '\n' */
							while (buf != '\n') 
								buf = fgetc(F);
							buf = fgetc(F);
						}
						while (((buf-'0') >= 0) && ((buf-'0') <= 9)) {
							dynamique = dynamique*10 + (buf -'0');
							buf = fgetc(F); 
						}
						
						/* d�but des data */

						printf("Lecture image NG type %s avec %d lignes et %d colonnes...\n",type,img.Nblig,img.Nbcol);
					
						/* taille connue, allocation dynamique possible */
						img = malloc_image(img.Nblig,img.Nbcol);

						/* lecture d'un bloc */
						fread(img.data,sizeof(unsigned char),img.Nbcol*img.Nblig,F);
						}
					else
						printf("Format non supporte pour l'instant...\n");
		fclose(F);
		}
	return img;
}

/*FONCTION : free_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : void free_image(IMAGE *m)
	Param�tre(s) d'entr�e :
		- IMAGE *m (adresse de la variable de type IMAGE)
	Param�tre de retour : void
	Description : Lib�ration de l'espace m�moire pour le type IMAGE*/
void free_image(IMAGE *m)
{
	if (m->data != NULL) {
		free(m->data); // On lib�re le champ data
		m->data = NULL;
	}
	if (m->pixel != NULL) {
		free(m->pixel); // On lib�re le champ pixel
		m->pixel = NULL;
	}
}

/*FONCTION : malloc_image
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : IMAGERGB malloc_image(int Nblig, int Nbcol)
	Param�tre(s) d'entr�e :
		- unsigend int Nblig (nombre de lignes de l'image)
		- unsigned int Nbcol (nombre de colonnes de l'image)
	Param�tre de retour :
		- IMAGE (image couleur allou�e dynamiquement)
	Description : Permet l'allocation dynamique (malloc) de matrices destin�s a des images niveau de gris*/
IMAGE malloc_image(unsigned int Nblig, unsigned int Nbcol)
{
	IMAGE mat = {0,0,NULL,NULL};
	int i;

	mat.Nblig = Nblig; // On renseigne le champ nombre de lignes
	mat.Nbcol = Nbcol; // On renseigne le champ nombre de colonnes
	// On alloue dynamiquement le champ data en fonction du nombre de lignes et du nombres de colonnes
	mat.data = (unsigned char*)malloc(Nblig*Nbcol*sizeof(unsigned char)); 
	if (mat.data == NULL)
		return(mat);
	// On alloue dynamiquement le champ pixel en fonction du nombre de lignes et du nombres de colonnes
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

/*FONCTION : detection_ppm_pgm
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : int detection_ppm_pgm(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � analyser)
	Param�tre de retour :
		- unsigned int (valeur retourn�e par la fonction d�pend du type d'image (pgm, ppm ou erreur))
	Description : Permet de detecter le type d'image entr� par l'utilisateur et si ce type est pris en
	charge par l'ordinateur*/
unsigned int detection_ppm_pgm(const char *in)
{
	unsigned int i = 0;

	while (in[i] != '.') // On parcours le nom du fichier jusqu'au point d'extension
	{
		i++; // On incr�mente i jusqu'au point d'extension
	}
	
	if (in[i + 1] == 'p') // Detection du premier "p" de "p"pm ou "p"gm
	{
		if (in[i + 2] == 'p') // Detection du second "p" de p"p"m
		{
			return 1; // Cas o� le fichier est un ppm
		}
		else if (in[i + 2] == 'g') // Detection du second "p" de p"g"m
		{
			return 2; // Cas o� le fichier est un pgm
		}
		else
		{
			return 3; // Cas d'erreur
		}
	}

	else
	{
		return 3; // Cas d'erreur
	}
}

/*FONCTION : detection_fichier
	Fichier : (d�claration) annexe.h, (d�finition) annexe.c
	Prototype : int detection_fichier(const char *in)
	Param�tre(s) d'entr�e :
		- const char *in (chaine de caract�res, nom du fichier � analyser)
	Param�tre de retour :
		- int (valeur retourn�e par la fonction d�pend de l'existance du fichier)
	Description : Permet de detecter que le fichier entr� par l'utilisateur existe*/
int detection_fichier(const char *in)
{
	FILE *F = NULL;

	if ((F = fopen(in, "r")) == NULL) // Test d'ouverture du flux
	{
		printf("Erreur fichier inexistant !\n");
		return -1; // Cas erreur -> retour -1
	}

	return 0; // Cas correct -> retour 0

}