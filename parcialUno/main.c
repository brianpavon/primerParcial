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
	int flag = 0;

    initArrayStructCliente(cliente,CANTIDAD_CLIENTES);
    initArrayStructPedido(pedido,CANTIDAD_PEDIDOS);
	do
	{
	    system("cls");
    	printf("-------------------MENU DE OPCIONES-------------------\n\n");
		printf("1-Menu Cliente:\n2-Menu de Pedidos: \n3-Reportes:\n4-Salir\n");
		getInt(&opcionMenu,"Ingrese la opcion: \n","Opcion incorrecta\n",0,4,2);
		switch(opcionMenu)
		{
		case 1:
			menuClientes(cliente,CANTIDAD_CLIENTES);

			flag = 1;
			break;
		case 2:
            if(flag == 1)
            {
            menuPedidos(pedido,CANTIDAD_PEDIDOS,cliente,CANTIDAD_CLIENTES);
            }
            else if(flag == 0)
            {
                printf("Primero debe dar de altas clientes\n\n");
                system("pause");
            }
			break;
		case 3:
            if(flag == 1)
            {
              pedidos_menuReportes(pedido,CANTIDAD_PEDIDOS,cliente,CANTIDAD_CLIENTES);
            }
            else if(flag == 0)
            {
                printf("Primero debe dar de altas clientes\n\n");
                system("pause");
            }
			break;

		}
	}while(opcionMenu != 4);
    return 0;
}
