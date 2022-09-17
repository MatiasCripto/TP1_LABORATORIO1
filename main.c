#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"


int main()
{
    char salir = 'n';
    int opciones;
    int opcUno;
    int opcDos;
    int opcTres;
    // int costoDeComida;
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
    //  int contadorJugadores;
    // int flagCosto;
    //  int flagJugadores;
    //  int flagControl;
    int contUefa;
    int contConmebol;
    int contConcacaf;
    int contCaf;
    int contOfc;
    int contAfc;
    //  float pUefa;
    //  float pConmebol;
    //  float pConcacaf;
    //  float pCaf;
    //  float pAfc;

    contAfc = 0;
    contCaf = 0;
    contConcacaf = 0;
    contConmebol = 0;
    contOfc = 0;
    contUefa = 0;
    //  flagControl = 0;
    //  flagCosto = 0;
    //  flagJugadores = 0;
    //  contadorJugadores = 0;
    // costoHospedaje = 0;
    // costoDeComida = 0;
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
        system("cls");
        switch(opciones)
        {
        case 1:// menu de mantenimiento
            menuMantenimiento(&opcUno);
            if(opcUno == 1 || opcUno ==2 || opcUno == 3)
            {
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
            }
            else
            {
                printf("La opcion es incorrecta\n");
            }
            break;
        case 2:// menu jugadores

            menuJugadores(&opcDos);

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
                    menuConfederaciones(&opcTres);
                    switch(opcTres)
                    {
                    case 1:
                        contUefa++;
                        break;
                    case 2:
                        contConmebol++;
                        break;
                    case 3:
                        contConcacaf++;
                        break;
                    case 4:
                        contOfc++;
                        break;
                    case 5:
                        contAfc++;
                        break;
                    case 6:
                        contCaf++;
                        break;
                    }
                    printf("Elija el numero de camiseta\nNumero: ");
                    scanf("%d", &numeroCamiseta);
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
                    menuConfederaciones(&opcTres);
                      switch(opcTres)
                    {
                    case 1:
                        contUefa++;
                        break;
                    case 2:
                        contConmebol++;
                        break;
                    case 3:
                        contConcacaf++;
                        break;
                    case 4:
                        contOfc++;
                        break;
                    case 5:
                        contAfc++;
                        break;
                    case 6:
                        contCaf++;
                        break;
                    }
                    printf("Elija el numero de camiseta\nNumero: ");
                    scanf("%d", &numeroCamiseta);
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
                    menuConfederaciones(&opcTres);
                      switch(opcTres)
                    {
                    case 1:
                        contUefa++;
                        break;
                    case 2:
                        contConmebol++;
                        break;
                    case 3:
                        contConcacaf++;
                        break;
                    case 4:
                        contOfc++;
                        break;
                    case 5:
                        contAfc++;
                        break;
                    case 6:
                        contCaf++;
                        break;
                    }
                    printf("Elija el numero de camiseta\nNumero: ");
                    scanf("%d", &numeroCamiseta);
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
                    printf("Elija la confederacion:\n\n");
                    printf("1- UEFA\n");
                    printf("2- CONMEBOL\n");
                    printf("3- CONCACAF\n");
                    printf("4- OFC\n");
                    printf("5- AFC\n");
                    printf("6- CAF\n");
                    scanf("%d", &confederaciones);
                      switch(opcTres)
                    {
                    case 1:
                        contUefa++;
                        break;
                    case 2:
                        contConmebol++;
                        break;
                    case 3:
                        contConcacaf++;
                        break;
                    case 4:
                        contOfc++;
                        break;
                    case 5:
                        contAfc++;
                        break;
                    case 6:
                        contCaf++;
                        break;

                    }
                    printf("Elija el numero de camiseta\nNumero: ");
                    scanf("%d", &numeroCamiseta);
                }
                break;
            default:
                printf("no es una opcion valida\n");
                break;
            }
            break;
        case 3:
            printf("ingresaste al menu de control\n");
            break;
        case 4:
            printf(" porcentaje uefa: %d\n porcentaje conmebol: %d\n porcentaje concacaf: %d\n porcentaje Ofc: %d\n porcentaje Afc: %d\n porcentaje Caf: %d\n", contUefa, contConmebol, contConcacaf, contOfc, contAfc, contCaf);
            break;
        case 5:
            confirmarSalida(&salir);
            break;
        default:
            printf("no es una opcion valida");
            break;
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;

}








