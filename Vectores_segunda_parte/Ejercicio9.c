/*
 * Ejercicio 9:
 * Se ingresan DNI y nota de un parcial de los alumnos de un curso.
 * El ingreso de datos finaliza con un DNI negativo. Se sabe que como máximo pueden presentarse a rendir 60
 * alumnos.
 * Mostrar:
 * a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado).
 * b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.
 */

#include <stdio.h>
#define MAX_ALUMNOS 60

int IngresoListado(int[], float[], int);
int PedirDNI(int[], int);
int BusquedaSecuencial(int[], int, int);
float LeeControlRango(float, float);
void Ordenamiento(int[], float[], int);
float ObtenerMayor(float[], int);
void MostrarListado(int[], float[], int);
void MostrarMayorNota(int[], float[], float, int);

main() 
{
    int cantAlumnos, listaDNI[MAX_ALUMNOS];
    float mayorNota, listaNotas[MAX_ALUMNOS];
    
    cantAlumnos = IngresoListado(listaDNI, listaNotas, MAX_ALUMNOS);
    Ordenamiento(listaDNI, listaNotas, cantAlumnos);
    mayorNota = ObtenerMayor(listaNotas, cantAlumnos);
    MostrarListado(listaDNI, listaNotas, cantAlumnos);
    MostrarMayorNota(listaDNI, listaNotas, mayorNota, cantAlumnos);
}

int IngresoListado(int listaDNI[], float listaNotas[], int tam)
{
    int dni, i = 0;
    
    dni = PedirDNI(listaDNI, i);
    // Ya está validado el DNI, por lo que puedo simplemente restringir los negativos
    while (dni > 0 && i < tam)
    {
        listaDNI[i] = dni;
        printf("\nIngrese la nota del alumno: ");
        listaNotas[i] = LeeControlRango(1,10);
        i++;
        dni = PedirDNI(listaDNI, i);
    }
    // Devuelvo la cantidad de alumnos ingresados
    return i;
}

// Recibe la lista de DNI para poder buscar y comprobar que no se repitan ingresos
int PedirDNI(int listaDNI[], int tam)
{
    int dni, band = 0, pos = -1;
    printf("\nIngrese el DNI del alumno: ");
    do
    {
        if (!band)
            band++;
        else
            printf("Ingrese nuevamente: ");
        scanf("%d", &dni);
        if (dni > 10000000)
            pos = BusquedaSecuencial(listaDNI, dni, tam);
    } while ((dni >= 0 && dni < 10000000) || pos != -1);
    return dni;
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

float LeeControlRango(float limiteInferior, float limiteSuperior)
{
    int band = 0;
    float dato;
    do
    {
        if(!band)
            band++;
        else
            printf("Ingrese nuevamente: ");
        scanf("%f", &dato);
    } while (dato < limiteInferior || dato > limiteSuperior);
    return dato;
}

// Ordenamiento en forma ascendente
void Ordenamiento(int vec1[], float vec2[], int tam)
{
    int i, j, iAux;
    float fAux;
    for (i = 0; i < tam -1; i++)
        for(j = 0; j < tam - 1 - i; j++)
            if(vec1[j] > vec1[j+1])
            {
                iAux = vec1[j];
                vec1[j] = vec1[j+1];
                vec1[j+1] = iAux;

                fAux = vec2[j];
                vec2[j] = vec2[j+1];
                vec2[j+1] = fAux;
            }
}

float ObtenerMayor(float vec[], int tam)
{
    int i;
    float mayor = vec[0];
    for(i = 1; i < tam; i++)
        if (vec[i] > mayor)
            mayor = vec[i];
    return mayor;
}

void MostrarListado(int listaDNI[], float listaNotas[], int tam)
{
    int i;
    printf("\nDNI del alumno \t Calificacion");
    for(i = 0; i < tam; i++)
        printf("\n%d \t %.2f", listaDNI[i], listaNotas[i]);
}

void MostrarMayorNota(int listaDNI[], float listaNotas[], float mayorNota, int tam)
{
    int i;
    printf("\nLa maxima nota fue %.2f.\nDNI de los alumnos que la obtuvieron: ", mayorNota);
    for(i = 0; i < tam; i++)
        if(listaNotas[i] == mayorNota)
            printf("\n%d", listaDNI[i]);
}
