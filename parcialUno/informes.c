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
         printf("1-Cliente con mas pedidos pendientes\n"
                "2-Cliente con mas pedidos completados\n"
                "3-Cliente con mas pedidos\n"
                "4-Cliente que reciclo mas plasticos\n"
                "5-Cliente que reciclo menos plasticos\n"
                "6-Cantidad de cliente que reciclo mas de 1000 kgs\n"
                "7-Cantidad de cliente que reciclo menos de 100 kgs\n"
                "6-Imprimir pedidos completados\n"
                "7-Pedidos por localidad\n"
                "8-Cantidad de kgs de propileno promedio por cliente\n"
                "9-Informar por CUIT, cantidad de kgs por tipo de plastico\n"
                "10-Salir\n");
         getInt(&opcion,"Ingrese la opcion deseada\n","Opcion invalida\n",0,10,2);
         switch(opcion)
         {
         case 1:
            informes_clienteConMasPedidosPendientes(cliente,sizeCliente,pedido,sizePedido);
            break;
         case 2:
            informes_clienteConMasPedidosCompletados(cliente,sizeCliente,pedido,sizePedido);
            break;
         case 3:
            informes_cantidadPedidosPorCliente(cliente,sizeCliente,pedido,sizePedido);
            break;
         case 4:

            break;
         case 5:

            break;
         case 6:

            break;
         case 7:

            break;
         case 8:

            break;
         case 9:

            break;

         }

     }while(opcion != 10);

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
	int j;
	int retorno = -1;
	int maximoPedidoPendiente;
	int flag = 0;
	int id;
	int index;

	if(cliente != NULL && sizeCliente > 0 && pedido != NULL && sizePedido > 0)
	{

		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                   for(j=0 ; j<sizePedido ; j++)
                    {
                        if(pedido[j].status == PENDIENTE && cliente[i].idCliente == pedido[j].idCliente)
                        {
                            pedido[j].contPedidos++;
                            break;
                        }
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
            printf("El cliente con mayor pedidos pendientes es %s\n",cliente[index].name);
    }
    return retorno;
}


/**
 * \brief funcion que nos muestra el cliente con mas pedidos completados
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_clienteConMasPedidosCompletados(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido)
{
	int i;
	int j;
	int retorno = -1;
	int maximoPedidoCompletado;
	int flag = 0;
	int id;
	int index;

	if(cliente != NULL && sizeCliente > 0 && pedido != NULL && sizePedido > 0)
	{

		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                    for(j=0 ; j<sizePedido ; j++)
                    {
                        if(pedido[j].status == COMPLETADO && cliente[i].idCliente == pedido[j].idCliente)
                        {
                            pedido[j].contPedidos++;
                            break;
                        }
                    }
                }

            }
            for(j=0 ; j<sizePedido ; j++)
            {
                if(flag == 0 || pedido[j].contPedidos > maximoPedidoCompletado)
                {
                    maximoPedidoCompletado = pedido[j].contPedidos;
                    id = pedido[j].idCliente;
                    flag = 1;
                    retorno = 0;
                }
            }
            index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
            printf("El cliente con mayor pedidos completados es %s\n",cliente[index].name);
    }
    return retorno;
}

/**
 * \brief funcion que nos muestra el cliente con mas pedidos
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_cantidadPedidosPorCliente(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido)
{
	int i;
	int j;
	int retorno = -1;
	int maximoCliente;
	int flag = 0;
	int id;
	int index;

	if(cliente != NULL && sizeCliente > 0 && pedido != NULL && sizePedido > 0)
	{

		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                  for(j=0 ; j<sizePedido ; j++)
                    {
                        if(pedido[j].status == COMPLETADO && pedido[j].status == PENDIENTE && cliente[i].idCliente == pedido[j].idCliente)
                        {
                            pedido[j].contPedidos++;
                            break;
                        }
                    }
                }
            }
            for(j=0 ; j<sizePedido ; j++)
            {
                if(flag == 0 || pedido[j].contPedidos > maximoCliente)
                {
                    maximoCliente = pedido[j].contPedidos;
                    id = pedido[j].idCliente;
                    flag = 1;
                    retorno = 0;
                }
            }
            index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
            printf("El cliente con mayor pedidos es %s\n",cliente[index].name);
    }
    return retorno;
}

/**
 * \brief funcion que nos muestra el cliente con mas pedidos
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
 int informes_clienteRecicloMasKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int retorno = -1;
     int i;
     int j;
     int cantidadTotalKilos;

     if(cliente != NULL && sizeCliente > 0 && pedido != NULL && sizePedido > 0)
     {
         for(i=0 ; i<sizeCliente ; i++)
         {
             if(cliente[i].status == STATUS_OCUPADO)
             {
                 for(j=0 ; j<sizePedido ; j++)
                 {
                     if(cliente[i].idCliente == pedido[j].idCliente && pedido[j].status == COMPLETADO && pedido[j].cantidadRecolectada > 0)
                     {

                     }

                 }
             }
         }

     }

     return retorno;
 }
