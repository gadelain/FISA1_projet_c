#pragma once
#define INC_DECRYPTAGE_

int decryptage_cesar(const char *str);
int decryptage_image_pgm(const char *str, const char *fichier_crypt, const char *key_crypt);
int decryptage_image_ppm(const char *str, const char *fichier_crypt, const char *key_crypt);