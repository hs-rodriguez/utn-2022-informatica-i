/*
    Ejercicio 2:
    Realizar un programa que se ingresan juegos de 3 valores.
    Cada uno de estos 3 valores, son: el primero es un código de 1 a 9 y los dos siguientes son valores
    numéricos( el primero entero y el segundo real ).
    Para cada juego de valores calcular e informar:
    --si el código es valor impar el producto entre los valores
    --si el código es valor par la suma entre los valores.
    El fin de datos ocurre cuando el código es cero.
    Implementar las siguientes funciones:
    a-) LeerControl -> Función que ingresa y controla el ingreso del código
    b-) ImparPar -> Función que retorna ‘P’ si el número es par y ‘I’ si es impar.
    c-) Producto -> Función que calcula el producto
    d-) Suma -> Función que calcula la suma
*/

#include <stdio.h>
int LeeControl(int, int);
char ImparPar(int);
float Producto(int,float);
float Suma (int,float);

int main (void)
{
    int codigo, entero;
    float real;

    codigo = LeeControl(0, 9);
    
    while (codigo != 0)
    {
        printf("\nIngrese un numero entero y uno real: ");
        scanf("%d %f", &entero, &real);
        if(ImparPar(codigo) == 'I')
        {
            printf("El producto es: %.2f", Producto(entero, real));
        }
        else
        {
            printf("La suma es: %.2f", Suma(entero, real));
        }

        codigo = LeeControl(0, 9);
    }
    

    return 0;
}

int LeeControl (int LI, int LS)
{
  int nro;
  do{
  	  printf("\n Ingrese un numero entero positivo (entre 0 y 9)\n");
	  scanf ("%d", &nro);
    }while ( nro < LI  || nro > LS );

  return nro;
}

float Producto (int entero, float real)
{
    float producto;
    producto = entero * real;
    return producto;
}

char ImparPar (int nro)
{
    if(nro%2==0)
    return 'P';
    else
    return 'I';
}

float Suma (int entero, float real)
{
    return entero + real;
}
