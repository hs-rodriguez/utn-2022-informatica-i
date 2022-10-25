/**
 * Ejercicio 7:
 * Realizar un programa que comenzando de 0 al tocar una tecla incremente 
 * automaticamente uno a uno el número mostrado por un display de 7 segmentos 
 * conectado al puerto paralelo. Al llegar al nueve debe volver a comenzar la secuencia.
 */

#include <stdio.h>
#include <conio.h>
#include "sim/sim7segWin.c"

#define ESC 27

int main(void)
{
    int num = 0, tecla = 0;
    unsigned char NUMEROS [] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
    ioperm(PUERTO_BASE, 1, 1);
    while (tecla != ESC) {
        if (num == 10)
            num = 0;
        outb(NUMEROS[num], PUERTO_BASE);
        tecla = getch();
        num++;
    }
    
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}