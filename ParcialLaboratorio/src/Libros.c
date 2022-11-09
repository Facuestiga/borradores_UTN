/*
 * Libros.c
 *
 *  Created on: 30 sep. 2022
 *      Author: Facu
 */

#include "Libros.h"
#include "utn.h"

/**
 * Funcin que autoincrementa el ID
 */
int idAutomatico = 1;
int Libro_ObtenerIdUnico(void) {
	return idAutomatico++;
}

void Pais_imprimirUno(Pais pais){
	printf("ID: %d\n",pais.id);
	printf("Pais: %s\n",pais.descripcion);
}

int Pais_imprimirPaises(Pais *arrayPaises, int size){
	int rtn = -1;
	int i;

	if (size > 0) {
		//ESTA TODO BIEN
		for (i = 0; i < size; i++) {
			if (arrayPaises[i].status == OCUPADO) { //Si 'estado' == OCUPADO
				Pais_imprimirUno(arrayPaises[i]);
				rtn = 0; //Ok
			}
		}
	}

	return rtn;
}

void Genero_imprimirUno(Genero genero){
	printf("ID: %d\n",genero.id);
	printf("Descripcion: %s\n",genero.descripcion);
}

int Genero_imprimirGeneros(Genero *arrayGeneros, int size){
	int rtn = -1;
	int i;

	if (size > 0) {
		for (i = 0; i < size; i++) {
			if (arrayGeneros[i].status == OCUPADO) { //Si 'estado' == OCUPADO
				Genero_imprimirUno(arrayGeneros[i]);
				rtn = 0; //Ok
			}
		}
	}

	return rtn;
}

void Autor_imprimirUno(Autor arrayAutor){
	printf("ID: %d\n",arrayAutor.id);
	printf("Nombre: %s\n",arrayAutor.nombre);
}

int Autor_imprimirAutores(Autor *arrayAutores, int size){
	int rtn = -1;
	int i;

	if (size > 0) {
		//ESTA TODO BIEN
		for (i = 0; i < size; i++) {
			if (arrayAutores[i].status == OCUPADO) { //Si 'estado' == OCUPADO
				Autor_imprimirUno(arrayAutores[i]);
				rtn = 0; //Ok
			}
		}
	}

	return rtn;
}



void Editorial_imprimirUna(Editorial editorial){
	printf("ID: %d\n", editorial.id);
	printf("Descripcion: %s\n", editorial.descripcion);
}


int Editorial_imprimirEditoriales(Editorial *arrayEditoriales, int size){
	int rtn = -1;
	int i;

	if (size > 0) {
		//ESTA TODO BIEN
		for (i = 0; i < size; i++) {
			if (arrayEditoriales[i].status == OCUPADO) { //Si 'estado' == OCUPADO
				Editorial_imprimirUna(arrayEditoriales[i]);
				rtn = 0; //Ok
			}
		}
	}

	return rtn;
}


/**
 * @brief Funcion que imprime un solo libro
 * @param arrayLibro: arrayLibro de listado de libros
 */
void Libro_imprimirUno(Libro arrayLibro) {
	printf("---------------------------");
	printf("\nID: %d\n",arrayLibro.id);
	printf("\nID_GENERO: %d\n", arrayLibro.idGenero);
	printf("ID_AUTOR: %d\n",arrayLibro.idAutor);
	printf("ID_EDITORIAL: %d\n", arrayLibro.idEditorial);
	printf("Titulo: %s\n",arrayLibro.titulo);
	printf("Precio: $%.2f\n",arrayLibro.precio);
	printf("Fecha de publicacion: %d/%d/%d\n",arrayLibro.fechaPublicacion.dia, arrayLibro.fechaPublicacion.mes, arrayLibro.fechaPublicacion.anio);
	printf("---------------------------");
	printf("---------------------------\n\n");
}

/**
 * @brief Funcion que imprime todos los libros
 * @param arrayLibro: arrayLibro de libros
 * @param size: longitud del arrayLibro
 * @return Retorna 0 caso Exito! (-1) Error!
 */
int Libro_imprimirTodos(Libro arrayLibro[], int size) {
	int rtn = -1;
	int i;

	if (arrayLibro != NULL && size > 0) {
			//ESTA TODO BIEN
			for (i = 0; i < size; i++) {
				if (arrayLibro[i].status == OCUPADO) { //Si 'estado' == OCUPADO
					Libro_imprimirUno(arrayLibro[i]);
					rtn = 0; //Ok
				}
			}
	}

	return rtn;
}

/***
 * Funcion para inicializar el status del array en 0
 * @param arrayLibro
 * @param size
 * @return retorna 1 caso Exito, 0 en caso de Error
 *  */
int Libro_initArrayLibro(Libro *arrayLibro,int size){
	int i;
	int retorno = -1;
	if(size > 0)
	{

		for(i=0;i<size;i++)
		{
			arrayLibro[i].status = LIBRE;

		}
		retorno = 0;
	}
	return retorno;
}

/**
 * Funcion que busca un lugar libre en el array
 * @param arrayLibro
 * @param size
 * @return retorna el index del array que esta libre, -1 en caso de error
 */
int Libro_buscarLugarLibre(Libro *arrayLibro,int size){
	int index = -1;
	int i;
	if(size > 0)
	{
		index = 0;
		for(i=0;i<size;i++)
		{
			if(arrayLibro[i].status == LIBRE)
			{
				index = i;
				break;
			}
		}

	}
	return index;
}

/**
 * Funcion que busca un ID pasado por parametro
 * @param arrayLibro
 * @param size
 * @param id: ID a buscar
 * @return retorno el indice donde se encuentra el id a buscar, -1 en caso de error
 */
int Libro_buscarPorIdParametro(Libro *arrayLibro, int size, int id){
	int rtn = -1;
	int i;

	if (size > 0) {
		for (i = 0; i < size; i++) {
			if (arrayLibro[i].id == id && arrayLibro[i].status == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/**
 * Funcion para dar de ALTA un libro
 * @param arrayLibro
 * @param size
 * @param indice: posicion del array donde se va a dar de alta
 * @param arrayEditoriales
 * @param arrayAutores
 * @param sizeEntities
 * @return retorna 0 en caso de exito, o -1 en caso de error
 */
int Libro_addLibro(Libro *arrayLibro,int size,int indice, Editorial *arrayEditoriales, Autor *arrayAutores, Genero *arrayGeneros ,int sizeEntities){
	int retorno = -1;
	int idAutor;
	int idEditorial;
	int idGenero;
	int i;
	Libro bufferLibro;

	if(size > 0 && indice < size && indice >= 0){
		if(utn_getDescripcion(bufferLibro.titulo, MAX_CHARS, "\nIngrese nombre del Libro: ", "\nError! Ingrese un nombre", 2) == 0){

			strncpy(bufferLibro.titulo, strlwr(bufferLibro.titulo), MAX_CHARS);
			bufferLibro.titulo[0] = toupper(bufferLibro.titulo[0]);
			for(i=0; i<size; i++){
				if(bufferLibro.titulo[i] == ' '){
					bufferLibro.titulo[i + 1] = toupper(bufferLibro.titulo[i + 1]);
				}
			}

			printf("\nSeleccione el ID del genero al que pertenece el libro\n");
			for(i = 0; i < sizeEntities; i++){
				printf("\nID: %d\nDescripcion:%s", arrayGeneros[i].id, arrayGeneros[i].descripcion);
			}
			if(utn_getNumero(&idGenero, "\nIngrese ID del genero del libro ", "\nError! Ingrese un numero \n", 1, 5, 2) == 0){

			printf("\nSeleccione el ID del autor al que pertenece el libro\n");
			for(i = 0; i<sizeEntities; i++){
				printf("\nID: %d\nNombre:%s", arrayAutores[i].id, arrayAutores[i].nombre);
			}
			if(utn_getNumero(&idAutor, "\nIngrese el ID del autor", "\nError. Ingrese un numero.\n", 1, 5, 2) == 0){
				printf("\nSeleccione el ID de la editorial a la que pertenece el libro\n");
				for(i = 0; i<sizeEntities; i++){
					printf("\nID: %d\nDescripcion:%s", arrayEditoriales[i].id, arrayEditoriales[i].descripcion);
				}

				if(utn_getNumero(&idEditorial, "\n\nIngrese el ID de la editorial ", "\nError. Ingrese un numero.\n", 1, 5, 2) == 0 &&
				   utn_getNumeroFlotante(&bufferLibro.precio, "\nIngrese precio: ", "\nError! Ingrese un numero", 10, 10000000, 2)== 0 &&
				   utn_getNumero(&bufferLibro.fechaPublicacion.dia, "\nIngrese fecha de publicacion(Numerica)\nDia: ", "\nError! Ingrese un numero: ", 1, 31, 2) == 0 &&
				   utn_getNumero(&bufferLibro.fechaPublicacion.mes, "\nMes: ", "\nError! Ingrese un numero: ", 1, 12, 2) == 0 &&
				   utn_getNumero(&bufferLibro.fechaPublicacion.anio, "Anio: ", "\nError! Ingrese un numero: ", 1800, 2022, 2) == 0 ){
				   bufferLibro.id = Libro_ObtenerIdUnico();
				   bufferLibro.idGenero = idGenero;
				   bufferLibro.idAutor = idAutor;
				   bufferLibro.idEditorial = idEditorial;
				   bufferLibro.status = 1;
				   arrayLibro[indice] = bufferLibro;
				   Libro_imprimirUno(arrayLibro[indice]);
				   retorno = 0;
				}
			}
		}
		}
	}
	return retorno;
}

/**
 * Funcion para dar de BAJA un libro
 * @param arrayLibro
 * @param size
 * @return retorna 0 caso exito, 0 -1 en caso de error
 */
int Libro_bajaLibro(Libro *arrayLibro, int size){
	int retorno = -1;
	int idBaja;
	int index;
	int confirma;

	if(size > 0){
		if(utn_getNumero(&idBaja, "\nIngrese ID del libro a eliminar: ", "\nError! Ingrese un numero: ", 1, 100, 3) == 0){
			while (Libro_buscarPorIdParametro(arrayLibro, size, idBaja) == -1) {
				printf("NO EXISTE ID.");
				printf("INGRESE ID A DAR DE BAJA: ");
				utn_getNumero(&idBaja, "\nIngrese ID del libro a eliminar: ", "\nError! Ingrese un numero: ", 1, 100, 3);
			}
			index = Libro_buscarPorIdParametro(arrayLibro, size, idBaja);
			if(utn_getNumero(&confirma, "\nEsta seguro que desea continuar con la eliminacion? [1-SI]-[0-NO]", "\nError! Ingrese un numero", 0, 1, 3) == 0){
				if(confirma){
					arrayLibro[index].status = LIBRE;

					//Baja Exitosa
					retorno = 0;
				}else {
					printf("Se ha cancelado el proceso de eliminacion");
				}
			}
		}
	}

	return retorno;
}

/**
 * Funcion para modificar libros
 * @param arrayLibro
 * @param size
 * @param arrayEditoriales
 * @param arrayAutores
 * @param sizeEntities
 * @return
 */
int Libro_modificar(Libro *arrayLibro,int size, Editorial *arrayEditoriales, Autor *arrayAutores, Genero *arrayGeneros, int sizeEntities){

	int retorno = -1;
	int index;
	Libro auxLibro;

		index = Libro_buscarLibroPorId(arrayLibro, size);
		if(index > -1 && size > 0){
			auxLibro = arrayLibro[index];

			auxLibro = Libro_modificarUnLibro(auxLibro, arrayEditoriales, arrayAutores, arrayGeneros,sizeEntities);

			arrayLibro[index] = auxLibro;
			retorno = 0;
		}

	return retorno;
}

/**
 * Funcion que modifica UN libro del array
 * @param libro
 * @param arrayEditoriales
 * @param arrayAutores
 * @param sizeEntities
 * @return retorna el Libro
 */
Libro Libro_modificarUnLibro(Libro libro, Editorial *arrayEditoriales, Autor *arrayAutores, Genero *arrayGeneros, int sizeEntities){
	int opcion;
		if(utn_getNumero(&opcion, "\nIngrese la opcion de lo que desea modificar\n"
								"1.Titulo\n"
								"2.Precio\n"
								"3.Fecha de publicacion\n"
								"4.Autor\n"
								"5.Editorial\n"
								"6.Genero\n"
								"\n0.CANCELAR Modificacion\n", "Opcion no habilitada", 0, 6, 2) == 0){



		switch (opcion) {
		case 0:
			printf("\nModificacion Cancelada\n");
			break;
		case 1:
			utn_getDescripcion(libro.titulo, MAX_CHARS, "\nIngrese titulo del libro", "error\n", 2);
			break;
		case 2:
			utn_getNumeroFlotante(&libro.precio, "Ingrese precio: ", "\nError! Ingrese un precio: ", 10, 1000000, 2);
			break;
		case 3:
			utn_getNumero(&libro.fechaPublicacion.dia, "\nIngrese dia", "\nError\n", 1, 31, 2);
			utn_getNumero(&libro.fechaPublicacion.mes, "\nIngrese mes", "\nError\n", 1, 31, 2);
			utn_getNumero(&libro.fechaPublicacion.anio, "\nIngrese anio", "\nError\n", 1, 31, 2);
			break;
		case 4:
			if(Autor_imprimirAutores(arrayAutores, sizeEntities) == 0){
				utn_getNumero(&libro.idAutor, "\nIngrese el ID del autor\n", "Error. Ingrese un numero\n", 1, 5, 2);
			}

			break;
		case 5:
			if(Editorial_imprimirEditoriales(arrayEditoriales, sizeEntities) == 0){
				utn_getNumero(&libro.idEditorial, "\nIngrese el ID de la editorial\n", "Error. Ingrese un numero\n", 1, 5, 2);
			}
			break;
		case 6:
			if(Genero_imprimirGeneros(arrayGeneros, sizeEntities) == 0){
				utn_getNumero(&libro.idGenero, "\nIngrese el ID del genero\n", "\nError! Ingrese un numero \n", 1, 5, 2);
			}
			break;
		}
		}else{
			printf("\nError en la modificacion.\n");
		}
		return libro;
}

/**
 * Busca libro por ID
 * @param arrayLibro
 * @param size
 * @return retorna 0 caso exitoso, o -1 en caso de Error
 */
int Libro_buscarLibroPorId(Libro *arrayLibro, int size){
	int rtn = -1;
	int flag = 0;
	int i;
	int buscarID;

	if (size > 0) {

		Libro_imprimirTodos(arrayLibro, size);

		//PEDIR UN ID
		if(utn_getNumero(&buscarID, "\nIngrese ID: ", "Error! ID incorrecto.\nVuelva  a intentarlo\n", 0, 100, 2) == 0){
			for (i = 0; i < size; i++) {
				if (arrayLibro[i].status == OCUPADO && arrayLibro[i].id == buscarID) {
					flag = 1;
					rtn = i; //retorno index del ID que estoy buscando
					break;

				}
			}
		}
		if (flag == 0) { //Si no encontre ID...
			rtn = -2;
		}

	}
	return rtn;
}

/***
 * Funcion para listar libro con sus respectivos datos
 * @param arrayLibros
 * @param size
 * @param arrayEditoriales
 * @param arrayAutores
 * @param sizeEntities
 * @return retorna 0 en caso Exito, o -1 en caso de error
 */
int Libro_listarLibrosCompletos(Libro *arrayLibros, int size, Editorial *arrayEditoriales, Autor *arrayAutores, Genero *arrayGeneros, int sizeEntities){
	int retorno = -1;
	int i, j, k, x;
	printf("\nTITULO\t\t\tAUTOR\t\t\tEDITORIAL\t\t\tGENERO\t\t\tPRECIO\t\t\tFECHA DE PUBLICACION");
	for(i = 0; i<size; i++){

		if(arrayLibros[i].status == OCUPADO){
			for(j = 0; j < sizeEntities; j++){
				if(arrayLibros[i].idAutor == arrayAutores[i].id){
					for(k = 0; k < sizeEntities; k++){
						if(arrayLibros[i].idEditorial == arrayEditoriales[i].id){
							for(x = 0; x<sizeEntities; x++){
								if(arrayLibros[i].idGenero == arrayGeneros[i].id){
									printf("\n%s\t\t"
										   "%s\t\t\t%s\t\t%s\t\t\t%.2f\t\t%d/%d/%d", arrayLibros[i].titulo, arrayAutores[j].nombre, arrayEditoriales[j].descripcion,arrayGeneros[i].descripcion,arrayLibros[i].precio, arrayLibros[i].fechaPublicacion.dia, arrayLibros[i].fechaPublicacion.mes, arrayLibros[i].fechaPublicacion.anio);
								}
							}
						}
					}
			}
		}
		}
	}

	return retorno;
}

/***Menu***/
/**
 * Imprime el menu principal
 */
void imprimirMenu(){
	printf("\n\tMenu Principal - Facundo Estigarribia\n\n"
			"1.Alta\n"
			"2.Modificacion\n"
			"3.Baja\n"
			"4.Informar\n"
			"5.Listar\n"
			"6.Salir\n\n");
}

/***Informar***/

/**
 * Funcion que informe el total y promedio de los importes y cuantos libros superan ese promedio
 * @param arrayLibro
 * @param size
 * @return retorna 0 en caso exitoso, o -1 en caso de Error
 */
int Libro_informarPuntoA(Libro *arrayLibro, int size){
	int retorno = -1;
	int i;
	int contadorLibro = 0;
	//int contadorMayorQuePromedio = 0;
	float acumuladorPrecio = 0;
	float promedio;

	if(size > 0){
		for(i = 0; i<size; i++){
			if(arrayLibro[i].status == OCUPADO){
				acumuladorPrecio = acumuladorPrecio + arrayLibro[i].precio;
				contadorLibro++;
			}
		}
		if(contadorLibro > 0 && acumuladorPrecio > 0){
			promedio = acumuladorPrecio/contadorLibro;

			printf("\n.El total de los importes es: %.2f"
				   "\n.El promedio de los importes es: %.2f"
				   , acumuladorPrecio, promedio);
			Libro_contarMayoresQueElPromedio(arrayLibro, size, promedio);
			retorno = 0;
		}else{
			printf("\nNo se pudo calcular el promedio.\n");
			retorno = -2;
		}

	}
	return retorno;
}


int Libro_contarMayoresQueElPromedio(Libro *arrayLibro, int size, float promedio){
	int retorno = -1;
	int i;
	int contadorLibro = 0;

	if(size > 0 && promedio > 0){
		for(i = 0; i<size; i++){
			if(arrayLibro[i].status == OCUPADO && (arrayLibro[i].precio > promedio)){
				contadorLibro++;
				retorno = 0;
				printf("\n.La cantidad de libros que su precio supera el promedio de importes es: %d",contadorLibro);
			}
		}
	}

	return retorno;
}
/**
 * Funcion que informe la cantidad de libro cuya fecha de publicacion es anterior al 1/1/2000
 * @param arrayLibro
 * @param size
 * @return retorna 0 en caso exitoso, o -1 en caso de Error
 */
int Libro_informarPuntoB(Libro *arrayLibro, int size){
	int retorno = -1;
	int i;
	int contadorLibro = 0;

	if(size > 0){
		for(i = 0; i<size; i++){
			if(arrayLibro[i].status == OCUPADO && arrayLibro[i].fechaPublicacion.anio < 2000){
				contadorLibro++;
			}
		}
		if(contadorLibro > 0){
			printf("\n.La cantidad de libros cuya fecha de publicacion es anterior al 1/1/2000 son: %d\n", contadorLibro);
		}else{
			printf("\n.Ningun libro ha sido publicado antes del 1/1/2000");
		}
	}

	return retorno;
}


/**
 * Funcion para ordenar el array por importe y por titulo
 */
int Libro_ordenarImporteYTitulo(Confederacion *arrayC, int size, Jugador *arryJ, int sizeJ){
	int retorno = -1;
	int auxSize = size;
	int flagSwap;
	int i;
	int auxiliarCmp;
	Confederacoin buffer;
	if(size > 0){
		do{

			flagSwap = 0;

			for(i = 0; i < size-1; i++){

				auxiliarCmp = strncmp(arrayLibro[i].titulo, arrayLibro[i + 1].titulo, MAX_CHARS);

				if(auxiliarCmp > 0 ||
				   (auxiliarCmp == 0 && arrayLibro[i].precio > arrayLibro[i + 1].precio)){
					  flagSwap = 1;
					  buffer = arrayLibro[i];
					  arrayLibro[i] = arrayLibro[i + 1];
					  arrayLibro[i + 1] = buffer;

				   }
			}
			size--;
		}while(flagSwap);
		Libro_imprimirTodos(arrayLibro, auxSize);
	}

	return retorno;
}

/**
 * Funcion que lista los libros cuyo genero no es Novela
 * @param arrayLibros
 * @param size
 * @return
 */
int Libro_listarLibroQueNoSeanNovelas(Libro *arrayLibros, int size){
	int retorno = -1;
	int i;

	if(size > 0){
		for(i = 0; i<size; i++){
			if(arrayLibros[i].status == OCUPADO){
				if(arrayLibros[i].idGenero != 5){
					Libro_imprimirUno(arrayLibros[i]);
				}
			}
		}
	}

	return retorno;
}

int Libro_listarLibrosArgentinosDeEditorialDeterminada(Libro *arrayLibros, int size, Autor *arrayAutores, int sizeEntities){
	int retorno = -1;
	int i;

	if(size > 0 && sizeEntities > 0){
		for(i = 0; i<size; i++){
			if(arrayLibros[i].status == OCUPADO){

			}
		}
	}

	return retorno;
}
