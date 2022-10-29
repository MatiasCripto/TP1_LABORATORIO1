/*
 * informes.h
 *
 *  Created on: 29 oct. 2022
 *      Author: USER
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
/** \brief muestra los jugadores por confederaciones
 *
 * \param vec[] eJugador array a recorrer
 * \param tam int tamanio del array
 * \param listaConf[] eConfederaciones array de confederaciones a recorrer
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarJugadoresConfederaciones(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra el promedio de salarios y los que ganan mas del promedio
 *
 * \param lista[] eJugador array a recorrer
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarPromedioDeSalarios(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra los jugadores segun en la confederacion que se elija por id
 *
 * \param idConfe int id de confederacion para elegir y ver los jugadores
 * \param vec[] eJugador array de jugadores
 * \param tam int tamanio del array
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarJugadoresIdConfederaciones(int idConfe, eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra los informes
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarInformes(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra la confederacion con mayor contratos
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarConfederacionMayorContratos(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra la region que contenga mas jugadores
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederacones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarRegionMayorJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra el total de los salarios
 *
 * \param lista[] eJugador array a recorrer
 * \param tam int tamanio del array
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarTotalDeSalarios(eJugador lista[], int tam);
/** \brief calcula el porcentaje de los jugadores por confederacion y los muestra
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int porcentajeJugadoresPorConf(eJugador lista[],int tam,eConfederaciones listaConf[],int tamConf);
