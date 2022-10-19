#include <stdio.h>

#define cuadrado(x) (x)*(x)

int main(void) {
    int a, cuad;
    printf("\nIngrese un numero: ");
    scanf("%d", &a);
    cuad = cuadrado(a+1);
    printf("\nEl cuadrado de %d es %d", a, cuad);
}