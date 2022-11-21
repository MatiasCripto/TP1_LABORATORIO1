/*
 * validaciones.h
 *
 *  Created on: 9 nov. 2022
 *      Author: USER
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
int menuPrincipal();
int menuListados();
int myGets(char* cadena, int longitud);
int getInt(int* pResultado);
int esNumerica(char* cadena);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int isValidNombre(char *pBuffer, int limite);
int utn_getNombre( char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int getDeCadenaAEntero(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int getString(char *pBuffer, int limite);
int isValidNumber(char *pBuffer, int limite);
int utn_getCharSeguir(char * pResultado, char * mensaje, char * mensajeError, int reintentos);
int getChar (char * pResultado,int tam);
int esNumericaChar ( char * cadena);
void menuPosicion();
void menuNacionalidad();
int menuEdicioon();
int menuConvocados();
int menuOrdenamientos();
int confirmarSalida(char* pSalida);
