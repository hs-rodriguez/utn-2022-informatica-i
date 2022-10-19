/*
    Ejercicio 10:
    Confeccionar un programa que permita ingresar un carácter alfanumérico
    y determinee informe si lo ingresado corresponde a una vocal,
    con el mensaje "VOCAL"
*/

#include <stdio.h>
#include <ctype.h>

int main (void)
{
    char c;
    printf("Ingrese un caracter alfanumerico: ");
    scanf("%c", &c);

    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("VOCAL");

    return 0;
}