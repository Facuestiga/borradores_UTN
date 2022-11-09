#include "parser.h"

/** \brief Parsea los datos de los Selecciones desde el archivo Selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int cant;
	char id[MAX_CHARS];
	char nombreCompleto[MAX_CHARS];
	char edad[MAX_CHARS];
	char posicion[MAX_CHARS];
	char nacionalidad[MAX_CHARS];
	char idSeleccion[MAX_CHARS];
	Jugador* auxJugador;

	if (pFile != NULL && pArrayListJugador != NULL  )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]%[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if (cant < 6)
			{
				break;
			}

			auxJugador =Jugador_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if (auxJugador != NULL)
			{
				ll_add( pArrayListJugador, auxJugador );
				retorno = 0;
				auxJugador = NULL;
			}
		}
		while (!feof(pFile));
	}
	return retorno;

}

/** \brief Parsea los datos de los Selecciones desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int cant;
	Jugador* auxJugador;

	if (pFile != NULL && pArrayListJugador != NULL  )
	{
		while ( !feof(pFile) )
		{
			auxJugador = Jugador_new();

			if ( auxJugador != NULL )
			{
				cant = fread( auxJugador, sizeof(Jugador), 1, pFile);

				if ( cant == 1 )
				{
					ll_add(pArrayListJugador, auxJugador);
					retorno = 0;
					auxJugador = NULL;
				}
			}
		}
	}
	return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int cant;
	char id[MAX_CHARS];
	char pais[MAX_CHARS];
	char confederacion[MAX_CHARS];
	char convocados[MAX_CHARS];

	Seleccion* auxSeleccion;

	if (pFile != NULL && pArrayListSeleccion != NULL  )
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
		do
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
			if (cant < 4)
			{
				break;
			}

			auxSeleccion =Seleccion_newParametros(id, pais, confederacion, convocados );
			if (auxSeleccion != NULL)
			{
				ll_add( pArrayListSeleccion, auxSeleccion );
				retorno = 0;
				auxSeleccion = NULL;
			}
		}
		while (!feof(pFile));
	}
	return retorno;
}

