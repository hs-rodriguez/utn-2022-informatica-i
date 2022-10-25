/**
 * Ejercicio 4:
 * Encender los leds en secuencia en simultáneo desde los dos extremos hasta el centro. 
 * Por ejemplo al inicio encender los leds 0 y 7 luego sumar el 1 y 6 sin apagar el resto, 
 * así hasta encender todos los leds, luego ir apagando en sentido inverso. 
 * Repetir el proceso 10 veces.
 */

#include "sim/simledsWin.c"
#include <unistd.h>

#define DELAY 300000 // 300000 us = 300 ms

int main(void)
{
    int i, j, leds, maskHigh = 0x80, maskLow = 0x01;
    ioperm(PUERTO_BASE, 1, 1);
    for (i = 0; i < 10; i++) {
        leds = 0;
        for (j = 0; j <= 7; j++) {
            leds = (leds^(maskHigh>>j))^(maskLow<<j);
            outb(leds, PUERTO_BASE);
            usleep(DELAY);
        }
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}