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
                "9-Ingresar una localidad e imprimir pedidos pendientes de esa localidad\n"
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
            informes_cantidadPorLocalidadPedidosPendientes(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 10:
            informes_promedioPropilenoPorCliente(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
            break;
         case 11:
            informes_cantidadKilosPlasticoPorCuit(cliente,sizeCliente,pedido,sizePedido);
            system("pause");
            system("cls");
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

 /**
 * \brief funcion que imprime las localidades de los clientes activos
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_imprimirLocalidades(sCliente *cliente,int sizeCliente)
 {
     int retorno = -1;
     int i;
     if(cliente != NULL && sizeCliente > 0)
     {
         printf("%19s\n\n","Localidad:");
         for(i=0; i<sizeCliente; i++)
         {
             if(cliente[i].status == STATUS_OCUPADO && cliente[i].localidad != NULL)
             {

                 printf("%20s\n",cliente[i].localidad);
                 retorno = 0;
             }
         }
     }

     return retorno;
 }

  /**
 * \brief funcion que imprime por localidad la cantidad de pedidos pendientes
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_cantidadPorLocalidadPedidosPendientes(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido)
 {
     int retorno = -1;
     int i;
     int j;
     int contadorPedidos = 0;
     int acumPedidos = 0;
     sCliente auxCliente;

     if(cliente != NULL && sizeCliente>0 && pedido != NULL && sizePedido>0)
     {
         informes_imprimirLocalidades(cliente,sizeCliente);
         getString(auxCliente.localidad,"Escriba la localidad\n","Dato incorrecto\n",0,CANTIDAD_LETRAS,2);

         for(i=0; i<sizeCliente; i++)
         {
             if(cliente[i].status == STATUS_OCUPADO &&
                strncmp(cliente[i].localidad,auxCliente.localidad,CANTIDAD_LETRAS)==0)
             {
                 for(j=0; j<sizePedido; j++)
                 {
                     if(pedido[j].status == PENDIENTE && pedido[j].idCliente == cliente[i].idCliente)
                     {
                         contadorPedidos++;
                         retorno = 0;
                     }
                 }
             }
         }
         acumPedidos = acumPedidos + contadorPedidos;
         printf("La localidad %s tiene %d pedidos pendientes\n",auxCliente.localidad,acumPedidos);
     }

     return retorno;
 }

 /**
 * \brief funcion que imprime el promedio de propileno por cliente
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int informes_promedioPropilenoPorCliente(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido)
{
	int i;
	int j;
	int retorno = -1;
	int contadorCliente = 0;
	int acumCliente = 0;
	float acumPropileno = 0;
	float promedio;
	if(pedido != NULL && sizePedido > 0 && cliente != NULL && sizeCliente > 0 )
	{

		    for(i=0; i<sizeCliente; i++)
            {
                if(cliente[i].status == STATUS_OCUPADO)
                {
                    contadorCliente++;
                    for(j=0 ; j<sizePedido ; j++)
                    {
                        if(pedido[j].status == COMPLETADO &&
                           cliente[i].idCliente == pedido[j].idCliente &&
                           pedido[j].plasticoPp > 0)
                        {
                            acumPropileno = acumPropileno + pedido[j].plasticoPp;
                            retorno = 0;
                        }
                    }
                }
            }
            acumCliente = acumCliente + contadorCliente;
            promedio = acumPropileno / acumCliente;
            //printf("%d\n",acumCliente);
            //printf("%.2f\n",acumPropileno);
            printf("El promedio de kgs de propileno por cliente es %.2f\n",promedio);
    }
    return retorno;
}

/**
* \brief funcion que imprime por cuit la cantidad de kgs de plastico elegido
* \param array de estructura
* \param tamanio del array de estructura
* \param array de estructura
* \param tamanio del array de estructura
* \return 0 como señal de OK, sino devuelve -1
*
*/
int informes_cantidadKilosPlasticoPorCuit(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido)
{
    int retorno = -1;
    int i;
    int j;
    int id;
    int index;
    int opcion;
    float cantidadHdpe;
    float cantidadLdpe;
    float cantidadPp;

    if(cliente != NULL && sizeCliente>0 && pedido != NULL && sizePedido>0)
    {
        imprimirClienteConSuCuit(cliente,sizeCliente);
        getInt(&id,"Seleccione el CUIT mediante el ID correspondiente\n","El ID seleccionado no corresponde",0,CANTIDAD_CLIENTES,2);
        index = cliente_buscarPorIdSinPedirDatos(cliente,sizeCliente,id);
        if(cliente[index].status == STATUS_OCUPADO)
        {
            for(i=0; i<sizeCliente; i++)
            {
                for(j=0 ; j<sizePedido; j++)
                {
                    if(pedido[j].status == COMPLETADO && pedido[j].idCliente == cliente[index].idCliente)
                    {
                        cantidadHdpe =  pedido[j].plasticoHdpe;
                        cantidadLdpe =  pedido[j].plasticoLdpe;
                        cantidadPp =  pedido[j].plasticoPp;
                        retorno = 0;
                    }
                }
            }
            printf("1-Plastico HDPE\n2-Plastico LDPE\n3-Plastico PP\n");
            getInt(&opcion,"Elija el plastico\n","Dato invalido\n",0,3,2);
            switch(opcion)
            {
                case 1:
                    printf("Cantidad de kgs de HDPE %.2f\n",cantidadHdpe);
                    break;

                case 2:
                    printf("Cantidad de kgs de LDPE %.2f\n",cantidadLdpe);
                    break;
                case 3:
                    printf("Cantidad de kgs de PP %.2f\n",cantidadPp);
                    break;
            }
        }
        else
        {
            printf("El dato ingresado no corresponde a un cliente valido\n");
        }

    }
    return retorno;
}
