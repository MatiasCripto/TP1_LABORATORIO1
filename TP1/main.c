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
    int acumuladorComida;
    int acumuladorTransporte;
    int acumuladorHospedaje;
    int numeroCamiseta;
    int confederaciones;
    int contadorArquero;
    int contadorDefensor;
    int contadorMediocampo;
    int contadorDelantero;
    int contUefa;
    int contConmebol;
    int contConcacaf;
    int contCaf;
    int contOfc;
    int contAfc;
    int acumJugadores;
    //  int contadorJugadores;
    //  int flagCosto;
    //  int flagJugadores;
    //  int flagControl;
    float costoManenimiento;
    float totalConAumento;
    float aumento;
    float pUefa;
    float pConmebol;
    float pConcacaf;
    float pCaf;
    float pAfc;
    float pOfc;


    pUefa = 0;
    pConmebol = 0;
    pConcacaf = 0;
    pCaf = 0;
    pAfc = 0;
    pOfc = 0;
    acumJugadores = 0;
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
    contadorArquero = 0;
    contadorDefensor = 0;
    contadorDelantero = 0;
    contadorMediocampo = 0;
    acumuladorComida = 0;
    acumuladorTransporte = 0;
    acumuladorHospedaje = 0;
    costoManenimiento = 0;

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
                    menuCostos(&acumuladorTransporte);
                    break;
                }
            }
            else
            {
                printf("La opcion es incorrecta\n");
            }
            break;
        case 2:// menu jugadores

            cargaJugadores(&opcDos);

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
                    cargaConfederaciones(&opcTres);
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
                    cargaConfederaciones(&opcTres);
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
                    cargaConfederaciones(&opcTres);
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
                   cargaConfederaciones(&opcTres);
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
                }
                break;
            default:
                printf("no es una opcion valida\n");
                break;
            }
            break;
        case 3:
            dividir(&pUefa, acumJugadores, contUefa);
            dividir(&pConmebol, acumJugadores, contConmebol);
            dividir(&pConcacaf, acumJugadores, contConcacaf);
            dividir(&pOfc, acumJugadores, contOfc);
            dividir(&pAfc, acumJugadores, contAfc);
            dividir(&pCaf, acumJugadores, contCaf);
            costoManenimiento = acumuladorComida + acumuladorHospedaje + acumuladorTransporte;
            aumento = costoManenimiento * 0.35;
            totalConAumento = costoManenimiento + aumento;
            printf("\n Los calculos se realizaron con exito.\n\n\n");
            break;
        case 4:
            printf(" Promedio UEFA: %.2f\n Promedio CONMEBOL: %.2f\n Promedio CONCACAF: %.2f\n Promedio OFC: %.2f\n Promedio AFC: %.2f\n Promedio CAF: %.2f\n", pUefa, pConmebol, pConcacaf, pOfc, pAfc, pCaf);
              if(pUefa > pConmebol && pUefa > pConcacaf && pUefa > pOfc && pUefa > pAfc && pUefa > pCaf)
            {
                printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f su nuevo valor es de $%.2f\n ", costoManenimiento, aumento, totalConAumento);
            }
            else
            {
                printf("El costo de mantenimiento es de $%d\n", costoManenimiento);
            }
            break;
        case 5:
            confirmarSalida(&salir);
            break;
        default:
            printf("no es una opcion valida");
            break;
        }
        system("pause");
        acumJugadores = acumJugadores + opcTres;
    }while(salir == 'n');

    return 0;

}








