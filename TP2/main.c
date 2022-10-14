#include <stdio.h>
#include <stdlib.h>

#define TAM 3


typedef struct
{
    int id;
    char nombre[50];
    char regiom[50];
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

int menu();
int inicializarJugador(eJugador lista[], int tam);
int buscarLibre(eJugador lista[], int tam);
int altaJugador(eJugador lista[], int tam, int* pId);
void mostrarJugador(eJugador j);
int mostrarJugadores(eJugador lista[], int tam);
int bajaJugador(eJugador lista[], int tam);
int BuscarJugadorId(eJugador lista[], int tam, int id);

int main()
{
    char seguir = 's';
    int nexId = 1;
    eJugador lista[TAM] = {{21, "Messi", "Delantero", 10, 100, 70000, 3 },
        {233, "Quinteros", "Volante" , 10, 101, 40000, 4},
        {3000, "De la Cruz", "Volante", 11, 102, 25000, 3 }};

    /*if(!inicializarJugador(lista, TAM))
    {
        printf("Error al cargar datos ");
    }*/

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaJugador(lista, TAM, &nexId))
            {
                printf("No se pudo realizar el Alta\n");
            }
            else
            {
                printf("El Alta se realizo con exito\n");
            }
            break;
        case 2:
            if(!bajaJugador(lista, TAM))
            {
                printf("No se pudo realizar la Baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;
        case 3:
            printf("Modificar Jugador\n");
            break;
        case 4:
            mostrarJugadores(lista, TAM);
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
    printf("     *** ABM JUGADORES ***     \n\n");
    printf("1- ALTA DE JUGADOR\n");
    printf("2- BAJA DE JUGADOR\n");
    printf("3- MODIFICACION DE JUGADOR\n");
    printf("4- INFORMES\n");
    printf("5- SALIR\n");
    printf("Ingrese Opcion: \n");
    scanf("%d", &opcion);
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

int altaJugador(eJugador lista[], int tam, int* pId)
{
    int todoOk = 0;
    int indice;
    short auxShort;
    int auxInt;
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

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(auxJugador.nombre);

            printf("Ingrese Posicion: ");
            fflush(stdin);
            gets(auxJugador.posicion);

            printf("Ingrese Numero de Camiseta del 1 al 100: ");
            scanf("%hd", &auxShort);
            while(auxShort<1 || auxShort >100)
            {
                printf("Error, Reingrese Numero de Camiseta: ");
                scanf("%hd", &auxShort);
            }
            auxJugador.numeroCamiseta = auxShort;

            printf("Ingrese id de la Confederacion:\n"
                   " 100 - CONMEBOL\n"
                   " 101 - UEFA\n"
                   " 102 - AFC\n"
                   " 103 - CAF\n"
                   " 104 - CONCACAF\n"
                   " 105 - OFC\n"
                   "Ingrese una Opcion: ");
            scanf("%d", &auxInt);
            while(auxInt <100 || auxInt >105)
            {
                printf("Error, Reingrese id de la Confederacion:\n"
                   " 100 - CONMEBOL\n"
                   " 101 - UEFA\n"
                   " 102 - AFC\n"
                   " 103 - CAF\n"
                   " 104 - CONCACAF\n"
                   " 105 - OFC\n"
                   "Ingrese una Opcion: ");
            scanf("%d", &auxInt);
            }
            auxJugador.idConfederacion = auxInt;

            printf("Ingrese Salario: ");
            scanf("%f", &auxJugador.salario);

            printf("Ingrese anios de Contrato: ");
            scanf("%hd", &auxJugador.aniosContrato);

            auxJugador.isEmpty = 0;

            lista[indice] = auxJugador;

            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarJugador(eJugador j)
{
    printf("| %4d  | %-10s   |   %-10s    |    %d       |   %10.2f     |   %3d       | %d anios   |\n",
           j.id,
           j.nombre,
           j.posicion,
           j.numeroCamiseta,
           j.salario,
           j.idConfederacion,
           j.aniosContrato);
}

int mostrarJugadores(eJugador lista[], int tam)
{
    int todoOk = 0;
    int flag;
    int auxId;

    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("                               *** LISTA DE JUGADORES ***\n");
        printf("=====================================================================================================\n");
        printf("|  ID   |    NOMBRE    |     POSICION    | N CAMISETA  |     SUELDO       |CONFEDERACION| CONTRATO  | \n");
        printf("-----------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <tam-1; i++)
        {
            for(int j = i+1; j<tam ; j++)
            {
                if(lista[i].id > lista[j].id)
                {
                    auxId = lista[i].id;
                    lista[i].id = lista[j].id;
                    lista[j].id = auxId;
                }
            }
        }
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i]);
                flag = 0;
            }

        }
        printf("=====================================================================================================\n");
        if(flag)
        {
            printf("No hay jugsdores para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaJugador(eJugador lista[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam > 0)
    {
        system("cls");
        printf("                               *** LISTA DE JUGADORES ***\n");
        printf("=====================================================================================================\n");
        printf("|  ID   |    NOMBRE    |     POSICION    | N CAMISETA  |     SUELDO       |CONFEDERACION| CONTRATO  | \n");
        printf("=====================================================================================================\n\n");
        for(int i = 0; i <tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarJugador(lista[i]);

            }
        }
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = BuscarJugadorId(lista, tam, id);

        if(indice == -1)
        {
            printf("el id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            mostrarJugador(lista[indice]);
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

int BuscarJugadorId(eJugador lista[], int tam, int id)
{
    int indice = -1;

    if(lista != NULL && tam >0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id && lista[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}
