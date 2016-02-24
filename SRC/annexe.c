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
		for (int i = 0; i < tab.taille; i++)
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