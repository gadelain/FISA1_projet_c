#include <stdio.h>
#include <stdlib.h>

#include "annexe.h"
#include "cryptage.h"
#include "decryptage.h"

int main(void)
{
	TABLEAU recup = { 0, NULL };

	//recup = recup_fichier("test.txt");

	//free_tableau(&recup);
	cryptage_cesar("fichier.txt");
	decryptage_cesar("fichier_crypt.txt");

	system("pause");
	return 0;
}