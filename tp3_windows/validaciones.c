/*
 * validaciones.c
 *
 *  Created on: 9 nov. 2022
 *      Author: USER
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "Jugador.h"


/** \brief
 *
 * \param cadena char* cadena a recorrer
 * \param longitud int longitud de la cadena
 * \return int -1 Error: NO es numerica. 0 Es valido
 *
 */
int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena, longitud, stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;

}
/** \brief Obtiene el dato como una cadena de caracteres, para luego
 * 	      validarlo y parsear/formatear el dato a una variable entera.
 *
 * \param pResultado int* Puntero a entero, con el valor a setear.
 * \return int retorna -1 si la validacion fallo y 0 si salio bien
 *
 */
int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }

    }
    return retorno;
}

/** \brief Recibe una cadena de caracteres y devuelve 1
 * 		  en el caso de que el texto este compuesto solo por n�meros.
 *
 * \param cadena char* Cadena de carateres a recorrer.
 * \return int retorna 1 si la validacion fallo y 0 si salio todo bien
 *
 */
int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) < 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] <'0' || cadena[i] > '9'/* || cadena[i] != ','*/)// para flotante, contar las comas y que me ermita una sola
            {
                retorno =0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/** \brief Pide al usuario un numero
 *
 * \param pResultado int* Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje char* El mensaje que imprime para pedir un valor
 * \param mensajeError char* mensaje que imprime si el rango no es valido
 * \param minimo int valor minimo valido (inclusive)
 * \param maximo int valor maximo valido (no inclusive)
 * \param reintentos int cantidad de reintentos
 * \return int retorna 0  si esta todo OK. -1: Si hubo un error
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s", mensaje);
        if(getInt(&bufferInt)==0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    return retorno;
}
/** \brief valida una cadena de caracteres
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int retorna 0 si fallo y 1 si salio todo bien
 *
 */
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
            ((pBuffer[0]>='A' && pBuffer[0]<='Z') || (pBuffer[0]>='a' && pBuffer[0]<='z')))
    {
        retorno = 1;
    }
    return retorno;
}
/** \brief valida una cadena de caracteres
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int retorna 0 si fallo y 1 si salio todo bien
 *
 */
int isValidNumber(char *pBuffer, int limite)
{
    int retorno = 0;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
            ((pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
    }
    return retorno;
}
/** \brief pide una cadena al usuario y la valida
 *
 * \param pNombre char* cadena a recibir
 * \param limite int limite de caracteres de la cadena
 * \param mensaje char* mensaje de peticion al usuario
 * \param mensajeError char* mensaje de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
            mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if(getString(buffer, limite) == 0 &&
                    isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/** \brief pide una cadena al usuario y la valida
 *
 * \param pNombre char* cadena a recibir
 * \param limite int limite de caracteres de la cadena
 * \param mensaje char* mensaje de peticion al usuario
 * \param mensajeError char* mensaje de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos)
{
	char aux[30];
	int retorno = -14;
	if(pResultado != NULL)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf ( "%s" ,mensaje);
			if(getChar(aux,30)== 0)
			{
				aux[0]= tolower(aux[0]);
				if(aux[0] == 's' || aux[0] == 'n')
				{
					*pResultado = aux[0];
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
		if(reintentos < 1)
		{
			retorno= -1;
		}
	}
	return retorno;
}
int getChar ( char * pResultado,int tam)
{
	int retorno = -1;
	char buffer[tam];
	if (pResultado != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumericaChar(buffer) == 0)
		{
			strcpy(pResultado,buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/** \brief recibe una cadena y la valida que sea numerica
 *
 * \param pNombre char* cadena a recibir
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int esNumericaChar (char * cadena)
{
	int retorno = -1;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		while (cadena[i] != '\0' )
		{
			if (cadena[i] >= '0' && cadena[i] <= '9' )
			{
				retorno = -1;
				break ;
			}
			i++;
		}
		retorno = 0;

	}
	else
	{
		retorno = 0;
	}
	return retorno;

}

/** \brief pide una cadena al usuario y la valida
 *
 * \param pNombre char* cadena a recibir
 * \param limite int limite de caracteres de la cadena
 * \param mensaje char* mensaje de peticion al usuario
 * \param mensajeError char* mensaje de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int getDeCadenaAEntero(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
            mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if(getString(buffer, limite) == 0 &&
                    isValidNumber(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/** \brief valida que sea una cadena
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int  retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}
int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("     *** MENU PRINCIPAL ***     \n\n");
    printf(" 1- CARGA DE ARCHIVO\n");
    printf(" 2- ALTA DE JUGADOR\n");
    printf(" 3- MODIFICACION DE JUGADOR\n");
    printf(" 4- BAJA DE JUGADOR\n");
    printf(" 5- LISTADOS\n");
    printf(" 6- CONVOCAR JUGADORES\n");
    printf(" 7- ORDENAR Y LISTAR\n");
    printf(" 8- GENERAR ARCHIVO BINARIO\n");
    printf(" 9- CARGAR ARCHIVO BINARIO\n");
    printf("10- GUARDAR ARCHIVOS CSV\n");
    printf("11- SALIR\n");
    if((utn_getNumero(&opcion, "Ingrese una opcion\n","Error, opcion invalida, reingrese una opcion\n",1,11,99)) == -1)
    {
    	exit(1);
    }
    return opcion;
}

int menuListados()
{
	int opcion;
	system("cls");
	printf("     *** MENU DE LISTADOS ***     \n\n");
	printf("1- TODOS LOS JUGADORES\n");
	printf("2- TODAS LAS SELECCIONES\n");
	printf("3- JUGADORES CONVOCADOS\n");
	if((utn_getNumero(&opcion, "Ingrese una opcion\n","Error, opcion invalida, reingrese una opcion\n",1,3,99)) == -1)
	{
		exit(1);
	}

	return opcion;
}
void menuPosicion()
{

    printf("   *** ELIJA LA POSICION ***\n");
    printf(" 1 - PORTERO\n");
    printf(" 2 - DEFENSA CENTRAL\n");
    printf(" 3 - LATERAL IZQUIERO\n");
    printf(" 4 - LATERAL DERECHO\n");
    printf(" 5 - PIVOTE\n");
	printf(" 6 - MEDIOCENTRO\n");
	printf(" 7 - MEDIOCENTRO OFENSIVO\n");
	printf(" 8 - EXTREMO IZQUIERDO\n");
	printf(" 9 - EXTREMO DERECHO\n");
	printf("10 - MEDIAPUNTA\n");
	printf("11 - DELANTERO CENTRO\n");


}
void menuNacionalidad()
{

    printf("   *** ELIJA LA NACIONALIDAD ***\n");
    printf(" 1 - ALEMAN\n");
    printf(" 2 - ARABE\n");
    printf(" 3 - ARGENTINO\n");
    printf(" 4 - AUSTRIACO\n");
    printf(" 5 - BELGA\n");
	printf(" 6 - BRASILERO\n");
	printf(" 7 - CANADIENSE\n");
	printf(" 8 - CAMERUNES\n");
	printf(" 9 - COREANO (SUR)\n");
	printf("10 - COSTARRICENSE\n");
	printf("11 - CROATA\n");
	printf("12 - DINAMARQUES\n");
	printf("13 - ECUATORIANO\n");
	printf("14 - ESPANIOL\n");
	printf("15 - ESTADOUNIDENSE\n");
	printf("16 - FRANCES\n");
	printf("17 - GALES\n");
	printf("18 - GHANES\n");
	printf("19 - INGLES\n");
	printf("20 - IRANI\n");
	printf("21 - JAPONES\n");
	printf("22 - MARROQUI\n");
	printf("23 - MEXICANO\n");
	printf("24 - NERLANDES\n");
	printf("25 - POLACO\n");
	printf("26 - PORTUGUES\n");
	printf("27 - QATARI\n");
	printf("28 - SENEGALES\n");
	printf("29 - SERBIO\n");
	printf("30 - SUIZO\n");
	printf("31 - TUNECINO\n");
	printf("32 - URUGUAYO\n");

}
int menuEdicioon()
{
	int opcion = -1;
	system("cls");
	printf("     *** MENU DE EDICION ***     \n\n");
	printf("1- EDITAR NOMBRE COMPLETO\n");
	printf("2- EDITAR EDAD\n");
	printf("3- EDITAR POSICION\n");
	printf("4- EDITAR NACIONALIDAD\n");
	utn_getNumero(&opcion, "Ingrese una opcion\n","Error, opcion invalida, reingrese una opcion\n",1,4,99);

	return opcion;
}
int menuConvocados()
{
	int opcion;
	system("cls");
	printf("     *** MENU DE CONVOCADOS ***     \n\n");
	printf("1- CONVOCAR JUGADORES\n");
	printf("2- QUITAR JUGADOR DE LA SELECCION\n");
	if((utn_getNumero(&opcion, "Ingrese una opcion\n","Error, opcion invalida, reingrese una opcion\n",1,2,99)) == -1)
	{
		exit(1);
	}
	return opcion;
}
int menuOrdenamientos()
{
	int opcion;
	system("cls");
	printf("     *** LISTADOS ORDENADOS ***     \n\n");
	printf("1- MOSTRAR JUGADORES ORDENADOS POR NACIONALIDAD\n");
	printf("2- MOSTRAR SELECCIONES ORDENADAS POR CONFEDERACION\n");
	printf("3- MOSTRAR JUGADORES ORDENADOS POR EDAD\n");
	printf("4- MOSTRAR JUGADORES ORDENADOS POR NOMBRE\n");
	if((utn_getNumero(&opcion, "Ingrese una opcion\n","Error, opcion invalida, reingrese una opcion\n",1,4,99)) == -1)
	{
		exit(1);
	}
	return opcion;
}
int confirmarSalida(char* pSalida)
{
    int todoOk;
    char confirma;

    todoOk = 0;

    if(pSalida != NULL)
    {
        printf("confirma salida? presione S si quiere salir: \n");
        fflush(stdin);
        confirma = tolower (getchar());
        if(confirma == 's')
        {
            *pSalida = 's';
        }

        todoOk = 1;
    }
    return todoOk;
}
