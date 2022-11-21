#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "validaciones.h"

Jugador* jug_new()
{
	Jugador* nuevoJugador;
	nuevoJugador = (Jugador*)malloc(sizeof(Jugador));
	    if(nuevoJugador != NULL)
	    {
	    	nuevoJugador->id = 0;

	        strcpy(nuevoJugador->nombreCompleto," ");

	        nuevoJugador->edad = 0;

	        strcpy(nuevoJugador->posicion," ");

	        strcpy(nuevoJugador->nacionalidad," ");

	        nuevoJugador->idSeleccion = 0;

	    }

	    return nuevoJugador;
}
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* nuevoJugador;
	nuevoJugador = jug_new();

	    if(nuevoJugador != NULL)
	    {
	        if(!(jug_setId(nuevoJugador,atoi(idStr))&&
	        		jug_setNombreCompleto(nuevoJugador, nombreCompletoStr)&&
					jug_setEdad(nuevoJugador,atoi(edadStr))&&
					jug_setPosicion(nuevoJugador, posicionStr)&&
					jug_setNacionalidad(nuevoJugador, nacionalidadStr)&&
	                jug_setIdSeleccion(nuevoJugador,atoi(idSelccionStr))))
	        {
	            jug_delete(nuevoJugador);
	            nuevoJugador = NULL;
	        }
	    }

	    return nuevoJugador;
}

void jug_delete(Jugador* this)
{

	if(this != NULL)
	{
		free(this);
	}
}

int jug_setId(Jugador* this,int id)
{
	int todoOk = 0;
	    if(this != NULL && id >= 0 && id <= 1000)
	    {
	    	this->id = id;
	        todoOk = 1;
	    }
	    else
	    {
	        printf("id invalido\n");
	    }

	    return todoOk;
}
int jug_getId(Jugador* this,int* id)
{
	int todoOk = 0;
	    if(this != NULL && id != NULL)
	    {
	        *id = this->id;
	        todoOk = 1;
	    }

	    return todoOk;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk = 0;
	    char auxCadena[60];
	    if(this != NULL && nombreCompleto != NULL  && strlen(nombreCompleto) < 60 && strlen(nombreCompleto)>2)
	    {
	        strcpy(auxCadena,nombreCompleto);
	        strlwr(auxCadena);
	        auxCadena[0] = toupper(auxCadena[0]);
	        strcpy(this->nombreCompleto,auxCadena);
	        todoOk = 1;
	    }
	    else
	    {
	        printf("nombre invalido\n");
	    }


	return todoOk;
}
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int todoOk = 0;
	    if(this != NULL && nombreCompleto != NULL)
	    {
	        strcpy(nombreCompleto,this->nombreCompleto);
	        todoOk = 1;
	    }

	    return todoOk;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int todoOk = 0;
		char auxCadena[60];
		if(this != NULL && posicion != NULL  && strlen(posicion) < 60 && strlen(posicion)>2)
		{
			strcpy(auxCadena,posicion);
			strlwr(auxCadena);
			auxCadena[0] = toupper(auxCadena[0]);
			strcpy(this->posicion,auxCadena);
			todoOk = 1;
		}
		else
		{
			printf("posicion invalida\n");
		}
	return todoOk;
}
int jug_getPosicion(Jugador* this,char* posicion)
{
	int todoOk = 0;
		if(this != NULL && posicion != NULL)
		{
			strcpy(posicion,this->posicion);
			todoOk = 1;
		}

	return todoOk;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk = 0;
		char auxCadena[60];
		if(this != NULL && nacionalidad != NULL  && strlen(nacionalidad) < 60 && strlen(nacionalidad)>2)
		{
			strcpy(auxCadena,nacionalidad);
			strlwr(auxCadena);
			auxCadena[0] = toupper(auxCadena[0]);
			strcpy(this->nacionalidad,auxCadena);
			todoOk = 1;
		}
		else
		{
			printf("nacionalidad invalida\n");
		}
	return todoOk;
}
int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int todoOk = 0;
		if(this != NULL && nacionalidad != NULL)
		{
			strcpy(nacionalidad,this->nacionalidad);
			todoOk = 1;
		}

	return todoOk;
}

int jug_setEdad(Jugador* this,int edad)
{
	int todoOk = 0;
		if(this != NULL && edad >= 0 && edad <= 100)
		{
			this->edad = edad;
			todoOk = 1;
		}
		else
		{
			printf("edad invalida\n");
		}

	return todoOk;
}
int jug_getEdad(Jugador* this,int* edad)
{
	int todoOk = 0;
	    if(this != NULL && edad != NULL)
	    {
	        *edad = this->edad;
	        todoOk = 1;
	    }
	return todoOk;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int todoOk = 0;
		    if(this != NULL && idSeleccion >= 0 && idSeleccion <= 20000)
		    {
		    	this->idSeleccion = idSeleccion;
		        todoOk = 1;
		    }
		    else
		    {
		        printf("id invalido\n");
		    }

		    return todoOk;
}
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int todoOk = 0;
		if(this != NULL && idSeleccion != NULL)
		{
			*idSeleccion = this->idSeleccion;
			todoOk = 1;
		}
	return todoOk;
}
int jug_mostrarJugador( Jugador* jugador)
{
	int todoOk = 0;
	    int id;
	    char nombre[60];
	    char posicion[60];
	    char nacionalidad[60];
	    int edad;
	    int idSeleccion;


	    if(jug_getId(jugador, &id)&&
	       jug_getNombreCompleto(jugador, nombre)&&
		   jug_getPosicion(jugador, posicion)&&
		   jug_getNacionalidad(jugador, nacionalidad)&&
		   jug_getEdad(jugador, &edad)&&
		   jug_getSIdSeleccion(jugador,&idSeleccion))
	    {
	    	printf("-----------------------------------------------------------------------------------------------\n");
	        printf("|%4d|%-30s|%3d   |%-20s|%-15s|    %4d     |\n",id,nombre,edad,posicion,nacionalidad,idSeleccion);
	        todoOk = 1;
	    }

	    return todoOk;
}
int jug_asignarNombrePosiciones(char* posicion)
{
    int todoOk = -1;
    int auxInt;

    if(posicion != NULL)
    {
    	menuPosicion();
    	utn_getNumero(&auxInt,"Ingrese una opcion\n","Error, parametro no valido\n",1,11,99);
        switch(auxInt)
            {
            case 1:
                strcpy(posicion,"Portero");
                break;
            case 2:
                strcpy(posicion,"Defensa Central");
                break;
            case 3:
                strcpy(posicion,"Lateral izquierdo");
                break;
            case 4:
                strcpy(posicion,"Lateral derecho");
                break;
            case 5:
				strcpy(posicion,"Pivote");
				break;
            case 6:
				strcpy(posicion,"Mediocentro");
				break;
            case 7:
				strcpy(posicion,"Mediocentro ofensivo");
				break;
            case 8:
				strcpy(posicion,"Extremo izquiero");
				break;
            case 9:
				strcpy(posicion,"Extremo derecho");
				break;
            case 10:
				strcpy(posicion,"Mediapunta");
				break;
            case 11:
				strcpy(posicion,"Delantero centro");
				break;
            }

        todoOk = 0;
    }

    return todoOk;
}
int jug_asignarNombreNacionalidad(char *nacionalidad)
{
    int todoOk = -1;
    int auxInt;

    if(nacionalidad != NULL)
    {
    	menuNacionalidad();
        utn_getNumero(&auxInt,"Ingrese una opcion\n","Error, parametro no valido\n",1,32,99);
        switch(auxInt)
            {
            case 1:
                strcpy(nacionalidad,"Aleman");
                break;
            case 2:
                strcpy(nacionalidad,"Arabe");
                break;
            case 3:
                strcpy(nacionalidad,"Argentino");
                break;
            case 4:
                strcpy(nacionalidad,"Austriaco");
                break;
            case 5:
				strcpy(nacionalidad,"Belga");
				break;
            case 6:
				strcpy(nacionalidad,"Brasilero");
				break;
            case 7:
				strcpy(nacionalidad,"Canadiense");
				break;
            case 8:
				strcpy(nacionalidad,"Camerunes");
				break;
            case 9:
				strcpy(nacionalidad,"Sud Coreano");
				break;
            case 10:
				strcpy(nacionalidad,"Costarricense");
				break;
            case 11:
				strcpy(nacionalidad,"Croata");
				break;
            case 12:
				strcpy(nacionalidad,"Dinamarques");
				break;
			case 13:
				strcpy(nacionalidad,"Ecuatoriano");
				break;
			case 14:
				strcpy(nacionalidad,"Espaniol");
				break;
			case 15:
				strcpy(nacionalidad,"Estadounidense");
				break;
			case 16:
				strcpy(nacionalidad,"Frances");
				break;
			case 17:
				strcpy(nacionalidad,"Gales");
				break;
			case 18:
				strcpy(nacionalidad,"Ghanes");
				break;
			case 19:
				strcpy(nacionalidad,"Ingles");
				break;
			case 20:
				strcpy(nacionalidad,"Irani");
				break;
			case 21:
				strcpy(nacionalidad,"Japones");
				break;
			case 22:
				strcpy(nacionalidad,"Marroqui");
				break;
			case 23:
				strcpy(nacionalidad,"Mexicano");
				break;
			case 24:
				strcpy(nacionalidad,"Nerlandes");
				break;
			case 25:
				strcpy(nacionalidad,"Polaco");
				break;
			case 26:
				strcpy(nacionalidad,"Portugues");
				break;
			case 27:
				strcpy(nacionalidad,"Qatari");
				break;
			case 28:
				strcpy(nacionalidad,"Senegales");
				break;
			case 29:
				strcpy(nacionalidad,"Serbio");
				break;
			case 30:
				strcpy(nacionalidad,"Suizo");
				break;
			case 31:
				strcpy(nacionalidad,"Tunecino");
				break;
			case 32:
				strcpy(nacionalidad,"Uruguayo");
				break;
            }

        todoOk = 0;
    }

    return todoOk;
}

int jug_modificarDatosJugador(Jugador* jugador)
{
	int todoOk = 0;
	char auxNombre[60];
	char auxEdad[60];
	char auxPosicion[60];
	char auxNacionalidad[60];

	if(jugador != NULL)
	{
		switch(menuEdicioon())
		{
		case -1:
			printf("No logro obtener datos\n");
			break;
		case 1:
			if((utn_getNombre(auxNombre, 60, "Ingrese Nombre\n", "Error, reingrese nombre\n", 99))==0)
			{
				if(jug_setNombreCompleto(jugador, auxNombre) == 1)
				{
					printf("Nombre modificaco con exito\n");
				}
			}
			else
			{
				printf("Error en la modificacion\n");
			}
			break;
		case 2:
			if((getDeCadenaAEntero(auxEdad, 3, "Ingrese edad\n", "Error, reingrese edad\n", 99)) == 0)
			{
				if(jug_setEdad(jugador, atoi(auxEdad)) == 1)
				{
					printf("Edad modificada con exito\n");
				}
				else
				{
					printf("Error en la modificacion\n");
				}
			}
			break;
		case 3:
			if((jug_asignarNombrePosiciones(auxPosicion))== 0)
			{
				if(jug_setPosicion(jugador, auxPosicion))
				{
					printf("Posicion modificada con exito\n");
				}
				else
				{
					printf("Error en la modificacion\n");
				}
			}
			break;
		case 4:
			if((jug_asignarNombreNacionalidad(auxNacionalidad))== 0)
			{
				if(jug_setNacionalidad(jugador, auxNacionalidad))
				{
					printf("Nacionalidad modificada con exito\n");
				}
				else
				{
					printf("Error en la modificacion\n");
				}
			}
			break;
		}
	}
	return todoOk;
}

