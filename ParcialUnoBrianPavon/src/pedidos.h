/*
 * pedidos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define RESUELTO 1
#define PENDIENTE 0
#define ISEMPTY 0
#include "utn.h"
#include "cliente.h"

typedef struct
{
	int idPedido;
	int status;
	int statusPedido;
	char tipoPlastico;
	int idCliente;

}sPedido;

void menuPedidos(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente);
sCliente pedido_obtenerCliente(sCliente *cliente, int sizeCliente, sPedido *pedido);
int initArrayStructPedido(sPedido *pedido,int sizePedido);
int pedidos_buscarLugarLibre(sPedido *pedido,int sizePedido);


#endif /* PEDIDOS_H_ */
