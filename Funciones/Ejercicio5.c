/*
    Ejercicio 5:
    Confeccionar un programa que permita el ingreso de ternas de valores enteros y positivos.
    Se finaliza el ingreso con los 3 o 2 valores iguales
    Se pide para cada terna:
    a) determinar e informar el menor valor de cada terna. Confeccionar y usar la función MINIMO que
    retorne el mínimo valor de la terna
    b) determinar e informar los valores pares de cada terna. Confeccionar y usar la función PAR que
    retorne 1 si el número es par y 0 si no lo es.
    c) determinar e informar el factorial del menor valor de cada terna. Confeccionar y usar la función
    FACTORIAL
    d) determinar e informar el promedio de las ternas ingresadas de orden impar. Usar función
    PROMEDIO.
    TODOS LOS INFORME EN EL PROGRAMA PRINCIPAL.
*/

#include <stdio.h>

int LeeControl(int);
int Minimo (int, int, int);
int Par (int);
int Factorial (int);
float promedio(int, int, int);

int main (void)
{
    int n1, n2, n3, menor, cont = 0;

    printf("Ingrese un valor entero positivo: ");
    n1 = LeeControl(1);
    printf("Ingrese un valor entero positivo: ");
    n2 = LeeControl(1);
    printf("Ingrese un valor entero positivo: ");
    n3 = LeeControl(1);

    while (n1 != n2 && n1 != n3 && n2 != n3)
    {
        cont++;
        menor = Minimo(n1, n2, n3);
        printf("\nEl menor valor es: %d", menor);
        printf("\nLos numeros pares son: ");
        if (Par(n1))
            printf("%d ", n1);
        if (Par(n2))
            printf("%d ", n2);
        if (Par(n3))
            printf("%d ", n3);
        printf("\nEl factorial de %d es: %d", menor, Factorial(menor));
        if (cont % 2 != 0)
            printf("\nEl promedio de la terna es: %.2f\n\n", promedio(n1, n2, n3));
        
        printf("Ingrese un valor entero positivo: ");
        n1 = LeeControl(1);
        printf("Ingrese un valor entero positivo: ");
        n2 = LeeControl(1);
        printf("Ingrese un valor entero positivo: ");
        n3 = LeeControl(1);
    }
    

    return 0;
}


int LeeControl(int limiteInferior)
{
    int dato, band = 0;
    int error;

    do
    {
        if(!band) //Si band es igual a 0, cambiar el valor
            band++;
        else
            printf("Ingrese nuevamente: ");
        
        error = scanf("%d", &dato);
        fflush(stdin);
    } while (error != 1 || dato < limiteInferior);

    return dato;
}

int Minimo (int n1, int n2, int n3)
{
    if (n1 < n2 && n1 < n3)
    {
        return n1;
    }
    else if (n2 < n3)
    {
        return n2;
    }
    else
        return n3;
}

int Par (int n)
{
    if (n % 2 == 0)
        return 1;
    else
        return 0;  
}

int Factorial (int n)
{
    if (n <= 1)
        return 1;
    else
        return n * Factorial(n - 1);
}

float promedio (int n1, int n2, int n3)
{
    return (float)(n1 + n2 + n3) / 3;
}