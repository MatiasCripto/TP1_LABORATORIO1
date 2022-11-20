/*
 * confederaciones.c
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


void mostrarConfederacion(eConfederaciones c)
{
    printf("|%4d |     %-10s   |         %-15s       |        %d       |\n",
           c.id,
           c.nombre,
           c.region,
           c.anioCreacion);
}

int mostrarConfederaciones(eConfederaciones lista[], int tam)
{
    int todoOk = 0;
    int flag;
    int i;
    int j;
    int k;
    eConfederaciones auxConf;

    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("                               *** LISTA DE CONFEDERACIONES ***\n");
        printf("==============================================================================\n");
        printf("| ID  |     NOMBRE       |              REGION           | ANIO DE CREACION  | \n");
        printf("------------------------------------------------------------------------------\n");
        for(i = 0; i <tam-1; i++)
        {
            for(j = i+1; j<tam ; j++)
            {
                if(lista[i].id > lista[j].id)
                {
                    auxConf = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxConf;
                }
            }
        }
        for(k = 0; k <tam; k++)
        {
            if(lista[k].isEmpty == 0)
            {
                mostrarConfederacion(lista[k]);
                flag = 0;
            }
        }
        printf("==============================================================================\n");
        if(flag)
        {
            printf("No hay confederacion para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}


int asignarNombreConfederaciones(eConfederaciones lista[],int tam, int idConfederacion, char descConfederaciones[])
{
    int todoOk = 0;
    int i;
    if(lista != NULL && tam >0 && descConfederaciones != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].id == idConfederacion)
            {
                strcpy(descConfederaciones, lista[i].nombre);
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int harcodearConfederaciones(int* pConfederacion, eConfederaciones vec[], int tamConf, int cant)
{
    int todoOk = 0;
    int i;
    eConfederaciones confederaciones[6] =
        {{100, "CONMEBOL", "SUDAMERICA", 1916,0},
        {101, "UEFA", "EUROPA", 1954,0},
        {102, "AFC", "ASIA", 1954,0},
        {103, "CAF", "AFRICA", 1957,0},
        {104, "CONCACAF", "N Y C AMERICA", 1961,0},
        {105, "OFC", "OCEANIA", 1966,0}
    };
    if(pConfederacion != NULL && vec != NULL && tamConf > 0 && cant<= tamConf && cant <= 6)
    {
        for(i = 0; i < cant; i++)
        {
            vec[i] = confederaciones[i];
            (*pConfederacion)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

int altaConfederacion(eConfederaciones lista[], int tamConf,int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    char auxCad[50];
    eConfederaciones auxConf;

    if(lista != NULL && pId != NULL&& tamConf >0)
    {

        system("cls");
        printf("            ***  ALTA DE CONFEDERACIONES  ***\n\n");
        indice = buscarLibreConfe(lista, tamConf);
        if(indice == -1)
        {
            printf("No hay lugar ");
        }
        else
        {
            auxConf.id = *pId;
            (*pId)++;

            utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre\n",99);

            strlwr(auxCad);

            auxCad[0] = toupper(auxCad[0]);

            strcpy(auxConf.nombre, auxCad);

            fflush(stdin);
            utn_getNombre(auxCad,50,"Ingrese Region: \n","Error, reingrese Region\n",99);

            strlwr(auxCad);

            auxCad[0] = toupper(auxCad[0]);

            strcpy(auxConf.region, auxCad);

            fflush(stdin);

            utn_getNumero(&auxInt,"Ingrese anio de creacion: \n","Numero no valido\n", 1, 2022, 99);

            auxConf.anioCreacion = auxInt;

            fflush(stdin);

            auxConf.isEmpty = 0;

            lista[indice] = auxConf;

            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarLibreConfe(eConfederaciones lista[], int tam)
{
    int posicionLibre = -1;
    int i;
    if(lista != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}

int bajaConfederacion(eConfederaciones lista[], int tamConf)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int i;
    if(lista != NULL && tamConf > 0)
    {
        system("cls");
        printf("                               *** LISTA DE CONFEDERACIONES ***\n");
        printf("==============================================================================\n");
        printf("| ID  |     NOMBRE       |              REGION           | ANIO DE CREACION  | \n");
        printf("------------------------------------------------------------------------------\n");
        for(i = 0; i <tamConf; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarConfederacion(lista[i]);

            }
        }
        printf("===============================================================================\n");
        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",100,200,99);

        indice = buscarConfederacionId(id,lista, tamConf);

        if(indice == -1)
        {
            printf("el id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarConfederacion(lista[indice]);
            printf("Presione S para continuar");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

int buscarConfederacionId(int id, eConfederaciones lista[], int tamConf)
{
    int indice = -1;
    int i;
    if(lista != NULL && tamConf > 0)
    {
        for(i = 0; i < tamConf; i++)
        {
            if(!lista[i].isEmpty && lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
int modificarConfederacion(eConfederaciones vec[], int tam)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma = 's';
    char auxCad[50];
    int auxInt;
    int i;

    eConfederaciones auxConf;

    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("            *** MODIFICAR CONFEDERACION ***         \n");

        for(i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0)
            {
                mostrarConfederacion(vec[i]);
            }
        }
        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",1,3000,2);

        indice = buscarConfederacionId(id, vec, tam);

        if(indice == -1)
        {
            printf("No existe una confederacion con el id: %d", id);
        }
        else
        {
            mostrarConfederacion(vec[indice]);
            printf("Confirma modificacion?: s/n :");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                fflush(stdin);
                switch(menuModificacionConfederacion())
                {
                case 1:
                    utn_getNombre(auxCad,50,"Ingrese nombre: \n","Error, reingrese nombre\n",99);
                    strlwr(auxCad);
                    auxCad[0] = toupper(auxCad[0]);
                    strcpy(auxConf.nombre, auxCad);
                    break;
                case 2:
                    utn_getNombre(auxCad,50,"Ingrese Region: \n","Error, reingrese Region\n",99);
                    strlwr(auxCad);
                    auxCad[0] = toupper(auxCad[0]);
                    strcpy(auxConf.region, auxCad);
                    fflush(stdin);
                    break;
                case 3:
                    utn_getNumero(&auxInt,"Ingrese anio de creacion: \n","Numero no valido\n", 1, 2022, 99);
                    auxConf.anioCreacion = auxInt;
                    fflush(stdin);
                    break;
                default:
                    printf("La opcion es invalida");

                }
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

