/*
 * cliente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "utn.h"
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int idCliente;
    int status;
    char name[51];
    char cuit[51];
    char direccion[100];
    char localidad[100];
    int idPedido;
}sCliente;

typedef struct
{
    int id;
    char descripcion[50];
}sGhostDos;

void menuClientes(sCliente *cliente, int sizeCliente);
int initArrayStruct(sCliente *cliente,int sizeCliente);
int buscarLugarLibre(sCliente *cliente,int sizeCliente);
int addCliente(sCliente *cliente,int sizeCliente,int id);
int imprimirTodosLosClientes(sCliente *cliente, int sizeCliente);
int buscarClientePorId(sCliente *cliente, int sizeCliente);
void menuModificacionClientes(sCliente *cliente, int sizeCliente);
int bajaClientePorId(sCliente *cliente, int sizeCliente);
int buscarPorId(sCliente *cliente, int sizeCliente, int id);
//void ghostHardcodeo(sCliente *cliente, int sizeCliente);



#endif /* CLIENTE_H_ */
