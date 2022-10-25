/**
 * Ejercicio 11:
 * Se toman los datos provenientes de una placa de adquisición de datos. 
 * Esta placa detecta partículas emitidas codificadas de 0 a 15 e informa su 
 * nivel relativo de radiación. 
 * La información se entrega a la PC a través de los ports 300H y 301H de la manera que 
 * indica el dibujo.
 * 
 * Codigo  Nivel de radiacion
 * _______ ___________________  S F 
 * _|_|_|_|_|_|_|_  _|_|_|_|_|_|_|_
 * 
 * El bit F valdrá 0 durante todo el experimento y se pondrá en 1 indicando su finalización.
 * El bit S estará en 1 cada vez que se tiene un dato válido y pasará a 0 entre cada dato.
 * Imprimir el reporte de los promedios de radiación por partícula, ORDENADO EN FORMA 
 * DESCENDENTE POR PROMEDIO DE RADIACION sabiendo que en ningún momento los niveles 
 * de radiación acumulados superarán la capacidad de un entero.
 * 
 * IMPLEMENTAR Macros para:
 * LECTURA DE PUERTO
 * PROMEDIO
 * ORDEN
 * INFORME
 */

#include <stdio.h>
#include "sim/sim11.c"

#define N 16
#define PORT0 0x300
#define PORT1 0x301

#define LEER(T) \
T[0] = inb(PORT0);\
T[1] = inb(PORT1)

#define PROMEDIO(T, S) \
for (i = 0; i < S; i++)\
        if (T[i].cantidad != 0)\
            T[i].promedio = (float) T[i].radiacion / T[i].cantidad

// cuidado con los nombres cuando se crean variables en las macros
#define ORDENAMIENTO(T, S) \
struct Particula ___aux;\
int ___i, ___j;\
for (___i = 0; ___i < S-1; ___i++)\
    for (___j = 0; ___j < S-1-___i; ___j++)\
        if (T[___j].promedio < T[___j+1].promedio) {\
            ___aux = T[___j];\
            T[___j] = T[___j+1];\
            T[___j+1] = ___aux;\
        }

#define INFORME(T, S) \
printf("\nPromedios de radiacion:");\
    for (i = 0; i < S; i++)\
        if (T[i].cantidad != 0)\
            printf("\nParticula %d: %.2f", T[i].codigo, T[i].promedio)

struct Bits {
    unsigned short f: 1;
    unsigned short s: 1;
    unsigned short rad: 10;
    unsigned short cod: 4;
};

union Uni{
    struct Bits Bit;
    unsigned char Byte[2];
};

struct Particula{
    int radiacion;
    int codigo;
    int cantidad;
    float promedio;
};

int main(void)
{
    struct Particula particulas[N];
    int i;
    union Uni U; 
 
    ioperm(PORT0, 2, 1);
    for (i = 0; i < N; i++) {
        particulas[i].radiacion = 0;
        particulas[i].codigo = i;
        particulas[i].cantidad = 0;
        particulas[i].promedio = 0;
    }

    do {
        LEER(U.Byte);
    } while (U.Bit.s == 0);

    while (U.Bit.f == 0) {
        particulas[U.Bit.cod].radiacion += U.Bit.rad;
        particulas[U.Bit.cod].cantidad++;

        do {
            LEER(U.Byte);           // flancos
        } while (U.Bit.s == 1);
        do {
            LEER(U.Byte);
        } while (U.Bit.s == 0);
    }
    ioperm(PORT0, 2, 0);

    PROMEDIO(particulas, N);
    ORDENAMIENTO(particulas, N);
    INFORME(particulas, N);

    return 0;
}

/*
70 1e
0111 0000   0001 1110 -> Particula 7, radiacion 7

83 c2
1000 0011   1100 0010 -> Particula 8, radiacion 240

70 e
0111 0000   0000 1110 -> Particula 7, radiacion 3
*/