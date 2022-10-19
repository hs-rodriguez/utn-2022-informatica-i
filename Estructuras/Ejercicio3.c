/*
    Ejercicio 3:
    Se dispone de los siguientes datos de los empleados de una empresa:
    Apellido y nombre, sueldo y antigüedad.
    Las ternas de datos se ingresarán en cualquier orden.
    Luego del último juego de datos se ingresará "FIN" en apellido y nombre.
    Se sabe que la cantidad de empleados no es más de 100.
    Se pide un programa que:
    a-) Muestre en pantalla un listado ordenado en forma ALFABETICA por apellido y nombre, 
    de todos aquellos empleados que superen o iguales el sueldo promedio, informando 
    sus tres atributos.
    b-) Datos completos del o los empleados de mayor antigüedad.
*/

#include <stdio.h>
#include <string.h>
#define MAX_EMPLEADOS 100

#ifdef __unix
#include <strings.h>
#define strcmpi strcasecmp
#define fflush(stdin); getchar();
#endif

/*
 * TDA (Tipo de dato abstracto) Empleado:
 * Campos: apellidoNombre (string), sueldo (float), antiguedad (int).
 */
typedef struct {
    int antiguedad;
    float sueldo;
    char apellidoNombre[31];
} Empleado;

int Carga(Empleado[], int);
void Ordenamiento(Empleado[], int);
void Mostrar(Empleado[], int);
int Maximo(Empleado[], int);

main()
{
   Empleado listaEmpleados[MAX_EMPLEADOS];
   int cantEmpleados = Carga(listaEmpleados, MAX_EMPLEADOS);
   Ordenamiento(listaEmpleados, cantEmpleados);
   Mostrar(listaEmpleados, cantEmpleados);
}

/**
 * Funcion Carga: 
 * Objetivo: Permite inicializar la base de datos de empleados, con una carga incompleta.
 * Recibe: Vector de tipo Empleado, cantidad maxima de empleados. 
 * Retorna: Cantidad cargada de empleados.
 */
int Carga(Empleado lista[], int tam)
{
    int i = 0, band = 0;
    Empleado aux;
    printf("\nIngrese el apellido y nombre (FIN para terminar): ");
    gets(aux.apellidoNombre);
    while (strcmpi(aux.apellidoNombre, "fin") != 0 && i < tam)
    {
        printf("\nIngrese el sueldo: ");
        do
        {
            if (!band)
                band++;
            else
                printf("El sueldo debe ser mayor a cero. Ingrese nuevamente: ");
            scanf("%f", &aux.sueldo);
        } while (aux.sueldo <= 0);
        band = 0;
        printf("\nIngrese la antiguedad: ");
        do
        {
            if (!band)
                band++;
            else
                printf("La antiguedad no puede ser negativa. Ingrese nuevamente: ");
            scanf("%d", &aux.antiguedad);
        } while (aux.antiguedad < 0);
        band = 0;
        lista[i] = aux;
        i++;

        printf("\nIngrese el apellido y nombre (FIN para terminar): ");
        fflush(stdin);
        gets(aux.apellidoNombre);
    }
    return i;
}

/**
 * Funcion Ordenamiento: 
 * Objetivo: Ordenar alfabeticamente la lista de empleados.
 * Recibe: Vector de tipo Empleado, cantidad de empleados. 
 */
void Ordenamiento(Empleado lista[], int tam)
{
    int i, j;
    Empleado aux;
    for (i = 0; i < tam - 1; i++)
        for (j = 0; j < tam - 1 - i; j++)
            if (strcmpi(lista[j].apellidoNombre, lista[j+1].apellidoNombre) > 0)
            {
                aux = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux;
            }
}

/**
 * Funcion Mostrar: 
 * Objetivo: Muestra los empleados que:
 *     - Superen o igualen el sueldo promedio.
 *     - Tengan mayor antiguedad.
 * Recibe: Vector de tipo Empleado, cantidad de empleados. 
 */
void Mostrar(Empleado lista[], int tam)
{
    int i, max = Maximo(lista, tam);
    float prom = 0;
    // Calcular sueldo promedio
    for (i = 0; i < tam; i++)
        prom += lista[i].sueldo;
    if (tam != 0)
        prom /= tam;
    
    // Mostrar los empleados con sueldo mayor o igual al promedio
    // Usando los % con numeros para alineacion, y los guiones para imprimir una tabla
    printf("\nEmpleados con sueldo mayor o igual al promedio:\n");
    printf("\n----------------------------------------------------");
    printf("\n|%-30s|%8s|Antiguedad|", "Apellido y nombre", "Sueldo");
    printf("\n----------------------------------------------------");
    for (i = 0; i < tam; i++)
        if (lista[i].sueldo >= prom)
            printf("\n|%-30s|%8.2f|%10d|", lista[i].apellidoNombre, lista[i].sueldo, lista[i].antiguedad);
    printf("\n----------------------------------------------------");

    // Mostrar los empleados de mayor antiguedad
    printf("\nEmpleados con mayor antiguedad:\n");
    printf("\n----------------------------------------------------");
    printf("\n|%-30s|%8s|Antiguedad|", "Apellido y nombre", "Sueldo");
    printf("\n----------------------------------------------------");
    for (i = 0; i < tam; i++)
        if (lista[i].antiguedad == max)
            printf("\n|%-30s|%8.2f|%10d|", lista[i].apellidoNombre, lista[i].sueldo, lista[i].antiguedad);
    printf("\n----------------------------------------------------");
}

/**
 * Funcion Maximo: 
 * Objetivo: Permite obtener la mayor antiguedad (maximo multiple).
 * Recibe: Vector de tipo Empleado, cantidad de empleados. 
 * Retorna: Mayor antiguedad.
 */
int Maximo(Empleado lista[], int tam)
{
    int i, max;
    max = lista[0].antiguedad;
    for (i = 1; i < tam; i++)
        if (lista[i].antiguedad > max)
            max = lista[i].antiguedad;
    return max;
}