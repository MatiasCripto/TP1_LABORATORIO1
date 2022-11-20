/*
 * input.c
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <ctype.h>


void menu( int* pOpciones, int acumUno, int acumDos, int acumTres, int contUno, int contDos, int contTres, int contCuatro)
{
    if(pOpciones != NULL)
    {
        system("cls");
        printf("\n\n     Menu principal\n\n");
        printf("1. Ingrese los costos de mantemiento\n");
        printf(" Costo de hopedaje -> $%d\n", acumUno);
        printf(" Costo de comida -> $%d\n", acumDos);
        printf(" Costo de transporte -> $%d\n", acumTres);

        printf("\n\n2. Carga de jugadores\n");
        printf("  1 - Arqueros -> %d\n", contUno);
        printf("  2 - Defensor -> %d\n", contDos);
        printf("  3 - Mediocampista -> %d\n", contTres);
        printf("  4 - Delantero -> %d\n", contCuatro);
        printf("3. Realizar todos los calculos\n");
        printf("4. Informar todos los resultados\n");
        printf("5. Salir\n");
        fflush(stdin);
        scanf("%d", pOpciones);
    }
}


int menuMantenimiento(int* op1)
{
    if(op1 != NULL)
    {
        printf("ingresaste al menu de mantenimiento, elija una opcion:\n\n\n\n");
        printf("1- costo de hospedaje\n");
        printf("2- costo de comida\n");
        printf("3- costo de transporte\n");
        fflush(stdin);
        scanf("%d", op1);
    }
    return *op1;
}

int cargaConfederaciones(int* opcion)
{
    int resultado;
    int numeroCamiseta;

    resultado = 0;

    if(opcion != NULL )
    {
        printf("Elija la confederacion:\n\n");
        printf("1- UEFA\n");
        printf("2- CONMEBOL\n");
        printf("3- CONCACAF\n");
        printf("4- OFC\n");
        printf("5- AFC\n");
        printf("6- CAF\n");
        fflush(stdin);
        scanf("%d", opcion);

        while(*opcion != 1 && *opcion != 2 && *opcion != 3 && *opcion != 4 && *opcion != 5 && *opcion != 6)
        {

            printf("No es un parametro valido: \n");
            printf("Elija la confederacion:\n\n");
            printf("1- UEFA\n");
            printf("2- CONMEBOL\n");
            printf("3- CONCACAF\n");
            printf("4- OFC\n");
            printf("5- AFC\n");
            printf("6- CAF\n");
            fflush(stdin);
            scanf("%d", opcion);
        }
        printf("Elija el numero de camiseta\nNumero: ");
        fflush(stdin);
        scanf("%d", &numeroCamiseta);
        resultado = 1;
    }
    return resultado;
}

int menuJugadores(int* pOpciones)
{
    if(pOpciones != NULL)
    {
        printf("Ingresaste al menu de carga de jugadores.\n\n");
        printf("Elija la posicion: \n\n");
        printf("1- Arquero\n");
        printf("2- Defensor\n");
        printf("3- Mediocampista\n");
        printf("4- Delantero\n");
        fflush(stdin);
        scanf("%d", pOpciones);
        system("cls");
    }
    return *pOpciones;
}
void menuCostos(int* pAcumCosto)// input
{
    int todoOk;
    int costos;

    if(pAcumCosto != NULL)
    {
        printf("Ingrese el costo: ");
        fflush(stdin);
        todoOk = scanf("%d", &costos);
        if(todoOk == 1)
        {
            *pAcumCosto = *pAcumCosto + costos;
        }
        else
        {
            printf("No es una opcion valida\n");
        }
    }
}
int guardarCostosMantenimiento(int* hospedaje, int* transporte, int* comida, int* pOpciones)
{
    int todoOk = 0;
    if(pOpciones != NULL && hospedaje != NULL && transporte != NULL && comida != NULL)
    {
        switch(menuMantenimiento(pOpciones))
        {
        case 1:// costo hospedaje
            menuCostos(hospedaje);
            break;
        case 2:// costo comida
            menuCostos(comida);
            break;
        case 3://costo transporte
            menuCostos(transporte);
            break;
        default:
            printf("La opcion es incorrecta\n");
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}
int cargarJugadores(int* pOpcionJugador, int* contadorArquero, int* acumJugadores, int* contadorDefensor, int* contadorMediocampo, int* contadorDelantero, int* opcionConfe)
{
    int todoOk = 0;
    if(pOpcionJugador != NULL && contadorArquero != NULL && contadorDefensor != NULL && acumJugadores != NULL && contadorDelantero != NULL && contadorMediocampo != NULL && opcionConfe != NULL)
    {
        switch(menuJugadores(pOpcionJugador))// carga de jugadores con hasta su maximo de ingresos
        {
        case 1:

            if(*contadorArquero == 2)
            {
                printf("El cupo de esa posicion ya esta cubierto\n");
            }
            else
            {
                cargaConfederaciones(opcionConfe);
                (*contadorArquero)++;
                (*acumJugadores)++;
            }
            break;
        case 2:
            if(*contadorDefensor ==8)
            {
                printf("El cupo de esa posicion ya esta cubierto\n");
            }
            else
            {
                cargaConfederaciones(opcionConfe);
                (*contadorDefensor)++;
                (*acumJugadores)++;
            }
            break;
        case 3:
            if(*contadorMediocampo ==8)
            {
                printf("El cupo de esa posicion ya esta cubierto\n");
            }
            else
            {
                cargaConfederaciones(opcionConfe);
                (*contadorMediocampo)++;
                (*acumJugadores)++;
            }
            break;
        case 4:
            if(*contadorDelantero ==4)
            {
                printf("El cupo de esa posicion ya esta cubierto\n");
            }
            else
            {
                cargaConfederaciones(opcionConfe);
                (*acumJugadores)++;
                (*contadorDelantero)++;
            }
            break;
        default:
            printf("no es una opcion valida\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
int acumuladoresDeConfederaciones(int* contUefa, int* contConcacaf, int* contConmebol, int* contCaf, int* contOfc, int* contAfc, int* opcConfederaciones)
{
    int todoOk = 0;
    if(contAfc != NULL && contCaf != NULL && contConcacaf != NULL && contConmebol != NULL && contOfc != NULL && contUefa)
    {
        switch(*opcConfederaciones)
        {
        case 1:
            (*contUefa)++;
            break;
        case 2:
            (*contConmebol)++;
            break;
        case 3:
            (*contConcacaf)++;
            break;
        case 4:
            (*contOfc)++;
            break;
        case 5:
            (*contAfc)++;
            break;
        case 6:
            (*contCaf)++;
            break;
        }
        todoOk = 1;
    }

    return todoOk;
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


int dividir(float* pResultado, int dividendo, int divisor)
{
    int todoOk = 0;

    if(pResultado != NULL && divisor != 0)
    {
        *pResultado = (float) dividendo / divisor;
        todoOk = 1;
    }
    return todoOk;
}
int calcularInformes(float* costoMantenimiento, float* aumento, float* totalConAumento, int* acumuladorComida, int* acumuladorHospedaje, int* acumuladorTransporte)
{
    int todoOk = 0;
    if(costoMantenimiento != NULL && acumuladorComida != NULL && acumuladorHospedaje != NULL && acumuladorTransporte != NULL && aumento != NULL && totalConAumento != NULL)
    {
        *costoMantenimiento = *acumuladorComida + *acumuladorHospedaje + *acumuladorTransporte;
        *aumento = *costoMantenimiento * 0.35;
        *totalConAumento = *costoMantenimiento + *aumento;
        todoOk = 1;
    }

    return todoOk;
}


