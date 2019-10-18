#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "pedidos.h"
#include "cliente.h"
#include "informes.h"

/**
 * \brief permite al usuario ingresar a un menu de opciones para acceder a informes
 * \param array de estructura
 * \param tamanio de la estructura
 * \param array de estructura
 * \param tamanio de la estructura
 * \return void
 *
 */
 void informes_menuInformesMasComplejos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int opcion;
     system("cls");
     do
     {
         printf("--------------MENU INFORMES SEGUNDA PARTE--------------\n");
         printf("1-Cliente con mas pedidos pendientes\n2-Cliente con mas pedidos completados\n3-Cliente con mas pedidos\n4-Salir\n");
         getInt(&opcion,"Ingrese la opcion deseada\n","Opcion invalida\n",0,4,2);
         switch(opcion)
         {
         case 1:
            informes_clienteConMasPedidosPendientes(cliente,sizeCliente,pedido,sizePedido);
            break;
         case 2:

            break;
         case 3:

            break;
         case 4:

            break;
         }

     }while(opcion != 4);

 }

 /**
 * \brief funcion que nos muestra el cliente con mas pedidos pendientes
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_clienteConMasPedidosPendientes(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido)
{
	int i;
	int j=0;
	int retorno = -1;
	int maximoPedidoPendiente;
	int flag = 0;
	int id;
	int index;
	pedido[j].contPedidos = 0;
	if(cliente != NULL && sizeCliente > 0 && pedido != NULL && sizePedido > 0)
	{
            retorno = 0;
		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)

                for(j=0 ; j<sizePedido ; j++)
                {
                    if(pedido[j].status == PENDIENTE)
                    {
                        pedido[j].contPedidos++;
                    }
                }
            }
            for(j=0 ; j<sizePedido ; j++)
            {
                if(flag == 0 || pedido[j].contPedidos > maximoPedidoPendiente)
                {
                    maximoPedidoPendiente = pedido[j].contPedidos;
                    id = pedido[j].idCliente;
                    flag = 1;
                    retorno = 0;
                }
            }
            index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
            printf("%d\n",index);
            printf("El cliente con mayor pedidos es %s\n",cliente[index].name);
    }
    return retorno;
}

