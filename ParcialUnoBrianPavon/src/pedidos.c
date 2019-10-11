#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "utn.h"
#include "pedidos.h"
#include "cliente.h"

void menuPedidos(sPedido *pedido,int sizePedido)
{
	int opcion;
	int id = 0;
		do
		{
		printf("\n\n--------------MENU DE PEDIDOS--------------\n\n");
		initArrayStruct(pedido,sizePedido);
		printf("\n\n1-Alta:\n2-Modificacion:\n3-Baja:\n4-Salir\n");
		getInt(&opcion,"Ingrese la opcion: \n","Opcion invalida\n",0,5,2);
		switch(opcion)
			{
			case 1:
				imprimirTodosLosClientes(cliente,sizeCliente);

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



int addPedidos(sCliente *cliente,int sizeCLiente,sPedido *pedido,int sizePedido,int id)
{
	int i;
	int retorno = -1;
	char respuesta;
	sCliente auxCliente;
	sPedido auxPedido;
	i = buscarLugarLibre(pedido,sizePedido);

	    if(i!=-1)
	    {
	            auxPedido.idPedido = id+1;
	            auxCliente = pedido_obtenerCliente(cliente,sizeCliente,pedido);
	            auxPedido.idCliente = auxCliente.idCliente;
	            printf("\n\n%3s %20s %20s\n\n","ID de Pedido","Cliente","Cuit");
	            getChar(&respuesta,"Confirma el nuevo ghost?Ingrese s para confirmar o n para cancelar\n","El ghost no fue dado de alta\n",'s','z',1);
	                if(respuesta == 's')
	                {
	                    retorno = 0;
	                    pedido[i].idPedido = auxPedido.idPedido;
	                    pedido[i].status = PENDIENTE;
	                    printf("Se dio de alta al pedido %d del cliente %s",pedido[i]->idPedido,cliente[i]->name);
	                }

	        else
	        {
	            printf("No hay lugar disponible\n");
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

sGhostDos pedido_obtenerCliente(sCliente *cliente, int sizeCliente, sPedido *pedido)
{
   int i;
   int index;
   sCliente clienteRetorno;
   clienteRetorno.idCliente = -1;

   do
   {
       for (i=0; i<sizeCliente; i++)
       {
           printf("ID %d: %s\n", cliente[i].idCliente);
       }

       getInt(&index,"Seleccion el cliente que corresponde al ID: \n","ERROR\n",0,CANTIDAD_SECTORES,2);

       for (i=0; i<sizeCliente; i++)
       {
           if (cliente[i].idCliente == index)
           {
               clienteRetorno = cliente[i];
           }
       }

       if (clienteRetorno.idCliente == -1)
       {
           printf("\nEl .... no existe\n\n");
       }
   }

   while(clienteRetorno.idCliente==-1);
   return clienteRetorno;
}



