/*
    Ejercicio 4:
    Se ingresa un numero entero de 3 cifras. Descomponerlo en 
    unidad, decena y centena.
*/

#include <stdio.h>

int main(void)
{
    int numero, centena, decena, unidad;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    // Se descompone el numero usando dividiendo para tomar los cocienctes y restos
    centena = numero / 100;
    numero %= 100;
    decena = numero / 10;
    unidad = numero % 10;

    printf("\nLa centena es: %d", centena);
    printf("\nLa decena es: %d", decena);
    printf("\nLa unidad es: %d", unidad);

    return 0;
}