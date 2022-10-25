/**
 * Ejercicio 9:
 * Mostrar la palabra HOLA, enviando al display de a una letra por vez esperando 
 * medio segundo entre letra y letra.
 */

#include <stdio.h>
#include <unistd.h>
#include "sim/sim7segWin.c"

#define DELAY 500000 // 500000 us = 500 ms

int main(void)
{
    int i;
    unsigned char LETRAS [] = {0x76, 0x3f, 0x38, 0x77};
    ioperm(PUERTO_BASE, 1, 1);

    for (i = 0; i < 4; i++) {
        outb(LETRAS[i], PUERTO_BASE);
        usleep(DELAY);
    }
    
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}