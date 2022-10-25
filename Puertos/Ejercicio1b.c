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
        if (led >= 0 && led <= 7)
            outb(1 << led, PUERTO_BASE);
        else
            band++;
    }
    ioperm(PUERTO_BASE, 1, 0);
    return 0;
}