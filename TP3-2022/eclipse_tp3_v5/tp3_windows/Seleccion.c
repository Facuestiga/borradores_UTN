#include "Seleccion.h"


Seleccion* Seleccion_new(){
	Seleccion* aux = malloc(sizeof(Seleccion));

	return aux;
}



Seleccion* Seleccion_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){

	int id;
	char pais[MAX_CHARS];
	char confederacion[MAX_CHARS];
	int convocados;

	Seleccion* this = Seleccion_new();

	if(validarEntero(idStr)==1 && validarCadena(paisStr)==1 &&  validarCadena(confederacionStr)==1 && validarEntero(convocadosStr) == 1 ){

		id = atoi(idStr);
		convocados = atoi(convocadosStr);

		printf("%d  %d  ", id, convocados);

		if(this != NULL){
			//setter Seleccion
			Seleccion_setId(this, id);
			Seleccion_setPais(this, pais);
			Seleccion_setConfederacion(this, confederacion);
			Seleccion_setConvocados(this, convocados);
		}
	}

	return this;
}


int Seleccion_getId(Seleccion* this,int* id){
	int retorno = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int Seleccion_setId(Seleccion* this, int id){
	int retorno = -1;
	if (this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}


int Seleccion_getPais(Seleccion* this, char* pais){
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strncpy(pais, this->pais,MAX_CHARS);
	}

	return retorno;
}
int Seleccion_setPais(Seleccion* this, char*pais){
	int retorno = -1;

	if(this != NULL && validarCadena(pais) == 1)
	{
		retorno = 0;
		strncpy(this->pais, pais,MAX_CHARS);
	}

	return retorno;
}

int Seleccion_getConfederacion(Seleccion* this,char* confederacion){
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strncpy(confederacion, this->confederacion, MAX_CHARS);
	}

	return retorno;
}
int Seleccion_setConfederacion(Seleccion* this, char* confederacion){
	int retorno = -1;

	if(this != NULL && validarCadena(confederacion) == 1)
	{
		retorno = 0;
		strncpy(this->confederacion, confederacion, MAX_CHARS);
	}

	return retorno;
}

int Seleccion_getConvocados(Seleccion* this,int* convocados){
	int retorno = -1;
		if (this != NULL && convocados != NULL)
		{
			*convocados = this->convocados;
			retorno = 0;
		}
		return retorno;
}
int Seleccion_setConvocados(Seleccion* this,int convocados){
	int retorno = -1;
	if (this != NULL && convocados > 0)
	{
		this->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}
