/*
 * jugadores.h
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include "confederaciones.h"

typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
} eJugador;

#endif /* JUGADORES_H_ */

/** \brief inicializa el array dejando las posiciones libres
 *
 * \param lista[] eJugador array a recorrer
 * \param tam int tamanio del array
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int inicializarJugador(eJugador lista[], int tam);
/** \brief busca una posicion libre en el array
 *
 * \param lista[] eJugador array a recorrer
 * \param tam int tamanio del array
 * \return int retorna -1 si fallo, y si no, retorna la posicion libre
 *
 */
int buscarLibre(eJugador lista[], int tam);
/** \brief da de alta un jugador
 *
 * \param lista[] eJugador array de jugador
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \param tam int tamanio del array de jugadores
 * \param pId int* puntero al id autoincremental
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int altaJugador(eJugador lista[], eConfederaciones listaConf[], int tamConf, int tam, int* pId);
/** \brief carga los datos ingresados
 *
 * \param lista eJugador* puntero a la estructura jugador
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del arrayt de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int cargarDatosJugador(eJugador* lista,eConfederaciones listaConf[], int tamConf);
/** \brief muestra un jugador
 *
 * \param j eJugador variable para asignar los datos
 * \param lista[] eJugador array de jugador
 * \param tam int tamanio del  array de jugadores
 * \param listaConf[] eConfederaciones array de confederaicones
 * \param tamConf int tamanio del array de confederaciones
 * \return void
 *
 */
void mostrarJugador(eJugador j, eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief muestra todos los jugadores
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciuones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief da la baja a un jugador
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int bajaJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief busca un jugador por su id
 *
 * \param id int id a buscar
 * \param vec[] eJugador array de jugador
 * \param tam int tamanio del array de jugadores
 * \return int retorna -1 si fallo y si no, retorna la posicion de ese id
 *
 */
int buscarJugadorId(int id, eJugador lista[], int tam);
/** \brief modifica un jugador
 *
 * \param vec[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int modificarJugador(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief harcodea los jugadores
 *
 * \param pjugador int* puntero al id de jugadores
 * \param vec[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param cant int cantidad a harcodear
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int harcodearJugadores(int* pjugador, eJugador vec[], int tam, int cant);
/** \brief modifica los datos del jugador
 *
 * \param jugador eJugador* puntero a la estructura eJugador
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int modificarDatosJugador(eJugador* jugador);
/** \brief asigna la descripcion al id ingresado
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param idposicion int id ingresado para asignar la descripcion
 * \param descPosicion[] char descripcion a asignar
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int asignarNombrePosiciones(eJugador* jugador);
/** \brief muestra los jugadores por el id
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array
 * \param listaConf[] eConfederaciones array de confederaciones
 * \param tamConf int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarJugadoresPorId(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
/** \brief ordena la lista por doble criterio
 *
 * \param lista[] eJugador array de jugadores
 * \param tam int tamanio del array de jugadores
 * \param listaConfe[] eConfederaciones array de confederaciones
 * \param tamConfe int tamanio del array de confederaciones
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int ordenarDobleCriterio(eJugador lista[], int tam, eConfederaciones listaConfe[], int tamConfe);


int ordenarConfederacionesPorNombreYPorJugadores(eJugador lista[], int tam, eConfederaciones listaConfe[], int tamConfe);

