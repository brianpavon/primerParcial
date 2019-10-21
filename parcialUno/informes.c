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
                "6-Cantidad de clientes que reciclaron mas de 1000 kgs\n"
                "7-Cantidad de clientes que reciclaron menos de 100 kgs\n"
                "8-Imprimir pedidos completados y porcentaje reciclado\n"
                "9-Pedidos por localidad\n"
                "10-Cantidad de kgs de propileno promedio por cliente\n"
                "11-Informar por CUIT, cantidad de kgs por tipo de plastico\n"
                "12-Salir\n");
         getInt(&opcion,"Ingrese la opcion deseada\n","Opcion invalida\n",0,12,2);
         switch(opcion)
         {
         case 1:
            informes_clienteConMasPedidosPendientes(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 2:
            informes_clienteConMasPedidosCompletados(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 3:
            informes_cantidadPedidosPorCliente(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 4:
            informes_clienteRecicloMasKilos(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 5:
            informes_clienteRecicloMenosKilos(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 6:
            informes_clienteReciclaronMasMilKilos(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 7:
            informes_clienteReciclaronMenosCienKilos(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 8:
            informes_porcentajeReciclado(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 9:

            break;
         case 10:

            break;
         case 11:

            break;

         }

     }while(opcion != 12);

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
 * \brief funcion que nos muestra el cliente que reciclo mas kilos
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
     int clienteMaximoKilos;
     int flag = 0;
     int id;
     int index;

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
                        pedido[j].cantidadReciclada = pedido[j].plasticoHdpe + pedido[j].plasticoLdpe + pedido[j].plasticoPp;
                     }

                 }
             }
         }
             for(j=0 ; j<sizePedido; j++)
             {
                 if(flag == 0 || pedido[j].cantidadReciclada > clienteMaximoKilos)
                    {
                        clienteMaximoKilos = pedido[j].cantidadReciclada;
                        id = pedido[j].idCliente;
                        flag = 1;
                        retorno = 0;
                    }
             }
             index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
             printf("El cliente que reciclo mas kilos es %s\n",cliente[index].name);

     }

     return retorno;
 }

 /**
 * \brief funcion que nos muestra el cliente que reciclo menos kilos
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
 int informes_clienteRecicloMenosKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int retorno = -1;
     int i;
     int j;
     int clienteMenosKilos;
     int flag = 0;
     int id;
     int index;

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
                        pedido[j].cantidadReciclada = pedido[j].plasticoHdpe + pedido[j].plasticoLdpe + pedido[j].plasticoPp;
                     }

                 }
             }
         }
             for(j=0 ; j<sizePedido; j++)
             {
                 if(flag == 0 || pedido[j].cantidadReciclada < clienteMenosKilos)
                    {
                        clienteMenosKilos = pedido[j].cantidadReciclada;
                        id = pedido[j].idCliente;
                        flag = 1;
                        retorno = 0;
                    }
             }
             index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
             printf("El cliente que reciclo menos kilos es %s\n",cliente[index].name);

     }

     return retorno;
 }

 /**
 * \brief funcion que nos muestra el cliente que reciclaron mas de 1000 kgs
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_clienteReciclaronMasMilKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int retorno = -1;
     int i;
     int j;
     int contadorClientes = 0;
     int acumuladorClientes = 0;

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
                        pedido[j].cantidadReciclada = pedido[j].plasticoHdpe + pedido[j].plasticoLdpe + pedido[j].plasticoPp;
                        if(pedido[j].cantidadReciclada > 1000)
                        {
                            contadorClientes++;
                            retorno = 0;
                        }
                     }

                 }
             }
         }
        acumuladorClientes = acumuladorClientes + contadorClientes;
        printf("La cantidad de clientes que reciclaron mas de mil kgs fue: %d\n",acumuladorClientes);
     }

     return retorno;
 }

 /**
 * \brief funcion que nos muestra el cliente que reciclaron menos de 100 kgs
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_clienteReciclaronMenosCienKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int retorno = -1;
     int i;
     int j;
     int contadorClientes = 0;
     int acumuladorClientes = 0;

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
                        pedido[j].cantidadReciclada = pedido[j].plasticoHdpe + pedido[j].plasticoLdpe + pedido[j].plasticoPp;
                        if(pedido[j].cantidadReciclada < 100)
                        {
                            contadorClientes++;
                            retorno = 0;
                        }
                     }

                 }
             }
         }
        acumuladorClientes = acumuladorClientes + contadorClientes;
        printf("La cantidad de clientes que reciclaron menos de cien kgs fue: %d\n",acumuladorClientes);
     }

     return retorno;
 }

 /**
 * \brief funcion que nos muestra el porcentaje de plasticos reciclados de cada cliente
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_porcentajeReciclado(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido)
{
	int i;
	int j;
	int retorno = -1;
	float porcentajeReciclado;
	if(pedido != NULL && sizePedido > 0 && cliente != NULL && sizeCliente > 0 )
	{

		    printf("%5s %10s %25s\n","ID Pedido","CUIT","Porcentaje reciclado");
		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                    for(j=0 ; j<sizePedido ; j++)
                    {
                        if(cliente[i].idCliente == pedido[j].idCliente &&
                           pedido[j].status == COMPLETADO &&
                           pedido[j].cantidadRecolectada > 0)
                        {
                            pedido[j].cantidadReciclada = pedido[j].plasticoHdpe + pedido[j].plasticoLdpe + pedido[j].plasticoPp;
                            porcentajeReciclado = (pedido[j].cantidadReciclada *100) / pedido[j].cantidadRecolectada;

                            printf("%5d %18s %18.2f\n",pedido[j].idPedido,cliente[i].cuit,porcentajeReciclado);
                            retorno = 0;
                        }
                    }
                }
            }
    }
    return retorno;
}
