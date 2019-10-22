#ifndef INFORMES_H_
#define INFORMES_H_

#include "utn.h"
#include "cliente.h"
#include "pedidos.h"

void informes_menuInformesMasComplejos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteConMasPedidosPendientes(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteConMasPedidosCompletados(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido);
int informes_cantidadPedidosPorCliente(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteRecicloMasKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteRecicloMenosKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteReciclaronMasMilKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido);
int informes_clienteReciclaronMenosCienKilos(sCliente *cliente,int sizeCliente, sPedido *pedido, int sizePedido);
int informes_porcentajeReciclado(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido);
int informes_imprimirLocalidades(sCliente *cliente,int sizeCliente);
int informes_cantidadPorLocalidadPedidosPendientes(sCliente *cliente, int sizeCliente, sPedido *pedido, int sizePedido);
int informes_promedioPropilenoPorCliente(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido);
int informes_cantidadKilosPlasticoPorCuit(sCliente *cliente,int sizeCliente,sPedido *pedido,int sizePedido);

#endif /* INFORMES_H_ */
