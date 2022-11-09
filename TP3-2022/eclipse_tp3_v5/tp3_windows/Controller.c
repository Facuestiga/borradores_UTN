#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	   int retorno = -1;
	    FILE* pFile;

	    if ( path != NULL && pArrayListJugador != NULL )
	    {
	        system("cls");

	        pFile = fopen( path, "r");
	        if ( pFile == NULL )
	        {
	            printf("No se pudo abrir el archivo\n");
	        }
	        else
	        {

	            if ( parser_JugadorFromText( pFile, pArrayListJugador ) == 0 )
	            {
	                printf( "\nCarga de archivo en modo texto exitosa\n" );
	                retorno = 0;
	            }
	        }
	    }
	    fclose(pFile);
	    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{

    int retorno = -1;
    FILE* pFile;

    if ( path != NULL && pArrayListJugador != NULL )
    {
        system("cls");
        //printf("\nArchivo ""data.bin"" cargado con exito. (modo binario).\n");

        pFile = fopen( path, "rb");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if ( parser_JugadorFromBinary( pFile, pArrayListJugador )==0 )
            {
                printf( "Carga de archivo binario exitosa\n" );
                retorno = 0;
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	 int retorno = 0;
	    int id = 0;
	    char nombreCompleto[MAX_CHARS];
	    int edad;
	    char posicion[MAX_CHARS];
	    char nacionalidad[MAX_CHARS];
	    //int idSeleccion;

	    Jugador* auxJugador;

	    if ( pArrayListJugador != NULL )
	    {
	        system("cls");
	        printf("Alta de Jugador\n");

	        auxJugador = Jugador_new();
	        id = Jugador_getMaxId(pArrayListJugador);
	        id = id + 1;
	        if( utn_get_name(nombreCompleto, MAX_CHARS, "Ingrese nombre y apellido: ", "\nError! Ingrese un nombre", 2) == 0 &&
				utn_getNumero(&edad, "Ingrese una edad: ", "\nError! Ingrese un numero.", 18, MAX_CHARS, 2) == 0 &&
				utn_getDescripcion(posicion, MAX_CHARS, "Ingrese una posicion: ", "\nError! Reintente", 2) == 0 &&
				utn_getDescripcion(nacionalidad, MAX_CHARS, "Ingrese nacionalidad: ", "\nError! Reintente", 2) == 0){

	        	if(Jugador_setId(auxJugador, id) == 0 &&
					Jugador_setNombreCompleto(auxJugador, nombreCompleto) == 0 &&
					Jugador_setEdad(auxJugador, edad) == 0 &&
					Jugador_setPosicion(auxJugador, posicion) == 0 &&
					Jugador_setNacionalidad(auxJugador, nacionalidad) == 0){

	        		ll_add( pArrayListJugador, auxJugador );
	        		printf("\nJugador cargado con exito\n");

	        	}
	        	else {
	        		 Jugador_delete(auxJugador); //libero espacio en memoria
	        		 printf("\nerror al cargar jugador\n");
	        	}

	        }

	    }
	    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador;

	//char seguir = 's';
	//char salir;

	int id;
	int opcion;
	int indice;

	char nombreCompleto[MAX_CHARS];
	int edad;
	char posicion[MAX_CHARS];
	char nacionalidad[MAX_CHARS];

	int confirma;

	controller_listarJugadores(pArrayListJugador);

	if ( pArrayListJugador != NULL )
	{
		//system("cls");
		printf("Modificar datos de Jugador\n");

		printf("Ingrese id: ");
		scanf("%d", &id);
		indice = Jugador_buscarJugadorId( pArrayListJugador, id );
		if ( indice == -1 )
		{
			printf("No se encontro el Jugador\n");
		}
		else
		{
			auxJugador = ll_get(pArrayListJugador, indice);

			do
			{
				system("cls");
				printf("\n");
				printf("ID  	Nombre		Edad		Posicion		Nacionalidad		ID_Seleccion   \n");
				Jugador_mostrarJugador(auxJugador);
				opcion = menuEdit();

				switch (opcion)
				{
				case 1:
					system("cls");
					if(utn_get_name(nombreCompleto, MAX_CHARS, "\nIngrese nombre y apellido:\n", "\nError! Reintente", 2) == 0){
						if(utn_getNumero(&confirma, "Confirma cambio de nombre? 1-[SI] 0-[NO]\n", "\nError! Ingrese un numero", 0, 1, 2) == 0){
							if (confirma == 1)
							{
								if(Jugador_setNombreCompleto(auxJugador, nombreCompleto) == 0){
									printf("\nModificacion exitosa.\n");
								}
							}
							else
							{
								printf("Edición cancelada\n");
							}
						}
					}
					break;

				case 2:
					system("cls");
					//printf("  Editar Horas Trabajadas\n");
					if(utn_getNumero(&edad, "\nIngrese edad: ", "\nError! Ingrese un numero", 18, 50, 2) == 0){
						if(utn_getNumero(&confirma, "Confirma cambio de edad? 1-[SI] 0-[NO]\n", "\nError! Ingrese un numero", 0, 1, 2) == 0){
							if(confirma == 1){
								if(Jugador_setEdad(auxJugador, edad) == 0){
									printf("\nModificacion exitosa.\n");
								}
							}else {
								printf("Edición cancelada\n");
							}
						}
						else {
							printf("Edición cancelada\n");
						}
					}

					break;
				case 3:
					system("cls");
					if(utn_get_name(posicion, MAX_CHARS, "\nIngrese posicion:\n", "\nError! Reintente", 2) == 0){
						if(utn_getNumero(&confirma, "Confirma cambio de nombre? 1-[SI] 0-[NO]\n", "\nError! Ingrese un numero", 0, 1, 2) == 0){
							if (confirma == 1)
							{
								if(Jugador_setPosicion(auxJugador, posicion) == 0){
									printf("\nModificacion exitosa.\n");
								}
							}
							else
							{
								printf("Edición cancelada\n");
							}
						}
					}
					break;

				case 4:
					system("cls");
					if(utn_get_name(nacionalidad, MAX_CHARS, "\nIngrese nacionalidad:\n", "\nError! Reintente", 2) == 0){
						if(utn_getNumero(&confirma, "Confirma cambio de nombre? 1-[SI] 0-[NO]\n", "\nError! Ingrese un numero", 0, 1, 2) == 0){
							if (confirma == 1)
							{
								if(Jugador_setNacionalidad(auxJugador, posicion) == 0){
									printf("\nModificacion exitosa.\n");
								}
							}
							else
							{
								printf("Edición cancelada\n");
							}
						}
					}
					break;
				case 5:
					printf("\nSaliendo del menu de modificacion...\n");
					break;

				/*default:
					printf("Opcion invalida\n");
					break;*/
				}
				system("pause");
			}
			while(opcion != 5);

		}
	}

	return retorno;

}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int id;
	int indice;
	char confirma;

	Jugador* auxJugador;

	controller_listarJugadores(pArrayListJugador);

	if ( pArrayListJugador != NULL )
	{
		system("cls");
		printf("Baja de Jugador\n");

		printf("Ingrese id: ");
		scanf("%d", &id);
		indice = Jugador_buscarJugadorId( pArrayListJugador, id );
		if ( indice == -1 )
		{
			printf("No se encontro el Jugador\n");
		}
		else
		{
			auxJugador = ll_get(pArrayListJugador, indice);
			printf("Jugador seleccionado: ");
			Jugador_mostrarJugador(auxJugador);
			printf("\n");
			printf("Confirma la baja? (S/N)\n");
			fflush(stdin);
			scanf("%c", &confirma);
			if ( tolower(confirma) == 's' )
			{
				ll_remove(pArrayListJugador, indice);
				printf("Baja exitosa\n");
				retorno = 0;
			}
		}

	}
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador;
	int size;

	if (pArrayListJugador != NULL )
	{

		system("cls");
		printf("Listar Jugadores \n");
		size = ll_len(pArrayListJugador);
		printf("ID		NombreCompleto		Edad		Posicion		Nacionalidad		ID_Seleccion          \n");
		for (int i = 0; i < size; i++)
		{
			auxJugador = (Jugador*) ll_get( pArrayListJugador, i );
			Jugador_mostrarJugador(auxJugador);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{

    char seguir = 's';
    char salir;

    int retorno = 0;
    int opcion;
    if ( pArrayListJugador != NULL )
    {
        system("cls");
        printf("Ordenar jugadores\n");

        do
        {
            opcion = menuSort();

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("  Ordenar jugadores por nacionalidad  \n");
                ll_sort( pArrayListJugador, controller_ordenarJugadoresPorNacionalidad, 1 );
                controller_ListJugador(pArrayListJugador);

                break;
            case 2:
                system("cls");
                printf("  Ordenar selecciones por confederacion\n");
                ll_sort( pArrayListJugador, controller_ordenarSeleccionesPorConfederacion, 0 );
                controller_ListJugador(pArrayListJugador);

                break;
            case 3:
                system("cls");
                printf("  Ordenar jugadores por edad\n");
                ll_sort( pArrayListJugador, controller_ordenarJugadoresPorEdad, 1 );
                controller_ListJugador(pArrayListJugador);
                break;
            case 4:
                system("cls");
                printf("  Ordenar jugadores por nombre\n");
                ll_sort( pArrayListJugador, controller_ordenarJugadoresPorNombre, 0 );
                controller_ListJugador(pArrayListJugador);
                break;
            case 5:
                printf("Esta seguro que quiere salir? (S/N)\n");
                fflush(stdin);
                scanf("%c", &salir);
                salir = toupper(salir);
                if (salir == 'S')
                {
                    seguir = 'n';
                }
                else
                {
                    break;
                }
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            system("pause");
        }
        while(seguir == 's');
    }
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
    return 1;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pFile;

	if ( path != NULL && pArrayListSeleccion != NULL )
	{
		system("cls");

		pFile = fopen( path, "r");
		if ( pFile == NULL )
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{

			if ( parser_SeleccionFromText( pFile, pArrayListSeleccion ) == 0 )
			{
				printf( "\nCarga de archivo en modo texto exitosa\n" );
				retorno = 0;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Modificar datos de Jugador
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


int controller_ordenarJugadoresPorNacionalidad(void* jugadorA, void* jugadorB){

    int retorno = -1;
    char jugadorNacionalidad1[MAX_CHARS];
    char jugadorNacionalidad2[MAX_CHARS];
    Jugador* firstJugador = (Jugador*) jugadorA;
    Jugador* secondJugador = (Jugador*) jugadorB;

    if(Jugador_getNacionalidad(firstJugador, jugadorNacionalidad1) == 0 && Jugador_getNacionalidad(secondJugador, jugadorNacionalidad2) == 0){

    }


    return retorno;
}
