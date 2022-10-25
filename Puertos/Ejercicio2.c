/**
 * Ejercicio 2:
 * Prender los leds en secuencia ida y vuelta 10 veces con una velocidad 
 * adecuada para que pueda visualizarse a simple vista. 
 * Usar desplazamiento de bits.
 */

#include "sim/simledsWin.c"
#include <unistd.h>

#define DELAY 100000 // 100000 us = 100 ms

int main(void)
{
    int i, j;
    ioperm(PUERTO_BASE, 1, 1);
    for (i = 1; i <= 10; i++) {
        for (j = 0; j < 7; j++) {
            outb(1 << j, PUERTO_BASE);
            usleep(DELAY);
        }
        for (j = 0; j < 7; j++) {
            outb(128 >> j, PUERTO_BASE);
            usleep(DELAY);
        }
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}