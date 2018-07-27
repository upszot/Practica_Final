#ifndef Complemento_ArrayList_H_INCLUDED
#define Complemento_ArrayList_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif // Complemento_ArrayList_H_INCLUDED


/** \brief Devuelve nuevo arraylist con datos filtrados de acuerdo a la funcion que reciba.
 *
 * \param void*
 * \return ArrayList* al_filter(ArrayList* listIn , int
 *
 */
ArrayList* al_filter(ArrayList* listIn , int (*functionFilter)(void*));

/** \brief Clona el array que recibe y lo ordena, devuelve el array clonado.
 *
 * \param void*
 * \param void*
 * \return ArrayList* clonaOrdenado(ArrayList *this,int
 *
 */
ArrayList* clonaOrdenado(ArrayList *this,int (*pFunc)(void* ,void*),int orden);

/** \brief Recorre el arrayList desde y hasta la posicion que se indique, imprime un titulo y muestra cada uno de los elementos recorridos con la funcion que se le pasa.
 *
 * \param void*
 * \return int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int
 *
 */
int al_MuestraElemento_desde_hasta(ArrayList *this,char *Titulo,int (*pFunc)(void*) ,int desde,int hasta,int paginado);

