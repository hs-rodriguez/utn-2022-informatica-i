/**
 * Ejercicio 4:
 * Determinar la paridad de un numero entero corto sin signo.
 */

#include <stdio.h>

int main(void) {
    unsigned short int n, paridad = 0;
    printf("Ingrese el numero: ");
    scanf("%hu", &n);

    for (; n; n /=2)
        paridad ^= (n % 2);

    if (paridad)
        printf("El numero tiene una cantidad impar de unos y ceros.");
    else
        printf("El numero tiene una cantidad par de unos y ceros.");

    return 0;
}
