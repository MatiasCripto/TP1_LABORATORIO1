#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	char buffer[6][60];
	int cant = 0;
	int retorno = 0;
	Jugador* auxJugador = NULL;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

		    do
		    {
		        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
		        if(cant < 6)
		        {
		            break;
		        }

		        	auxJugador = jug_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
		            if(auxJugador != NULL)
		            {
		                ll_add(pArrayListJugador,auxJugador);
		                auxJugador = NULL;
		                retorno = 1;
		            }


		    }
		    while(!feof(pFile));

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int cant = 0;
	Jugador* auxJugador = NULL;
	if(pFile != NULL && pArrayListJugador != NULL)
	{
		ll_clear(pArrayListJugador);
	do
	{

	auxJugador = jug_new();
	if(auxJugador != NULL)
	{
		cant = fread(auxJugador,sizeof(Jugador),1,pFile);
		if(cant == 1)
		{
			ll_add(pArrayListJugador, auxJugador);
			auxJugador = NULL;
		}
		else
		{
			if(feof(pFile))
			{
				jug_delete(auxJugador);
				break;
			}

		}
	  }
			else
			{
				break;
			}

		}
		while(!feof(pFile));
		retorno = 1;
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
	char buffer[4][60];
		int cant = 0;
		int retorno = 0;
		Seleccion* auxSeleccion = NULL;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);

			    do
			    {
			        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3]);
			        if(cant < 4)
			        {
			            break;
			        }

			        auxSeleccion = selec_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
			            if(auxSeleccion != NULL)
			            {

			                ll_add(pArrayListSeleccion,auxSeleccion);

			                auxSeleccion = NULL;
			                retorno = 1;
			            }
			    }
			    while(!feof(pFile));

	    return retorno;
}
int parser_JugadorToText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	int auxId;
	char auxNombreCompleto[60];
	int auxEdad;
	char auxPosicion[60];
	char auxNacionalidad[60];
	int auxIdSeleccion;
	int i = 0;
	Jugador*  jugador;
	if(pArrayListJugador != NULL && pFile != NULL)
	{
		fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for (i = 0; i< ll_len(pArrayListJugador);i++ )
			{
				jugador = ll_get(pArrayListJugador,i);
				if (jugador != NULL &&
					jug_getId(jugador,&auxId) &&
					jug_getNombreCompleto(jugador,auxNombreCompleto)&&
					jug_getEdad(jugador,&auxEdad)&&
					jug_getPosicion(jugador,auxPosicion)&&
					jug_getNacionalidad(jugador,auxNacionalidad)&&
					jug_getSIdSeleccion(jugador,&auxIdSeleccion))
				{
					fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",auxId,auxNombreCompleto,auxEdad,auxPosicion,auxNacionalidad, auxIdSeleccion);
					todoOk = 1;
				}
				else
				{
					jugador = NULL;
				}
			}
	}
	return todoOk;
}

