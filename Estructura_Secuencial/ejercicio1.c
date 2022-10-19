/*  
    Ejercicio 1:
    Se ingresan la cantidad de horas trabajadas y el valor por hora 
    de un empleado. Determinar el sueldo. 
*/

#include <stdio.h>

int main(void)
{
    int horas;
    float valorHora, sueldo;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas);
    printf("Ingrese el valor por hora: ");
    scanf("%f", &valorHora);

    sueldo = horas * valorHora;

    printf("El sueldo es: %.2f", sueldo);

    return 0;
}
