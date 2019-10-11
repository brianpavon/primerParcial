#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#define MAX_INPUT_BUFFER 4096


/** \brief Revisa que el string sean solo numeros
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */

int validarInt(char *buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Revisa que el string ingresado tenga solo letras
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */

int validarStringLetras(char *buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief verifica si el array de cadena de caracteres ingresado es un numero de telefono o celular
 * \param  array de cadena de caracteres a verificar
 * \return int 1 si es numero de telefono -1 si no lo es
 *
 */
int esNumeroTelefonico(char *buffer)
{
    int i; //indice para revisar el string
    int guionesContador; //contador de guiones
    int flag=0; // bandera que permite saber si solo posee numeros y guiones
    guionesContador=0;
    i=0;
    while (buffer[i]!='\0')
    {
        if ((buffer[i]!=' ') && buffer[i]!='-' && (buffer[i]<'0' || buffer[i]>'9'))
        {
            flag=-1;
        }
        if (buffer[i]=='-')
        {
            guionesContador++;
        }
    }
if (flag==0 && guionesContador!=0)
{
    flag=1;
}
return flag;
}

/** \brief Revisa que el string sean solo numeros float
 * \param buffer conteniendo el float como string
 * \return -1 error, 0 OK
 *
 */
int esFloat(char *buffer)
{
    int i; //indice que permite revisar el string de floats
    int retorno=1; //bandera que permite saber si tiene solo numeros y puntos
    i=0;
    while (buffer[i]!= '\0')
    {
        if ((buffer[i]<'0' || buffer[i]>'9') && buffer[i]!= '.')
        {
            retorno=-1;
        }
    i++;
    }
return retorno;
}
