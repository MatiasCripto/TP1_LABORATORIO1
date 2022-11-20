/*
 * input.h
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#ifndef INPUT_H_
#define INPUT_H_



#endif /* INPUT_H_ */
/** \brief pide una opcion y acumula los costos
 *
 * \param op1 int* guarda la opcion ingresada
 * \return void
 *
 */
int menuMantenimiento(int* op1);

/** \brief menu con las distintas confederaciones
 *
 * \param opcion int* guarda la opcion ingresada
 * \return int
 *
 */
int cargaConfederaciones(int* opcion);

/** \brief menu cn los distintos puestos de jugadores
 *
 * \param pOpciones int* guarda la opcion ingresada
 * \return void
 *
 */
int menuJugadores(int* pOpciones);

/** \brief recibe el costo y lo acumula
 *
 * \param pAcumCosto int* acumulador de costos
 * \return void
 *
 */
void menuCostos(int* pAcumCosto);



int guardarCostosMantenimiento(int* hospedaje, int* transporte, int* comida, int* pOpciones);




int cargarJugadores(int* pOpcionJugador, int* contadorArquero, int* acumJugadores, int* contadorDefensor, int* contadorMediocampo, int* contadorDelantero, int* opcionConfe);



int acumuladoresDeConfederaciones(int* contUefa, int* contConcacaf, int* contConmebol, int* contCaf, int* contOfc, int* contAfc, int* opcConfederaciones);



int calcularInformes(float* costoMantenimiento, float* aumento, float* totalConAumento, int* acumuladorComida, int* acumuladorHospedaje, int* acumuladorTransporte);


/** \brief confirma la carga y muestra actualizado los gastos y jugadores ingresados
 *
 * \param pOpciones int* almacena la opcion ingresada del menu principal
 * \param acumUno int acumula los gastos ingresados
 * \param acumDos int acumula los gastos ingresados
 * \param acumTres int acumula los gastos ingresados
 * \param contUno int cuenta los jugadores de cada posicion
 * \param contDos int cuenta los jugadores de cada posicion
 * \param contTres int cuenta los jugadores de cada posicion
 * \param contCuatro int cuenta los jugadores de cada posicion
 * \return void no retorna nada
 *
 */
void menu( int* pOpciones,int acumUno, int acumDos, int acumTres, int contUno, int contDos, int contTres, int contCuatro);


/** \brief valida a el caracter 's' para que sea la unica opcion que se debe ingresar si se quiere salir del programa
 *
 * \param pSalida char* asignacion de caracter
 * \return int
 *
 */
int confirmarSalida(char* pSalida);



/** \brief divide dos numeros validando que uno no sea 0
 *
 * \param pResultado float* donde se almacena el resultado
 * \param dividendo int ingreso del divisor
 * \param divisor int ingreso del dividendo != 0
 * \return int
 *
 */
int dividir(float* pResultado, int dividendo, int divisor);
