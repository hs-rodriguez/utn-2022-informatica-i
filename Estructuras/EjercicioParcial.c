/**
 * Una empresa de transporte posee una flota de 30 camiones para transportar cereales desde
 * los silos hasta distintos lugares del país. De cada camión se conoce la patente (máximo 7
 * caracteres) y el nro de interno (entero de 3 cifras).
 * Cada vez que se realiza un viaje se registra:
 *  Nro de interno del camión - tipo de cereal transportado (máximo 15 caracteres) - 
 *  Cantidad de toneladas transportadas
 * Esta información termina con Nro de interno cero o negativo.
 * Se pide realizar un programa que:
 * a) Cargue la base de datos de los 30 camiones. Función CARGA.
 * b) Indique la cantidad de toneladas transportadas totales del cereal "TRIGO"
 * c) Liste en forma ordenada ascendente por toneladas transportadas, indicando Nro interno,
 * cantidad de viajes realizados y cantidad de toneladas transportadas. Función ORDEN - Función
 * LISTAR.
 * d) Indique las patentes de los camiones que NO realizaron viaje. Si todos realizaron viajes,
 * indicar el mensaje "TODOS LOS CAMIONES REALIZARON VIAJES".
 * e) Indique la patente del camión que realizó la mínima cantidad de viajes. Se supone único.
 * Función Mínimo.
 */

#include <stdio.h>
#include <string.h>
#define MAX_CAM 30

#ifdef __unix
#include <strings.h>
#define fflush(stdin); getchar();
#define strcmpi strcasecmp
#endif

typedef struct {
    char patente[8];
    int interno; 
    int toneladas;
    int viajes;
} Camion;

int Carga(Camion[], int);
int LeeControl(int, int);
int Busqueda(Camion[], int, int);
void Orden(Camion[], int);
void Listar(Camion[], int);
int Minimo(Camion[], int);

int main(void)
{
    Camion listaCamiones[MAX_CAM];
    int interno, pos, band, toneladas, toneladasTrigo = 0;
    int cantCam = Carga(listaCamiones, MAX_CAM);
    char cereal[16];

    for (pos = 0; pos < cantCam; pos++)
    {
        listaCamiones[pos].toneladas = 0; 
        listaCamiones[pos].viajes = 0;
    }

    printf("\nIngrese el numero de interno: ");
    scanf("%d", &interno);
    while (interno > 0)
    {
        pos = Busqueda(listaCamiones, interno, cantCam);
        if (pos != -1)
        {
            printf("\nIngrese el tipo de cereal transportado: ");
            fflush(stdin);
            gets(cereal);
            printf("\nIngrese la cantidad de toneladas: ");
            band = 0;
            do
            {
                if (!band)
                    band++;
                else
                    printf("La cantidad de toneladas debe ser mayor a cero. Ingrese nuevamente: ");
                scanf("%d", &toneladas);
            } while (toneladas <= 0);
            listaCamiones[pos].toneladas += toneladas;
            listaCamiones[pos].viajes++;
            if (strcmpi(cereal, "trigo")==0)
                toneladasTrigo += toneladas;
        }
        else
            printf("El interno no existe.");

        printf("\nIngrese el numero de interno: ");
        scanf("%d", &interno);
    }

    Orden(listaCamiones, cantCam);
    Listar(listaCamiones, cantCam);
    printf("\n\nLa cantidad de toneladas de trigo totales es: %d", toneladasTrigo);

    band = 0;
    for (pos = 0; pos < cantCam; pos++)
    {
        if(listaCamiones[pos].viajes == 0) 
        {
            band++;
            break; // Si ya encuentro uno sin viajes, interrumpo el for porque ya no me importa el resto
        }
    } 

    if (band == 0)
        printf("\nTodos los camiones realizaron viajes.");
    else
    {
        printf("\nPatentes de los que no hicieron viajes:");
        for (pos = 0; pos < cantCam ; pos++)
            if(listaCamiones[pos].viajes == 0)
                printf(" %s",listaCamiones[pos].patente);
    }
    pos = Minimo(listaCamiones, cantCam);
    printf("\n\nLa patente del camion con menos viajes es: %s", listaCamiones[pos].patente);

    return 0;
}

int Carga(Camion v[], int tam)
{
    Camion aux;
    int i = 0, band;
    printf("\nIngrese el numero de interno: ");
    aux.interno = LeeControl(100, 999);
    while (aux.interno > 0 && i < tam)
    { 
        printf("\nIngrese la patente: ");
        fflush(stdin);
        gets(aux.patente);
        
        v[i] = aux;
        i++;
        band = 0;

        printf("\nIngrese el numero de interno: ");
        do
        {
            if(!band)
                band++;
            else
                printf("El numero de interno ya existe. Ingrese nuevamente: ");
            aux.interno = LeeControl(100, 999);
        } while (Busqueda(v, aux.interno, i) != -1);
    }
    return i;
}

int LeeControl(int li, int ls)
{
    int dato, band = 0;
    do {
        if (!band)
            band++;
        else
            printf("El numero no es valido. Ingrese nuevamente: ");
        scanf("%d", &dato);
    } while ((dato < li && dato > 0) || dato > ls);
    return dato;
}

int Busqueda(Camion v[], int dato, int tam)
{
    int i = 0, pos = -1;
    while (i<tam && pos==-1)
    {
        if(v[i].interno == dato)
        pos = i;
        else
        i++;
    }
    return pos;
}

void Orden(Camion v[], int tam)
{
    int i, j;
    Camion aux;
    for (i = 0; i < tam-1; i++)
        for (j = 0; j < tam-1-i; j++)
            if(v[j].toneladas > v[j+1].toneladas)
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
}

void Listar(Camion v[], int tam)
{
    int i;
    printf("\nInterno Viajes Toneladas");
    for (i = 0; i < tam; i++)
        printf("\n%7d %6d %9d", v[i].interno, v[i].viajes, v[i].toneladas);
}

int Minimo(Camion v[], int tam)
{
    int i, band = 0, posMin, min;
    for (i = 0; i < tam; i++)
    {
        if(v[i].viajes > 0 && band == 0)
        {
            min = v[i].viajes;
            posMin = i;
            band++;
        }
        else if (v[i].viajes < min)
        {
            min = v[i].viajes;
            posMin = i;
        }
    }
    return posMin;
}