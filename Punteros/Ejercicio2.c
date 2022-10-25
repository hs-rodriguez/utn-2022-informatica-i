/**
 * Ejercicio 2:
 * Realizar una función que simule la función strlen (devuelve la cantidad de
 * caracteres validos de un string). El ingreso de la cadena (máximo 20 caracteres)
 * y el informe de la cantidad de caracteres en el programa principal.
 */

#include <stdio.h>

int stringLength(char *);

int main(void)
{
    int tam;
    char string[21] = "Esto es una cadena"; // 18
    tam = stringLength(string);
    printf("El string \"%s\" tiene %d caracteres.", string, tam);

    return 0;
}

int stringLength(char *str)
{
    int i = 0;
    while (*(str+i) != '\0'){
        i++;
    }
    return i;
}