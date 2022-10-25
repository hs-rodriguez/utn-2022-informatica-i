/**
 * Ejercicio 5:
 * Prender los leds en secuencia del 0 al 7 y al llegar al último volver a comenzar por el 0. 
 * Repetir el proceso 10 veces.
 */

#include "sim/simledsWin.c"
#include <unistd.h>

#define DELAY 300000 // 300000 us = 300 ms

int main(void)
{
    int i, j;
    ioperm(PUERTO_BASE, 1, 1);
    for (i = 0; i < 10; i++) {
        for (j = 0; j <= 7; j++) {
            outb((2<<j)-1, PUERTO_BASE);
            usleep(DELAY);
        }
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}