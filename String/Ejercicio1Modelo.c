/*
    Ejercicio 1:
    En una fábrica se producen 10 productos distintos. Por cada producto 
    se cuenta con un código de parte que consiste en un numero de 5 cifras, 
    un nombre de producto que puede tener hasta 8 letras y un costo de
    producción por unidad.
    Cada venta que se realiza, la fábrica carga el código de parte, la cantidad vendida 
    y el precio unitario del producto.
    La carga de venta se termina al ingresar un producto con código 0.
    Se pide:
    - Cargar la base de datos inicial de los 10 productos.
    - Permitir el ingreso de ventas con las características mencionadas arriba.
    - Si el precio de venta unitario de un producto es menor a su costo imprimir 
    un cartel con la siguiente consigna ”Venta del producto xxx por debajo del costo” 
    donde xxx es el nombre del mismo.
    - Al finalizar la carga determinar:
    - Un listado ordenado alfabéticamente informando las cantidades vendidas de cada 
    producto y su contribución neta a la fábrica (precio de venta – costo de producción)
    - Listar, de existir, los códigos que fueron vendidos en alguna oportunidad por debajo 
    del costo.
    - Informar el código y nombre que más se vendió en cantidad y la que produjo menos ingreso.
*/

#include<stdio.h>
#include<string.h>
#define NOMBREMAXPROD 8
#define CANTPRODUCTOS 4

// Modificaciones para que me funcione en Linux
#ifdef __unix__
#include <strings.h>
#define strcmpi strcasecmp
#define fflush(stdin) getchar()
#endif

int LeeControlRango(int limiteInferior, int limiteSuperior);
int BusquedaSecuencial(int vec[], int dato, int tam);
void CargarBaseDeDatos(int [], float [], char [][NOMBREMAXPROD], int );
void Ventas(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam);
void Ordenamiento(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam);
void Mostrar(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam);
void ProductosDebajoDelCosto(int listaCodigo[], int cantVendida[], float listaCosto[], float precioUnitario[], int tam);
void MayorMenor(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam);

main()
{
    int cantVendida[CANTPRODUCTOS]={0};
    float precioUnitario[CANTPRODUCTOS]; //un precio por c/prod
    int listaCodigo[CANTPRODUCTOS];
    char listaProd[CANTPRODUCTOS][NOMBREMAXPROD]; //matriz de caracteres (vector de string)
    float listaCosto[CANTPRODUCTOS];
    CargarBaseDeDatos(listaCodigo, listaCosto, listaProd, CANTPRODUCTOS);
    Ventas(listaCodigo, listaCosto, listaProd, cantVendida, precioUnitario, CANTPRODUCTOS);
    Ordenamiento(listaCodigo, listaCosto, listaProd, cantVendida, precioUnitario, CANTPRODUCTOS);
    Mostrar(listaCodigo, listaCosto, listaProd, cantVendida, precioUnitario, CANTPRODUCTOS);
    ProductosDebajoDelCosto(listaCodigo, cantVendida, listaCosto, precioUnitario, CANTPRODUCTOS);
    MayorMenor(listaCodigo, listaCosto, listaProd, cantVendida, precioUnitario, CANTPRODUCTOS);
}

int LeeControlRango(int limiteInferior, int limiteSuperior)
{
    int dato, band = 0;
    do
    {
        if(!band)
            band++;
        else
            printf("Ingrese nuevamente: ");
        scanf("%d", &dato);
    } while (dato < limiteInferior || dato > limiteSuperior);
    return dato;
}

int BusquedaSecuencial(int vec[], int dato, int tam)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < tam)
    {
        if (vec[i] == dato)
            pos = i;
        else
            i++;
    }
    return pos;
}

void CargarBaseDeDatos(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int tam)
{
    int i, pos, codigo;
    for ( i = 0; i < tam; i++)
    {
        do{
            printf("\nIngrese el codigo de parte: ");
            codigo = LeeControlRango(10000, 99999);
            fflush(stdin);
            pos = BusquedaSecuencial(listaCodigo,codigo,i);
        } while(pos !=-1);
        listaCodigo[i]=codigo;

        printf("\nIngrese el nombre del producto: ");
        scanf("%s", listaProd[i]);
        do{
            printf("\nIngrese el costo del producto: ");
            scanf("%f", &listaCosto[i]); 
        }while (listaCosto[i] <= 0);
    }
}

void Ventas(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam)
{
    int pos, codigo;
    printf("\nIngrese el codigo de la venta: ");
    scanf("%d", &codigo);
    while (codigo != 0)
    {
        pos = BusquedaSecuencial(listaCodigo,codigo,tam);
        if (pos != -1 && cantVendida[pos] == 0)
        {
            printf("\nIngrese la cantidad vendida: ");
            scanf("%d", &cantVendida[pos]);
            printf("\nIngrese el precio: ");
            scanf("%f", &precioUnitario[pos]);

            if(precioUnitario[pos] < listaCosto[pos])
                printf("\nVenta del producto %s por debajo del costo", listaProd[pos]);
        } 
        else
            printf("\nEl producto no existe o ya se vendio.");
    
        printf("\nIngrese el codigo de la venta: ");
        scanf("%d", &codigo);
    }
    
}

void Ordenamiento(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam)
{
    int i, j, auxInt;
    float auxFloat;
    char auxChar[NOMBREMAXPROD];
    for (i = 0; i < tam-1; i++)
        for(j = 0; j < tam -1 -i; j++)
            if(strcmpi(listaProd[j], listaProd[j+1]) > 0)
            {
                strcpy(auxChar, listaProd[j]);
                strcpy(listaProd[j], listaProd[j+1]);
                strcpy(listaProd[j+1], auxChar);
                
                auxInt = listaCodigo[j];
                listaCodigo[j] = listaCodigo[j+1];
                listaCodigo[j+1] = auxInt; 

                auxInt = cantVendida[j];
                cantVendida[j] = cantVendida[j+1];
                cantVendida[j+1] = auxInt; 

                auxFloat = listaCosto[j];
                listaCosto[j] = listaCosto[j+1];
                listaCosto[j+1] = auxFloat; 

                auxFloat = precioUnitario[j];
                precioUnitario[j] = precioUnitario[j+1];
                precioUnitario[j+1] = auxFloat;
            }
}

void Mostrar(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam)
{
    int i;
    printf("\nCodigo\t  Nombre\tCantidad vendida\tContribucion");
    for (i = 0; i < tam; i++)
    {
        printf("\n%6d\t%8s\t%16d\t%12.2f", listaCodigo[i], listaProd[i], cantVendida[i], precioUnitario[i]*cantVendida[i]-listaCosto[i]*cantVendida[i]);
    }
    
}

void ProductosDebajoDelCosto(int listaCodigo[], int cantVendida[], float listaCosto[], float precioUnitario[], int tam)
{
    int i;
    printf("\nLos codigos vendidos por debajo del costo: ");
    for (i = 0; i < tam; i++)
        if(precioUnitario[i] < listaCosto[i] && cantVendida[i] > 0)
            printf("%d ", listaCodigo[i]);
}

void MayorMenor(int listaCodigo[], float listaCosto[], char listaProd[][NOMBREMAXPROD], int cantVendida[], float precioUnitario[], int tam)
{
    int i, cantMayor = cantVendida[0]; // Mayor multiple
    float ingreso, menorIngreso = precioUnitario[0]*cantVendida[0] - listaCosto[0]*cantVendida[0];
    for (i = 1; i < tam; i++)
    {
        if (cantVendida[i] > cantMayor)
            cantMayor = cantVendida[i];

        ingreso = precioUnitario[i]*cantVendida[i] - listaCosto[i]*cantVendida[i];
        if (ingreso < menorIngreso)
            menorIngreso = ingreso;
    }

    printf("\nProducto(s) que mas cantidad vendio: ");
    for (i = 0; i < tam; i++)
        if (cantVendida[i] == cantMayor)
            printf("%d %s (%d)", listaCodigo[i], listaProd[i], cantVendida[i]);
    
    printf("\nProducto(s) de menor ingreso: ");
    for (i = 0; i < tam; i++)
    {
        ingreso = precioUnitario[i]*cantVendida[i] - listaCosto[i]*cantVendida[i];
        if (ingreso == menorIngreso)
            printf("%d %s ($%.2f)", listaCodigo[i], listaProd[i], ingreso);
    }
}
