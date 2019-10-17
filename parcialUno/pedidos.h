#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define COMPLETADO 2
#define PENDIENTE 1
#define ISEMPTY 0
#include "utn.h"
#include "cliente.h"

typedef struct
{
	int idPedido;
	int status;
    float cantidadRecolectada;
	float plasticoHdpe;
	float plasticoLdpe;
	float plasticoPp;
	int idCliente;

}sPedido;

void menuPedidos(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente,int id);
sCliente pedido_obtenerCliente(sCliente *cliente, int sizeCliente, sPedido *pedido);
int initArrayStructPedido(sPedido *pedido,int sizePedido);
int pedidos_buscarLugarLibre(sPedido *pedido,int sizePedido);
void pedido_hcData(sPedido *pedido, int sizePedido);
int addPedidos(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido,int id);
int imprimirPedidosPendientesConClientes(sPedido *pedido, int sizePedido,sCliente *cliente, int sizeCliente);
int imprimirPedidosPendientes(sPedido *pedido, int sizePedido);
int pedidos_procesarPlasticos(sPedido *pedido,int sizePedido);
void pedidos_menuReportes(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente);
int imprimirPedidosCompletosConClientes(sPedido *pedido, int sizePedido,sCliente *cliente, int sizeCliente);
int cantidadDePedidosPorCliente(sPedido *pedido,int sizePedido,sCliente *cliente,int sizeCliente);

#endif /* PEDIDOS_H_ */
