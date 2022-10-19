/*
    Ejercicio 3:
    Se ingresan 3 nros. distintos. Determinar el mayor.
*/

#include <stdio.h>

int main(void)
{
    float n1, n2, n3, mayor;
    printf ("Ingrese tres numeros: ");
    scanf("%f %f %f", &n1, &n2, &n3);

    //Resolucion alternativa con operador ternario
    mayor = n1 >= n2 ? (n1 >= n3 ? n1 : n3) : (n2 >= n3 ? n2 : n3); 

    printf("El numero mayor es: %.2f", mayor);

    return 0;
}