/**
 * Ejercicio 3:
 * Realizar una función que simule la función strcat (concatena el segundo string 
 * a continuación del primero) El ingreso de las cadenas( máximo 40 y 20 carateres 
 * respectivamente ) y el informe de la cadena resultante en el programa principal.
 */

#include <stdio.h>

void stringConcat(char *, char *);

int main(void)
{
    char string1[41], string2[21];
    printf("\nIngrese la primera cadena: ");
    gets(string1);
    printf("\nIngrese la segunda cadena: ");
    gets(string2);

    printf("\nCadena 1: %s\nCadena 2: %s", string1, string2);
    stringConcat(string1, string2);
    printf("\nCadena resultante: %s", string1);

    return 0;
}

void stringConcat (char *str1, char *str2)
{
    int i = 0, j = 0;
    while (*(str1+i) != '\0') {
        i++;
    }
    while (*(str2+j) != '\0') {
        *(str1+i) = *(str2+j);
        i++;
        j++;
    }
    *(str1+i) = '\0';
}