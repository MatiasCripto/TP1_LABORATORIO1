/*
 * mibiblioteca.h
 *
 *  Created on: 22 sep. 2022
 *      Author: USER
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_



#endif /* MIBIBLIOTECA_H_ */

#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED




#endif // MENUPRINCIPAL_H_INCLUDED

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



/** \brief recibe el costo y lo acumula
 *
 * \param pAcumCosto int* acumulador de costos
 * \return void
 *
 */
void menuCostos(int* pAcumCosto);



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

