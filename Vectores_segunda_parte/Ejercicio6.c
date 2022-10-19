/* 
    Ejercicio 6:
    Una fábrica produce 20 tipos de embalajes mediante 5 maquinas (identificadas por código numérico de 3
    cifras). Cada día durante un mes por cada tipo de embalaje producido se genera una planilla, donde se indica
    tipo de embalaje (0 a 19) y máquina que la produjo y cantidad producida.
    En la última información se ingresó una cantidad negativa.

    Determinar:
    a) Cantidad total de embalajes fabricados.
    b) Tipo de embalaje del cual se ha fabricado la mayor cantidad.
    c) Listado ordenado en forma ascendente por cantidad de embalajes fabricados por maquina, indicando:
    Numero de maquina Cantidad fabricada
    d) Embalajes (Número/s) no producidos.
    UTILIZAR FUNCIONES: CARGACODIGOMAQUINA – CARGADATOS - MAXIMO –
    INFORME para cada item. Solicitado.
*/

#include <stdio.h>

int LeeControlRango(int, int);
int Maximo(int[], int);
int BusquedaSecuencial(int [], int, int);
void CargaCodigoMaquina(int[], int); 
int CargaDatos(int[], int[], int[], int);
void MostrarVectores(int[], int[], int);
void MostrarNoProducidos(int[], int);

int main (void) 
{
    int maquinas[5], maquinasProductoras[20], cantidadProducida[20] = {0}, cantidadTotal;
    CargaCodigoMaquina(maquinas, 5);
    cantidadTotal = CargaDatos(maquinas, maquinasProductoras, cantidadProducida, 20);
    printf("\nCantidad total: %d", cantidadTotal);
    printf("\nEmbalaje que mas se fabrico: %d", Maximo(cantidadProducida, 20));
    MostrarVectores(maquinasProductoras, cantidadProducida, 20);
    MostrarNoProducidos(cantidadProducida, 20);

    return 0;
}

int LeeControlRango(int limiteInferior, int limiteSuperior)
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

int Maximo(int vec[], int tam) 
{
    int posMax = 0;
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > vec[posMax])
            posMax = i;
    }
    return posMax;
}

void CargaCodigoMaquina(int vec[], int tam) 
{
    int dato, pos, band;
    for (int i = 0; i < tam; i++)
    {
        band = 0;
        printf("Ingrese el codigo de la maquina: ");
        do
        {
            if (!band)
                band++;
            else
                printf("Ingrese nuevamente: ");

            dato = LeeControlRango(100, 999);
            pos = BusquedaSecuencial(vec, dato, i);
        } while (pos != -1);

        vec[i] = dato;
    }
   
}

int CargaDatos(int maquinas[], int maquinasProductoras[], int cantidad[], int tam) 
{
    int i, cantidadProducida, cantidadTotal = 0, dato, pos, band;

    printf("Ingrese la cantidad producida: ");
    scanf("%d", &cantidadProducida);

    while(cantidadProducida >= 0 && pos != -1)
    {
        printf("Ingrese el tipo de embalaje producido: ");
        band = 0;
        do
        {
            if (!band) // band == 0
                band++;
            else
                printf("Ingrese nuevamente: ");
            
            i = LeeControlRango(0, 19);
        } while (cantidad[i] != 0);
    
        band = 0;
        printf("Ingrese la maquina que lo realizo: ");
        do
        {
            if (!band)
                band++;
            else
                printf("Ingrese nuevamente: ");
            
            scanf("%d", &dato);
            pos = BusquedaSecuencial(maquinas, dato, 5);
        } while (pos == -1);
        maquinasProductoras[i] = dato;

        cantidad[i] = cantidadProducida;
        cantidadTotal += cantidadProducida;

        pos = BusquedaSecuencial(cantidad, 0, tam);

        printf("Ingrese la cantidad producida: ");
        scanf("%d", &cantidadProducida);
    }
    return cantidadTotal;
}

void MostrarVectores(int maquinasProductoras[], int cantidad[], int tam) 
{
    printf("\nEmbalaje \t Maquina \t Cantidad ");
    for (int i = 0; i < tam; i++)
    {
        if(cantidad[i] != 0)
            printf("\n%d \t\t %d \t\t %d", i, maquinasProductoras[i], cantidad[i]);
    }  
}

void MostrarNoProducidos(int cantidadProducida[], int tam)
{
    // d) Embalajes (Número/s) no producidos.
    printf("\nTipos de embalajes no producidos:");
    for (int i = 0; i < tam; i++)
    {
        if(cantidadProducida[i] == 0)
            printf(" %d", i);
    }  
}

