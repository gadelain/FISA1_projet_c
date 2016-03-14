#pragma once
#define INC_CRYPTAGE_

int cryptage_cesar(const char *str);
int cryptage_clef(const char *str);
int cryptage_image(const char *str);


int cryptage_image_ppm(const char *str, const char *fichier);
int cryptage_image_pgm(const char *str, const char *fichier);
