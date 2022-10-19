/*
    Ejercicio 9:
    Confeccionar un programa que :
    a) Solicite el ingreso de un valor entero N, <= 12 y luego una lista de N números reales.
    b) Calcule e informe : 1) el promedio de los positivos
    2) el promedio de los negativos
    3) la cantidad de ceros.
    c) Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO ' y FINALIZAR
*/

#include <stdio.h>

int main (void)
{
    int n, positivos = 0, negativos = 0, ceros = 0;
    float real, promedioPositivos = 0, promedioNegativos = 0;

    printf("Ingrese el valor de N (mayor o igual a 12): ");
    scanf("%d", &n);

    if (n > 12)
        printf("Valor excedido.");
    else {
        for (int i = 1; i <= n; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%f", &real);

            if (real > 0)
            {
                promedioPositivos += real;
                positivos++;
            }
            else if (real < 0)
            {
                promedioNegativos += real;
                negativos++;
            }
            else
                ceros++;
        }

        if (positivos != 0)
            promedioPositivos /= positivos;
        if (negativos != 0)
            promedioNegativos /= negativos;

        printf("\nPromedio de positivos: %.2f", promedioPositivos);
        printf("\nPromedio de negativos: %.2f", promedioNegativos);
        printf("\nCantidad de ceros: %d", ceros);
    }

    return 0;
}