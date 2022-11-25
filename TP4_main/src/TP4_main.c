/*
 ============================================================================
 Name        : TP4_main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    int valor;
} eDato;
// la estructura perona solo es para mostrar en el filter//
typedef struct
{
	int id;
	char nombre[20];
	int edad;
	char sexo;
}ePersona;
int ordenarPorId(void* id1,void* id2);
void mostrarPersona(ePersona* persona);
void mostrarPersonas(LinkedList* lista);
int esHombre(void* hombre);

int main()
{
	setbuf(stdout,NULL);
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
    printf("TP4 \n\n\n\n");
    int retorno;


/*ll_newLinkedList*/
    LinkedList* lista=ll_newLinkedList();


    eDato* unDato=(eDato*)malloc(sizeof(eDato));
    ePersona* persona=(ePersona*)malloc(sizeof(ePersona));
    if(unDato==NULL && persona == NULL)
    {
        exit(1);

    }
    unDato->id=33;
    unDato->valor=66;

    //estos valores solo son para el filter
    ePersona p1 = {123,"Jorge",  35, 'M'};
	ePersona p2 = {135,"Jesica", 31, 'F'};
	ePersona p3 = {254,"Agustin",23, 'M'};
	ePersona p4 = {658,"Camila" ,22, 'F'};
	ePersona p5 = {496,"Esteban",39, 'M'};
	ePersona p6 = {378,"Soledad",29, 'F'};

	ll_add(lista,&p1);
	ll_add(lista,&p2);
	ll_add(lista,&p3);
	ll_add(lista,&p4);
	ll_add(lista,&p5);
	ll_add(lista,&p6);

/* ll_filter*/ //solo muestra a los hombres
	LinkedList* listaFiltrada = ll_filter(lista,esHombre);

	mostrarPersonas(listaFiltrada);



/* ll_len  */
    retorno=ll_len(lista);
    printf("ll_len( )retorna :%d por que la lista esta vacia \n",retorno);


/* ll_add */
    retorno=ll_add(lista,unDato);
    printf("ll_add( )retorna :%d . \n0 si agrego a la lista -1 si no pudo \n",retorno);
    retorno=ll_len(lista);
    printf("size despues de ll_add %d\n",retorno);


/* ll_get */
    eDato* auxiliar=NULL;
    auxiliar=(eDato*)ll_get(lista,0);
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }


/* ll_set */
    eDato* unDatoParaRemplazar=(eDato*)malloc(sizeof(eDato));
    if(unDatoParaRemplazar==NULL)
    {
        exit(1);
    }
    unDatoParaRemplazar->id=55;
    unDatoParaRemplazar->valor=105;

    ll_set(lista,0,unDatoParaRemplazar);
    //compruebo pidiendo el dato en esa posicion con ll_get

    auxiliar=(eDato*)ll_get(lista,0);
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }


/* ll-remove  */
    //utilizo removo para eliminar el unico elemento de la lista, por lo que cuando llame a ll_len el valor debe ser 0
    ll_remove(lista,0);
    retorno=ll_len(lista);
    printf("ll_len despues de ll_remove al unico elemento de la lista %d\n",retorno);


/*  ll_clear  */
    eDato* array=(eDato*)malloc(sizeof(eDato)*5);
    if(array!=NULL)
    {

        for(i=0; i<5; i++)
        {
            (array+i)->id=i+1;
            (array+i)->valor=i;

        }
        for(j=0; j<5; j++)
        {
            ll_add(lista,array+j);
        }
        retorno=ll_len(lista);
        printf("ll_len despues de cargar 5 elemntos con ll_add :%d \n",retorno);
        ll_clear(lista);
        retorno=ll_len(lista);
        printf("ll_len despues de utilizar ll_clear  :%d \n",retorno);

    }

/* ll_isEmpty */
    retorno=ll_isEmpty(lista);
    printf("ll_isEmpty sobre la lista vacia retorna %d \n",retorno);


/*ll_indexOf*/
    for(k=0; k<5; k++)
    {
        (array+k)->id=k;
        (array+k)->valor=1+k;
        ll_add(lista,array+k);
    }
    auxiliar=(eDato*)ll_get(lista,3);
    //tendria que coincidir el indice de ll_get con ll_indexOf
    retorno=ll_indexOf(lista,auxiliar);
    printf("ll_index retorno el indice del elemento obtenido con ll_get(lista,3) :%d \n",retorno);

/* ll_push */
    eDato* datoPush=(eDato*)malloc(sizeof(eDato));
    if(datoPush!=NULL)
    {
        datoPush->id=99;
        datoPush->valor=100;
    }
    ll_push(lista,0,datoPush);
    retorno=ll_len(lista);
    printf("ll_len despues de ll_push(lista,0)%d", retorno );
    auxiliar=(eDato*)ll_get(lista,0);
    printf("ll_get(lista,0) retorno un puntero con los valores del nuevo elemento con push\n");
    if(auxiliar!=NULL)
    {
        printf("id : %d\n", auxiliar->id);
        printf("valor: %d\n",auxiliar->valor);
    }
/* ll_pop */
    auxiliar=(eDato*)ll_pop(lista,0);
    retorno=ll_len(lista);
    printf("ll_len despues de usar ll_pop(lista,0) devuelve:%d ",retorno);

    printf("el auxiliar que retorna ll_pop es el del indice 0  verifico mostrando campo\n");
    printf("id: %d valor: %d\n",auxiliar->id,auxiliar->valor);

/* ll_clone */
    LinkedList* listaClone=ll_clone(lista);
    retorno=ll_len(listaClone);
    printf("ll_clone(lista) y lo asigne a listaClone\n ");
    printf("ll_len(listaClone) tiene que ser  igual a lista original %d\n",retorno);

/* ll_sublist */
    LinkedList* listaSublist=ll_subList(listaClone,0,2);
    retorno=ll_len(listaSublist);
    printf("ll_sublist(listaClone,0,2 y lo asigno a listaSubList\n");
    printf("ll_len(listaSublist)tiene que ser de 2 elementos :%d\n",retorno);

/* ll_containsAll*/
    retorno=ll_containsAll(listaClone,listaSublist);
    printf("ll_containsAll(listaClone,listaSubList) retorna %d  ,por que es una sublista de listaClone \n",retorno);
    retorno=ll_containsAll(listaSublist,listaClone);
    printf("ll_containsAll(listaSublist,listaClone) retorna %d  ,por que es una sublista de listaClone \n",retorno);
/* ll_contains */
    retorno=ll_contains(listaClone,auxiliar);
    printf("ll_contains(listaClone,auxiliar) auxiliar es un puntero que se le asigno un dato eliminado con ll_pop\n");
    printf("ll_contains retorna %d\n",retorno);
    ll_push(listaClone,0,auxiliar);
    retorno=ll_contains(listaClone,auxiliar);
    printf("ll_contains retorna %d despues de ll_push(listaClone,0,auxiliar)\n",retorno);
    retorno=ll_len(listaClone);
    printf("ll_len(listaClone) retorna ahora %d\n",retorno);

/* ll_sort */
    LinkedList* listaOrdenar=ll_newLinkedList();
    eDato*auxOrdenar=NULL;
    eDato* datosParaOrdenar=(eDato*)malloc(sizeof(eDato)*10);
    if(datosParaOrdenar!=NULL)
    {
        for(l=0;l<10;l++)
        {
            (datosParaOrdenar+l)->id=l;
            (datosParaOrdenar+l)->valor=10-l;
        }
    }
    for(m=0;m<10;m++)
    {
        ll_add(listaOrdenar,datosParaOrdenar+m);
        auxOrdenar=(eDato*)ll_get(listaOrdenar,m);
        printf("id:%d valor: %d\n",auxOrdenar->id,auxOrdenar->valor);
    }
    ll_sort(listaOrdenar,ordenarPorId,0);
    printf("ll_sort(listaOrdenar,OrdenarPorId,0)\n");
    for(n=0;n<ll_len(listaOrdenar);n++)
    {
        auxOrdenar=(eDato*)ll_get(listaOrdenar,n);
        printf("id:%d valor: %d\n",auxOrdenar->id,auxOrdenar->valor);
    }



/* ll_deleteLinkedList */
    ll_deleteLinkedList(listaOrdenar);
    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaClone);
    ll_deleteLinkedList(listaSublist);
    free(datoPush);
    free(array);
    free(unDato);

    return 0;
}
int ordenarPorId(void* id1, void* id2)
{
    int resultadoComparcion=0;
    if(((eDato*)id1)->id > ((eDato*)id2)->id)
    {
        resultadoComparcion=1;
    }
    if(((eDato*)id1)->id < ((eDato*)id2)->id)
    {
        resultadoComparcion=-1;
    }
    //printf("resultado comparacion %d",resultadoComparcion);
    return resultadoComparcion;

}
void mostrarPersonas(LinkedList* lista)
{
	int i;
	if(lista != NULL)
	{
		printf("ID    NOMBRE     EDAD  SEXO\n");
		for(i = 0; i < ll_len(lista); i++)
		{
			mostrarPersona((ePersona*)ll_get(lista,i));
		}
		printf("\n\n");
	}
}
void mostrarPersona(ePersona* persona)
{
	if(persona != NULL)
	{
		printf("%3d   %-12s%2d    %c\n", persona->id, persona->nombre, persona->edad, persona->sexo);
	}
}

int esHombre(void* hombre)
{
	int ok = 0;
	ePersona* persona = NULL;
	if(hombre != NULL)
	{
		persona = (ePersona*) hombre;
		if(persona->sexo == 'M')
		{
			ok = 1;
		}
	}
	return ok;
}
