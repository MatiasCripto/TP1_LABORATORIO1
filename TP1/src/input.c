/*
 * input.c
 *
 *  Created on: 23 sep. 2022
 *      Author: USER
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "mibiblioteca.h"
#include <ctype.h>


void menuMantenimiento(int* op1)
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
}

int cargaConfederaciones(int* opcion)
{
    int resultado;
    int numeroCamiseta;

    resultado = 0;

    if(opcion != NULL)
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
        printf("Elija el numero de camiseta\nNumero: ");
        fflush(stdin);
        scanf("%d", &numeroCamiseta);

        while(*opcion != 1 && *opcion != 2 && *opcion != 3 && *opcion != 4 && *opcion != 5 && *opcion != 6 && (numeroCamiseta <0 ) )
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
			printf("Elija el numero de camiseta\nNumero: ");
			fflush(stdin);
			scanf("%d", &numeroCamiseta);
        }

        resultado = 1;
    }
    return resultado;
}

void cargaJugadores(int* pOpciones)
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

}




