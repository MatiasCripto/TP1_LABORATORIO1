/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"

int main(void)
{
	setbuf(stdout,NULL);

    char salir = 'n';
    int opciones;
    int opcMantenimiento;
    int opcJugadores;
    int acumuladorComida;
    int acumuladorTransporte;
    int acumuladorHospedaje;
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
    int flagCosto;
    int flagJugadores;
    int flagCalculos;
    float costoMantenimiento;
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
    flagCalculos = 0;
    flagCosto = 0;
    flagJugadores = 0;
    contadorArquero = 0;
    contadorDefensor = 0;
    contadorDelantero = 0;
    contadorMediocampo = 0;
    acumuladorComida = 0;
    acumuladorTransporte = 0;
    acumuladorHospedaje = 0;
    costoMantenimiento = 0;

    do
    {
        // menu principal
        menu(&opciones, acumuladorHospedaje, acumuladorComida, acumuladorTransporte, contadorArquero, contadorDefensor, contadorMediocampo, contadorDelantero);
        system("cls");
        switch(opciones)
        {
        case 1:// menu de mantenimiento
                guardarCostosMantenimiento(&acumuladorHospedaje, &acumuladorTransporte, &acumuladorComida, &opcMantenimiento);
                flagCosto = 1;
            break;
        case 2:// menu jugadores
            if(flagCosto == 1)
            {
                flagJugadores = 1;
                cargarJugadores(&opcJugadores, &contadorArquero, &acumJugadores,&contadorDefensor,&contadorMediocampo,&contadorDelantero,&confederaciones);
                acumuladoresDeConfederaciones(&contUefa,&contConcacaf,&contConmebol,&contCaf,&contOfc,&contAfc,&confederaciones);
            }
            else
            {
                printf("Primero debe ingresar en la opcion 1 para poder entrar aqui\n");
            }
            break;
        case 3:
            if(flagJugadores == 1)
            {
                flagCalculos = 1;
                if(calcularInformes(&costoMantenimiento, &aumento, &totalConAumento, &acumuladorComida, &acumuladorHospedaje, &acumuladorTransporte) == 1)
                {
                    dividir(&pUefa, contUefa, acumJugadores );
                    dividir(&pConmebol, contConmebol, acumJugadores);
                    dividir(&pConcacaf, contConcacaf, acumJugadores);
                    dividir(&pOfc, contOfc, acumJugadores);
                    dividir(&pAfc, contAfc, acumJugadores);
                    dividir(&pCaf, contCaf, acumJugadores);
                    printf("\n Los calculos se realizaron con exito.\n\n\n");
                }
                else
                {
                    printf("Error al hacer los calculos\n");
                }
            }
            else
            {
                printf("Primero tiene que pasar por las opciones 1 y 2 para ingresar aqui\n");
            }
            break;
        case 4:
            if(flagCalculos == 1)
            {
                mostrarInformes(&pUefa, &pConmebol, &pConcacaf, &pOfc, &pAfc, &pCaf, &costoMantenimiento,&aumento,&totalConAumento);
            }
            else
            {
                printf("Primero debe pasar pos las opciones 1, 2 y 3 para poder ingresar aqui\n");
            }
            flagCosto = 0;
            flagCalculos = 0;
            flagJugadores = 0;
            break;
        case 5:
            confirmarSalida(&salir);
            break;
        default:
            printf("no es una opcion valida\n");
            break;
        }
        system("pause");
    }while(salir == 'n');
    return 0;
 }


