#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include "cliente.h"

#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define CANTIDAD_EMPLEADOS 1000
#define CANTIDAD_SECTORES 3

/**
 * \brief permite al usuario ingresar a un menu
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return void
 *
 */
void menuClientes(sCliente *cliente, int sizeCliente)
{
	int opcion;
	int id = 0;

	do
	{
	printf("\n\n--------------MENU DE CLIENTES--------------\n\n");
	initArrayStruct(cliente,sizeCliente);
	printf("\n\n1-Alta:\n2-Modificacion:\n3-Baja:\n4-Salir\n");
	getInt(&opcion,"Ingrese la opcion: \n","Opcion invalida\n",0,5,2);
	switch(opcion)
		{
		case 1:
			addCliente(cliente,sizeCliente,id);
			__fpurge(stdin);
			id++;
			break;
		case 2:
			menuModificacionClientes(cliente,sizeCliente);
			__fpurge(stdin);
			break;
		case 3:
			bajaClientePorId(cliente,sizeCliente);
			__fpurge(stdin);
			break;
		case 4:
			imprimirTodosLosClientes(cliente,sizeCliente);
			break;
		}
	}while(opcion != 5);
}


 /**
 * \brief inicializa el estado de un array de estructuras, dejando el estado vacio o en cero
 * \param array a inicializar
 * \param tamanio del array
 * \return Si se pudo realizar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int initArrayStruct(sCliente *cliente,int sizeCliente)
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

/*void cliente_hcData(sGhost *cliente, int sizeCliente)
{
    int i; //variable de control para los ghosts
    int id[]= {1,8,9,7,2,4};
    char name[][50]= {"Lorena","Eduardo","Carlos","Pedro","Carlos","Mateo"};
    char lastName[][50]={"B","A","B","A","B","A"};
    float salario[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,1,3,3,2,2};

    for(i=0; i<sizeGhost; i++)
    {
        ghost[i].id = id[i];
        strcpy(ghost[i].name, name[i]);
        strcpy(ghost[i].lastName, lastName[i]);
        ghost[i].salario = salario[i];
        ghost[i].status = STATUS_OCUPADO;
        ghost[i].sector = sector[i];
    }
}*/

 /**
 * \brief funcion que nos permitira cargar una estructura en un array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */

int addCliente(sCliente *cliente,int sizeCliente,int id)
{
    int i;
    int retorno = -1;
    char respuesta;
    sCliente auxCliente;
    i=buscarLugarLibre(cliente,sizeCliente);

    if(i!=-1)
    {
            auxCliente.idCliente = id+1;
            __fpurge(stdin);
            getString(auxCliente.name,"Ingrese el nombre de la empresa:\n","DATO INCORRECTO\n",0,51,2);
            __fpurge(stdin);
            getString(auxCliente.direccion,"Ingrese la direccion del cliente:\n","DATO INCORRECTO\n",0,100,2);
            __fpurge(stdin);
            getString(auxCliente.localidad,"Ingrese la localidad del cliente: \n","DATO INCORRECTO\n",0,100,2);
            __fpurge(stdin);
            getString(auxCliente.cuit,"Ingrese el CUIT del cliente: \n","DATO INCORRECTO",0,51,2);
            __fpurge(stdin);

            printf("\n\n------------------------------------------------------------\n\n");
            getChar(&respuesta,"Confirma el nuevo cliente?Ingrese s para confirmar o n para cancelar\n","El cliente no fue dado de alta\n",'s','z',1);
                if(respuesta == 's')
                {
                    retorno = 0;
                    cliente[i].idCliente = auxCliente.idCliente;
                    strncpy(cliente[i].name,auxCliente.name,100);
                    strncpy(cliente[i].direccion,auxCliente.direccion,100);
                    strncpy(cliente[i].localidad,auxCliente.localidad,100);
                    strncpy(cliente[i].cuit,auxCliente.cuit,51);
                    cliente[i].status = STATUS_OCUPADO;
                    printf("Se dio de alta al cliente ID:%d Nombre:%s CUIT:%s",cliente[i].idCliente,cliente[i].name,cliente[i].cuit);
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
		    printf("\n\n%3s %20s %20s %20s %20s\n\n","ID","Nombre","Direccion","Localidad","CUIT");
		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                    retorno = 0;

                    printf("%3d %20s %20s %20s %20s",cliente[i]->idCliente,cliente[i]->name,cliente[i]->direccion,cliente[i]->localidad,cliente[i]->cuit);

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
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
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
            system("clear");
            printf("\n\n\n******---MENU DE MODIFICACION DE CLIENTES******---\n\n\n");
            imprimirTodosLosClientes(cliente, sizeCliente);
            printf("1-Modificar la direccion\n2-Modificar la localidad\n3-Volver al menu anterior\n");
            getInt(&opcion,"Ingrese el dato a modificar\n","No es una opción válida",1,3,2);
            switch(opcion)
            {
                case 1:
                    system("clear");
                    getString(auxCliente.direccion,"Ingrese la nueva direccion del cliente:\n","DATO INCORRECTO\n",0,100,2);
                    getChar(&rta,"La direccion se modificara. Ingrese s para continuar...\n","La direccion no se modifica\n",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(cliente[i].direccion,auxCliente.localidad,100);
                    }
                    break;
                case 2:
                    system("clear");
                    getString(auxCliente.localidad,"Ingrese la nueva localidad del cliente:\n","DATO INCORRECTO\n",0,100,2);
                    getChar(&rta,"La direccion se modificara. Ingrese s para continuar...\n","La direccion no se modifica\n",'s','z',2);
                    if(rta == 's')
                    {
                        strncpy(cliente[i].localidad,auxCliente.localidad,100);
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
 * \param array de esturctura con relacion uno a muchos
 * \param tamanio del array de relacion uno a mucho
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
        }

    }
    else
        {
            printf("El ID no corresponde a un cliente activo\n");
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

 /**
 * \brief permite elegir una estructura a relacionar con una principal
 * \param array de estructura con relacion uno a mucho
 * \param tamanio del array de estructura
 * \param array de estructura principal
 * \return devuelve el parametro elegido para relacionar
 *
 */


