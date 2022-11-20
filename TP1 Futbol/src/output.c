/*
 * output.c
 *
 *  Created on: 18 nov. 2022
 *      Author: Pablo
 */

#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include <ctype.h>
#include <string.h>


int mostrarInformes(float* pUefa, float* pConmebol, float* pConcacaf, float* pOfc, float* pAfc, float* pCaf, float* costoMantenimiento,float*  aumento,float* totalConAumento)
{
    int todoOk = 0;
    if(pUefa != NULL && pConmebol != NULL && pConcacaf != NULL && pOfc != NULL && pAfc != NULL && pCaf != NULL && costoMantenimiento != NULL && aumento != NULL && totalConAumento != NULL)
    {
        printf(" Promedio UEFA: %.2f\n Promedio CONMEBOL: %.2f\n Promedio CONCACAF: %.2f\n Promedio OFC: %.2f\n Promedio AFC: %.2f\n Promedio CAF: %.2f\n", *pUefa, *pConmebol, *pConcacaf, *pOfc, *pAfc, *pCaf);
        if(pUefa > pConmebol && pUefa > pConcacaf && pUefa > pOfc && pUefa > pAfc && pUefa > pCaf)
        {
            printf("El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f su nuevo valor es de $%.2f\n ", *costoMantenimiento, *aumento, *totalConAumento);
        }
        else
        {
            printf("El costo de mantenimiento es de $%.2f\n", *costoMantenimiento);
        }
    }


    return todoOk;
}
