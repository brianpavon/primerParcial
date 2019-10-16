#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "cliente.h"



/**
 * \brief permite al usuario ingresar a un menu
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return void
 *
 */
void menuClientes(sCliente *cliente, int sizeCliente,int id)
{
	int opcion;

	do
	{
    system("cls");
	printf("--------------MENU DE CLIENTES--------------\n");
    printf("\n\n1-Alta:\n2-Modificacion:\n3-Baja:\n4-Salir\n");
	getInt(&opcion,"Ingrese la opcion: \n","Opcion invalida\n",0,5,2);
	switch(opcion)
		{
		case 1:
			addCliente(cliente,sizeCliente,id);
			fflush(stdin);

			break;
		case 2:
			menuModificacionClientes(cliente,sizeCliente);
			fflush(stdin);
			break;
		case 3:
			bajaClientePorId(cliente,sizeCliente);
			fflush(stdin);
			break;
		}
	}while(opcion != 4);
}


 /**
 * \brief inicializa el estado de un array de estructuras, dejando el estado vacio o en cero
 * \param array a inicializar
 * \param tamanio del array
 * \return Si se pudo realizar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int initArrayStructCliente(sCliente *cliente,int sizeCliente)
{
    int i;//variable de control
	int retorno = -1;
	if(cliente != NULL && sizeCliente > 0)
	{

		for(i=0;i<sizeCliente;i++)
		{
			cliente[i].status = STATUS_VACIO;

		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief busca en un array de estructuras, el primer lugar disponible
 * \param array de estructura
 * \param tamanio del array
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */

int buscarLugarLibre(sCliente *cliente,int sizeCliente)
{
    int index = -1;
	int i;
	if(cliente != NULL && sizeCliente > 0)
	{

		for(i=0;i<sizeCliente;i++)
		{
			if(cliente[i].status == STATUS_VACIO)
			{
				index = i;
				break;
			}
		}

	}
	return index;

}

 /**
 * \brief permite harcodear una estructura de array, cargando datos por defecto
 * \param array de estructura
 * \param tamanio del array
 * \return void
 *
 */

void cliente_hcData(sCliente *cliente, int sizeCliente)
{
    int i;
    int id[]= {1,8,9,7,2,4};
    char name[][CANTIDAD_LETRAS]= {"Cabsha SA","Kalop","Philips","Logitech","Samsung","Sony"};
    char direccion[][CANTIDAD_LETRAS]={"las heras 1","las heras 2","las heras 3","las heras 4","las heras 5","las heras 6"};
    char localidad[][CANTIDAD_LETRAS]= {"Berazategui","Avellaneda","CABA","Lomas de Zamora","Lanus","CABA"};
    char cuit[][CANTIDAD_LETRAS]={"302697864","302697881","302697114","311296450","301527452","303261479"};
    for(i=0; i<6; i++)
    {
        cliente[i].idCliente = id[i];
        strcpy(cliente[i].name, name[i]);
        strcpy(cliente[i].direccion, direccion[i]);
        strcpy(cliente[i].localidad, localidad[i]);
        strcpy(cliente[i].cuit, cuit[i]);
        cliente[i].status = STATUS_OCUPADO;

    }
}

 /**
 * \brief funcion que nos permitira cargar una estructura en un array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param id cargado en el menu
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */

int addCliente(sCliente *cliente,int sizeCliente,int id)
{
    int i;
    int retorno = -1;
    char respuesta;
    sCliente auxCliente;
    i = buscarLugarLibre(cliente,sizeCliente);

    if(i!= -1)
    {
            auxCliente.idCliente = id+1;
            fflush(stdin);
            getString(auxCliente.name,"Ingrese el nombre del cliente: \n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
            getString(auxCliente.cuit,"Ingrese el CUIT del cliente: \n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
            getString(auxCliente.direccion,"Ingrese la direccion del cliente: \n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
            getString(auxCliente.localidad,"Ingrese la localidad del cliente: \n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
            fflush(stdin);

            printf("\n\n------------------------------------------------------------\n\n");
            getChar(&respuesta,"Confirma el nuevo cliente?Ingrese s para confirmar o n para cancelar\n","El cliente no fue dado de alta\n",'s','z',1);
                if(respuesta == 's')
                {
                    retorno = 0;
                    cliente[i].idCliente = auxCliente.idCliente;
                    strncpy(cliente[i].name,auxCliente.name,CANTIDAD_LETRAS);
                    strncpy(cliente[i].cuit,auxCliente.cuit,CANTIDAD_LETRAS);
                    strncpy(cliente[i].direccion,auxCliente.direccion,CANTIDAD_LETRAS);
                    strncpy(cliente[i].localidad,auxCliente.localidad,CANTIDAD_LETRAS);
                    cliente[i].status = STATUS_OCUPADO;
                    printf("Se dio de alta al cliente ID:%d Nombre:%s CUIT:%s\n",cliente[i].idCliente,cliente[i].name,cliente[i].cuit);

                }

        else
        {
            printf("No hay lugar disponible\n");
        }

    }
    return retorno;

}

 /**
 * \brief funcion que nos muestra todos los campos cargados en la estructura dentro del array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return si pudo encontrar los campos cargados devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int imprimirTodosLosClientes(sCliente *cliente, int sizeCliente)
{
	int i;
	int retorno = -1;
	if(cliente != NULL && sizeCliente>0)
	{
            retorno = 0;
		    printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","Nombre","Direccion","Localidad","CUIT");
		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {

                    printf("%3d %20s %20s %20s %20s\n",cliente[i].idCliente,cliente[i].name,cliente[i].direccion,cliente[i].localidad,cliente[i].cuit);

                }

            }
    }
    return retorno;
}

 /**
 * \brief funcion que va a recorrer el array de estructura, y buscara un elemento por su ID
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return devuelve la posicion del elemento, sino devuelve -1
 *
 */
int buscarClientePorId(sCliente *cliente, int sizeCliente)
{
	int retorno = -1;
	int i;
	int id;
	if(cliente != NULL && sizeCliente >0)
	{
        imprimirTodosLosClientes(cliente,sizeCliente);
        getInt(&id,"Ingrese el ID que desea buscar\n","El ID no existe\n",0,1000,1);

		for(i=0;i<sizeCliente;i++)
		{
			if(cliente[i].status == STATUS_OCUPADO)
			{
				if(cliente[i].idCliente == id)
				{
					retorno = i; //devuelvo la posicion
					break;
				}

			}

		}
	}
	return retorno;
}

 /**
 * \brief permite al usuario ingresar a un menu de modificaciones
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return void
 *
 */
void menuModificacionClientes(sCliente *cliente, int sizeCliente)
{
    int opcion;
    int i;
    char rta;
    sCliente auxCliente;

    i = buscarClientePorId(cliente,sizeCliente);
    if(i != -1)
    {
    	do
        {
            //system("pause");
            system("cls");
            printf("******---MENU DE MODIFICACION DE CLIENTES******---\n\n\n");

            printf("1-Modificar la direccion\n2-Modificar la localidad\n3-Volver al menu anterior\n");
            getInt(&opcion,"Ingrese el dato a modificar\n","No es una opción válida",1,3,2);
            switch(opcion)
            {
                case 1:
                    system("cls");
                    getString(auxCliente.direccion,"Ingrese la nueva direccion del cliente:\n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
                    getChar(&rta,"La direccion se modificara. Ingrese s para continuar...\n","La direccion no se modifica\n",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(cliente[i].direccion,auxCliente.direccion,CANTIDAD_LETRAS);
                    }
                    break;
                case 2:
                    system("cls");
                    getString(auxCliente.localidad,"Ingrese la nueva localidad del cliente:\n","DATO INCORRECTO\n",0,CANTIDAD_LETRAS,2);
                    getChar(&rta,"La direccion se modificara. Ingrese s para continuar...\n","La direccion no se modifica\n",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(cliente[i].localidad,auxCliente.localidad,CANTIDAD_LETRAS);
                    }
                    break;

            }

        }while(opcion != 3);
    }
}

 /**
 * \brief permite al usuario realizar una baja logica de un elemento,colocando el status en vacio de la estructura dentro del array
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return si pudo realizar la baja devuelve un 0, como señal de OK, sino un -1
 *
 */
int bajaClientePorId(sCliente *cliente, int sizeCliente)
{
    int retorno = -1;
    int i;
    char rta;


    printf("Utilice el ID para dar la baja al cliente\n\n");
    i = buscarClientePorId(cliente, sizeCliente);
    if(cliente[i].status == STATUS_OCUPADO && i != -1)
    {
        getChar(&rta,"Esta seguro que desea borrar el cliente? Ingrese s para continuar o n para cancelar\n","No se dio de baja\n",'s','z',2);
        if(rta == 's')
        {
            cliente[i].status = STATUS_VACIO;
            printf("El cliente %s fue dado de baja\n",cliente[i].name);
            system("cls");
        }

    }
    else
        {
            printf("El ID no corresponde a un cliente activo\n");
            system("pause");
        }


    return retorno;
}

  /**
 * \brief busca en un array de estructura por su ID
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param id establecido en la estructura
 * \return devuelve la posicion del ID, con un 0 en señal de ok, sino -1
 *
 */
 int buscarPorId(sCliente *cliente, int sizeCliente, int id)
{
    int i;
    int retorno = -1;

    if(cliente!= NULL && sizeCliente>0)
    {

        for(i=0; i<sizeCliente; i++)
        {
            if(cliente[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



