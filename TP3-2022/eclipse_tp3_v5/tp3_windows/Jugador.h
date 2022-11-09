
#ifndef Jugador_H_INCLUDED
#define Jugador_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

}Jugador;

Jugador* Jugador_new();
Jugador* Jugador_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr);

void Jugador_delete(Jugador* pJugador);

int Jugador_getMaxId(LinkedList* pArrayListJugador);

int Jugador_setId(Jugador* this,int id);
int Jugador_getId(Jugador* this,int* id);

int Jugador_setNombreCompleto(Jugador* this,char* nombreCompleto);
int Jugador_getNombreCompleto(Jugador* this,char* nombreCompleto);

int Jugador_setPosicion(Jugador* this,char* posicion);
int Jugador_getPosicion(Jugador* this,char* posicion);

int Jugador_setNacionalidad(Jugador* this,char* nacionalidad);
int Jugador_getNacionalidad(Jugador* this,char* nacionalidad);

int Jugador_setEdad(Jugador* this,int edad);
int Jugador_getEdad(Jugador* this,int* edad);

int Jugador_setIdSeleccion(Jugador* this,int idSeleccion);
int Jugador_getIdSeleccion(Jugador* this,int* idSeleccion);


int Jugador_buscarJugadorId(LinkedList* pArrayListJugador, int id);

int menu();
int menuEdit();
int Jugador_mostrarJugador(Jugador* jugador);

#endif // Jugador_H_INCLUDED
