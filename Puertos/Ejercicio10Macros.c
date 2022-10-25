/**
 * Ejercicio 10:
    Se desea realizar un sistema que permita registrar la cantidad de personas que utilizan el 
    subte en una estación. La misma cuenta con 8 molinetes numerados del 0 al 7.
    Cada vez que una persona pasa por uno de los molinetes se recibe un dato por el puerto 0x400 con el
    siguiente formato:
    F _ _ _ M M M S
    Donde el bit menos significativo es el bit de sincronismo. Luego hay tres bits que indican el número de
    molinete por el cual ha pasado la persona. El bit más significativo se utiliza para detectar el fin de datos.
    Consideraciones:
    • El dato se considera válido cuando el bit de sincronismo pasa de 0 a 1
    • El proceso termina cuando el bit más significativo se pone en 1
    Al finalizar el proceso mostrar un listado con la cantidad de personas que pasaron por cada uno de los
    molinetes.
 */

#include <stdio.h>
#include "sim/sim10.c"

#define N 8
#define PORT 0x400

#define LEER(T) T = inb(PORT)
#define LISTAR(T) \
int I;\
for (I = 0; I < N; I++)\
    printf("\nPersonas que pasaron por el molinete %d: %d", I, T[I])
                  

struct Bits {
    unsigned char s:1;
    unsigned char cod:3;
    unsigned char:3;
    unsigned char f:1;
};

union Uni {
    struct Bits Bit;
    unsigned char Byte;
};

int main(void) {
    int molinetes[N] = {0};
    union Uni U;

    ioperm(PORT, 1, 1);

    do {
        LEER(U.Byte);
    } while (U.Bit.s == 0);

    while (U.Bit.f == 0)
    {
        molinetes[U.Bit.cod]++;

        do {
            LEER(U.Byte);
        } while (U.Bit.s == 1);

        do {
            LEER(U.Byte);
        } while (U.Bit.s == 0);
    }

    ioperm(PORT, 1, 0);

    LISTAR(molinetes);

    return 0;   
}