/*
 ============================================================================
 Name        : ParcialLaboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Libros.h"
#define MAX_LIBROS 100
#define MAX_ENTITIES 5

int main(void) {

	setbuf(stdout,NULL);
	Editorial editoriales [MAX_ENTITIES] = { {1, "Editorial 1",1}, {2, "Editorial 2",1}, {3, "Editorial 3",1}, {4, "Editorial 4",1}, {5, "Editorial 5",1} };
	Pais paises[MAX_ENTITIES] =  { {1, "Argentina"}, {2, "Espania"}, {3, "Inglaterra"}, {4, "Colombia"}, {5, "Italia"} };
	Autor autores[MAX_ENTITIES] = { {1, "Sofia", 1 , 1}, {2, "Facundo", 5, 1}, {3, "Rolando", 2, 1}, {4, "Matias", 1, 1}, {5, "Jose", 5, 1} };
	Libro libros[MAX_LIBROS];

	int opcion, opcionListar, opcionInforme;
	int contadorLibro = 0;
	int auxiliarIndice;
	int flagCase1 = 0;

	if(Libro_initArrayLibro(libros, MAX_LIBROS) == 0){
		printf("Se ha inicializado el array de libros.\n");
		do{
			imprimirMenu();
			if(utn_getNumero(&opcion, "Ingrese opcion: \n", "\nERROR! Ingrese opcion: \n", 1, 6, 2) == 0){

				switch(opcion){
				//ALTA
				case 1:
					if(contadorLibro < MAX_LIBROS){
						auxiliarIndice = Libro_buscarLugarLibre(libros, MAX_LIBROS);
						if(auxiliarIndice >= 0){
							if(Libro_addLibro(libros, MAX_LIBROS, auxiliarIndice, editoriales, autores, MAX_ENTITIES)==0){
								printf("\nCarga realizada con exito\n");
								contadorLibro++;
								flagCase1 = 1;
							}
							else{
								printf("\nERROR al realizar la carga\n");
							}
						}
					}else{
						printf("\nNo hay mas espacio\n");
					}
					break;
				//MODIFICACION
				case 2:

					if(flagCase1 != 0){
						printf("\nSeleccione el ID del libro que desea modificar.\nIngrese 0 para cancelar la modificacion.\n");
						if(Libro_modificar(libros, MAX_LIBROS, editoriales, autores, MAX_ENTITIES) == 0){
							printf("\nModificacion exitosa\n");
							Libro_imprimirTodos(libros, MAX_LIBROS);
						}
						else{
							printf("\Modificacion cancelada.\n");
						}
					} else {
						printf("\nDebe ingresar al menos un libro para poder Modificar.\n");
					}

					break;

				//BAJA
				case 3:
					if(contadorLibro > 0 && contadorLibro < MAX_LIBROS){
						if(Libro_imprimirTodos(libros, MAX_LIBROS) == 0){
							if(Libro_bajaLibro(libros, MAX_LIBROS) == 0){
								printf("\nEliminacion exitosa\n");
								Libro_imprimirTodos(libros, MAX_LIBROS);
								contadorLibro--;
							}
							else {
								printf("\nEliminacion cancelada");
							}
						}
					} else{
						printf("\nDebe ingresar al menos 1 libro para poder dar de Baja\n");
					}
					break;

				//INFORMAR
				case 4:
					if(contadorLibro > 0){
						if(utn_getNumero(&opcionInforme, "\nQue desea informar?\n1. Total y promedios de los importes, y cuantos libros superan ese promedio."
												"\n2. Cantidad de libros cuya fecha de publicacion es MENOR al 1-1-2000",
												"\Error! Ingrese un numero", 1, 2, 3) == 0){

							switch(opcionInforme){
							case 1:
								if(Libro_informarPuntoA(libros, MAX_LIBROS) == 0){
									printf("\nInforme exitoso.\n");
								}
								break;
							case 2:
								if(Libro_informarPuntoB(libros, MAX_LIBROS) == 0){
									printf("\nInforme exitoso.\n");
								}
								break;
							}

						}
					} else {
						printf("\nDebe ingresar al menos un libro para poder ingresar a la opcion de Informar\n");
					}
					break;

				//LISTAR
				case 5:
					if(contadorLibro > 0){
						if(utn_getNumero(&opcionListar, "\nQue desea listar?"
												"\n1. Todas las editoriales"
												"\n2. Todos los paises"
												"\n3. Todos los autores"
												"\n4. Todos los libros"
												"\n5. Listado de libros ordenados por importe y titulo"
												"\n\nIngrese opcion: ", "\nError! Ingrese un numero: ",1, 5, 2) == 0){
							switch(opcionListar){
							case 1:
								printf("---- LISTADO DE EDITORIALES ----\n");
									if(Editorial_imprimirEditoriales(editoriales, MAX_ENTITIES) == 0){
										continue;
									}
								break;
							case 2:

								break;
							case 3:

								break;
							case 4:
								printf("---- LISTADO DE LIBROS ----\n");
								if(Libro_listarLibrosCompletos(libros, MAX_LIBROS, editoriales, autores, MAX_ENTITIES) == 0){
									continue;
								}
								break;
							case 5:

								break;
							}

						}
					} else{
						printf("\nDebe ingresar al menos un libro para poder Listar\n");
					}
					break;
				case 6:
					printf("\nSaliendo del programa...");
					system("pause");
					break;
				}


			}
		}while(opcion != 6);
	}else{
		printf("El array de libros no pudo Inicializarse");
	}

	return 0;
}
