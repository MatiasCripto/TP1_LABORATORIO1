#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Seleccion.h"
#include "Jugador.h"


Seleccion* selec_new()
{
	Seleccion* nuevaSeleccion;
	nuevaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
		    if(nuevaSeleccion != NULL)
		    {
		    	nuevaSeleccion->id = 0;

		        strcpy(nuevaSeleccion->pais," ");

		        strcpy(nuevaSeleccion->confederacion," ");

		        nuevaSeleccion->convocados = 0;

		    }

		    return nuevaSeleccion;
}
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* nuevaSeleccion;
	nuevaSeleccion = selec_new();
		if(nuevaSeleccion != NULL)
		{
			nuevaSeleccion->id = atoi(idStr);
			strcpy(nuevaSeleccion->pais,paisStr);
			strcpy(nuevaSeleccion->confederacion,confederacionStr);
			selec_setConvocados(nuevaSeleccion,atoi(convocadosStr));

		}

	return nuevaSeleccion;
}
void selec_delete(Seleccion* this)
{
	if(this != NULL)
		{
			free(this);
		}
}

int selec_getId(Seleccion* this,int* id)
{
	int todoOk = 0;
		if(this != NULL && id != NULL)
		{
			*id = this->id;
			todoOk = 1;
		}

	return todoOk;
}
int selec_getPais(Seleccion* this,char* pais)
{
	int todoOk = 0;
		if(this != NULL && pais != NULL)
		{
			strcpy(pais,this->pais);
			todoOk = 1;
		}

	return todoOk;
}
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int todoOk = 0;
		if(this != NULL && confederacion != NULL)
		{
			strcpy(confederacion,this->confederacion);
			todoOk = 1;
		}

	return todoOk;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int todoOk = 0;
			if(this != NULL && convocados >= 0 && convocados <= 22)
			{
				this->convocados = convocados;
				todoOk = 1;
			}
			else
			{
				printf("cantidad invalida\n");
			}

		return todoOk;
}
int selec_getConvocados(Seleccion* this,int* convocados)
{

	int todoOk = 0;
	    if(this != NULL && convocados != NULL)
	    {
	        *convocados = this->convocados;
	        todoOk = 1;
	    }
	return todoOk;
}
int selec_mostrarSeleccion( Seleccion* seleccion)
{
	int todoOk = 0;
	    int id;
	    char pais[60];
	    char confederacion[60];
	    int convocados;



	    if(selec_getId(seleccion, &id)&&
	       selec_getPais(seleccion, pais)&&
		   selec_getConfederacion(seleccion, confederacion)&&
		   selec_getConvocados(seleccion, &convocados)
		   )
	    {
	        printf("|%4d|%-30s|%-20s|    %4d     |\n",id,pais,confederacion,convocados);
	        todoOk = 1;
	    }

	    return todoOk;
}
