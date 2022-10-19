/*
    Ejercicio 1:
    Se conoce:
    - DNI
    - APELLIDO Y NOMBRE ( máximo 40 caracteres)
    - NOTA PROMEDIO
    de 30 alumnos de una comisión.
    SE PIDE:
    A-) CARGAR TODA LA INFORMACION EN ARRAYS.
    B-) SE CONSULTA SEGUN APELLIDO Y NOMBRE. INFORMANDO DNI Y LA NOTA PROMEDIO.
    LA CONSULTA FINALIZA CUANDO SE INGRESA "FIN"
    C-) INFORMAR, ORDENADO ALFABETICAMENTE POR APELLIDO Y NOMBRE:
    DNI APELLIDO Y NOMBRE NOTA PROMEDIO
*/

#include <stdio.h>
#include <string.h>
#define CANT_ALUMNOS 30
#define MAX_CHAR 41

// Modificaciones para que me funcione en Linux
#ifdef __unix__
#include <strings.h>
#define strcmpi strcasecmp
#define fflush(stdin) getchar()
#endif

void CargarLista(int[], char[][MAX_CHAR], float[], int);
int PedirDNI(int[], int);
int iLeeControlRango(int, int);
float fLeeControlRango(float, float);
int iBusquedaSecuencial(int[], int, int);
void Consulta(int[], char[][MAX_CHAR], float[], int);
int BusquedaAlumno(char[][MAX_CHAR], char[], int);
void Ordenamiento (int[], char[][MAX_CHAR], float[], int);
void Informar (int[], char[][MAX_CHAR], float[], int);

main()
{
    int listaDNI[CANT_ALUMNOS];
    char listaAlumnos[CANT_ALUMNOS][MAX_CHAR];
    float listaNotas[CANT_ALUMNOS];
    CargarLista(listaDNI, listaAlumnos, listaNotas, CANT_ALUMNOS);
    Consulta(listaDNI, listaAlumnos, listaNotas, CANT_ALUMNOS);
    Ordenamiento(listaDNI, listaAlumnos, listaNotas, CANT_ALUMNOS);
    Informar(listaDNI, listaAlumnos, listaNotas, CANT_ALUMNOS);
}

void Consulta(int listaDNI[], char listaAlumnos[][MAX_CHAR], float listaNotas[], int tam)
{
    int pos;
    char alumno[MAX_CHAR];
    printf("\nIngrese su apellido y nombre: ");
    gets(alumno);

    while(strcmpi(alumno, "fin") != 0) // compara los dos string
    {
        pos = BusquedaAlumno(listaAlumnos, alumno, tam);
        if (pos != -1)
            printf("\nDNI: %d\nNota promedio: %.2f", listaDNI[pos], listaNotas[pos]);
        else
            printf("El alumno no esta en la lista.\n");
        
        printf("\nIngrese su apellido y nombre: ");
        gets(alumno); 
    }
}

int BusquedaAlumno(char listaAlumnos[][MAX_CHAR], char alumno[], int tam)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < tam)
    {
        if (strcmpi(listaAlumnos[i], alumno) == 0 )
            pos = i;
        else
            i++;
    }
    return pos;
}

void CargarLista(int listaDNI[], char listaAlumnos[][MAX_CHAR], float listaNotas[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        listaDNI[i] = PedirDNI(listaDNI, i);
        fflush(stdin);
        printf("Ingrese el apellido y nombre del alumno: ");
        // No puedo usar scanf porque no lee el string completo si hay espacios
        // scanf("%s", listaAlumnos[i]);
        gets(listaAlumnos[i]);
        // Alternativa
        //fgets(listaAlumnos[i], MAX_CHAR, stdin);
        printf("Ingrese la nota del alumno: ");
        listaNotas[i] = fLeeControlRango(1, 10);
        fflush(stdin);
    }
}

// Recibe la lista de DNI para poder buscar y comprobar que no se repitan ingresos
int PedirDNI(int listaDNI[], int tam)
{
    int dni, pos = -1;
    printf("\nIngrese el DNI del alumno: ");
    do
    {
        dni = iLeeControlRango(10000000, 100000000);
        pos = iBusquedaSecuencial(listaDNI, dni, tam);
    } while (pos != -1);
    return dni;
}

int iLeeControlRango(int limiteInferior, int limiteSuperior)
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

float fLeeControlRango(float limiteInferior, float limiteSuperior)
{
    float dato;
    int band = 0;
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

int iBusquedaSecuencial(int vec[], int dato, int tam)
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

void Ordenamiento (int listaDNI[], char listaAlumnos[][MAX_CHAR], float listaNotas[], int tam)
{
    int i, j, auxInt;
    float auxFloat;
    char auxChar[MAX_CHAR];
    for (i = 0; i < tam - 1; i++)
        for (j = 0; j < tam - 1 - i; j++)
            if (strcmpi(listaAlumnos[j], listaAlumnos[j+1]) > 0)
            {
                strcpy(auxChar, listaAlumnos[j]);
                strcpy(listaAlumnos[j], listaAlumnos[j+1]);
                strcpy(listaAlumnos[j+1], auxChar);

                auxInt = listaDNI[j+1];
                listaDNI[j+1] = listaDNI[j];
                listaDNI[j] = auxInt;

                auxFloat = listaNotas[j+1];
                listaNotas[j+1] = listaNotas[j];
                listaNotas[j] = auxFloat;
            }              
}

void Informar (int listaDNI[], char listaAlumnos[][MAX_CHAR], float listaNotas[], int tam)
{
    int i;
    printf("\nDNI \t\t Alumno \t Nota");
    for (i = 0; i < tam; i++)
        printf("\n%d \t %s \t %.2f",listaDNI[i],listaAlumnos[i],listaNotas[i]);
}
