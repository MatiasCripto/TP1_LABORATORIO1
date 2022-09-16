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

void menuCostos(int* pAcumCosto)// input
{
    int costos;

    if(pAcumCosto != NULL)
    {
        printf("Ingrese el costo: ");
        scanf("%d", &costos);
        *pAcumCosto = *pAcumCosto + costos;
    }
}

int menuJugadores(void)
{
   int opcion;

        printf("Elija la confederacion:\n");
        printf("1 UEFA\n");
        printf("2 CONMEBOL\n");
        printf("3 CONCACAF\n");
        printf("4 OFC\n");
        printf("5 AFC\n");
        printf("6 CAF\n");
        scanf("%d", &opcion);

        while(opcion !=1 || opcion !=2 || opcion !=3 || opcion !=4 || opcion !=5 || opcion !=6)
        {
            printf("No es un parametro valido: \n");
                   printf("Elija la confederacion:\n");
                   printf("1 UEFA\n");
                   printf("2 CONMEBOL\n");
                   printf("3 CONCACAF\n");
                   printf("4 OFC\n");
                   printf("5 AFC\n");
                   printf("6 CAF\n");
                   fflush(stdin);
                   scanf("%d", &opcion);
         }
        //printf("Elija el numero de camiseta\n");
        //scanf("%d", camiseta);

        return opcion;
}




