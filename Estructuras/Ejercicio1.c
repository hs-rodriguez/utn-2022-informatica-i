/*
    Ejercicio 1:
    1-) Generar el TDA  ALUMNOS conteniendo los siguientes campos:
        DNI  (entero)
        APELLIDO Y NOMBRE  ( 60 caracteres)
        NOTA PRIMER PARCIAL (entero)
        NOTA SEGUNDO PARCIAL (entero)
        NOTA PROMEDIO  (real)
        CONDICION    ( 20 caracteres)


    2-) Se sabe que como máximo hay 90 alumnos. Generar un VECTOR en programa principal del tipo ALUMNOS.


    3-)Generar la función  CARGA_ALUMNOS  que permita SOLAMENTE el ingreso de:
            DNI – APELLIDO Y NOMBRE – NOTA PRIMER PARCIAL – NOTA SEGUNDO PARCIAL
    De cada alumno. Esta carga finaliza con DNI cero.
    NOTAS (0 a 10). Utilizar función LeeControlDato.  Para el ingreso y verificacion de los valores.


    4-) Generar la función PROCESO  que calcule el promedio y la condición de cada alumno, según:
        Ambas notas >= 8  condición   “PROMOCIONA”
        Alguna nota o las dos  < 6      condición  “REPROBADA”
        Otro caso   condición  “CURSADA”


    5-) Permitir  consultas por DNI, informando la NOTA PROMEDIO y CONDICION correspondiente.
        Finaliza la consulta con DNI a consultar igual a cero.
        FUNCION  BUSQUEDA. (Solo busca el DNI a consultar dentro del vector creado)
        
    6-) Ordenar por nota promedio en forma  descendente
*/

#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 90 // 90 en enunciado

#ifdef __unix
#include <strings.h>
#define fflush(stdin); getchar();
#endif

struct Alumno
{
    int dni;
    char nombre[61];
    int primerParcial;
    int segundoParcial;
    float promedio;
    char condicion[21];
};

int Carga_Alumnos(struct Alumno[], int);
int LeeControlDato(int, int);
int Busqueda(struct Alumno[], int, int);
void Proceso(struct Alumno[], int);
void Consulta(struct Alumno[], int);
void Ordenamiento(struct Alumno[], int);
void Mostrar(struct Alumno[], int);

main()
{
    struct Alumno listaAlumnos[MAX_ALUMNOS];
    int cantAlumnos;

    cantAlumnos = Carga_Alumnos(listaAlumnos, MAX_ALUMNOS);
    Proceso(listaAlumnos, cantAlumnos);
    Consulta(listaAlumnos, cantAlumnos);
    Ordenamiento(listaAlumnos, cantAlumnos);
    Mostrar(listaAlumnos, cantAlumnos);
}

int Carga_Alumnos (struct Alumno V[], int tam)
{
    int i = 0, dni, band = 0;

    printf("\nIngrese el DNI: ");
    do
    {
        if (!band)
            band++;
        else
            printf("El DNI ya existe. Ingrese nuevamente: ");
        dni = LeeControlDato(10000000, 99999999);
    } while (Busqueda(V, dni, i) != -1);
    
    while (dni > 0)
    {
        V[i].dni = dni;
        printf("\nIngrese el apellido y nombre: ");
        fflush(stdin);
        gets(V[i].nombre);
        printf("\nIngrese la nota del primer parcial: ");
        V[i].primerParcial = LeeControlDato(0, 10);
        printf("\nIngrese la nota del segundo parcial: ");
        V[i].segundoParcial = LeeControlDato(0, 10);
        i++;
        band = 0;

        printf("\nIngrese el DNI: ");
        do
        {
            if (!band)
                band++;
            else
                printf("El DNI ya existe. Ingrese nuevamente: ");
            dni = LeeControlDato(10000000, 99999999);
        } while (Busqueda(V, dni, i) != -1);
    }
   return i; 
}

int LeeControlDato(int limiteInferior, int limiteSuperior)
{
    int dato, band = 0;
    do
    {
        if (!band)
            band++;
        else
            printf("Dato no valido. Ingrese Nuevamente: ");
        scanf("%d", &dato);
    } while ((dato < limiteInferior || dato > limiteSuperior) && dato != 0);
    return dato;
}

int Busqueda(struct Alumno V[], int dato, int tam)
{
    int i = 0, pos = -1;
    while (i < tam && pos == -1)
    {
        if (V[i].dni == dato)
            pos = i;
        i++;
    }
    return pos;
}

void Proceso(struct Alumno V[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        V[i].promedio = (float)(V[i].primerParcial + V[i].segundoParcial) / 2;
        if (V[i].primerParcial >= 8 && V[i].segundoParcial >= 8)
            strcpy(V[i].condicion, "PROMOCIONA");
        else if (V[i].primerParcial < 6 || V[i].segundoParcial < 6)
            strcpy(V[i].condicion, "REPROBADA");
        else
            strcpy(V[i].condicion, "CURSADA");
    }  
}

void Consulta(struct Alumno V[], int tam)
{
    int dni, pos;

    printf("\nIngrese el DNI: ");
    dni = LeeControlDato(10000000, 99999999);

    while (dni != 0)
    {
        pos = Busqueda(V, dni, tam);
        if (pos != -1)
        {
            printf("\nLa nota promedio es: %.2f", V[pos].promedio);
            printf("\nCondicion: %s", V[pos].condicion);
        }
        else
            printf("El DNI ingresado no existe.");

        printf("\nIngrese el DNI: ");
        dni = LeeControlDato(10000000, 99999999);
    }
}

void Ordenamiento (struct Alumno V[], int tam)
{
    int i, j, iAux;
    float fAux;
    char sAux[61];
    for (i = 0; i < tam - 1; i++)
        for (j = 0; j < tam - 1 - i; j++)
            if (V[j].promedio < V[j+1].promedio)
            {
                iAux = V[j].dni;
                V[j].dni = V[j+1].dni;
                V[j+1].dni = iAux;

                iAux = V[j].primerParcial;
                V[j].primerParcial = V[j+1].primerParcial;
                V[j+1].primerParcial = iAux;

                iAux = V[j].segundoParcial;
                V[j].segundoParcial = V[j+1].segundoParcial;
                V[j+1].segundoParcial = iAux;

                fAux = V[j].promedio;
                V[j].promedio = V[j+1].promedio;
                V[j+1].promedio = fAux;

                strcpy(sAux, V[j].nombre);
                strcpy(V[j].nombre, V[j+1].nombre);
                strcpy(V[j+1].nombre, sAux);

                strcpy(sAux, V[j].condicion);
                strcpy(V[j].condicion, V[j+1].condicion);
                strcpy(V[j+1].condicion, sAux);
            }
}

void Mostrar(struct Alumno V[], int tam)
{
    int i;
    printf("\n%-8s | %-60s | %s | %s | %s | %s", "DNI", "Apellido y Nombre", "Parcial 1", "Parcial 2", "Promedio", "Condicion");
    for (i = 0; i < tam; i++)
    {
        printf("\n%d | %-60s | %9d | %9d | %8.2f | %s", V[i].dni, V[i].nombre, V[i].primerParcial, V[i].segundoParcial, V[i].promedio, V[i].condicion);
    }
}