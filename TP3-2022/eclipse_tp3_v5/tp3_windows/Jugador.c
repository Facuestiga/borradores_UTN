

#include "Jugador.h"



int menu()
{

    int opcion = 0;
    int retorno = -1;
    system("cls");
    printf("\n     *** ABM Jugador ***\n");
    if(utn_getNumero(&opcion, "1. Cargar archivos jugadores.csv MODO TEXTO\n"
    		"2. Cargar archivos jugadores.csv MODO BINARIO\n"
    		"3. Cargar archivos selecciones.csv MODO TEXTO\n"
    		//"4. Cargar archivos selecciones.csv MODO BINARIO\n"
    		"5. Alta de Jugador\n"
    		"6. Modificar datos de Jugador\n"
    		"7. Baja de Jugador\n"
    		"8. Listar jugadores\n"
    		"9. Convocar jugadores\n"
    		"10. Ordenar y listar\n"
    		"11. Generar archivo binario\n"
    		"12. Cargar archivo binario\n"
    		"13. Guardar archivos .csv\n"
    		"14. Salir\n"
    		"Ingrese opcion: \n", "Error! Ingrese un numero\n", 1, 14, 2) == 0){
    	retorno = opcion;
    }
    return retorno;
}



Jugador* Jugador_new(){
	Jugador* aux = malloc(sizeof(Jugador));

	return aux;
}

Jugador* Jugador_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr){

	int id;
	char nombreCompleto[51];
	int edad;
	char posicion[51];
	char nacionalidad [51];
	int idSeleccion;

	Jugador* this = Jugador_new();

	if(validarEntero(idStr)==1 && validarCadena(nombreCompletoStr)==1 &&  validarCadena(posicionStr)==1 && validarFlotante(nacionalidadStr)==1 &&
		validarCadena(edadStr) == 1 &&  validarEntero(idSeleccionStr) == 1 ){

		id = atoi(idStr);
		edad = atoi(edadStr);
		idSeleccion = atoi(idSeleccionStr);
		printf("%d  %d  %d", id, edad, idSeleccion);

		if(this != NULL){
			//setter Jugador
			Jugador_setId(this, id);
			Jugador_setNombreCompleto(this, nombreCompleto);
			Jugador_setPosicion(this, posicion);
			Jugador_setNacionalidad(this, nacionalidad);
			Jugador_setEdad(this, edad);
			Jugador_setIdSeleccion(this, idSeleccion);

		}
	}

	return this;
}


void Jugador_delete(Jugador* pJugador){
	 if (pJugador != NULL)
	{
		free(pJugador);
	}
}


int Jugador_setId(Jugador* this,int id){
	int retorno = -1;
	if (this != NULL )
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
int Jugador_getId(Jugador* this,int* id){

    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
       retorno = 0;
    }
    return retorno;
}

int Jugador_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int status = -1;

	if(this != NULL && validarCadena(nombreCompleto) == 1)
	{
		status = 0;
		strncpy(this->nombreCompleto, nombreCompleto,MAX_CHARS);
	}

	return status;
}
int Jugador_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int status = -1;

		if(this != NULL)
		{
			status = 0;
			strncpy(nombreCompleto, this->nombreCompleto,MAX_CHARS);
		}

		return status;
}

int Jugador_setPosicion(Jugador* this,char* posicion){
	int status = -1;

	if(this != NULL && validarCadena(posicion) == 1)
	{
		status = 0;
		strncpy(this->posicion, posicion,MAX_CHARS);
	}

	return status;
}
int Jugador_getPosicion(Jugador* this,char* posicion){
	int status = -1;

	if(this != NULL)
	{
		status = 0;
		strncpy(posicion, this->posicion,MAX_CHARS);
	}

	return status;
}

int Jugador_setNacionalidad(Jugador* this,char* nacionalidad){
	int status = -1;

	if(this != NULL && validarCadena(nacionalidad) == 1)
	{
		status = 0;
		strncpy(this->nacionalidad, nacionalidad,MAX_CHARS);
	}

	return status;
}
int Jugador_getNacionalidad(Jugador* this,char* nacionalidad){
	int status = -1;

	if(this != NULL)
	{
		status = 0;
		strncpy( nacionalidad, this->nacionalidad,MAX_CHARS);
	}

	return status;
}

int Jugador_setEdad(Jugador* this,int edad){
	int status = -1;

	if(this != NULL )
	{
		status = 0;
		this->edad = edad;
	}

	return status;
}
int Jugador_getEdad(Jugador* this,int* edad){
	int status = -1;

	if(this != NULL)
	{
		status = 0;
		*edad = this->edad;
	}

	return status;
}

int Jugador_setIdSeleccion(Jugador* this,int idSeleccion){
	int status = -1;

	if(this != NULL)
	{
		status = 0;
		this->idSeleccion= idSeleccion;
	}

	return status;
}
int Jugador_getIdSeleccion(Jugador* this,int* idSeleccion){
	int status = -1;

	if(this != NULL)
	{
		status = 0;
		*idSeleccion = this->idSeleccion;
	}

	return status;
}



int Jugador_getMaxId(LinkedList* pArrayListJugador){
	Jugador* auxJugador = NULL;
	int mayor = -1;
	int id;
	if(pArrayListJugador != NULL)
	{
		for( int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
			Jugador_getId(auxJugador, &id);
			if( i==0 || id > mayor)
			{
				mayor = id;
			}
		}
	}
	return mayor;
}


int Jugador_buscarJugadorId(LinkedList* pArrayListJugador, int id){
	int indice = -1;
	int idAux;
	int size = ll_len(pArrayListJugador);
	Jugador* auxJugador;

	for (int i = 0; i < size; i++)
	{
		auxJugador = ll_get(pArrayListJugador, i);
		if( Jugador_getId(auxJugador, &idAux) == 0 && idAux == id)
		{
			indice = i;
		}
	}
	return indice;
}

int Jugador_mostrarJugador(Jugador* jugador){
    int retorno = -1;
    int id;
    char nombreCompleto[MAX_CHARS];
    int edad;
    char posicion[MAX_CHARS];
    char nacionalidad[MAX_CHARS];
    int idSeleccion;


    if (jugador != NULL)
    {
       retorno = 1;
        if ( Jugador_getId( jugador, &id ) == 0 &&
                Jugador_getNombreCompleto( jugador, nombreCompleto ) == 0 &&
                Jugador_getEdad( jugador, &edad) == 0 &&
                Jugador_getPosicion(jugador, posicion) == 0 &&
				Jugador_getNacionalidad(jugador, nacionalidad) == 0 &&
				Jugador_getIdSeleccion(jugador, &idSeleccion) == 0
           )
        {
            printf ("%-7d %-15s %-8d %-15s %-15s        %-6d\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
           retorno = 0;
        }
    }
    return retorno;
}

int menuEdit(){
    int opcion = 0;
    int retorno = -1;
    //system("cls");
    printf("\n");
    printf("     *** Menu de edicion ***\n");
    if(utn_getNumero(&opcion, "1. Editar nombre\n"
    						  "2. Editar edad\n"
    						  "3. Editar posicion\n"
    						  "4. Editar nacionalidad\n"
    						  "5. Salir\n"
    						  "Ingrese opcion: \n", "\nError! Ingrese un numero", 1, 5, 2) == 0){
    	retorno = opcion;
    }

    return retorno;
}
