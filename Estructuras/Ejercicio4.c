/**
 * Ejercicio 4:
 * Se desea realizar un programa para una clase de una facultad. La clase tiene 40 alumnos. Los datos de los
 * alumnos consisten en: nombre (hasta 30 caracteres), número de legajo (entero entre 0 y 10000) y edad.
 * Una vez realizada la carga de la base de datos se ingresará por teclado el legajo de un alumno y su nota
 * (entre 1 y 10) en una materia. El ingreso finalizará con un legajo negativo. Para un mismo alumno se
 * ingresarán múltiples notas y se garantiza que se ingresará al menos una por alumno. De no existir el legajo
 * ingresado informar el error y continuar.
 * Se pide realizar un programa que realice lo siguiente:
 *  a) Cargar la base de datos de los 40 alumnos
 *  b) Permitir el ingreso de las notas de los alumnos por teclado como se explica en el enunciado
 *  c) Al finalizar la carga imprimir lo siguiente en pantalla:
 *      a. Un listado ordenado de mayor a menor por promedio de notas indicando nombre y legajo.
 *      Utilizar una función que ordene.
 *      b. Cantidad de alumnos para los cuales se cargó solo 1 nota.
 *      c. El nombre del alumno con mayor cantidad de notas 10. Hay que considerar que no hay más de
 *      1 alumno con máxima cantidad de notas 10. En este punto utilizar una función de búsqueda
 *      que retorne el legajo del alumno.
 */

#include <stdio.h>
#include <string.h>

#define CANT_ALUMNOS 5 // 40 en enunciado

/**
 * Estructura Alumno:
 * Campos: 
 * nombre (string)
 * legajo (int)
 * edad (int)
 * promedio (float)
 * cantidadNotas (int)
 * cantidad10 (int)
 */
typedef struct {
    char nombre[31];
    int legajo;
    int edad;
    float promedio;
    int cantidadNotas;
    int cantidad10;
} Alumno;

void Carga(Alumno[], int);
int LeeControlRango(int, int);
int Busqueda(Alumno[], int, int);
void CargaNotas(Alumno[], int);
void Ordenamiento(Alumno[], int);
void Mostrar(Alumno[], int);
int Maximo(Alumno[], int);

main()
{
    Alumno listaAlumnos[CANT_ALUMNOS];
    Carga(listaAlumnos, CANT_ALUMNOS);
    CargaNotas(listaAlumnos, CANT_ALUMNOS);
    Ordenamiento(listaAlumnos, CANT_ALUMNOS);
    Mostrar(listaAlumnos, CANT_ALUMNOS);  
}

/**
 * Funcion Carga: 
 * Objetivo: Permite inicializar la base de datos de alumnos.
 * Recibe: Vector de tipo Alumno, cantidad de alumnos. 
 */
void Carga(Alumno listaAlumnos[], int tam)
{
    int i, band = 0;
    Alumno aux;
    for (i = 0; i < tam; i++)
    {
        printf("\nIngrese el nombre del alumno: ");
        fflush(stdin);
        gets(aux.nombre);
        printf("\nIngrese el legajo: ");
        do
        { 
            if (!band)
                band++;
            else
                printf("El legajo ya existe. Ingrese nuevamente: ");
            aux.legajo = LeeControlRango(0, 10000);
        } while (Busqueda(listaAlumnos, aux.legajo, i) != -1);
        band = 0;
        printf("\nIngrese la edad: ");
        aux.edad = LeeControlRango(18, 80);
        listaAlumnos[i] = aux;
    }
}

/**
 * Funcion LeeControlRango: 
 * Objetivo: Permite validar un numero.
 * Recibe: Limite inferior del rango, limite superior. 
 * Retorna: Numero dentro del rango.
 */
int LeeControlRango(int li, int ls)
{
    int dato, band = 0;
    do
    {
        if (!band)
            band++;
        else
            printf("El numero no es valido. Ingrese nuevamente: ");
        scanf("%d", &dato);    
    } while(dato < li || dato > ls);
    return dato;
}

/**
 * Funcion Busqueda: 
 * Objetivo: Permite buscar un dato en un vector.
 * Recibe: Vector de tipo Alumno, dato a buscar, cantidad de elementos del vector. 
 * Retorna: La posicion del vector que contiene el dato si existe, o -1 si no lo encuentra.
 */
int Busqueda(Alumno lista[], int dato, int tam)
{
    int i = 0, pos = -1;
    while (i < tam && pos == -1)
    {
        if (lista[i].legajo == dato)
            pos = i;
        i++;
    }
    return pos;
}

/**
 * Funcion CargaNotas: 
 * Objetivo: Permite cargar las notas de los alumnos y calcular sus promedios.
 * Recibe: Vector de tipo Alumno, cantidad de alumnos. 
 */
void CargaNotas(Alumno lista[], int tam)
{
    int legajo, nota, pos;

    // Inicializo en cero los campos de la estructura (No se puede hacer en la definicion del tipo de dato)
    for (pos = 0; pos < tam; pos++)
    {
        lista[pos].promedio = 0;
        lista[pos].cantidad10 = 0;
        lista[pos].cantidadNotas = 0;
    }
    
    printf("\nIngrese el legajo del alumno: ");
    scanf("%d", &legajo);
    while (legajo > -1)
    {
        pos = Busqueda(lista, legajo, tam);
        if (pos != -1)
        {
            printf("\nIngrese la nota: ");
            nota = LeeControlRango(1, 10);
            lista[pos].promedio += nota;
            lista[pos].cantidadNotas++;
            if (nota == 10)
                lista[pos].cantidad10++;
        }
        else
            printf("El legajo ingresado no existe. ");

        printf("\nIngrese el legajo del alumno: ");
        scanf("%d", &legajo);
    }

    // Calcular los promedios
    for (pos = 0; pos < tam; pos++)
    {
        // Se garantiza una nota por alumno
        if (lista[pos].cantidadNotas == 0) 
        {
            lista[pos].cantidadNotas = 1;
            printf("\nIngrese una nota del alumno %d: ", lista[pos].legajo);
            lista[pos].promedio = LeeControlRango(1, 10);
            if (lista[pos].promedio == 10)
                lista[pos].cantidad10 = 1;
        }

        lista[pos].promedio /= lista[pos].cantidadNotas;  
    }
}

/**
 * Funcion Ordenamiento: 
 * Objetivo: Permite ordenar la lista de alumnos por promedio en orden descendente.
 * Recibe: Vector de tipo Alumno, cantidad de alumnos. 
 */
void Ordenamiento (Alumno lista[], int tam)
{
    int i, j;
    Alumno aux;
    for (i = 0; i < tam-1; i++)
        for (j = 0; j < tam-1-i; j++)
            if(lista[j].promedio < lista[j+1].promedio)
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
}

/**
 * Funcion Mostrar: 
 * Objetivo: Muestra la lista de alumnos y las condiciones del enunciado.
 * Recibe: Vector de tipo Alumno, cantidad de alumnos. 
 */
void Mostrar(Alumno lista[], int tam)
{
    int i, cantidad = 0;
    printf("\nLegajo \t Nota \t Nombre");
    for (i = 0; i < tam; i++)
        printf("\n%d \t %.2f \t %s", lista[i].legajo, lista[i].promedio, lista[i].nombre);
    for (i = 0; i < tam; i++)
        if (lista[i].cantidadNotas == 1)
            cantidad++;
    printf("\n\nLa cantidad de alumnos con una sola nota es %d.", cantidad);
    i = Busqueda(lista, Maximo(lista, tam), tam);
    printf("\nEl alumno con mayor cantidad de notas 10 es: %s", lista[i].nombre);
}

/**
 * Funcion Maximo: 
 * Objetivo: Obtener el legajo del alumno con más cantidad de 10.
 * Recibe: Vector de tipo Alumno, cantidad de alumnos. 
 * Retorna: Legajo del alumno con más 10.
 */
int Maximo(Alumno lista[], int tam)
{
    int i, max, legajo;
    max = lista[0].cantidad10;
    legajo = lista[0].legajo;
    for (i = 1; i < tam; i++)
        if (lista[i].cantidad10 > max)
        {
            max = lista[i].cantidad10;
            legajo = lista[i].legajo;
        }
    return legajo;
}