/*
 ============================================================================
 Name        : ParcialUnoBrianPavon.c
 Author      : Brian Pavon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "validaciones.h"
#include "cliente.h"
#include "pedidos.h"


#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000


int main(void)
{

	sCliente cliente [CANTIDAD_CLIENTES];
	sPedido pedido [CANTIDAD_PEDIDOS];

	int opcionMenu;

	do
	{
		printf("-------------------MENU DE OPCIONES-------------------\n\n");
		printf("1-Menu Cliente:\n2-Menu de Pedidos: \n3-Menu de Residuos:\n4-Salir\n");
		getInt(&opcionMenu,"Ingrese la opcion: \n","Opcion incorrecta",0,4,2);
		switch(opcionMenu)
		{
		case 1:
			menuClientes(cliente,CANTIDAD_CLIENTES);
			break;
		case 2:

			menuPedidos(pedido,CANTIDAD_PEDIDOS,cliente,CANTIDAD_PEDIDOS);
			break;
		case 3:

			break;

		}
	}while(opcionMenu != 4);
	return EXIT_SUCCESS;
}
