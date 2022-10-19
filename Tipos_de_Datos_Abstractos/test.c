#include <stdio.h>

union uni
{
   int entero;
   char caracter[4];
};

int main (void)
{
    union uni ejemplo;
    int i;
    ejemplo.entero = 257;
    printf("El valor del entero es: %d\n", ejemplo.entero);
    for (i = 0; i < 4; i++)
    {
        printf("Byte %d: %d\n", i, ejemplo.caracter[i]);
    }
    
    return 0;
}
