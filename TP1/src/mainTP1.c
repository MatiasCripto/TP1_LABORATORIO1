/*
 ============================================================================
 Name        : TPN!.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mibiblioteca.h"
#include "input.h"

int main(void)
{
	setbuf(stdout, NULL);
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
	            menuMantenimiento(&opcMantenimiento);
	                flagCosto = 1;
	                switch(opcMantenimiento)
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
	                default:
	                    printf("La opcion es incorrecta\n");
	                    break;
	                }
	            break;
	        case 2:// menu jugadores
	            if(flagCosto == 1)
	            {
	                flagJugadores = 1;
	                cargaJugadores(&opcJugadores);

	                switch(opcJugadores)// carga de jugadores con hasta su maximo de ingresos
	                {
	                case 1:

	                    if(contadorArquero ==2)
	                    {
	                        printf("El cupo de esa posicion ya esta cubierto\n");
	                    }
	                    else
	                    {
	                        cargaConfederaciones(&confederaciones);
	                        contadorArquero++;
	                        acumJugadores++;
	                    }
	                    break;
	                case 2:
	                    if(contadorDefensor ==8)
	                    {
	                        printf("El cupo de esa posicion ya esta cubierto\n");
	                    }
	                    else
	                    {
	                        cargaConfederaciones(&confederaciones);
	                        contadorDefensor++;
	                        acumJugadores++;
	                    }
	                    break;
	                case 3:
	                    if(contadorMediocampo ==8)
	                    {
	                        printf("El cupo de esa posicion ya esta cubierto\n");
	                    }
	                    else
	                    {
	                        cargaConfederaciones(&confederaciones);
	                        contadorMediocampo++;
	                        acumJugadores++;
	                    }
	                    break;
	                case 4:
	                    if(contadorDelantero ==4)
	                    {
	                        printf("El cupo de esa posicion ya esta cubierto\n");
	                    }
	                    else
	                    {
	                        cargaConfederaciones(&confederaciones);
	                        acumJugadores++;
	                        contadorDelantero++;
	                    }
	                    break;
	                default:
	                    printf("no es una opcion valida\n");
	                    break;
	                }
	                switch(confederaciones)
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
	            else
	            {
	                printf("Primero debe ingresar en la opcion 1 para poder entrar aqui\n");
	            }
	            break;
	        case 3:
	            if(flagJugadores == 1)
	            {
	                flagCalculos = 1;
	                dividir(&pUefa, contUefa, acumJugadores );
	                dividir(&pConmebol, contConmebol, acumJugadores);
	                dividir(&pConcacaf, contConcacaf, acumJugadores);
	                dividir(&pOfc, contOfc, acumJugadores);
	                dividir(&pAfc, contAfc, acumJugadores);
	                dividir(&pCaf, contCaf, acumJugadores);
	                costoMantenimiento = acumuladorComida + acumuladorHospedaje + acumuladorTransporte;
	                aumento = costoMantenimiento * 0.35;
	                totalConAumento = costoMantenimiento + aumento;
	                printf("\n Los calculos se realizaron con exito.\n\n\n");
	            }
	            else
	            {
	                printf("Primero tiene que pasar por las opciones 1 y 2 para ingresar aqui\n");
	            }
	            break;
	        case 4:
	            if(flagCalculos == 1)
	            {
	                printf(" Promedio UEFA: %.2f\n Promedio CONMEBOL: %.2f\n Promedio CONCACAF: %.2f\n Promedio OFC: %.2f\n Promedio AFC: %.2f\n Promedio CAF: %.2f\n", pUefa, pConmebol, pConcacaf, pOfc, pAfc, pCaf);
	                if(pUefa > pConmebol && pUefa > pConcacaf && pUefa > pOfc && pUefa > pAfc && pUefa > pCaf)
	                {
	                    printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f su nuevo valor es de $%.2f\n ", costoMantenimiento, aumento, totalConAumento);
	                }
	                else
	                {
	                    printf("El costo de mantenimiento es de $%.2f\n", costoMantenimiento);
	                }
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
