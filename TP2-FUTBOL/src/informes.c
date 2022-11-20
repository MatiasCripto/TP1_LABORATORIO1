/*
 * informes.c
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "confederaciones.h"
#include "jugadores.h"
#include "validaciones.h"
#include "informes.h"




int mostrarJugadoresConfederaciones(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int idConfederacion;
    if(vec != NULL && tam > 0 && listaConf != NULL && tamConf > 0)
    {
        system("cls");
        printf("    *** Datos de Confederaciones ***\n");
        mostrarConfederaciones(listaConf, tamConf);
        utn_getNumero(&idConfederacion,"Ingrese una Opcion: \n","Error, Opcion no valida\n",100,110,99);

        mostrarJugadoresIdConfederaciones(idConfederacion, vec, tam, listaConf, tamConf);

        todoOk = 1;
    }
    return todoOk;
}

int mostrarPromedioDeSalarios(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int contador = 0;
    float AcumSalario  = 0;
    float promedio;
    int masDelPromedio = 0;
    int i;
    int j;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConf >0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 )
            {
                AcumSalario+=lista[i].salario;
                contador++;
            }
        }
        promedio = AcumSalario / contador;

        if(contador == 0)
        {
            printf("No hay salarios para mostrar\n");
        }
        else
        {
            promedio = AcumSalario / contador;
            printf("El promedio de salarios es: $%.2f\n", promedio);
        }
        for( j = 0; j < tam; j++)
        {
            if(lista[j].salario > promedio)
            {
                masDelPromedio++;
            }
        }
        printf("La cantidad de jugadores que superan el salario promedio son: %d\n", masDelPromedio);

        todoOk = 1;
    }
    return todoOk;
}


float mostrarTotalDeSalarios(eJugador lista[], int tam)
{
    float acumSalario  = 0;
    int contador = 0;
    int i;

    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                acumSalario+=lista[i].salario;
                contador++;
            }
        }
        if(contador == 0)
        {
            printf("No hay salarios para mostrar\n");
        }
        else
        {
            printf("El total de salarios es: $%.2f\n", acumSalario);
        }
    }
    return acumSalario;
}

int mostrarJugadoresIdConfederaciones(int idConfe, eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int i;
    if(vec != NULL && tam > 0 && listaConf != NULL && tamConf > 0)
    {
        printf("================================================================================================================\n");
        printf("|  ID  |       NOMBRE        |      POSICION      | N CAMISETA |      SUELDO    |   CONFEDERACION  | CONTRATO  | \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");
        for(i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0 && vec[i].idConfederacion == idConfe)
            {
                mostrarJugador(vec[i], vec, tam, listaConf, tamConf);
            }
        }
        printf("================================================================================================================\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarInformes(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConf > 0)
    {
        switch(menuInformes())
        {
        case 1:
            mostrarJugadores(lista, tam, listaConf, tamConf);
            break;
        case 2:
            mostrarJugadoresConfederaciones(lista, tam,listaConf,tamConf);
            break;
        case 3:
            mostrarTotalDeSalarios(lista,tam);
            mostrarPromedioDeSalarios(lista, tam, listaConf, tamConf);
            break;
        case 4:
            mostrarConfederacionMayorContratos(lista, tam, listaConf, tamConf);
            break;
        case 5:
            mostrarRegionMayorJugadores(lista, tam,listaConf,tamConf);
            break;
        case 6:
            porcentajeJugadoresPorConf(lista,tam,listaConf,tamConf);
            break;
        case 7:
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarConfederacionMayorContratos(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int maximo;
    int i;
    int j;
    int k;
    int l;
    int contadores[] = {0,0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConf > 0)
    {
        system("cls");
        printf("    *** confederacion con mas contratos ***\n");
        for(i = 0; i < tamConf; i++)
        {
            for(j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idConfederacion == listaConf[i].id)
                {
                    contadores[i]+= lista[j].aniosContrato;
                }
            }
        }
        for(k = 0; k < tamConf; k++)
        {
            if(flag == 0 || contadores[k] > maximo)
            {
                maximo = contadores[k];
                flag = 1;
            }
        }
        for(l = 0; l < tamConf; l++)
        {
            if(contadores[l] == maximo)
            {
                printf("Confederacion: %s con %d anios de contrato\n", listaConf[i].nombre, maximo);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarRegionMayorJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int maximo;
    int i;
    int j;
    int k;
    int l;
    int contadores[] = {0,0,0,0,0,0};
    int flag = 0;

    if(lista != NULL && tam > 0 && listaConf != NULL && tamConf > 0)
    {
        system("cls");
        printf("    *** Region conmayor jugadores ***\n");
        for( i = 0; i < tamConf; i++)
        {
            for( j = 0; j < tam; j++)
            {
                if(lista[j].isEmpty == 0 && lista[j].idConfederacion == listaConf[i].id)
                {
                    contadores[i]++;
                }
            }
        }
        for(k = 0; k < tamConf; k++)
        {
            if(flag == 0 || contadores[k] > maximo)
            {
                maximo = contadores[k];
                flag = 1;
            }
        }
        for(l = 0; l < tamConf; l++)
        {
            if(contadores[l] == maximo)
            {
                printf("%s\n", listaConf[l].region);
                mostrarJugadoresIdConfederaciones(listaConf[l].id,lista,tam,listaConf,tamConf);

            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int porcentajeJugadoresPorConf(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int contador = 0;
    int i;
    int jugadoresConmebol = 0;
    int jugadoresUefa = 0;
    int jugadoresConcacaf = 0;
    int jugadoresOfc = 0;
    int jugadoresCaf = 0;
    int jugadoresAfc = 0;
    float porcentajeConmebol;
    float porcentajeUefa;
    float porcentajeConcacaf;
    float porcentajeOfc;
    float porcentajeCaf;
    float porcentajeAfc;

    if(lista != NULL && tam > 0 && listaConf != NULL&& tamConf > 0)
    {
        for( i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idConfederacion == 100)
                {
                    jugadoresConmebol++;
                }
                if(lista[i].idConfederacion == 101)
                {
                    jugadoresUefa++;
                }
                if(lista[i].idConfederacion == 102)
                {
                    jugadoresAfc++;
                }
                if(lista[i].idConfederacion == 103)
                {
                    jugadoresCaf++;
                }
                if(lista[i].idConfederacion == 104)
                {
                    jugadoresConcacaf++;
                }
                if(lista[i].idConfederacion == 105)
                {
                    jugadoresOfc++;
                }
                contador++;
            }
        }
        porcentajeConmebol = (float) jugadoresConmebol*100/contador;
        porcentajeUefa =(float) jugadoresUefa*100/contador;
        porcentajeConcacaf =(float) jugadoresConcacaf*100/contador;
        porcentajeOfc =(float) jugadoresOfc*100/contador;
        porcentajeCaf =(float) jugadoresCaf*100/contador;
        porcentajeAfc =(float) jugadoresAfc*100/contador;

        printf("========================================\n");
        printf("CONFEDERACION | PORCENTAJE DE JUGADORES|\n");
        printf("----------------------------------------\n");
        printf("CONMEBOL      |%5.2f\n", porcentajeConmebol);
        printf("UEFA          |%5.2f\n", porcentajeUefa);
        printf("AFC           |%5.2f\n", porcentajeAfc);
        printf("CAF           |%5.2f\n", porcentajeCaf);
        printf("CONCACAF      |%5.2f\n", porcentajeConcacaf);
        printf("OFC           |%5.2f\n", porcentajeOfc);
        printf("========================================\n");
    }

    return todoOk;
}

