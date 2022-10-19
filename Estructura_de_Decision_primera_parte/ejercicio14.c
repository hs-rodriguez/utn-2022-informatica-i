/*
    Ejercicio 14:
    Determinar la edad de una persona ingresando la fecha actual 
    (dia - mes - año) y la fecha de nacimiento (dia - mes - año)
*/

#include <stdio.h>

int main (void)
{
    int diaA, mesA, anioA, diaN, mesN, anioN, edad;

    printf("Ingrese la fecha actual (dd-mm-aaaa): ");
    scanf("%d-%d-%d", &diaA, &mesA, &anioA);
    printf("Ingrese la fecha de nacimiento (dd-mm-aaaa): ");
    scanf("%d-%d-%d", &diaN, &mesN, &anioN);

    if(mesA > mesN)
        edad = anioA - anioN;
    else
        if (mesA < mesN)
            edad = anioA - anioN - 1;
        else
            if (diaA >= diaN)
                edad = anioA - anioN;
            else
                edad = anioA - anioN - 1;
    
    printf("La edad es %d", edad);

    return 0;
}