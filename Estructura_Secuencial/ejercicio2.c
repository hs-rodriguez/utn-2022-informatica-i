/*  
    Ejercicio 2:
    Se ingresan la cantidad de horas trabajadas de un empleado y sabiendo que el 
    valor por hora es de $300. Determinar su sueldo.
*/

#include <stdio.h>

int main(void)
{
    //
    int horas;
    float sueldo;

    printf("Ingrese la cantidad de horas trabajadas: ");
    scanf("%d", &horas);

    sueldo = horas * 300;

    printf("El sueldo es: %.2f", sueldo);

    return 0;
}
