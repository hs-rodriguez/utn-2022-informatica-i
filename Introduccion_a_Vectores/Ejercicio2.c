/*
    Ejercicio 2:
    Dada una lista de 10 valores enteros.
    Se pide
    a-) Cargar los datos en memoria en un vector llamado “A”
    b-) Asignar al quinto elemento del vector el valor 8.
    c-) Informar el producto entre el elemento ubicado en la 4ta posición del vector “A” por
    su subíndice.
    d-) Intercambiar el tercer elemento del vector con el octavo.
    e-) Informar la cantidad de elementos pares del vector.
    f-) Informar la suma de los elementos de orden de ingreso par (ubicados en pos. 1,3, 5....)
    g-) Realizar la suma de los últimos 5 elementos del vector
    h-) Generar otro vector ”B” donde cada elemento sea el contenido del original * 2
    i-) Generar otro vector “C” que sea la suma entre “A” y “B”
    j-) Generar el vector “D”, que sea “A” permutado.
    k-) Generar otro vector con los elementos impares de “A”
    l-) Informar la cantidad de veces que existe el número 8 en el vector ”A”
    m-) Informar el menor elemento del vector “A” y sus posiciones (múltiples)
*/

#include <stdio.h>
#include <conio.h>

void cargarVector(int[], int);
void mostrarVector(int[], int);
void cambiarElementoVector(int[], int, int, int);
void productoElementoIndice(int[], int, int);
void intercambiarElementos(int[], int, int, int);
int cantidadElementosPares(int[], int);
int sumaIngresosPares(int[], int);
int sumaUltimos5(int[], int);

int main (void)
{
    int vectorA[10];
    cargarVector(vectorA, 10);
    printf("\nValor de A: ");
    mostrarVector(vectorA, 10);
    getch();
    
    cambiarElementoVector(vectorA, 10, 5, 8);
    printf("\n\nCambio en posicion 5\n");
    mostrarVector(vectorA, 10);

    productoElementoIndice(vectorA, 10, 4);

    intercambiarElementos(vectorA, 10, 3, 8);
    printf("\n\nIntercambio de la posicion 3 y 8\n");
    mostrarVector(vectorA, 10);

    printf("\n\nSuma de los ingresos pares: %d", sumaIngresosPares(vectorA, 10));
    printf("\n\nSuma de los ultimos 5 elementos: %d", sumaUltimos5(vectorA, 10));

    return 0;
}

void cargarVector(int vec[], int tam) 
{
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese el valor de la posicion %d: ", i+1);
        scanf("%d", &vec[i]);
    } 
}

void mostrarVector(int vec[], int tam) 
{
    for (int i = 0; i < tam; i++)
    {
        printf("\nValor de la posicion %d: %d", i+1, vec[i]);
    }  
}

void cambiarElementoVector(int vec[], int tam, int pos, int valor)
{
    if (pos > 0 && pos <= tam)
        vec[pos-1] = valor;
    else
        printf("\nLa posicion no es valida.");
}

void productoElementoIndice(int vec[], int tam, int pos)
{
    if (pos > 0 && pos <= tam)
        printf("\nEl producto del elemento %d con su indice (%d) es: %d", vec[pos-1], pos-1, vec[pos-1]*(pos-1));
    else
        printf("\nLa posicion no es valida.");
}

void intercambiarElementos(int vec[], int tam, int posA, int posB)
{
    int aux;
    if (posA > 0 && posA <= tam && posB > 0 && posB <= tam)
    {
        aux = vec[posA-1];
        vec[posA-1] = vec[posB-1];
        vec[posB-1] = aux;
    }
}

int cantidadElementosPares(int vec[], int tam)
{
    int cant = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vec[i] % 2 == 0)
            cant++;
    }
    return cant;
}

int sumaIngresosPares(int vec[], int tam)
{
    int suma = 0;
    for (int i = 0; i < tam; i++)
    {
        if((i + 1) % 2 == 0)
            suma += vec[i];
    }
    return suma;
}

int sumaUltimos5(int vec[], int tam)
{
    int suma = 0;
    for (int i = 1; i <= 5; i++)
    {
        suma += vec[tam-i];
    }
    return suma;
}