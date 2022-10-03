/*
 * Libros.h
 *
 *  Created on: 30 sep. 2022
 *      Author: Facu
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 200
#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	int id;
	char descripcion[MAX_CHARS];
}Pais;

typedef struct{
	int id;
	char descripcion[MAX_CHARS];
	int status;
}Editorial;

typedef struct{
	int id;
	char nombre[MAX_CHARS];
	int idPais;
	int status;
}Autor;

typedef struct{
	int id;
	char titulo[MAX_CHARS];
	Fecha fechaPublicacion;
	float precio;
	int idAutor;
	int idEditorial;
	int status;
}Libro;
int Libro_ObtenerIdUnico(void);
void Libro_imprimirUno(Libro arrayLibro);
int Libro_imprimirTodos(Libro arrayLibro[], int size);

int Libro_initArrayLibro(Libro *arrayLibro,int size);
int Libro_buscarLugarLibre(Libro *arrayLibro,int size);
int Libro_addLibro(Libro *arrayLibro,int size,int indice, Editorial *arrayEditoriales, Autor *arrayAutores, int sizeEntities);
int Libro_bajaLibro(Libro *arrayLibro, int size);
int Libro_modificar(Libro *arrayLibro,int size, Editorial *arrayEditoriales, Autor *arrayAutores, int sizeEntities);
Libro Libro_modificarUnLibro(Libro libro, Editorial *arrayEditoriales, Autor *arrayAutores, int sizeEntities);
int Libro_buscarLibroPorId(Libro *arrayLibro, int size);
int Libro_buscarPorIdParametro(Libro *arrayLibro, int size, int id);


/***Listar entidades****/
void Autor_imprimirUno(Autor arrayAutor);
int Autor_imprimirAutores(Autor *arrayAutores, int size);
void Editorial_imprimirUna(Editorial editorial);
int Editorial_imprimirEditoriales(Editorial *arrayEditoriales, int size);
int Libro_listarLibrosCompletos(Libro *arrayLibros, int size, Editorial *arrayEditoriales, Autor *arrayAutores, int sizeEntities);

/***Menu***/
void imprimirMenu();

/***Informar***/
int Libro_informarPuntoA(Libro *arrayLibro, int size);
int Libro_informarPuntoB(Libro *arrayLibro, int size);
#endif /* LIBROS_H_ */
