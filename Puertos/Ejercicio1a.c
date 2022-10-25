/**
 * Ejercicio 1:
 * Ingresar por teclado números del 0 al 7. 
 * Según el número ingresado se debe encender dicho led mediante el puerto paralelo. 
 * Finalizar al ingresar un número inválido.
 * a. Resolver utilizando la sentencia switch
 * b. Resolver utilizando desplazamiento de bits.
 */

#include <stdio.h>
#include "sim/simledsWin.c"

int main(void)
{
    int led, band = 0;
    ioperm(PUERTO_BASE, 1, 1);
    while (!band) {
        printf("Ingrese el led a encender (0-7): ");
        scanf("%d", &led);
        switch(led) {
            case 0: outb(1, PUERTO_BASE); break;
            case 1: outb(2, PUERTO_BASE); break;
            case 2: outb(4, PUERTO_BASE); break;
            case 3: outb(8, PUERTO_BASE); break;
            case 4: outb(16, PUERTO_BASE); break;
            case 5: outb(32, PUERTO_BASE); break;
            case 6: outb(64, PUERTO_BASE); break;
            case 7: outb(128, PUERTO_BASE); break;
            default: band++;
        }
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}