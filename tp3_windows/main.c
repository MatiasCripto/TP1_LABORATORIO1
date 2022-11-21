#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "validaciones.h"
#include "Seleccion.h"

int main()
{
	char salir = 'n';
	setbuf(stdout,NULL);
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* jugadoresConvocados = ll_newLinkedList();

        	do{
        		switch(menuPrincipal()){
        			case 1:
        				if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) &&
        				   controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones))
        				{
        					printf("El archivo se cargo con exito\n");
        				}
        			break;
        			case 2:
        				if(!controller_agregarJugador(listaJugadores))
        				{
        					printf("Error al mostrar los datos\n");
        				}
        			break;
        			case 3:
        				if(!controller_editarJugador(listaJugadores))
        				{
        					printf("Error, no se puede modificar el jugador\n");
        				}
        			break;
        			case 4:
        				if(!controller_removerJugador(listaJugadores))
        				{
        					printf("Error, no se pudo remover el jugador\n");
        				}
        			break;
        			case 5:
        				if(!controller_listaDeListados(listaSelecciones,listaJugadores ))
        				{
        					printf("Error al mostrar el menu de listados\n");
        				}
        			break;
        			case 6:
        				switch(menuConvocados())
        				{
        				case 1:
							if(!controller_convocarJugador(listaJugadores, listaSelecciones))
							{
								printf("Error al convocar el jugador\n");
							}
        				break;
        				case 2:
        					if(!controller_quitarJugadorConvocado(listaJugadores, listaSelecciones))
        					{
        						printf("Error al quitar el jugador de la seleccion\n");
        					}
        					break;
        				}
        			break;
        			case 7:
        				switch(menuOrdenamientos())
        				{
        				case 1:
        					if(!controller_ordenarJugadoresNacionalidad(listaJugadores))
        					{
        						printf("Error al mostrar los datos\n");
        					}
        					break;
        				case 2:
        					if(!controller_ordenarSelecciones(listaSelecciones))
        					{
								printf("Error al mostrar los datos\n");
							}
        					break;
        				case 3:
        					if(!controller_ordenarJugadoresEdad(listaJugadores))
        					{
								printf("Error al mostrar los datos\n");
							}
        					break;
        				case 4:
        					if(!controller_ordenarJugadoresNombre(listaJugadores))
        					{
								printf("Error al mostrar los datos\n");
							}
        					break;
        				}

        			break;
        			case 8:
        				if(!controller_filtarConvocados(listaJugadores, jugadoresConvocados))
        				{
        					printf("Error al filtrar los jugadores\n");
        				}
        				if(!controller_guardarJugadoresModoBinario("jugadoresCovocados.bin" ,jugadoresConvocados))
        				{
        					printf("Error al guardar en binario\n");
        				}

        			break;
        			case 9:
        				if(!controller_cargarJugadoresDesdeBinario("jugadoresCovocados.bin" ,jugadoresConvocados))
        				{
        					printf("Error al cargar en binario\n");
        				}
        				if(!controller_listarJugadores(jugadoresConvocados))
        				{
        					printf("Error al mostrar los jugadores convocados\n");
        				}
        			break;
        			case 10:
        				if(!controller_guardarJugadoresModoTexto("jugadores.csv" , listaJugadores))
        				{
        					printf("Error al guardar en texto\n");
        				}
        			break;
        			case 11:
        				confirmarSalida(&salir);
        			break;
        		}
        	}while(salir == 'n');
        	ll_deleteLinkedList(jugadoresConvocados);
        	ll_deleteLinkedList(listaJugadores);
			ll_deleteLinkedList(listaSelecciones);

    return 0;
}

