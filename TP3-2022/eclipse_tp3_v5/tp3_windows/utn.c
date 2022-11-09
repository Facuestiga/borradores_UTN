/*
 * utn.c
 *
 *  Created on: 1 nov. 2022
 *      Author: Facu
 */

#include "utn.h"



static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[MAX_CHARS]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);

		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[MAX_CHARS];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * @brief funcion para obtener un nombre, solo con caracteres
 * @param pResultado puntero a donde se va a guardar la cadena obtenida
 * @param len la longitud maxima de la cadena
 * @param mensaje lo que se va  amostrar por pantalla para que vea el usuario
 * @param mensajeError para mostrar que tuvo un error
 * @param reintentos cantidad maxima de reintentos por errores
 * @return Retorna 0 Exito, (-1) Error!
 */
int utn_get_name(char* pResultado,int size,char* mensaje,char* mensajeError,int reintentos){
	int rtn = -2;
	char buffer[size];
	if(pResultado != NULL && size > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		rtn = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, size) && utn_Val_isValidName(buffer) )
			{
				strncpy(pResultado,buffer, size);
				rtn = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return rtn;
}

/**
 * @brief Valida que lo que hay dentro de la cadena es un nombre valido
 * @param nombre: array que contiene el nombre
 * @return devuelve -1 si no se obtuvo, y 0 si esta todo ok
 */
int utn_Val_isValidName(char* nombre){
	int i=0;
	int rtn = -1;
	if(nombre != NULL)
	{

		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==' '))
			{
				rtn = 0;
				break;
			}
			i++;
		}
	}
	return rtn;
}

int get_myGets(char* pResultado, int len)
{
	int returnFunction = -1;
	fflush(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		fflush(stdin);
		if(pResultado[strlen(pResultado)-1]== '\n')
		{
			pResultado[strlen(pResultado)-1]='\0';
		}
		returnFunction = 1;
	}
	return returnFunction;
}

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[MAX_CHARS];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[MAX_CHARS];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

// VALIDACIONES

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero entero
param: se pide un tipo char para validar si es un numero entero
return: int que refiere al estado -1 = 1 || 0 = 0
/////////////////////////////////////////////////////////////////////
*/
int validarEntero(char* pIngreso)
{
	int status = -1;
	int size = strlen(pIngreso);

	if(pIngreso != NULL && size > 0)
	{
		for(int i = 0;i< size;i++)
		{
			if(isdigit(pIngreso[i]) == 0)
			{
				if(i == 0)
				{
					if(pIngreso[0] != '-')
					{
						status = 0;
						break;
					}
				}
				else
				{
					status = 0;
				}
			}
		}
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es un numero flotante (Si es entero, no avisa)
param: se pide un tipo char para validar si es un numero flotante
return: int que refiere al estado -1 = 1 || 0 = 0
/////////////////////////////////////////////////////////////////////
*/
int validarFlotante(char* pIngreso)
{
	int sign = 0;
	int digits = 0;
	int status = -1;
	int size = strlen(pIngreso);

	if(pIngreso != NULL && size > 0)
	{
		for(int i = 0;i < size; i++)
		{
			if(pIngreso[i] == '.' || pIngreso[i] == ',')
			{
				sign++;
			}
			else
			{
				if(isdigit(pIngreso[i]) == 0)
				{
					if(i == 0)
					{
						if(pIngreso[0] != '-')
						{
							status = 0;
							break;
						}
					}
					else
					{
						status = 0;
						break;
					}
				}
			}
			if(isdigit(pIngreso[i]) == 1)
			{
				digits++;
			}
		}

		if(sign > 1 || digits == 0)
		{
			status = 0;
		}

	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide un char ingresado anteriormente para validar sí es un tipo caracter realmente
param: se pide un tipo char para validar si es un caracter
return: int que refiere al estado -1 = 1 || 0 = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCaracter(char ingreso)
{
	int status = -1;

	if(isalpha(ingreso) == 0)
	{
		status = 0;
	}

	return status;
}

/*
/////////////////////////////////////////////////////////////////////
brief: Función que pide una cadena de caracteres anteriormente ingresada para validar sí es alfabética
param: se pide un tipo char para validar si es un array de caracteres alfabéticos
return: int que refiere al estado -1 = 1 || 0 = 0
/////////////////////////////////////////////////////////////////////
*/
int validarCadena(char* pIngreso)
{
	int i= 0;
	int retorno;
	int size = strlen(pIngreso);

	if(pIngreso!=NULL && size > 0)
	{
		retorno= -1;

		while(pIngreso[i]!='\0')
		{
			if((pIngreso[i] >= 'A' && pIngreso[i] <= 'z' ) || pIngreso[i] == 32 || pIngreso[i] == '.' || pIngreso[i] == ',' || pIngreso[i] == '-'|| pIngreso[i] == '_')
			{
				if(pIngreso[i] > 'Z' && pIngreso[i] < 'a')
				{
					retorno = 0;
					break;
				}
				i++;

			}
			else
			{
				retorno= 0;
				break;
			}

		}
	}

	return retorno;
}



