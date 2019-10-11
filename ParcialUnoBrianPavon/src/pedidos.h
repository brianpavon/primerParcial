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
#include "utn.h"
#include "cliente.h"
typedef struct
{
	int idPedido;
	int status;
	int idPlastico;
	int idCliente;

}sPedido;

void menuPedidos(sPedido *pedido,int sizePedido);
pedido_obtenerCliente(sCliente *cliente, int sizeCliente, sPedido *pedido);

#endif /* PEDIDOS_H_ */
