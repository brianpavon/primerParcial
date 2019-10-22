#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "cliente.h"
#include "pedidos.h"
#include "informes.h"

#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int main()
{
    sCliente cliente [CANTIDAD_CLIENTES];
	sPedido pedido [CANTIDAD_PEDIDOS];

	int opcionMenu;
    int idCliente = 0;
    int idPedido = 0;

    initArrayStructCliente(cliente,CANTIDAD_CLIENTES);
    initArrayStructPedido(pedido,CANTIDAD_PEDIDOS);
    cliente_hcData(cliente,CANTIDAD_CLIENTES);
    pedido_hcData(pedido, CANTIDAD_PEDIDOS);
	do
	{
	    system("cls");
    	printf("-------------------MENU DE OPCIONES-------------------\n\n");
		printf("1-Alta Cliente:\n"
                "2-Menu de modificacion de cliente:\n"
                "3-Baja de cliente:\n"
                "4-Crear pedido:\n"
                "5-Procesar residuos\n"
                "6-Informes:\n"
                "7-Informes segunda parte\n"
                "8-Salir\n");
		getInt(&opcionMenu,"Ingrese la opcion: \n","Opcion incorrecta\n",0,8,2);
		switch(opcionMenu)
		{
		case 1:
		    system("cls");
			if(addCliente(cliente,CANTIDAD_CLIENTES,idCliente)==0)
            {
                idCliente++;

            }
            else
            {
                printf("No se dio de alta el cliente\n");
                system("pause");
            }
			break;
		case 2:
		    menuModificacionClientes(cliente,CANTIDAD_CLIENTES);
			break;
		case 3:
            bajaClientePorId(cliente,CANTIDAD_CLIENTES);
            system("pause");
			break;
        case 4:
            if(addPedidos(cliente,CANTIDAD_CLIENTES,pedido,CANTIDAD_PEDIDOS,idPedido)==0)
            {
                idPedido++;
            }
            break;
        case 5:
            pedidos_procesarPlasticos(pedido,CANTIDAD_PEDIDOS);
            system("pause");
            break;
        case 6:
                pedidos_menuReportes(pedido,CANTIDAD_PEDIDOS,cliente,CANTIDAD_CLIENTES);
                system("pause");
            break;
        case 7:
            informes_menuInformesMasComplejos(cliente,CANTIDAD_CLIENTES,pedido,CANTIDAD_PEDIDOS);
            break;

		}
	}while(opcionMenu != 8);
    return 0;
}
