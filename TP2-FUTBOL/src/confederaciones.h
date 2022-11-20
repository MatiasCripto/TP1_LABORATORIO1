/*
 * confederaciones.h
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_

typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
    int isEmpty;

} eConfederaciones;

#endif /* CONFEDERACIONES_H_ */
/** \brief muestra las confederaciones
 *
 * \param lista[] eConfederaciones array a recorrer
 * \param tam int tamanio del array
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int mostrarConfederaciones(eConfederaciones lista[], int tam);
/** \brief muestra una confederacion
 *
 * \param c eConfederaciones variable para asignar los datos
 * \return void
 *
 */
void mostrarConfederacion(eConfederaciones c);
/** \brief le asigna la descripcion del nombre al id recibido
 *
 * \param lista[] eConfederaciones array a recorrer
 * \param tam int tamanio del array
 * \param idConfederacion int id a recibir
 * \param descConfederaciones[] char descripcion a asignar
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int asignarNombreConfederaciones(eConfederaciones lista[],int tam,int idConfederacion,char descConfederaciones[]);
/** \brief harcodea las confederaciones
 *
 * \param pConfederacion int* puntero al id de la confederacion
 * \param vec[] eConfederaciones array a recorrer
 * \param tamConf int tamanio del array
 * \param cant int cantidad de harcodeos
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int harcodearConfederaciones(int* pConfederacion, eConfederaciones vec[], int tamConf, int cant);
/** \brief busca un lugar libre en el array
 *
 * \param lista[] eConfederaciones array a recorrer
 * \param tam int tamanio del array
 * \return int retorna -*1 si fallo o  si salio todo bien retorna el indice
 *
 */
int buscarLibreConfe(eConfederaciones lista[], int tam);
/** \brief da de alta una confederacion
 *
 * \param lista[] eConfederaciones array a recorrer
 * \param tamConf int tamanio del array
 * \param pId int* puntero al id
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int altaConfederacion(eConfederaciones lista[], int tamConf,int* pId);
/** \brief da de baja una confederacion
 *
 * \param lista[] eConfederaciones array a recorrer
 * \param tamConf int tamanio del array
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int bajaConfederacion(eConfederaciones lista[], int tamConf);
/** \brief buscar una confederacion con el id
 *
 * \param id int id a buscar
 * \param lista[] eConfederaciones array a recorrer
 * \param tamConf int tamanio del array
 * \return int devuelve -1 si no encontro el id, y si salio todo bien devuelve la posicion
 *
 */
int buscarConfederacionId(int id, eConfederaciones lista[], int tamConf);

/** \brief modifica un jugador
 *
 * \param vec[] eConfederaciones array a recorrer
 * \param tam int tamanio del array
 * \return int retorna 0 si fallo o 1 si salio todo bien
 *
 */
int modificarConfederacion(eConfederaciones vec[], int tam);
