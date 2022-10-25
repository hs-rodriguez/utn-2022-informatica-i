/**
 * Ejercicio 8:
 * Realizar un programa que muestre una cuenta regresiva en un display de 7 segmentos 
 * conectado al puerto paralelo comenzando de 9 hasta llegar al 0. Dejar un segundo de 
 * retardo entre número y número al finalizar apagar el display luego de que titile el 
 * número 0 cinco veces.
 */

#include <stdio.h>
#include <unistd.h>
#include "sim/sim7segWin.c"

#define DELAY 1 // 1 s

int main(void)
{
    int i;
    unsigned char NUMEROS [] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
    ioperm(PUERTO_BASE, 1, 1);

    for (i = 9; i >= 0; i--) {
        outb(NUMEROS[i], PUERTO_BASE);
        sleep(DELAY);
    }
    for (i = 0; i < 5; i++) {
        outb(NUMEROS[0], PUERTO_BASE);
        sleep(DELAY);
    }
    outb(0, PUERTO_BASE);
    
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}