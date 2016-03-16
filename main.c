/*			===== FISA 1 - Projet C - Cryptage / Décryptage =====
	Groupe : ADELAIN Guillaume (Chef de projet) - guillaume.adelain@telecom-st-etienne.fr
			 DURANTET Mathieu - mathieu.durantet@telecom-st-etienne.fr
			 ODORICO Matthieu - matthieu.odorico@telecom-st-etienne.fr
	Plateforme : Windows uniquement
	IDE : Microsoft Visual Studio Community 2015
	Codes source : Disponibles librement sur Github (https://github.com/gadelain/FISA1_projet_c)
		- Fichiers .c : annexe.c, cryptage.c, decryptage.c, main.c, menu.c
		- Fichiers .h : annexe.h, cryptage.h, decryptage.h, menu.h
		- Fichier annexe indispensable : default.ppm
	Problèmatique : Crypter et décrypter un fichier texte au format .txt selon trois méthodes :
		- Cryptage dit "Chiffre de César"
		- Cryptage par clé
		- Cryptage à l'aide d'images ppm / pgm
*/

/*		===== Informations sur le fichier =====
Fichier : main.c (Source)
Repertoire : .../Devs/
Description : Fichier main, point de départ et de fin du programme
*/

/*Entêtes préprocesseur*/
#include <stdio.h> // Gestion des I/O
#include <stdlib.h> // Gestion des commandes system pour Windows

#include "menu.h" // Fichier header pour les menus (voir le fichier pour description détaillées)

/*FONCTION : main
	Fichier : main.c
	Prototype : int main(void)
	Paramètre(s) d'entrée : void
	Paramètre de retour : 
		- int (permet le controle de la bonne execution dans l'IDE)
	Description : Fonction principale, contient le menu principal utile pour accéder à l'ensemble des 
	fonctionaitées du programme*/
int main(void)
{
	/*Variables de types classiques*/
	int retour_menu = 0; // Variable de controle des retours / detection des erreurs
	int watchdog = 0; // Variable pour la boucle principale
	unsigned int choix = 0;

	while (watchdog != 1)
	{
		system("cls");

		while (choix < 1 || choix > 4) // Condition pour le contrôle des valeurs entrées
		{
			// Menu
			printf("===== Projet C FISA 1 : Cryptage / Decryptage =====\n");
			printf("1 - Cryptage\n");
			printf("2 - Decryptage\n");
			printf("3 - Annexe / aide\n");
			printf("4 - Quitter le programme\n\n");
			scanf_s("%d", &choix);
			getchar(); // Attente d'une saisie clavier, permet d'éviter une boucle infinie en cas de saisie d'une lettre par l'utilisateur 

			if (choix < 1 || choix > 4) // Condition le contrôle des valeurs entrées
			{
				system("cls");
				printf("Erreur : vous n'avez pas entre un choix correct\n\n");
				choix = 0; // Reset du choix entré
			}
		}

		switch (choix) // A ce stade on est certain que choix est correct
		{
		case 1:
			system("cls");
			retour_menu = menu_cryptage();// Menu lié aux algorithmes de cryptage
			if (retour_menu != 0) // Controle de la bonne execution des algorithmes de cryptage
			{
				printf("Erreur dans l'execution du programme\n");
			}
			choix = 0; // Reset du choix entré
			break;
		case 2:
			system("cls");
			retour_menu = menu_decryptage(); // Menu lié aux algorithmes de decryptage
			if (retour_menu != 0)
			{
				printf("Erreur dans l'execution du programme\n"); // Controle de la bonne execution des algorithmes de decryptage
			}
			choix = 0; // Reset du choix entré
			break;
		case 3:
			system("cls");
			retour_menu = menu_annexe(); // Menu lié aux fonctions annexes
			if (retour_menu != 0)
			{
				printf("Erreur dans l'execution du programme\n"); // Controle de la bonne execution
			}
			choix = 0; // Reset du choix entré
			break;
		case 4:
			watchdog = 1; // Mise à jour du watchdog pour sortie du programme
			break;
		default:
			return -1; // Erreur dans l'execution du programme
			break;
		}

	}

	return 0;
}