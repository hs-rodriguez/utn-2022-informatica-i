#include <stdio.h>

int main(void) {
    int *ptr;
    int a;

    ptr = &a;
    *ptr = 56;

    printf("\nTam del ptr: %d bytes", sizeof(ptr));
    printf("\nDireccion de a: %p", ptr);
    printf("\nValor de a: %d", a);
    printf("\nValor de lo apuntado por ptr: %d", *ptr);

    return 0;
}