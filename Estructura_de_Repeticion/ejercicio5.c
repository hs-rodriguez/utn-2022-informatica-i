/*
    Ejercicio 5:
    Se ingresan 10 letras. Determinar la cantidad de vocales ingresadas
*/

#include <stdio.h>
#include <ctype.h>

int main (void) 
{
    char ing;
    int cont = 0;

    for (int i = 1; i <= 10; i++)
    {
        printf("Ingrese una letra (%d/10): ", i);
        scanf(" %c", &ing);

        ing = tolower(ing);

        if (ing == 'a' || ing == 'e' || ing == 'i' || ing == 'o' || ing == 'u')
        {
            cont++;
        }
    }

    printf("Vocales ingresadas: %d", cont);

    return 0;
}