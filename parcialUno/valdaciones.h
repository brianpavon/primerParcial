#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INPUT_BUFFER 4096


int validarInt(char *buffer);
int validarStringLetras(char *buffer);
int esNumeroTelefonico(char *buffer);
int esFloat(char *buffer);


#endif /* VALIDACIONES_H_ */
