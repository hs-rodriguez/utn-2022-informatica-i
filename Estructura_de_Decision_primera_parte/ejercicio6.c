/*
    Ejercicio 6:
    Ingresar el valor de la hora y las horas trabajadas. Calcular su sueldo si 
    se sabe que recibe un premio de $6500 si trabajo más de 50 horas 
    y si trabajo más de 150 horas $10000 adicionales.
*/

#include <stdio.h>

int main (void)
{
    int horas;
    float valorHora, sueldo;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas);
    printf("Ingrese el valor de la hora: ");
    scanf("%f", &valorHora);

    sueldo = horas * valorHora;

    if (horas > 50)
        sueldo += 6500;
    if (horas > 150)
        sueldo += 10000;

    printf("El sueldo es $%.2f", sueldo);

    return 0;
}