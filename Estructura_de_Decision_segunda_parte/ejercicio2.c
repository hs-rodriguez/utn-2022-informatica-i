/* 
    Ejercicio 2: 
    Se ingresan 2 nros reales (N1 y N2) y una opción de cálculo.
    Según opción: 1- SUMA (N1 + N2)
    2- RESTA (N1-N2)
    3- PRODUCTO (N1*N2)
    4- DIVISION (N1/N2) verificar si es posible sino indicar un mensaje.
*/

#include <stdio.h>

int main (void)
{
    float n1, n2, resultado;
    int opcion, band = 0;
    printf("Ingrese dos numeros: ");
    scanf("%f%f", &n1, &n2);

    printf("\n1. Suma (N1 + N2)\n2. Resta (N1 - N2)\n3. Producto (N1 * N2)\n4. Cociente (N1 / N2)");
    printf("\nIngrese la operacion que desea realizar: ");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        resultado = n1 + n2;
        break;
    case 2:
        resultado = n1 - n2;
        break;
    case 3:
        resultado = n1 * n2;
        break;
    case 4:
        if (n2 != 0)
            resultado = n1 / n2;
        else
        {
            band++;
            printf("\nNo esta definida la division por 0.");
        }
        break;
    default:
        band++;
        printf("\nLa operacion ingresada no es valida.");
        break;
    }

    if (band == 0)
        printf("\nEl resultado es: %.2f", resultado);

    return 0;
}