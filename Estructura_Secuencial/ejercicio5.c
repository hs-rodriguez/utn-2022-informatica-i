/*
    Ejercicio 5:
    Se ingresa un numero entero positivo de 4 cifras. Calcular e informar 
    la suma de sus dígitos hasta llegar a una solo cifra.
    Ejemplo 2574 se informa 9
*/

#include <stdio.h>

int main(void)
{
    int numero, millar, centena, decena, unidad;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    // Se descompone el numero usando dividiendo para tomar los cocienctes y restos
    millar = numero / 1000;
    numero %= 1000;
    centena = numero / 100;
    numero %= 100;
    decena = numero / 10;
    unidad = numero % 10;
    // Luego, se toman las cifras y se suman
    numero = millar + centena + decena + unidad;

    //Al usar solo estructura secuencial, se debe volver a hacer el proceso
    decena = numero / 10;
    unidad = numero % 10;
    numero = decena + unidad;

    decena = numero / 10;
    unidad = numero % 10;
    numero = decena + unidad;

    printf("La suma de sus cifras es: %d", numero);

    return 0;
}