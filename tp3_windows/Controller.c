#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "validaciones.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
		if(path != NULL && pArrayListJugador != NULL)
		{
			FILE* pFile = fopen(path,"r");
			if(pFile != NULL)
			{
				if(parser_JugadorFromText(pFile , pArrayListJugador))
				{
					retorno = 1;
				}
			}
			else
			{
				printf("No se pudo abrir el archivo\n");
			}
			fclose(pFile);
		}

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
	int retorno = 0;
	if(path != NULL && pArrayListJugador != NULL)
	{
		FILE* pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			if(parser_JugadorFromBinary(pFile , pArrayListJugador))
			{
				retorno = 1;
			}
		}
		else
		{
			printf("No se pudo abrir el archivo\n");
		}

		fclose(pFile);
	}
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
    int todoOk = 0;
    char buffer[6][60];
    int nexId = 0;
    Jugador* auxJugador = NULL;


    if(pArrayListJugador != NULL)
    {
    	FILE* pFile = fopen("id.txt","r");
    	if(pFile != NULL)
    	{
    		fscanf(pFile,"%[^\n]",buffer[0]);
    	}
    	fclose(pFile);
    	if((utn_getNombre(buffer[1], 60, "Ingrese Nombre\n", "Error, reingrese nombre\n", 99) == 0&&
    	getDeCadenaAEntero(buffer[2], 3, "Ingrese edad\n", "Error, reingrese edad\n", 99) == 0 &&
    	jug_asignarNombrePosiciones(buffer[3]) == 0&&
    	jug_asignarNombreNacionalidad(buffer[4])) == 0)
    	{
    		auxJugador = jug_newParametros(buffer[0], buffer[1],buffer[2], buffer[3],buffer[4], buffer[5]);
    		ll_add(pArrayListJugador,auxJugador);


    		FILE* pFile = fopen("id.txt","w");
				if(pFile != NULL)
			{
				nexId = atoi(buffer[0]);
				nexId++;
				fprintf(pFile,"%d\n",nexId);
			}
    	fclose(pFile);
    	}
    }
    return todoOk;
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
	int retorno = 0;
	int auxId;
	int auxIndice;
	int auxIdMax;
	char seguir;
	Jugador* auxJugador;

	if(pArrayListJugador!=NULL)
	{
		auxIdMax = controller_idSubSiguiente (pArrayListJugador);
		controller_listarJugadores(pArrayListJugador);
		if(utn_getNumero(&auxId,"\n ingrese el numero de id del jugador que desea modificar","\n error",1,auxIdMax,99)==0)
		{
			auxIndice = controller_buscarPorIdJugador(pArrayListJugador,auxId);
			if(auxIndice>=0)
			{
				auxJugador = ll_get(pArrayListJugador,auxIndice);
				jug_mostrarJugador(auxJugador);
				utn_getCharSeguir(&seguir, "Confirma la modificacion de este jugador? presione s para confirmar:\n", "Error, reingrese confirmacion\n", 99);

				if(auxJugador != NULL && seguir == 's')
				{
					jug_modificarDatosJugador(auxJugador);
					retorno=1;
				}
				else
				{
					printf("Modificacion cancelada por el usuario\n");
				}
			}
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
	int retorno = 0;
	int auxId;
	int auxIndice;
	int auxIdMax;
	char seguir;
	Jugador* auxJugador;

	if(pArrayListJugador!=NULL)
	{
		auxIdMax = controller_idSubSiguiente (pArrayListJugador);
		controller_listarJugadores(pArrayListJugador);
		if(utn_getNumero(&auxId,"\n ingrese el numero de id del jugador que desea eliminar","\n error",1,auxIdMax,99)==0)
		{
			auxIndice=controller_buscarPorIdJugador(pArrayListJugador,auxId);
			if(auxIndice>=0)
			{
				auxJugador = ll_get(pArrayListJugador,auxIndice);
				jug_mostrarJugador(auxJugador);
				if(utn_getCharSeguir(&seguir, "Confirma la baja? presione s para confirmar:\n", "Error, reingrese confirmacion\n", 99)== 0)
				{
					if(auxJugador != NULL && seguir == 's')
					{
						ll_remove(pArrayListJugador,auxIndice);
						printf("Baja exitosa\n");
						retorno=1;
					}
					else
					{
						printf("Baja cancelada por el usuario\n");
					}
				}
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
	int todoOk = 0;
	int i = 0;
	Jugador* auxJugador = NULL;
	if(pArrayListJugador != NULL)
	{
		printf("===============================================================================================\n");
		printf("|id  |  Nombre Completo             | edad |      posicion      |  nacionalidad |  Seleccion  |\n");
		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
			jug_mostrarJugador(auxJugador);
		}
		printf("===============================================================================================\n");
		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadoresNacionalidad(LinkedList* pArrayListJugador)
{
	int todoOk = 0;
		int i = 0;
		Jugador* auxJugador = NULL;
		if(pArrayListJugador != NULL)
		{
			printf("===============================================================================================\n");
			printf("|id  |  Nombre Completo             | edad |      posicion      |  nacionalidad |  Seleccion  |\n");
			ll_sort(pArrayListJugador, controller_ordenarPorJugadorNacionalidad, 1);
			for(i = 0; i < ll_len(pArrayListJugador); i++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
				jug_mostrarJugador(auxJugador);
			}
			printf("===============================================================================================\n");
			printf("\n\n");
			todoOk = 1;
		}

		return todoOk;
}
int controller_ordenarJugadoresEdad(LinkedList* pArrayListJugador)
{
	int todoOk = 0;
		int i = 0;
		Jugador* auxJugador = NULL;
		if(pArrayListJugador != NULL)
		{
			printf("===============================================================================================\n");
			printf("|id  |  Nombre Completo             | edad |      posicion      |  nacionalidad |  Seleccion  |\n");
			ll_sort(pArrayListJugador, controller_OrdenarJugadorPorEdad, 1);
			for(i = 0; i < ll_len(pArrayListJugador); i++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
				jug_mostrarJugador(auxJugador);
			}
			printf("===============================================================================================\n");
			printf("\n\n");
			todoOk = 1;
		}

		return todoOk;
}
int controller_ordenarJugadoresNombre(LinkedList* pArrayListJugador)
{
	int todoOk = 0;
		int i = 0;
		Jugador* auxJugador = NULL;
		if(pArrayListJugador != NULL)
		{
			printf("===============================================================================================\n");
			printf("|id  |  Nombre Completo             | edad |      posicion      |  nacionalidad |  Seleccion  |\n");
			ll_sort(pArrayListJugador, controller_ordenarJugadorPorNombre, 1);
			for(i = 0; i < ll_len(pArrayListJugador); i++)
			{
				auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
				jug_mostrarJugador(auxJugador);
			}
			printf("===============================================================================================\n");
			printf("\n\n");
			todoOk = 1;
		}

		return todoOk;
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
	int retorno = 0;

	FILE* pFile;

	if (path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			exit (1);
		}
		else
		{
			parser_JugadorToText(pFile , pArrayListJugador);
			retorno = 1;
		}

	}
	fclose(pFile);
	return retorno;
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
	int retorno = 0;
	int limite;
	int i = 0;
	Jugador*  jugador = NULL;
	FILE* pFile;

	if (path != NULL && pArrayListJugador != NULL && ll_isEmpty(pArrayListJugador) != 1)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			exit (1);
		}
		limite =ll_len(pArrayListJugador);
		for (i = 0; i < limite;i++ )
		{
			jugador = ll_get(pArrayListJugador,i);
			if (jugador != NULL)
			{
				fwrite(jugador, sizeof(Jugador),1,pFile);
				retorno = 1;
			}
			else
			{
				jugador = NULL;
			}
		}
	}
	fclose(pFile);
	return retorno;
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
	int retorno = 0;
			if(path != NULL && pArrayListSeleccion != NULL)
			{
				FILE* pFile = fopen(path,"r");
				if(pFile != NULL)
				{
					if(parser_SeleccionFromText(pFile , pArrayListSeleccion))
					{
						retorno = 1;
					}
				}
				else
				{
					printf("No se pudo abrir el archivo\n");
				}
				fclose(pFile);
			}

		    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int auxId;
	int auxIndice;
	int convocados;
	int auxIdMax;
	char seguir;
	Seleccion* auxSeleccion;

	if(pArrayListSeleccion!=NULL)
	{
		auxIdMax = controller_idSubSiguiente (pArrayListSeleccion);
		controller_listarSelecciones(pArrayListSeleccion);
		if(utn_getNumero(&auxId,"\n ingrese el numero de id de la seleccion que desea modificar","\n error",1,22,99)==0)
		{
			auxIndice = controller_buscarPorIdJugador(pArrayListSeleccion,auxId);
			if(auxIndice>=0)
			{
				auxSeleccion = ll_get(pArrayListSeleccion,auxIndice);
				//jug_mostrarSeleccion(auxSeleccion);
				utn_getCharSeguir(&seguir, "Confirma la modificacion de este jugador? presione s para confirmar:\n", "Error, reingrese confirmacion\n", 99);

				if(auxSeleccion != NULL && seguir == 's')
				{
					if((utn_getNumero(&convocados,"Ingrese cantidad de convocados\n", "Error, reingrese convocados\n",0,22, 99)) == 0)
					{
						if(selec_setConvocados(auxSeleccion, convocados) == 1)
						{
							printf("cantidad de convocados modificado con exito\n");
						}
						else
						{
							printf("Error en la modificacion\n");
						}
					}
					retorno=1;
				}
				else
				{
					printf("Modificacion cancelada por el usuario\n");
				}
			}
		}
	}
	return retorno;
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
	int todoOk = 0;
	int i = 0;
	Seleccion* auxSeleccion = NULL;
	if(pArrayListSeleccion != NULL)
	{
		printf("=======================================================================\n");
		printf("|id  |            Pais             | Confederacion      | Convocados  |\n");
		printf("-----------------------------------------------------------------------\n");
		for(i = 0; i < ll_len(pArrayListSeleccion); i++)
		{
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
			selec_mostrarSeleccion(auxSeleccion);
		}
		printf("========================================================================\n");
		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
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

	int todoOk = 0;
	int i = 0;
	Seleccion* auxSeleccion = NULL;
	if(pArrayListSeleccion != NULL)
	{
		printf("=======================================================================\n");
		printf("|id  |            Pais             | Confederacion      | Convocados  |\n");
		printf("-----------------------------------------------------------------------\n");
		ll_sort(pArrayListSeleccion, controller_ordenarSeleccionPorConfederacion, 1);

			for(i = 0; i < ll_len(pArrayListSeleccion); i++)
			{
				auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
				selec_mostrarSeleccion(auxSeleccion);
			}
			printf("========================================================================\n");
			printf("\n\n");
			todoOk = 1;

	}

	return todoOk;
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
	int retorno = 0;
	int limite;
	int i = 0;
	Seleccion*  seleccion = NULL;
	FILE* pFile;

	if (path != NULL && pArrayListSeleccion != NULL && ll_isEmpty(pArrayListSeleccion) != 1)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			exit (1);
		}
		limite =ll_len(pArrayListSeleccion);
		for (i = 0; i < limite;i++ )
		{
			seleccion = ll_get(pArrayListSeleccion,i);
			if (seleccion != NULL)
			{
				fwrite(seleccion, sizeof(Jugador),1,pFile);
				retorno = 1;
			}
			else
			{
				seleccion = NULL;
			}
		}
	}
	fclose(pFile);
	return retorno;
}
int controller_listaDeListados(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador)
{
	int todoOk = 1;
	if(pArrayListSeleccion!= NULL && pArrayListJugador != NULL)
	{
		switch(menuListados())
		{
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 3:
				controller_listarJugadoresConvocados(pArrayListJugador);
				break;
		}
	}
	return todoOk;
}
int controller_idSubSiguiente (LinkedList* pArrayListJugador)
{
	Jugador*  jugador = NULL;
	int siguienteId;
	int id;
	int tamanio;
	int i = 0;
	if (pArrayListJugador != NULL)
	{
		tamanio = ll_len(pArrayListJugador);
		for(i = 0;i<tamanio; i++)
		{
			jugador = ll_get(pArrayListJugador,i);
			if(jugador != NULL)
			{
				jug_getId(jugador,&id);
				if(id > siguienteId || i == 0)
				{
					siguienteId = id;
				}
			}
		}
	}


	return siguienteId;
}
int controller_buscarPorIdJugador(LinkedList* pArrayListJugador,int idABuscar)
{
	Jugador*  auxJugador = NULL;
	int bufferId;
	int tamanio;
	int i = 0;
	int retorno = -1;
	if (pArrayListJugador != NULL && idABuscar>0)
	{
		tamanio = ll_len(pArrayListJugador);
		for(i = 0;i<tamanio; i++)
		{
			auxJugador = ll_get(pArrayListJugador,i);
			if(auxJugador != NULL)
			{
				jug_getId(auxJugador,&bufferId);
				if(idABuscar == bufferId )
				{
					retorno=i;
					break;
				}
			}
		}
	}
	return retorno;
}

int controller_buscarPorIdSeleccion(LinkedList* pArrayListSeleccion,int idABuscar)
{
	Seleccion* auxSeleccion   = NULL;
	int bufferId;
	int tamanio;
	int i = 0;
	int retorno = -1;
	if (pArrayListSeleccion != NULL && idABuscar>0)
	{
		tamanio = ll_len(pArrayListSeleccion);
		for(i = 0;i<tamanio; i++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion,i);
			if(auxSeleccion != NULL)
			{
				selec_getId(auxSeleccion,&bufferId);
				if(idABuscar == bufferId )
				{
					retorno=i;
					break;
				}
			}
		}
	}
	return retorno;
}
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int idSeleccion;
	int idJugador;
	int indiceSeleccion;
	int indiceJugador;
	int convocado;
	int seleccionDelJugador;
	Seleccion* auxSeleccion = NULL;
	Jugador* auxJugador = NULL;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarSelecciones(pArrayListSeleccion);
		if(utn_getNumero(&idSeleccion, "Elija el id de la seleccion\n", "Error, reingrese el id\n", 1, 32, 50) == -1)
		{
			printf("Id erroneo\n");
		}
		else
		{
			indiceSeleccion = controller_buscarPorIdSeleccion(pArrayListSeleccion, idSeleccion);
			if(indiceSeleccion == -1)
			{
				printf("No existe el id\n");
			}
			else
			{
				auxSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);
				if(auxSeleccion != NULL)
				{
					selec_getConvocados(auxSeleccion, &convocado);
					if(convocado < 22)
					{
						controller_listarJugadores(pArrayListJugador);
						if(utn_getNumero(&idJugador, "Elija el id del jugador a convocar\n", "Error, reingrese el id\n", 1, 500, 50) == -1)
						{
							printf("Id erroneo\n");
						}
						else
						{
							indiceJugador = controller_buscarPorIdJugador(pArrayListJugador, idJugador);
							if(indiceJugador != -1)
							{
								auxJugador = ll_get(pArrayListJugador, indiceJugador);
								if(auxJugador != NULL)
								{
									jug_getSIdSeleccion(auxJugador, &seleccionDelJugador);
									if(seleccionDelJugador == 0)
									{
										jug_setIdSeleccion(auxJugador, idSeleccion);
										selec_setConvocados(auxSeleccion, convocado+1);
										todoOk = 1;
										printf("El jugador se convoco con exito!!!\n");
									}
									else
									{
										printf("El jugador ya esta convocado en otra seleccion\n");
									}
								}
							}
						}
					}
					else
					{
						printf("El cupo de convocados ya esta cubierto\n");
					}
				}
			}
		}
	}
	return todoOk;
}
int controller_quitarJugadorConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	int idJugador;
	int indiceJugador;
	int indiceSeleccion;
	int setearId = 0;
	int convocado;
	int seleccionDelJugador;
	Seleccion* auxSeleccion = NULL;
	Jugador* auxJugador = NULL;
	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadoresConvocados(pArrayListJugador);
		if(utn_getNumero(&idJugador, "Elija el id del jugador\n", "Error, reingrese el id", 1, 500, 50) == -1)
		{
			printf("Id erroneo\n");
		}
		else
		{
			indiceJugador = controller_buscarPorIdJugador(pArrayListJugador, idJugador);
			if(indiceJugador != -1)
			{
				auxJugador = ll_get(pArrayListJugador, indiceJugador);
				if(auxJugador != NULL)
				{
					jug_getSIdSeleccion(auxJugador, &seleccionDelJugador);
					if(seleccionDelJugador > 0)
					{
						indiceSeleccion = controller_buscarPorIdSeleccion(pArrayListSeleccion, seleccionDelJugador);
						if(indiceSeleccion == -1)
						{
							printf("No existe el id\n");
						}
						else
						{
							auxSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);
							jug_setIdSeleccion(auxJugador, setearId);
							selec_getConvocados(auxSeleccion, &convocado);
							selec_setConvocados(auxSeleccion, convocado-1);
							todoOk = 1;
							printf("El jugador se modifico con exito!!!\n");
						}
					}
					else
					{
						printf("No se pudo quitar el jugador de la seleccion\n");
					}
				}
			}
		}
	}
	return todoOk;
}

int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	int i = 0;
	int idSeleccion;
	Jugador* auxJugador = NULL;
	if(pArrayListJugador != NULL)
	{
		printf("===============================================================================================\n");
		printf("|id  |  Nombre Completo             | edad |      posicion      |  nacionalidad |  Seleccion  |\n");
		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(auxJugador, &idSeleccion);
			if(idSeleccion != 0)
			{
				jug_mostrarJugador(auxJugador);
			}
		}
		printf("===============================================================================================\n");
		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}
int controller_filtarConvocados(LinkedList* pArrayListJugador, LinkedList* jugConvocados)
{
	int todoOk = 0;
	int i = 0;
	int idSeleccion;

	Jugador* auxJugador = NULL;
	if(pArrayListJugador != NULL)
	{
		ll_clear(jugConvocados);

		for(i = 0; i < ll_len(pArrayListJugador); i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
			jug_getSIdSeleccion(auxJugador, &idSeleccion);
			if(idSeleccion != 0)
			{
				ll_add(jugConvocados, auxJugador);
			}
		}
	todoOk = 1;
	}

	return todoOk;
}
int controller_ordenarJugadorPorNombre(void *nombre1, void *nombre2)
{
	int todoOk = 0;

	if (nombre1 != NULL && nombre2 != NULL)
	{

		if (strcmp(((Jugador *)nombre1)->nombreCompleto,
				   ((Jugador *)nombre2)->nombreCompleto) > 0)
		{
			todoOk = 1;
 		}
		if (strcmp(((Jugador *)nombre1)->nombreCompleto,
				   ((Jugador *)nombre2)->nombreCompleto) < 0)
		{
			todoOk = -1;
		}
	}
	return todoOk;
}
int controller_ordenarPorJugadorNacionalidad(void *nombre1, void *nombre2)
{
	int todoOk = 0;

	if (nombre1 != NULL && nombre2 != NULL)
	{

		if (strcmp(((Jugador *)nombre1)->nacionalidad,
				   ((Jugador *)nombre2)->nacionalidad) > 0)
		{
			todoOk = 1;
		}
		if (strcmp(((Jugador *)nombre1)->nacionalidad,
				   ((Jugador *)nombre2)->nacionalidad) < 0)
		{
			todoOk = -1;
		}
	}
	return todoOk;
}
int controller_OrdenarJugadorPorEdad(void *jugador1, void *jugador2)
{
	int todoOk = 0;

	if (jugador1 != NULL && jugador2 != NULL)
	{

		if (((Jugador *)jugador1)->edad > ((Jugador *)jugador2)->edad)
		{
			todoOk = 1;
		}
		if (((Jugador *)jugador1)->edad < ((Jugador *)jugador2)->edad)
		{
			todoOk = -1;
		}
	}
	return todoOk;
}
int controller_ordenarSeleccionPorConfederacion(void *seleccion1, void *seleccion2)
{
	int todoOk = 0;

	if (seleccion1 != NULL && seleccion2 != NULL)
	{

		if (strcmp(((Seleccion*)seleccion1)->confederacion,
				   ((Seleccion*)seleccion2)->confederacion) > 0)
		{
			todoOk =  1;
		}
		if (strcmp(((Seleccion*)seleccion1)->confederacion,
				   ((Seleccion*)seleccion2)->confederacion) < 0)
		{
			todoOk =-1;
		}
	}
	return todoOk;
}

