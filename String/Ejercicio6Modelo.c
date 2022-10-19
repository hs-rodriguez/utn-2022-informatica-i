/*
 * Ejercicio 6:
 * Una Universidad publicó una lista de materias para cursar durante el verano, solicitando a los alumnos que
 * seleccionen cuales de ellas están interesados en cursar. Hay 10 materias ofrecidas, cada una con su NOMBRE
 * (20 caracteres) y CÓDIGO (entero).
 * CADA ALUMNO PUEDE ELEGIR O ANOTARSE EN UNA SOLA MATERIA, mediante el ingreso del nombre de la
 * materia que desea cursar. La entrada finaliza con la materia ZZZ.
 * Se pide:
 * a-) Cargar el Nombre y código de las materias ofrecidas. Utilizar una función.
 * b-) Realizar una función que ordene alfabéticamente por nombre de materia, con su código y cantidad de
 * alumnos anotados.
 * c-) Códigos de materias donde se anotaron menos de 12 alumnos. Utilizar una función.
 * d-) Cuántos alumnos se anotaron en total
 */


#include<stdio.h>
#include<string.h>
#define CANT_MATERIAS 5
#define CARACTERES 21

// Modificaciones para que me funcione en Linux
#ifdef __unix__
#include <strings.h>
#define strcmpi strcasecmp
#define fflush(stdin) getchar()
#endif

void Cargardatos(int listacodigo[], char listamaterias[][CARACTERES], int tam);
int busquedacodigo(int listacodigo[], int dato,int tam);
int busquedamateria(char listamaterias[][CARACTERES],char dato[],int tam);
int inscripcion(char[][CARACTERES], int[], int);
void ordenamiento(char[][CARACTERES], int[], int[], int);
void mostrar(char[][CARACTERES], int[], int[], int);
void Materiaconmenosalum(int [], int [], int);

main(){
    int listacodigo[CANT_MATERIAS];    
    int cantalum[CANT_MATERIAS]={0};
    char listamaterias[CANT_MATERIAS][CARACTERES];
    int canttotal;
    Cargardatos(listacodigo,listamaterias,CANT_MATERIAS);
    canttotal = inscripcion(listamaterias, cantalum, CANT_MATERIAS);
    ordenamiento(listamaterias, listacodigo, cantalum, CANT_MATERIAS);
    mostrar(listamaterias, listacodigo, cantalum, CANT_MATERIAS);
    Materiaconmenosalum(listacodigo, cantalum, CANT_MATERIAS);    
    printf("\nLa cantidad total de alumnos es: %d", canttotal);

}
void Cargardatos(int listacodigo[],char listamaterias[][CARACTERES], int tam)
{
    int i,pos,codigo;
    char materia[CARACTERES];
    for(i=0; i<tam; i++)
    {
        do{
            printf("Ingrese el codigo: ");
            scanf("%d", &codigo);
            fflush(stdin);
            pos = busquedacodigo(listacodigo, codigo, i);
        }while(pos != -1 || codigo<=0);
        listacodigo[i]=codigo;
    
        do{
            printf("Ingrese el nombre de la materia: ");
            gets(materia);
            pos = busquedamateria(listamaterias, materia, i);
        }while(pos!=-1);
        strcpy(listamaterias[i],materia); 
    }
}
/* Funciones de string
    strcmp -> compara
    strcmpi -> compara e ignora mayuscula/minuscula
    strcpy -> copia un string a otro
    strcat -> Concatena (une) dos string

    string compare
    string compare insensitive
    string copy
    string concat
*/
int busquedacodigo(int listacodigo[], int dato,int tam)
{
    int i = 0, pos = -1;
    while(pos == -1 && i < tam)
    {
        if (listacodigo[i] == dato)
            pos = i;
        else
            i++; 
    }
    return pos;
}


int busquedamateria(char listamaterias[][CARACTERES],char dato[],int tam)
{
    int i = 0, pos = -1;// si no encuentra el dato te da -1 y si lo encuentra te dice donde esta 
    while(pos == -1 && i < tam)
    {
        if (strcmpi(listamaterias[i], dato) == 0)
            pos = i;
        else
            i++; 
    }
    return pos;
}

int inscripcion(char listamaterias[][CARACTERES], int cantalum[], int tam)
{
    int i, canttotal=0;
    char nombremat[CARACTERES];
    printf("\nIngrese la materia a la cual se va a anotar: ");
    gets(nombremat);
    while(strcmpi(nombremat,"zzz") != 0)
    {
        i = busquedamateria(listamaterias,nombremat,tam);
        if(i != -1)
        {
            cantalum[i]++;
            canttotal++;
        }
        else
            printf("\nLa materia no existe");
        
        printf("\nIngrese la materia a la cual se va a anotar: ");
        gets(nombremat);
    }   
    return canttotal; 

}

void ordenamiento(char listamaterias[][CARACTERES], int listacodigo[], int cantalum[], int tam)
{
    int i, j, auxInt;
    char auxChar[CARACTERES];
    for (i = 0; i < tam-1; i++)
        for(j = 0; j < tam -1 -i; j++)
           if(strcmpi(listamaterias[j], listamaterias[j+1]) > 0) 
           {
                strcpy(auxChar, listamaterias[j]);
                strcpy(listamaterias[j], listamaterias[j+1]);
                strcpy(listamaterias[j+1], auxChar);

                auxInt = listacodigo[j+1];
                listacodigo[j+1] = listacodigo[j];
                listacodigo[j] = auxInt;

                auxInt = cantalum[j+1];
                cantalum[j+1] = cantalum[j];
                cantalum[j] = auxInt;
           }
}

void mostrar(char listamaterias[][CARACTERES], int listacodigo[], int cantalum[], int tam)
{
    int i;
    printf("\nMateria \t\t Codigo \t Cantidad Alumnos");
    for(i = 0; i < tam; i++)
        printf("\n%20s \t %d \t %d", listamaterias[i],listacodigo[i],cantalum[i]);
} 

void Materiaconmenosalum(int listacodigo[], int cantalum[], int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        if(cantalum[i] < 12)
        printf("\nEl codigo de la materia donde hay menos de 12 alumnos es: %d",listacodigo[i]);   
    }
    
}