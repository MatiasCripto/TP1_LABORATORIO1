/*
 ============================================================================
 Name        : tp2Eclip.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugadores.h"
#include "confederaciones.h"
#include "validacionesTP2.h"
#include "informes.h"


#define TAM 20
#define TAMCONF 6

int main()
{
	setbuf(stdout, NULL);
    char seguir = 's';
    int nexId = 1;
    int nexIdConfe = 100;
    int flagAlta = 0;
    eConfederaciones listaConfe[TAMCONF];
    eJugador lista[TAM];

    if(!inicializarJugador(lista, TAM))
    {
        printf("Error al cargar datos ");
    }
    inicializarJugador(lista, TAM);
    harcodearJugadores(&nexId, lista, TAM, 10);
    harcodearConfederaciones(&nexIdConfe,listaConfe, TAMCONF, 6);

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaJugador(lista,listaConfe, TAMCONF, TAM, &nexId ))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("El Alta se realizo con exito\n");
            }
            flagAlta = 1;
            break;
        case 2:
            if(flagAlta == 1)
            {
                if(!bajaJugador(lista, TAM, listaConfe, TAMCONF))
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    printf("Baja exitosa\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta un jugador\n");
            }
            break;
        case 3:
                if(flagAlta == 1)
                {
                    mostrarJugadoresPorId(lista,TAM,listaConfe, TAMCONF);
                    modificarJugador(lista, TAM, listaConfe, TAMCONF);
                }
                else
                {
                    printf("Primero debe dar de alta un jugador\n");
                }

            break;
        case 4:
                if(flagAlta == 1)
                {

                    mostrarInformes(lista, TAM, listaConfe, TAMCONF);
                }
                else
                {
                    printf("Primero debe dar de alta un jugador\n");
                }

            break;
        case 5:
            printf("Salir\n");
            confirmarSalida(&seguir);
            break;
        default:
            printf("Opcion Invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');

    return 0;
}

