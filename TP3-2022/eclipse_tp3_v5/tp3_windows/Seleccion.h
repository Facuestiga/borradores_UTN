
#ifndef Seleccion_H_INCLUDED
#define Seleccion_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "utn.h"

typedef struct
{
	int id;
	char pais[MAX_CHARS];
	char confederacion[MAX_CHARS];
	int convocados;
}Seleccion;

Seleccion* Seleccion_new();
Seleccion* Seleccion_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void Seleccion_delete();

int Seleccion_getId(Seleccion* this,int* id);
int Seleccion_setId(Seleccion* this, int id);


int Seleccion_getPais(Seleccion* this, char* pais);
int Seleccion_setPais(Seleccion* this, char*pais);

int Seleccion_getConfederacion(Seleccion* this,char* confederacion);
int Seleccion_setConfederacion(Seleccion* this, char* confederacion);

int Seleccion_getConvocados(Seleccion* this,int* convocados);
int Seleccion_setConvocados(Seleccion* this,int convocados);

#endif // Seleccion_H_INCLUDED
