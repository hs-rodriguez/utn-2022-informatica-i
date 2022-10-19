/**
 * Ejercicio 2:
 * Ingresar un char y asignar en los 3 bits más significativos unos
 */

 #include <stdio.h>

 int main(void)
 {
    unsigned char A;
    printf("\nIngrese un numero: ");
    scanf("%d", &A);
    printf("\nNumero original: %x(%d)", A, A);
    printf("\nNumero modificado: %x(%d)", A|0xE0, A|0xE0);
    return 0;
 }