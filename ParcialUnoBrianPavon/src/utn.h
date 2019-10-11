/*
 * utn.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <stdlib.h>

#define QTY_CARACTERES 50

int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos);

float getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos);

char getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				char minimo,
				char maximo,
				int reintentos);

int initArrayInt(int array[],int limite,int valor );

int imprimeArrayInt(int array[],int limite );

int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int maximoArrayInt(int array[],int limite,int *pResultado);
int minimoArrayInt(int array[],int limite,int *pResultado);

int ordenarArrayInt(int array[],int limite );

int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos);

int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad);
int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad);



#endif /* UTN_H_ */
