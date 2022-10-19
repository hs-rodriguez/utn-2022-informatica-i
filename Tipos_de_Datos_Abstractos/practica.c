/**
 * En una carrera de autos participan N autos, se registra al terminar
 * Tiempo (en segundos)
 * Numero de auto
 * Marca (30 caracteres)
 * Determinar el numero de auto y la marca del ganador
 */

#include <stdio.h>
#include <string.h>

union Auto {
    int tiempo;
    int numeroAuto;
    char marca[31];
};

int main (void)
{
    union Auto lista;
    int tiempoGanador;
    int numeroGanador;
    char marcaGanador[31];
    int n, i, band;

    printf("\nIngrese el numero de coches a participar: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        band = 0;
        printf("\nIngrese el tiempo del coche: ");
        scanf("%d", &lista.tiempo);
        if (i == 0 || lista.tiempo < tiempoGanador) {
            band = 1;
            tiempoGanador = lista.tiempo;
        }
        printf("\nIngrese el numero de auto: ");
        scanf("%d", &lista.numeroAuto);
        if (band)
            numeroGanador = lista.numeroAuto;
        printf("\nIngrese la marca del auto: ");
        fflush(stdin);
        gets(lista.marca);
        if (band)
            strcpy(marcaGanador, lista.marca);
    }

    printf("\n\nResultados de la carrera: ");
    printf("\nEl ganador fue el %d, de marca %s", numeroGanador, marcaGanador);

    return 0;
}