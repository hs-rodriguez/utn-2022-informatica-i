#include <stdio.h>

#define N 3

main()
{
    int vec[N], *p, i;
    p = vec;
    for (i = 0; i < N; i++){
        printf("Ingrese un entero: ");
        scanf("%d", p+i);
    }
    printf("\nDatos ingresados:\n");
    for (i = 0; i < N; i++){
        printf("%d\n", *(p+i));
    }
}