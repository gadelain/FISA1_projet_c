#include <stdio.h>
#include <stdlib.h>

#include "decryptage.h"
#include "annexe.h"

int decryptage_cesar(const char *str)
{
	TABLEAU cesar = { 0, NULL };

	int choix = 0;
	int chiffre_cesar = 0;
	int i = 0;

	cesar = recup_fichier(str);

	choix = menu_cesar_crypt();

	switch (choix)
	{
	case 1:
		system("cls");
		printf("Entrer le chiffre de Cesar :\n");
		scanf("%d", &chiffre_cesar);

		for (i = 0; i < cesar.taille; i++)
		{
			cesar.data[i] = cesar.data[i] - chiffre_cesar;
		}

		sauv_fichier("fichier_decrypt.txt", cesar);

		system("pause");

		return 0;
		break;
	case 2:
		return 0;
		break;
	default:
		return -1;
		break;
	}
}

int decryptage_image_pgm(const char *fichier_crypt, const char *key_crypt)
{
	TABLEAU texte = { 0, NULL };
	TABLEAU_int key = { 0, NULL };

	texte = recup_fichier(fichier_crypt);
	key = recup_fichier_int(key_crypt);


}
