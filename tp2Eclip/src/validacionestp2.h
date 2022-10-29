/*
 * validacionestp2.h
 *
 *  Created on: 29 oct. 2022
 *      Author: USER
 */

#ifndef VALIDACIONESTP2_H_
#define VALIDACIONESTP2_H_



#endif /* VALIDACIONESTP2_H_ */
/** \brief Recibe una cadena de caracteres y devuelve 1
 * 		  en el caso de que el texto este compuesto solo por números.
 *
 * \param cadena char* Cadena de carateres a recorrer.
 * \return int retorna 1 si la validacion fallo y 0 si salio todo bien
 *
 */
int esNumerica(char* cadena);
/** \brief Obtiene el dato como una cadena de caracteres, para luego
 * 	      validarlo y parsear/formatear el dato a una variable entera.
 *
 * \param pResultado int* Puntero a entero, con el valor a setear.
 * \return int retorna -1 si la validacion fallo y 0 si salio bien
 *
 */
int getInt(int* pResultado);
/** \brief
 *
 * \param cadena char* cadena a recorrer
 * \param longitud int longitud de la cadena
 * \return int -1 Error: NO es numerica. 0 Es valido
 *
 */
int myGets(char* cadena, int longitud);
/** \brief Pide al usuario un numero
 *
 * \param pResultado int* Direccion de memoria de la variable donde escribe el valor ingresado por el usuario
 * \param mensaje char* El mensaje que imprime para pedir un valor
 * \param mensajeError char* mensaje que imprime si el rango no es valido
 * \param minimo int valor minimo valido (inclusive)
 * \param maximo int valor maximo valido (no inclusive)
 * \param reintentos int cantidad de reintentos
 * \return int retorna 0  si esta todo OK. -1: Si hubo un error
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/** \brief pide una cadena al usuario y la valida
 *
 * \param pNombre char* cadena a recibir
 * \param limite int limite de caracteres de la cadena
 * \param mensaje char* mensaje de peticion al usuario
 * \param mensajeError char* mensaje de error
 * \param reintentos int cantidad de reintentos
 * \return int retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
/** \brief valida una cadena de caracteres
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int retorna 0 si fallo y 1 si salio todo bien
 *
 */
int isValidNombre(char *pBuffer, int limite);
/** \brief valida que sea una cadena
 *
 * \param pBuffer char* puntero a guardar el dato
 * \param limite int limite de la cadena
 * \return int  retorna -1 si fallo, y 0 si salio todo bien
 *
 */
int getString(char *pBuffer, int limite);

int esFlotante(char *str);

int getFloat(float* pResult);

int input_GetFloat(float* pResult, char* message, char* errorMessage, float min, float max, int retries);

int confirmarSalida(char* pSalida);
/** \brief da a elegir las opciones a modificar
 *
 * \return int retorna la opcion
 *
 */
int menuModificacion();
/** \brief da a elegir los informes
 *
 * \return int retorna la opcion
 *
 */
int menuInformes();
/** \brief da a elegir opciones del menu principal
 *
 * \return int retorna la opcion
 *
 */
int menu();
/** \brief da a elegir las opciones de la posicion
 *
 * \return void
 *
 */
void menuPosicion();

int menuModificacionConfederacion();
