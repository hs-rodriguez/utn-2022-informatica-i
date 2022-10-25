/**
 * Ejercicio 3:
 * Encender leds uno por medio y alternar usando xor. (simil árbol de navidad). 
 * Repetir el proceso 50 veces.
 */

#include "sim/simledsWin.c"
#include <unistd.h>

#define DELAY 300000 // 300000 us = 300 ms

int main(void)
{
    int i, j;
    ioperm(PUERTO_BASE, 1, 1);
    for (i = 0; i < 50; i++) {
        for (j = 0; j <= 7; j+=2) {
            // Si i es impar hacer xor con 1, si es par con 0
            outb(1 << (j ^(i & 1)), PUERTO_BASE);
            usleep(DELAY);
        }
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}