/**
 * Ejercicio 6:
 * Realizar un programa que solicite un número por teclado y el mismo sea 
 * visualizado en un display de 7 segmentos conectado al puerto paralelo. 
 * Permitir ingresar varios números hasta que ponga un número fuera del rango 
 * representable por el display.
 */

#include <stdio.h>
#include "sim/sim7segWin.c"

int main(void)
{
    int band = 0, num;
    unsigned char NUMEROS [] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};
    ioperm(PUERTO_BASE, 1, 1);
    while (!band) {
        printf("Ingrese el numero que desea visualizar: ");
        scanf("%d", &num);
        if (num >= 0 && num <= 9)
            outb(NUMEROS[num], PUERTO_BASE);
        else
            band++;
    }
    
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}