/*
 * mibiblioteca.c
 *
 *  Created on: 22 sep. 2022
 *      Author: USER
 */
#include <stdio.h>
#include <stdlib.h>
#include "mibiblioteca.h"
#include "input.h"
#include <ctype.h>
#include <string.h>

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






