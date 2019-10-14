#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <stdio_ext.h>
#include "utn.h"
#include "pedidos.h"
#include "cliente.h"

/**
 * \brief permite al usuario ingresar a un menu
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \param array de estructura principal
 * \param tamanio de la estructura principal
 * \return void
 *
 */
void menuPedidos(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente)
{
	int opcion;
	int id = 0;

		do
		{
            system("cls");
            printf("--------------MENU DE PEDIDOS--------------\n");
            printf("\n\n1-Alta:\n2-Procesar residuos:\n3-Salir:\n");
            getInt(&opcion,"Ingrese la opcion: \n","Opcion invalida\n",0,3,2);
            switch(opcion)
                {
                case 1:
                    addPedidos(cliente,sizeCliente,pedido,sizePedido,id);
                    id++;
                    system("pause");

                    break;
                case 2:

                    pedidos_procesarPlasticos(pedido,sizePedido);
                    system("pause");
                    break;
			}
		}while(opcion != 3);

}

 /**
 * \brief inicializa el estado de un array de estructuras, dejando el estado vacio o en cero
 * \param array a inicializar
 * \param tamanio del array
 * \return Si se pudo realizar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int initArrayStructPedido(sPedido *pedido,int sizePedido)
{
    int i;//variable de control
	int retorno = -1;
	if(pedido != NULL && sizePedido > 0)
	{

		for(i=0;i<sizePedido;i++)
		{
			pedido[i].status = ISEMPTY;

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

int pedidos_buscarLugarLibre(sPedido *pedido,int sizePedido)
{
    int index = -1;
	int i;
	if(pedido != NULL && sizePedido > 0)
	{

		for(i=0;i<sizePedido;i++)
		{
			if(pedido[i].status == ISEMPTY)
			{
				index = i;
				break;
			}
		}

	}
	return index;

}
/**
 * \brief funcion que nos permitira cargar una estructura en un array
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param id cargado en el menu
 * \return si encontro un lugar devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int addPedidos(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido,int id)
{
	int i;
	int retorno = -1;
	char respuesta;
	int index;
	sPedido auxPedido;
	i = pedidos_buscarLugarLibre(pedido,sizePedido);

	    if(i != -1)
	    {
                index = buscarClientePorId(cliente,sizeCliente);
                auxPedido.idCliente = cliente[index].idCliente;
	            auxPedido.idPedido = id+1;
	            getFloat(&auxPedido.cantidadRecolectada,"Ingrese los kgs a recolectar: \n","VALOR INCORRECTO\n",0,100000,2);
	            getChar(&respuesta,"Confirma el nuevo pedido?Ingrese s para confirmar o n para cancelar\n","El pedido no fue dado de alta\n",'s','z',1);
	                if(respuesta == 's')
	                {
	                    retorno = 0;
	                    pedido[i].cantidadRecolectada = auxPedido.cantidadRecolectada;
	                    pedido[i].idCliente = auxPedido.idCliente;
	                    pedido[i].idPedido = auxPedido.idPedido;
	                    pedido[i].status = PENDIENTE;
	                    printf("Se dio de alta al pedido %d del cliente %s\n",pedido[i].idPedido,cliente[index].name);
	                }

	        else
	        {
	            printf("No hay lugar disponible\n");
	        }
	    }
	    return retorno;

}


 /**
 * \brief funcion que nos muestra los pedidos pendientes con los clientes
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int imprimirPedidosPendientesConClientes(sPedido *pedido, int sizePedido,sCliente *cliente, int sizeCliente)
{
	int i;
	int j;
	int retorno = -1;
	if(pedido != NULL && sizePedido>0)
	{
            retorno = 0;
		    printf("%20s %20s %20s %20s %20s\n\n","ID Pedido","Cliente","CUIT","Direccion","Cantidad Recolectada");
		    for(i=0; i<sizePedido; i++)
            {
                if(pedido[i].status == PENDIENTE)

                for(j=0 ; j<sizeCliente ; j++)
                {
                    if(cliente[j].idCliente == pedido[i].idCliente)
                    {
                        printf("%20d %20s %20s %20s %20.2f\n",pedido[i].idPedido,cliente[j].name,cliente[j].cuit,cliente[j].direccion,pedido[i].cantidadRecolectada);
                    }

                }

            }
    }
    return retorno;
}

/**
 * \brief funcion que nos muestra todos los pedidos en estado pendiente
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return si pudo encontrar los campos cargados devuelve un 0, como señal de OK, sino devuelve -1
 *
 */
int imprimirPedidosPendientes(sPedido *pedido, int sizePedido)
{
	int i;
	int retorno = -1;
	if(pedido != NULL && sizePedido>0)
	{
            retorno = 0;
		    printf("%3s %20s\n","ID Pedido","Cantidad sin procesar");
		    for(i=0; i<sizePedido; i++)
            {
                if(pedido[i].status == PENDIENTE)
                {

                    printf("%3d %20.2f\n",pedido[i].idPedido,pedido[i].cantidadRecolectada);

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
int buscarPedidoPorId(sPedido *pedido, int sizePedido)
{
	int retorno = -1;
	int i;
	int id;
	if(pedido != NULL && sizePedido >0)
	{
        imprimirPedidosPendientes(pedido,sizePedido);
        getInt(&id,"Ingrese el ID que desea buscar\n","El ID no existe\n",0,1000,1);

		for(i=0;i<sizePedido;i++)
		{
			if(pedido[i].status == PENDIENTE)
			{
				if(pedido[i].idPedido == id)
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
 * \brief funcion que nos permitira el ingreso de las cantidades de los diferentes tipos de plasticos
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
 int pedidos_procesarPlasticos(sPedido *pedido,int sizePedido)
 {
    int retorno = -1;
    int index;
    float totalIngresado;
    char respuesta;

    printf("------VA A PROCESAR LOS RESIDUOS------\n\n");
    index = buscarPedidoPorId(pedido,sizePedido);
    if(index != -1 && pedido[index].cantidadRecolectada > 0)
    {
        getFloat(&pedido[index].plasticoHdpe,"Ingrese cantidad de Plasticos HDPE\n","Valor incorrecto\n",0,10000,2);
        getFloat(&pedido[index].plasticoLdpe,"Ingrese cantidad de Plasticos LDPE\n","Valor incorrecto\n",0,10000,2);
        getFloat(&pedido[index].plasticoPp,"Ingrese cantidad de Plasticos PP\n","Valor incorrecto\n",0,10000,2);
        totalIngresado = pedido[index].plasticoHdpe + pedido[index].plasticoLdpe + pedido[index].plasticoPp;
        getChar(&respuesta,"Desea procesar estos residuos?Ingrese s para continuar\n","Ingreso invalido",'s','z',2);
        if(respuesta == 's' && totalIngresado <= pedido[index].cantidadRecolectada)
        {
            pedido[index].status = COMPLETADO;
            printf("El pedido %d fue completado\n",pedido[index].idPedido);

            retorno = 0;
        }
        else if(totalIngresado > pedido[index].cantidadRecolectada)
        {
            printf("La cantidad procesada es mayor de lo que se recolecto\n");
        }

    }

    return retorno;
 }

 /**
 * \brief permite al usuario ingresar a un menu de reportes
 * \param array de estructura
 * \param tamanio de la estructura
 * \param array de esturctura
 * \param tamanio de estructura
 * \return void
 *
 */
void pedidos_menuReportes(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente)
{
    int opcion;

       	do
        {

            system("cls");
            printf("******---MENU DE REPORTES******---\n\n");

            printf("1-Informar clientes con pedidos pendientes\n2-Informar pedidos pendientes\n3-Informar pedidos procesados\n4-Salir\n");
            getInt(&opcion,"Ingrese el informe que desea\n","No es una opción válida",1,4,2);
            switch(opcion)
            {
                case 1:
                    system("cls");
                    cantidadDePedidosPorCliente(pedido,sizePedido,cliente,sizeCliente);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    imprimirPedidosPendientesConClientes(pedido,sizePedido,cliente,sizeCliente);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    imprimirPedidosCompletosConClientes(pedido,sizePedido,cliente,sizeCliente);
                    system("pause");
                    break;
            }

        }while(opcion != 4);
}

 /**
 * \brief funcion que nos muestra los pedidos completos con los clientes
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
int imprimirPedidosCompletosConClientes(sPedido *pedido, int sizePedido,sCliente *cliente, int sizeCliente)
{
	int i;
	int j;
	int retorno = -1;
	if(pedido != NULL && sizePedido>0 )
	{
            retorno = 0;
		    printf("%20s %20s %20s %20s %20s\n\n","ID Pedido","Cliente","CUIT","Direccion","Cantidad Recolectada");
		    for(i=0; i<sizePedido; i++)
            {
                if(pedido[i].status == COMPLETADO)
                for(j=0 ; j<sizeCliente ; j++)
                {
                    if(cliente[j].idCliente == pedido[i].idCliente)
                    {
                        printf("%20d %20s %20s %20s %20.2f\n",pedido[i].idPedido,cliente[j].name,cliente[j].cuit,cliente[j].direccion,pedido[i].cantidadRecolectada);
                    }
                }

            }
    }
    return retorno;
}

/**
 * \brief funcion que nos muestra los clientes con sus pedidos pendientes
 * \param array de estructura
 * \param tamanio del array de estructura
 * \param array de estructura
 * \param tamanio del array de estructura principal
 * \return 0 como señal de OK, sino devuelve -1
 *
 */
 int cantidadDePedidosPorCliente(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente)
 {
     int retorno = -1;
     int pedidos = 0;
     int cantidadPedidos = 0;
     int j;
     int i;

     if(cliente != NULL && sizeCliente >0 && pedido != NULL && sizePedido > 0)
     {
         printf("%20s %20s %20s %20s %20s\n\n","Cliente","CUIT","Direccion","Cantidad Recolectada","Cantidad de pedidos pendiente");
         for(i=0 ; i<sizePedido ; i++)
         {
             if(pedido[i].status == PENDIENTE)
             {
                 for(j=0; j<sizeCliente ; j++)
                 {
                     if(cliente[j].idCliente == pedido[i].idCliente && cliente[j].status == STATUS_OCUPADO)
                     {
                         pedidos++;
                         retorno = 0;
                     }
                 }
             }
         }
            cantidadPedidos = cantidadPedidos + pedidos;
            printf("%20s %20s %20s %20.2f %20d\n",cliente[j].name,cliente[j].cuit,cliente[j].direccion,pedido[i].cantidadRecolectada,cantidadPedidos);
     }

     return retorno;
 }
