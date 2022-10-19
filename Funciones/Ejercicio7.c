/*
    Ejercicio 7:
    Realizar un programa que al ingresar solicite el ingreso de dos números enteros y luego muestre por
    pantalla el siguiente menú (las xx de los números deben ser reemplazadas con los valores
    correspondientes):
    Menú de Opciones ---- -- -------- Numero 1: xx Numero 2: xx
    1) Sumar
    2) Restar
    3) Multiplicar
    4) Dividir
    5) Ingresar Nuevos Números
    6) Salir Ingrese su opción:
    Al ingresar el número de la opción del 1 al 4, se realiza la operación (mediante una función
    correspondiente a cada opción) y muestra el resultado hasta que se presione una tecla. Luego
    vuelve a mostrar el menú para poder realizar otra operación con los mismos números.
    La opción 5 pide el ingreso de dos nuevos números de trabajo mientras que la opción 6 sale y cierra
    el programa.
    El ingreso de la opción debe estar validado y en caso de ingresarse un número no válido debe
    solicitarlo nuevamente. Funcion LeeControl.
*/

#include <stdio.h>
#include <conio.h>

int LeeControl (int, int);
int Suma (int, int);
int Resta (int, int);
int Producto (int, int);
float Cociente (int, int);

int main (void)
{
    int n1, n2, opcion;

    printf("Ingrese dos numeros enteros: ");
    scanf("%d %d", &n1, &n2);

    while (opcion != 6)
    {
        printf("\n\nMenu de opciones\n---- -- --------\nNumero 1: %d Numero 2: %d\n1) Sumar\n2) Restar\n3) Multiplicar\n4) Dividir\n5) Ingresar nuevos numeros\n6) Salir\nIngrese su opcion: ", n1, n2);
        opcion = LeeControl(1, 6);

        switch (opcion)
        {
        case 1:
            printf("La suma es: %d", Suma(n1, n2));
            getch();
            break;
        case 2:
            printf("La resta es: %d", Resta(n1, n2));
            getch();
            break;
        case 3:
            printf("El producto es: %d", Producto(n1, n2));
            getch();
            break;
        case 4:
            if (n2 != 0)
                printf("El cociente es: %.2f", Cociente(n1, n2));
            else
                printf("No se puede dividir por cero.");
            getch();
            break;
        case 5:
            printf("Ingrese dos numeros enteros: ");
            scanf("%d %d", &n1, &n2);
        }
    }
    
    return 0;
}

int LeeControl(int limiteInferior, int limiteSuperior)
{
    int dato, band = 0;
    int error;

    do
    {
        if(!band) //Si band es igual a 0, cambiar el valor
            band++;
        else
            printf("Ingrese nuevamente: ");
        
        error = scanf("%d", &dato);
        fflush(stdin);
    } while (error != 1 || dato < limiteInferior || dato > limiteSuperior);

    return dato;
}

int Suma (int n1, int n2)
{
    return n1 + n2;
}

int Resta (int n1, int n2)
{
    return n1 - n2;
}

int Producto (int n1, int n2)
{
    return n1 * n2;
}

float Cociente (int n1, int n2)
{
    return (float)n1 / n2; // Casteo n1 a float para que la division sea exacta
}
