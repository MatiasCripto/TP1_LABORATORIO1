/*
 * validaciones.c
 *
 *  Created on: 29 oct. 2022
 *      Author: USER
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacionesTP2.h"

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

int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);// cambiar a atof
            retorno = 0;
        }

    }
    return retorno;
}


int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) < 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] <'0' || cadena[i] > '9' || cadena[i] != ',')
            {

                retorno =0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

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
            if( getString(buffer, limite) == 0 &&
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

int menuModificacion()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"     *** Modificar Jugador ***     \n\n1- Modificar Nombre\n2- Modificar Posicion\n3- Modificar Numero de camiseta\n4- Modificar Confederacion\n5- Modificar Salario\n6- Modificar Anios de contrato\n7- Salir\nIngrese Opcion: \n","Error, campo no valido",1,7,99);

    return opcion;
}
int menuModificacionConfederacion()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"     *** Modificar Confederacion ***     \n\n1- Modificar Nombre\n2- Modificar Region\n3- Modificar anio de creacion\nIngrese Opcion: \n","Error, campo no valido",1,3,99);

    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"  *** INFORMES ***\n\n1- LISTADO DE JUGADORES\n2- LISTADO DE JUGADORES POR CONFEDERACION\n3- INFORMES DE SALARIOS\n4- CONFEDERACION CON MAYOR ANIOS DE CONTRATO\n5- REGION CON MAS JUGADORES Y SU LISTADO\n6- PORCENTAJE DE JUGADORES POR CONFEDERACION\n7- SALIR\nIngrese una opcion: \n", "Error, opcion invalida\n\n",1,7,99);

    return opcion;
}

int menu()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"  *** ABM JUGADORES***\n\n1- ALTA DE JUGADOR\n2- BAJA DE JUGADOR\n3- MODIFICAR JUGADOR\n4- INFORMES\n5- SALIR\nIngrese una opcion: \n", "Error, opcion invalida\n\n",1,5,99);

    return opcion;
}

void menuPosicion()
{

    printf("   *** MENU POSICIONES ***\n");
    printf("1 - ARQUERO\n");
    printf("2 - DEFENSOR\n");
    printf("3 - MEDIOCAMPISTA\n");
    printf("4 - DELANTERO\n");

}


int input_GetFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries)
{
    float bufferFloat;
    int retorno = -1;
    while(retries>0)
    {
        retries--;
        printf("%s",message);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= min && bufferFloat <= max)
            {
                *pResult = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",errorMessage);
    }
    return retorno;
}

int getFloat(float* pResult)
{
    int retorno=-1;
    char buffer[64];
    if(pResult != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResult = atof(buffer);
            retorno = 0;
        }
    }

    return retorno;
}

int esFlotante(char *str) {
    int rtn = -1;
    int longitud = strlen(str);
    while (longitud > 0 && isspace(str[longitud - 1]))
        longitud--;
    if (longitud <= 0) return 0;
    int i;
    int haEncontradoElPunto = 0;
    for (i = 0; i < longitud; ++i) {
        if (str[i] == '-' && i > 0) {
            rtn = 0;
            break;
        }
        if (str[i] == '.') {
            if (haEncontradoElPunto) {
                rtn = 0;
                break;
            } else {

                haEncontradoElPunto = 1;
            }
        }
        if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.') {
            rtn = 0;
            break;
        }
    }
    return rtn;
}
int confirmarSalida(char* pSalida)
{
    int todoOk;
    char confirma;

    todoOk = 0;

    if(pSalida != NULL)
    {
        printf("confirma salida? presione S si quiere salir: ");
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

