#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define QTY_CARACTERES 50

 /**
 * \brief obtiene un entero y lo asigna a una variable
 * \param variable que se pasa como puntero a la que se le asignara el numero obtenido
 * \param mensaje que cargara el usuario de acuerdo a la necesidad
 * \param mensaje de error en caso de no cumplir con los requerimientos
 * \param rango minimo para obtener el entero
 * \param rango maximo para obtener el entero
 * \param cantidad de veces que se buscara el entero en caso que haya algun error
 * \return devuelve el entero que se ingreso
 *
 */
int getInt(	int *resultado,
			char *mensaje,
			char *mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%d",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}
/**
 * \brief obtiene un float y lo asigna a una variable
 * \param variable que se pasa como puntero a la que se le asignara el numero obtenido
 * \param mensaje que cargara el usuario de acuerdo a la necesidad
 * \param mensaje de error en caso de no cumplir con los requerimientos
 * \param rango minimo para obtener el float
 * \param rango maximo para obtener el float
 * \param cantidad de veces que se solicitara el float en caso que haya algun error
 * \return devuelve el float que se ingreso
 *
 */
float getFloat(	float *resultado,
				char *mensaje,
				char *mensajeError,
				float minimo,
				float maximo,
				int reintentos)
{
	int retorno = -1;
	float buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%f",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}

 /**
 * \brief obtiene un caracter y lo asigna a una variable
 * \param variable que se pasa como puntero a la que se le asignara el caracter obtenido
 * \param mensaje que cargara el usuario de acuerdo a la necesidad
 * \param mensaje de error en caso de no cumplir con los requerimientos
 * \param rango minimo para obtener el caracter
 * \param rango maximo para obtener el caracter
 * \param cantidad de veces que se solicitara el caracter en caso que haya algun error
 * \return devuelve el caracter que se ingreso
 *
 */
char getChar(	char *resultado,
				char *mensaje,
				char *mensajeError,
				char minimo,
				char maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer;
	if(	resultado != NULL &&
		mensaje != NULL &&
		mensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
		{
			do
			{
				printf("%s",mensaje);
				fflush(stdin);//__fpurge(stdin);
				if(scanf("%c",&buffer)==1)
				{
					if(buffer >= minimo && buffer <= maximo)
					{
						retorno = 1;
						*resultado = buffer;
						break;
					}
				}
				printf("%s",mensajeError);
				reintentos--;
			}while(reintentos >= 0);
		}

		return retorno;
}

 /**
 * \brief inicializa el array de enteros
 * \param array a inicializar
 * \param cantidad maxima de elementos
 * \param valor desde el cual se inicializara
 * \return Si se pudo realizar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int initArrayInt(int array[],int limite,int valor )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			array[i]=valor+i;
		}

	}
	return retorno;
}
/**
 * \brief imprime el array de enteros
 * \param array de enteros
 * \param cantidad maxima de elementos
 * \return Si se pudo realizar devuelve un 0, como señal de OK y se imprime los elementos por pantalla, sino devuelve -1
 *
 */
int imprimeArrayInt(int array[],int limite )
{
	int i;
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		printf("\n\n-------\n");
		for(i=0;i<limite;i++)
		{
			printf("%d\n",array[i]);
		}

	}
	return retorno;
}
 /**
 * \brief obtiene los elementos de un array de enteros
 * \param array del cual se obtendran los elementos
 * \param mensaje que cargara el usuario de acuerdo a la necesidad
 * \param mensaje de error en caso de no cumplir con los requerimientos
 * \param rango minimo del vector
 * \param rango maximo del vector
 * \param cantidad de veces que se solicitara el array de enteros en caso que haya algun error
 * \return devuelve los elementos que estan en el array de enteros,con un 0 en señal de OK, sino devuelve -1 en señal de error
 *
 */
int getArrayInt(	int array[],
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int i=0;
	int buffer;
	char respuesta = 'n';
	int retorno = -1;
	if(array != NULL && limite > 0)
	{
		do
		{
			if(getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				array[i] = buffer;
				i++;
				limite--;
			}
			printf("Continuar? (s/n)");
			fflush(stdin);//__fpurge(stdin);
			scanf("%c",&respuesta);
		}while(respuesta == 's' && limite > 0);
		retorno = i;
	}
	return retorno;
}

 /**
 * \brief obtiene el maximo en un array de enteros
 * \param array del cual se obtendran los elementos
 * \param cantidad maxima de elementos del array de enteros
 * \param direccion de memoria de la variable a la que se le asignara el valor obtenido
 * \return devuelve la posicion y/o el valor del maximo del array,con un 0 en señal de OK, sino devuelve -1 en señal de error
 *
 */

int maximoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int maximo;
	int posMaximo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		maximo = array[0];
		posMaximo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]>maximo)
			{
				maximo = array[i];
				posMaximo=i;
			}
		}
		*pResultado = posMaximo;
	}
	return retorno;
}

 /**
 * \brief obtiene el minimo en un array de enteros
 * \param array del cual se obtendran los elementos
 * \param cantidad maxima de elementos del array de enteros
 * \param direccion de memoria de la variable a la que se le asignara el valor obtenido
 * \return devuelve la posicion y/o el valor del minimo del array,con un 0 en señal de OK, sino devuelve -1 en señal de error
 *
 */

int minimoArrayInt(int array[],int limite,int *pResultado)
{
	int i;
	int retorno = -1;
	int minimo;
	int posMinimo;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		minimo = array[0];
		posMinimo = 0;
		for(i=1;i<limite;i++)
		{
			if(array[i]<minimo)
			{
				minimo = array[i];
				posMinimo=i;
			}
		}
		*pResultado = posMinimo;
	}
	return retorno;
}

 /**
 * \brief ordena los elementos de un array de enteros de manera ascendente
 * \param array del cual se obtendran los elementos
 * \param cantidad maxima de elementos del array de enteros
 * \return devuelve un 0 en señal de que realizo el ordenamiento de elementos
 *
 */

int ordenarArrayInt(int array[],int limite )
{
	int i;
	int flagSwap;
	int retorno = -1;
	int bufferInt;
	if(array != NULL && limite > 0)
	{
		retorno = 0;
		do
		{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i] > array[i+1])
				{
					flagSwap = 1;
					bufferInt = array[i];
					array[i] = array[i+1];
					array[i+1]=bufferInt;
				}
			}
		}while(flagSwap);
	}
	return retorno;
}

/**
 * \brief obtiene un string y lo asigna a una variable
 * \param variable a la que se le asignara el string obtenido
 * \param mensaje que cargara el usuario de acuerdo a la necesidad
 * \param mensaje de error en caso de no cumplir con los requerimientos
 * \param rango minimo de caracteres del string
 * \param rango maximo de caracteres del string
 * \param cantidad de veces que se solicitara el ingreso de string en caso que haya algun error
 * \return devuelve el string que se cargo, con un 0 en señal de que salio todo OK, sino devuelve -1
 *
 */
int getString(	char *pResultado,
				char *pMensaje,
				char *pMensajeError,
				int minimo,
				int maximo,
				int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(	pResultado != NULL &&
		pMensaje != NULL &&
		pMensajeError != NULL &&
		minimo <= maximo &&
		reintentos >= 0)
	{
		do
			{
				printf("%s",pMensaje);
				fflush(stdin);//__fpurge(stdin);
				fgets(buffer,sizeof(buffer),stdin);
				buffer[strlen(buffer)-1] = '\0';
				if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
				{
					strncpy(pResultado,buffer,maximo+1);
					retorno = 0;
				 	break;
				}
				printf("%s",pMensajeError);
				reintentos--;
			}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief imprime un array de string ya cargado
 * \param array de string que se va a imprimir
 * \param cantidad de elemento del array de string
 * \return imprime la lista de string,con un 0 indicando que salio todo bien, sino devuelve un -1
 *
 */
int imprimirArrayString(char aNombres[][QTY_CARACTERES], int cantidad)
{
	int i;
	int retorno = -1;
	if(aNombres != NULL && cantidad>0)//SE PREGUNTA !=NULL para ver si hay algo en la direccion de memoria,se usa con punteros y array
	{
		retorno = 0;
		for(i=0;i<cantidad;i++){
			printf("Nombre: %s \n",aNombres[i]);
		}
	}
	return retorno;
}

/**
 * \brief ordena un array de string ya cargado de forma ascendente
 * \param array de string que se va a imprimir
 * \param cantidad de elemento del array de string
 * \return devuelve un 0 indicando que salio todo bien, sino devuelve un -1
 *
 */
int ordenarArrayString(char aNombres[][QTY_CARACTERES], int cantidad){
	int i;
	int retorno = -1;
	char buffer[QTY_CARACTERES];
	int fSwap;
	if(aNombres != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aNombres[i],aNombres[i+1],QTY_CARACTERES)>0)
				{
					fSwap = 1;
					strncpy(buffer,aNombres[i],QTY_CARACTERES);
					strncpy(aNombres[i],aNombres[i+1],QTY_CARACTERES);
					strncpy(aNombres[i+1],buffer,QTY_CARACTERES);
				}
			}
		}while(fSwap);
	}
	return retorno;
}

/**
 * \brief obtiene el sexo F o M
 * \param puntero al que se le asignara el valor obtenido
 * \return devuelve 0 si obtiene el caracter correcto, sino -1
 *
 */

 char obtenerSexo(char *sexo)
 {
     int retorno = -1;
     char letra;//variable que guardara el sexo
     printf("Ingrese el sexo: \n");
     fflush(stdin);
     scanf("%c",&letra);
     letra = toupper(letra);
     if(letra == 'M' || letra == 'F')
     {
         retorno = 0;
         *sexo = letra;
     }
     else
     {
         printf("El sexo no es valido\n");
     }
     return retorno;
 }
