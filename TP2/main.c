#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 10
#define TAMCONF 6


typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
} eConfederaciones;

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

//funciones utn
int esNumerica(char* cadena);
int getInt(int* pResultado);
int myGets(char* cadena, int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos);
int isValidNombre(char *pBuffer, int limite);
int getString(char *pBuffer, int limite);


//////////////////
int menu();
int inicializarJugador(eJugador lista[], int tam);
int buscarLibre(eJugador lista[], int tam);
int altaJugador(eJugador lista[], eConfederaciones listaConf[], int tamConf, int tam, int* pId);
void mostrarJugador(eJugador j, eConfederaciones listaConf[], int tamConf);
int mostrarJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
int bajaJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf);
int buscarJugadorId(int id, eJugador lista[], int tam);
int modificarJugador(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf);
int harcodearJugadores(int* pjugador, eJugador vec[], int tam, int cant);
int mostrarConfederaciones(eConfederaciones lista[], int tam);
void mostrarConfederacion(eConfederaciones c);
int harcodearConfederaciones(eConfederaciones vec[], int tam);
int asignarNombreConfederaciones(eConfederaciones lista[] ,int tam,int idConfederacion,char descConfederaciones[]);
int menuModificacion();

int main()
{
    char seguir = 's';
    int nexId = 0;
    eConfederaciones listaConfe[TAMCONF] = {{100, "CONMEBOL", "SUDAMERICA", 1916},
        {101, "UEFA", "EUROPA", 1954},
        {102, "AFC", "ASIA", 1954},
        {103, "CAF", "AFRICA", 1957},
        {104, "CONCACAF", "N Y C AMERICA", 1961},
        {105, "OFC", "OCEANIA", 1966}};
    eJugador lista[TAM];

    /*if(!inicializarJugador(lista, TAM))
    {
        printf("Error al cargar datos ");
    }*/
    inicializarJugador(lista, TAM);
    harcodearJugadores(&nexId, lista, TAM, 10);
//    harcodearConfederaciones(listaConfe, TAMCONF);

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaJugador(lista,listaConfe, TAMCONF, TAM, &nexId ))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("El Alta se realizo con exito\n");
            }
            break;
        case 2:
            if(!bajaJugador(lista, TAM, listaConfe, TAMCONF))
            {
                printf("Baja cancelada por el usuario\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 3:
            modificarJugador(lista, TAM, listaConfe, TAMCONF);
            break;
        case 4:
            mostrarJugadores(lista, TAM, listaConfe, TAMCONF);
            break;
        case 5:
            printf("Salir\n");
            seguir = 'n';
            break;
        default:
            printf("Opcion Invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"  *** ABM JUGADORES***\n\n1- ALTA DE JUGADOR\n2- BAJA DE JUGADOR\n3- MODIFICAR JUGADOR\n4- INFORMES\n5- SALIR\nIngrese una opcion: \n", "Error, opcion invalida\n\n",1,5,99);

    return opcion;
}
int inicializarJugador(eJugador lista[], int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}
int buscarLibre(eJugador lista[], int tam)
{
    int posicionLibre = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                posicionLibre = i;
                break;
            }
        }
    }
    return posicionLibre;
}

int altaJugador(eJugador lista[], eConfederaciones listaConf[], int tamConf, int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    int auxInt;
    float auxFloat;
    eJugador auxJugador;
    if(lista != NULL && pId != NULL && tam > 0)
    {

        system("cls");
        printf("            ***  ALTA DE JUGADOR  ***\n\n");
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar ");
        }
        else
        {
            auxJugador.id = *pId;
            (*pId)++;

            utn_getNombre(auxJugador.nombre,50,"Ingrese nombre: \n","Error, reingrese nombre",3);

            utn_getNombre(auxJugador.posicion,50,"Ingrese posicion: \n", "Error, reingrese posicion",3);

            utn_getNumero(&auxInt,"Ingrese numero de camiseta: \n","Numero no valido\n", 1, 100, 99);

            auxJugador.numeroCamiseta = auxInt;

            fflush(stdin);

            mostrarConfederaciones(listaConf, tamConf);

            utn_getNumero(&auxInt,"Ingrese una Opcion: \n","Opcion no valida\n",100,105,99);

            auxJugador.idConfederacion = auxInt;

            printf("Ingrese Salario: ");
            scanf("%f", &auxFloat);

            auxJugador.salario = auxFloat;

            fflush(stdin);

            utn_getNumero(&auxInt,"Ingrese anios de contrato entre 1 y 10: \n","Error, no esta dentro del rango\n", 1, 10,99);

            auxJugador.aniosContrato = auxInt;

            auxJugador.isEmpty = 0;

            lista[indice] = auxJugador;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarJugador(eJugador j, eConfederaciones listaConf[], int tamConf)
{
    char descConfederaciones[50];

    asignarNombreConfederaciones(listaConf,tamConf, j.idConfederacion,descConfederaciones);

    printf("| %4d  |    %-10s     |        %-10s   | %3d        |   %10.2f   |      %-10s          | %2d anios  |\n",
           j.id,
           j.nombre,
           j.posicion,
           j.numeroCamiseta,
           j.salario,
           descConfederaciones,
           j.aniosContrato);
}

int mostrarJugadores(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int flag;
    eJugador auxJugador;
    eConfederaciones auxConf;

    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("                               *** LISTA DE JUGADORES ***\n");
        printf("========================================================================================================================\n");
        printf("|  ID   |       NOMBRE      |       POSICION      | N CAMISETA |     SUELDO     |       CONFEDERACION      | CONTRATO  | \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam-1; i++)
        {
            for(int j = i+1; j<tam ; j++)
            {
                if((lista[i].idConfederacion == lista[j].idConfederacion &&
                   strcmp(lista[i].nombre, lista[j].nombre) >0) ||(
                    lista[i].idConfederacion > lista[j].idConfederacion))
                {
                    auxJugador = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxJugador;





                }
                /*if(lista[i].id > lista[j].id)
                {
                    auxJugador = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxJugador;
                }*/
            }
        }
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i], listaConf, tamConf);
                flag = 0;
            }

        }
        printf("=================================================================================================================\n");
        if(flag)
        {
            printf("No hay jugsdores para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaJugador(eJugador lista[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("                               *** LISTA DE JUGADORES ***\n");
        printf("================================================================================================================\n");
        printf("|  ID   |    NOMBRE    |     POSICION    | N CAMISETA  |     SUELDO     |       CONFEDERACION      | CONTRATO  | \n");
        printf("---------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i], listaConf, tamConf);

            }
        }
        printf("================================================================================================================\n");
        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",1,3000,99);

        indice = buscarJugadorId(id,lista, tam);

        if(indice == -1)
        {
            printf("el id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarJugador(lista[indice], listaConf, tamConf);
            printf("\nPresione S para confirmar: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return todoOk;
}

int buscarJugadorId(int id, eJugador vec[], int tam)
{
    int indice = -1;
    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty && vec[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int harcodearJugadores(int* pjugador, eJugador vec[], int tam, int cant)
{
    int todoOk;
    eJugador jugadores[10] = {{1, "Messi", "Delantero", 10, 100, 70000, 3 },
        {2, "Quinteros", "Mediocampo", 10, 101, 40000, 4},
        {3, "Sorin", "Defensor", 3, 100, 28000, 3},
        {4, "Zlatan", "Delantero", 7, 103, 23000, 3},
        {5, "Rivaldo", "Delantero", 10, 105, 21000, 3},
        {6, "Ponzio", "Mediocampo", 23, 101, 24000, 3},
        {7, "Armani", "Arquero", 1, 102, 27000, 3},
        {8, "Martinez", "Arquero",23, 103, 20000, 3},
        {9, "Romero", "Defensor", 2, 104, 29000, 3},
        {10,"De Paul", "Mediocampo", 7, 100, 22000, 3},
    };
    if(pjugador != NULL && vec != NULL && tam > 0 && cant<= tam && cant <= 10)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = jugadores[i];
            (*pjugador)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

int modificarJugador(eJugador vec[], int tam, eConfederaciones listaConf[], int tamConf)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma = 's';
    char auxCad[50];
    int auxInt;

    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("            *** MODIFICAR JUGADOR ***         \n");

        for(int i = 0; i <tam; i++)
        {
            if(vec[i].isEmpty == 0)
            {
                mostrarJugador(vec[i], listaConf, tamConf);

            }
        }

        utn_getNumero(&id,"Ingrese id: ","Error, campo no valido",1,3000,2);

        indice = buscarJugadorId(id, vec, tam);

        if(indice == -1)
        {
            printf("No existe un jugador con el id: %d", id);
        }
        else
        {
            mostrarJugador(vec[indice], listaConf, tamConf);
            printf("Confirma modificacion?: s/n :");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                fflush(stdin);
                switch(menuModificacion())
                {
                case 1:
                    printf("Ingrese nuevo Nombre:\n");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(vec[indice].nombre, auxCad);
                    break;
                case 2:
                    printf("Ingrese nueva posicion: \n");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(vec[indice].posicion, auxCad);
                    break;
                case 3:
                    utn_getNumero(&auxInt,"Ingrese numero de camiseta: \n","Numero no valido\n", 1, 100, 3);
                    vec[indice].numeroCamiseta = auxInt;
                    break;
                case 4:
                    utn_getNumero(&auxInt,"Ingrese id de la Confederacion: \n100 - CONMEBOL\n101 - UEFA\n102 - AFC\n103 - CAF\n104 - CONCACAF\n105 - OFC\nIngrese una Opcion: \n","Opcion no valida\n",100,105,3);
                    vec[indice].idConfederacion = auxInt;
                    break;
                case 5:
                    printf("Ingrese nuevo salario");
                    break;
                case 6:
                    utn_getNumero(&auxInt,"Ingrese anios de contrato entre 1 y 10: \n", "Error, no esta dentro del rango\n", 1,10,3);
                    vec[indice].aniosContrato = auxInt;
                    break;
                default:
                    printf("La opcion es invalida");

                }
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }


        }

    }
    return todoOk;
}
int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena, longitud, stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;

}

int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[64];

    if(pResultado != NULL)
    {
        if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);// cambiar a atof
            retorno = 0;
        }

    }
    return retorno;
}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) < 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] <'0' || cadena[i] > '9'/* || cadena[i] != ','*/)// para flotante, contar las comas y que me ermita una sola
            {
                retorno =0;
                break;
            }
            i++;

        }
    }
    return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s", mensaje);
        if(getInt(&bufferInt)==0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s", mensajeError);
    }
    return retorno;
}
int menuModificacion()
{
    int opcion;
    system("cls");
    utn_getNumero(&opcion,"     *** Modificar Alumnos ***     \n\n1- Modificar Nombre\n2- Modificar Posicion\n3- Modificar Numero de camiseta\n4- Modificar Confederacion\n5- Modificar Salario\n6- Modificar Anios de contrato\n7- Salir\nIngrese Opcion: \n","Error, campo no valido",1,7,2);

    return opcion;
}
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
      ((pBuffer[0]>='A' && pBuffer[0]<='Z') || (pBuffer[0]>='a' && pBuffer[0]<='z')))

    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int utn_getNombre(  char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}
void mostrarConfederacion(eConfederaciones c)
{
    printf("|%4d |     %-10s   |         %-15s       |        %d       |\n",
           c.id,
           c.nombre,
           c.region,
           c.anioCreacion);
}
int mostrarConfederaciones(eConfederaciones lista[], int tam)
{
    int todoOk = 0;
    int flag;
    eConfederaciones auxConf;

    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("                               *** LISTA DE CONFEDERACIONES ***\n");
        printf("==============================================================================\n");
        printf("| ID  |     NOMBRE       |              REGION           | ANIO DE CREACION  | \n");
        printf("------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam-1; i++)
        {
            for(int j = i+1; j<tam ; j++)
            {
                if(lista[i].id > lista[j].id)
                {
                    auxConf = lista[i];
                    lista[i]= lista[j];
                    lista[j] = auxConf;
                }
            }
        }
        for(int i = 0; i <tam; i++)
        {

                mostrarConfederacion(lista[i]);
                flag = 0;


        }
        printf("==============================================================================\n");
        if(flag)
        {
            printf("No hay confederacion para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
/*int harcodearConfederaciones(eConfederaciones vec[], int tam)
{
    int todoOk = 1;
       eConfederaciones conf[6] = {{100, "CONMEBOL", "SUDAMERICA", 1916},
        {101, "UEFA", "EUROPA", 1954},
        {102, "AFC", "ASIA", 1954},{103, "CAF", "AFRICA", 1957},
        {104, "CONCACAF", "N Y C AMERICA", 1961},{105, "OFC", "OCEANIA", 1966}};


    return todoOk;

}*/

int asignarNombreConfederaciones(eConfederaciones lista[] ,int tam, int idConfederacion, char descConfederaciones[])
{
    int todoOk = 0;
    if(lista != NULL && tam >0 && descConfederaciones)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == idConfederacion)
            {
                strcpy(descConfederaciones, lista[i].nombre);
                break;
            }
        }

        todoOk = 1;
    }

    return todoOk;
}
