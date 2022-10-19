/**
 *  Ejercicio 5:
 *  Ingresar un numero entero (short) e imprimirlo en binario.
 *  (Usar el operador de desplazamiento)
 */

#include <stdio.h>

int main(int argc, char **argv) {
    short n, i;

    if (argc > 1) {
        sscanf(argv[1], "%hd", &n);
    }
    else {
        printf("Ingrese un numero: ");
        scanf("%hd", &n);
    }

    for (i = 0; i < 16; i++) {
        if (n & 0x8000)
            printf("1");
        else
            printf("0");
        n <<= 1;
    }

    return 0;
}
