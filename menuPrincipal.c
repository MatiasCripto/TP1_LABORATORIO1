#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"

void menu( int* pOpciones, int acumUno, int acumDos, int acumTres, int contUno, int contDos, int contTres, int contCuatro)
{
    if(pOpciones != NULL)
    {

        printf("\n\n     Menu principal\n\n");
        printf("1. Ingrese los costos de mantemiento\n");
        printf(" Costo de hopedaje -> %d\n", acumUno);
        printf(" Costo de comida -> %d\n", acumDos);
        printf(" Costo de transporte -> %d\n", acumTres);

        printf("2. Carga de jugadores\n");
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
void menuMantenimiento(int* op1)
{
    if(op1 != NULL)
    {
        printf("ingresaste al menu de mantenimiento, elija una opcion:\n\n\n\n");
            printf("1 costo de hospedaje\n");
            printf("2 costo de comida\n");
            printf("3 costo de transporte\n");
            scanf("%d", op1);
    }
}

void menuCostos(int* pCostos, int acumCosto)
{
    if(pCostos != NULL)
    {
        printf("Ingrese el costo: ");
        scanf("%d", pCostos);
        acumCosto = acumCosto + pCostos;
    }
}
