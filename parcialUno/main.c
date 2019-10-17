#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "cliente.h"
#include "pedidos.h"

#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int main()
{
    sCliente cliente [CANTIDAD_CLIENTES];
	sPedido pedido [CANTIDAD_PEDIDOS];

	int opcionMenu;
	int flagCliente = 0;
	int flagPedido = 0;
    int idCliente = 0;
    int idPedido = 0;
    initArrayStructCliente(cliente,CANTIDAD_CLIENTES);
    initArrayStructPedido(pedido,CANTIDAD_PEDIDOS);
    cliente_hcData(cliente,CANTIDAD_CLIENTES);
    pedido_hcData(pedido, CANTIDAD_PEDIDOS);
	do
	{
	    system("cls");
	    //cliente_hcData(cliente,CANTIDAD_CLIENTES);
    	printf("-------------------MENU DE OPCIONES-------------------\n\n");
		printf("1-Alta Cliente:\n2-Menu de modificacion de cliente: \n3-Baja de cliente:\n4-Crear pedido:\n5-Procesar residuos\n6-Informes: \n7-Salir\n");
		getInt(&opcionMenu,"Ingrese la opcion: \n","Opcion incorrecta\n",0,7,2);
		switch(opcionMenu)
		{
		case 1:
		    system("cls");
			if(addCliente(cliente,CANTIDAD_CLIENTES,idCliente)==0)
            {
                idCliente++;
                flagCliente = 1;

            }
            else
            {
                printf("No se dio de alta el cliente\n");
                system("pause");
            }
			break;
		case 2:
            if(flagCliente == 1)
            {
            menuModificacionClientes(cliente,CANTIDAD_CLIENTES);
            }
            else if(flagCliente == 0)
            {
                printf("Primero debe dar de altas clientes\n\n");
                system("pause");
            }
			break;
		case 3:
            if(flagCliente == 1)
            {
              bajaClientePorId(cliente,CANTIDAD_CLIENTES);
            }
            else if(flagCliente == 0)
            {
                printf("Primero debe dar de altas clientes\n\n");
                system("pause");
            }
			break;
        case 4:
            if(flagCliente == 1 && addPedidos(cliente,CANTIDAD_CLIENTES,pedido,CANTIDAD_PEDIDOS,idPedido)==0)
            {
                idPedido++;
                flagPedido = 1;
            }
            else if(flagCliente == 0)
            {
                printf("Primero debe dar de altas clientes\n\n");
                system("pause");
            }
            break;
        case 5:
            if(flagCliente == 1 && flagPedido == 1)
            {

                pedidos_procesarPlasticos(pedido,CANTIDAD_PEDIDOS);
            }
            else if(flagCliente == 0 && flagPedido == 0)
            {
                printf("Primero debe dar de altas clientes y pedidos\n\n");
                system("pause");
            }
            break;
        case 6:
                if(flagCliente == 1 && flagPedido == 1)
                {
                    pedidos_menuReportes(pedido,CANTIDAD_PEDIDOS,cliente,CANTIDAD_CLIENTES);
                }
                else if(flagCliente == 0 && flagPedido == 0)
                {
                    printf("Primero debe dar de altas clientes y pedidos\n\n");
                    system("pause");
                }
            break;

		}
	}while(opcionMenu != 7);
    return 0;
}
