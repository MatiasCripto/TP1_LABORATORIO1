#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"


int main()
{
    int opciones;
    int opcUno;
    int opcDos;
    int costoHospedaje;
    int costoDeComida;
    int costoDeTransporte;
    int acumuladorComida;
    int acumuladorTransporte;
    int acumuladorHospedaje;
    int numeroCamiseta;
    int confederaciones;
    int contadorArquero;
    int contadorDefensor;
    int contadorMediocampo;
    int contadorDelantero;
    int contadorJugadores;
    int flagCosto;
    int flagJugadores;
    int flagControl;
    int contUefa;
    int contConmebol;
    int contConcacaf;
    int contCaf;
    int contOfc;
    int contAfc;
    float pUefa;
    float pConmebol;
    float pConcacaf;
    float pCaf;
    float pOfc;
    float pAfc;

    contAfc = 0;
    contCaf = 0;
    contConcacaf = 0;
    contConmebol = 0;
    contOfc = 0;
    contUefa = 0;
    flagControl = 0;
    flagCosto = 0;
    flagJugadores = 0;
    contadorJugadores = 0;
    costoHospedaje = 0;
    costoDeComida = 0;
    costoDeTransporte = 0;
    contadorArquero = 0;
    contadorDefensor = 0;
    contadorDelantero = 0;
    contadorMediocampo = 0;
    acumuladorComida = 0;
    acumuladorTransporte = 0;
    acumuladorHospedaje = 0;

    do
    {
        // menu principal

        menu(&opciones, acumuladorHospedaje, acumuladorComida, acumuladorTransporte, contadorArquero, contadorDefensor, contadorMediocampo, contadorDelantero);

        switch(opciones)
        {
        case 1:// menu de mantenimiento

            menuMantenimiento(&opcUno);

            if(opcUno != 3 && opcUno !=2 && opcUno != 1)
            {
                printf("La opcion es incorrecta\n");
            }

            switch(opcUno)
            {
            case 1:// costo hospedaje

                menuCostos(&acumuladorHospedaje);
                break;
            case 2:// costo comida

                menuCostos(&acumuladorComida);

                break;

            case 3://costo transporte

                printf("Ingrese el costo: ");
                scanf("%d", &costoDeTransporte);
                acumuladorTransporte = acumuladorTransporte + costoDeTransporte;
                break;
        }


        break;


        case 2:// menu jugadores

            printf("Ingresaste al menu de carga de jugadores. \n\n\n\n\n");
            printf("Elija la posicion: \n");
            printf("1 Arquero\n");
            printf("2 Defensor\n");
            printf("3 Mediocampista\n");
            printf("4 Delantero\n");
            scanf("%d", &opcDos);
           // contadorJugadores++;
            while(opcDos != 4 || opcDos != 3 || opcDos != 2 || opcDos != 1)
            {

                switch(opcDos)// carga de jugadores con hasta su maximo de ingresos
                {
                case 1:
                    if(contadorArquero >1)
                    {
                        printf("El cupo de esa posicion ya esta cubierto\n");
                    }
                    else
                    {
                        contadorArquero++;
                        menuJugadores();

                    }
                    break;
                case 2:
                    if(contadorDefensor >7)
                    {
                        printf("El cupo de esa posicion ya esta cubierto\n");
                    }
                    else
                    {
                        contadorDefensor++;
                        menuJugadores();
                    }
                    break;
                case 3:
                    if(contadorMediocampo >7)
                    {
                        printf("El cupo de esa posicion ya esta cubierto\n");
                    }
                    else
                    {
                        contadorMediocampo++;
                        menuJugadores();


                    }
                    break;
                case 4:
                    if(contadorDelantero >3)
                    {
                        printf("El cupo de esa posicion ya esta cubierto\n");
                    }
                    else
                    {
                        contadorDelantero++;
                        printf("Elija la confederacion:\n");
                        printf("1 UEFA\n");
                        printf("2 CONMEBOL\n");
                        printf("3 CONCACAF\n");
                        printf("4 OFC\n");
                        printf("5 AFC\n");
                        printf("6 CAF\n");
                        scanf("%d", &confederaciones);
                        printf("Elija el numero de camiseta\n");
                        scanf("%d", &numeroCamiseta);
                    }
                    break;
                }


                break;
            }
            flagJugadores = 1;



        case 3:

                printf("ingresaste al menu de control\n");


            break;
        case 4:
            if(flagControl == 0)
            {
                printf("No puede ingresar aqui si no pasa primero por las opciones 1 y 2");
            }
            else
            {
                //contador de la confederacion * 100 / contador general
            }
            break;
        case 5:
            return 0;
            break;
        default:
            printf("no es una opcion valida");
            break;

        }

    }
    while(opciones != 5);


}

