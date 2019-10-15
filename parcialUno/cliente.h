#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "utn.h"
#define STATUS_VACIO 0
#define STATUS_OCUPADO 1
#define CANTIDAD_CLIENTES 100

typedef struct
{
    int idCliente;
    char name[51];
    char cuit[51];
    char direccion[100];
    char localidad[100];
    int status;

}sCliente;


void menuClientes(sCliente *cliente, int sizeCliente,int id);
int initArrayStructCliente(sCliente *cliente,int sizeCliente);
int buscarLugarLibre(sCliente *cliente,int sizeCliente);
int addCliente(sCliente *cliente,int sizeCliente,int id);
int imprimirTodosLosClientes(sCliente *cliente, int sizeCliente);
int buscarClientePorId(sCliente *cliente, int sizeCliente);
void menuModificacionClientes(sCliente *cliente, int sizeCliente);
int bajaClientePorId(sCliente *cliente, int sizeCliente);
int buscarPorId(sCliente *cliente, int sizeCliente, int id);
void cliente_hcData(sCliente *cliente, int sizeCliente);



#endif /* CLIENTE_H_ */
