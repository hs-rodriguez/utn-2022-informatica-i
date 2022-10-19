/*
    Ejercicio 1:
    Dada una lista de 10 valores enteros.
    Se pide:
    a-) Cargar la lista en memoria en un vector llamado A.
    b-) Copiar este vector en otro llamado B.
    c-) Generar un vector C correspondiente a la suma de A y B.
    d-) Copiar A en orden inverso en otro vector llamado D.
    e-) Listar los cuatro vectores simultáneamente informando en la primer columna el
    número de orden de los elementos.
    f-) Posiciones de elementos pares del vector A.
    g-) Elementos de posiciones impares del vector A.
    h-) La suma de los elementos del vector A.
    i-) Valor promedio del vector A.
    j-) Cantidad de elementos iguales a 32 del vector A.
    k-) Máximo Valor del vector A (único)
*/

#include <stdio.h>
#include <conio.h>

void cargarVector(int[], int);
void mostrarVector(int[], int);
void copiarVector(int[], int[], int);
void sumarVectores(int[], int[], int[], int);
void copiarVectorInverso(int[], int[], int);
void mostrarCuatroVectores(int[], int[], int[], int[], int);
void mostrarElementosParesVector(int[], int);
void mostrarPosicionesImparesVector(int[], int);
int sumarElementosVector(int[], int);
float promedioElementosVector(int[], int);
void mostrarElementosIgualesA32(int[], int);
int mayorValorVector(int[], int);



int main (void)
{
    int vectorA[10], vectorB[10], vectorC[10], vectorD[10];
    cargarVector(vectorA, 10);
    printf("\nValor de A: ");
    mostrarVector(vectorA, 10);
    getch();
    
    copiarVector(vectorA, vectorB, 10);
    printf("\n\nValor de B: ");
    mostrarVector(vectorB, 10);
    getch();

    sumarVectores(vectorA, vectorB, vectorC, 10);
    printf("\n\nValor de C: ");
    mostrarVector(vectorC, 10);
    getch();

    copiarVectorInverso(vectorA, vectorD, 10);
    printf("\n\nValor de D: ");
    mostrarVector(vectorD, 10);
    getch();

    mostrarCuatroVectores(vectorA, vectorB, vectorC, vectorD, 10);
    getch();

    mostrarElementosParesVector(vectorA, 10);
    getch();
    
    mostrarPosicionesImparesVector(vectorA, 10);
    getch();

    printf("\nLa suma de elementos de A es: %d", sumarElementosVector(vectorA, 10));

    printf("\nEl promedio de A es: %.2f", promedioElementosVector(vectorA, 10));

    mostrarElementosIgualesA32(vectorA, 10);

    printf("\nEl mayor valor de A es: %d", mayorValorVector(vectorA, 10));

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

void copiarVector(int vecOriginal[], int vecCopia[], int tam) 
{
    for (int i = 0; i < tam; i++)
    {
       vecCopia[i] = vecOriginal[i]; 
    }  
}

void sumarVectores(int vecA[], int vecB[], int vecSuma[], int tam) 
{
    for (int i = 0; i < tam; i++)
    {
       vecSuma[i] = vecB[i] + vecA[i]; 
    }  
}

void copiarVectorInverso(int vecOriginal[], int vecCopia[], int tam) 
{
    for (int i = 0; i < tam; i++)
    {
       vecCopia[i] = vecOriginal[(tam - 1) - i]; 
    }  
}

void mostrarCuatroVectores(int vecA[], int vecB[], int vecC[], int vecD[], int tam) 
{
    printf("\nIndice \t A \t B \t C \t D");
    for (int i = 0; i < tam; i++)
    {
        printf("\n%d \t %d \t %d \t %d \t %d", i+1, vecA[i], vecB[i], vecC[i], vecD[i]);
    }  
}

void mostrarElementosParesVector(int vec[], int tam) 
{
    printf("\nElementos pares del vector A: ");
    for (int i = 0; i < tam; i++)
    {
        if(vec[i] % 2==0)
        {
            printf("\nValor de la posicion %d: %d", i+1, vec[i]);
        }
    }  
}

void mostrarPosicionesImparesVector(int vec[], int tam) 
{
    printf("\nElementos en posiciones impares del vector A: ");
    for (int i = 0; i < tam; i++)
    {
        if((i + 1) % 2 != 0)
            printf("\nValor de la posicion %d: %d", i+1, vec[i]);
    }  
}

int sumarElementosVector(int vec[],int tam) 
{
    int sumaElementos = 0;
    for (int i = 0; i < tam; i++)
    {
       sumaElementos = sumaElementos + vec[i]; 
    }  
    return sumaElementos;
}

float promedioElementosVector(int vec[],int tam) 
{
    int sumaElementos = 0;
    for (int i = 0; i < tam; i++)
    {
       sumaElementos = sumaElementos + vec[i]; 
    }
    return (float)sumaElementos / tam;  
}

void mostrarElementosIgualesA32(int vec[], int tam) 
{
    printf("\nElementos iguales a 32 del vector A: ");
    for (int i = 0; i < tam; i++)
    {
        if(vec[i] == 32)
            printf("\nValor de la posicion %d: %d", i+1, vec[i]);
    }  
}

int mayorValorVector(int vec[], int tam) 
{
    // Devuelve el numero mayor
    int mayor = vec[0];
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > mayor)
            mayor = vec[i]; 
    }
    return mayor;

    // Alternativa, devuelve la posision del numero
    /* int posMax = 0;
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > vec[posMax])
        {
            posMax = i;
        }
    }
    return posMax;*/
}