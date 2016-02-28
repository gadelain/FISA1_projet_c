#include <stdio.h>
#include <stdlib.h>

#include "annexe.h"
#include "menu.h"
#include "cryptage.h"
#include "decryptage.h"

int main(void)
{
	TABLEAU recup = { 0, NULL };

	//recup = recup_fichier("test.txt");

	//free_tableau(&recup);
	menu_image_crypt();
	//decryptage_cesar("fichier_crypt.txt");

	//decryptage_image_pgm("fichier_crypt_image.txt", "key.txt");

	system("pause");
	return 0;
}