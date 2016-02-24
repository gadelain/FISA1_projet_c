#include <stdio.h>
#include <stdlib.h>

#include "annexe.h"

int main(void)
{
	TABLEAU recup = { 0, NULL };

	recup = recup_fichier("test.txt");

	//free_tableau(&recup);

	system("pause");
	return 0;
}