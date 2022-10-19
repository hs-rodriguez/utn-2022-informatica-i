/*
    Ejercicio 4:
    La UTN Regional Bs As tiene que mandar un alumno que la represente en una convención de la UTN. Se
    decidió considerar como candidatos al mejor promedio de los alumnos del último año de cada carrera (hay 10
    carreras codificadas del 0 al 9).
    Los candidatos se codifican de 0 a 9.
    Los alumnos de la universidad (como máximo 1000) deberán votar entre estos 10 candidatos para elegir el
    ganador.
    El voto consiste en ingresar el código del candidato elegido y la carrera a la que pertenece el votante. Cada
    alumno votará una sola vez.
    Realizar un programa que haga lo siguiente:
    a) Ingresar los nombres de los 10 candidatos.
    b) Ingresar los votos y, al finalizar (código =17) mostrar en pantalla:
    1. El nombre del candidato ganador (se lo supone único).
    2. Para cada candidato, la cantidad de votos que recibió de alumnos de cada carrera.
    3. Los nombres de los candidatos no votados
*/

#include <stdio.h>
#include <string.h>

#define CANT_CARRERAS 10 // 10 en el enunciado
#define CANT_CANDIDATOS 10 // 10 en el enunciado
#define MAX_ALUMNOS 10 // 1000 en el enunciado
#define MAX_CHAR 31

void IngresarCandidatos(char listaCandidatos[][MAX_CHAR], int tam);
void Votacion(int votos[][CANT_CARRERAS], int tam);
int ValidarCodigos(void);
void Ganador(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam);
void MostrarResultados(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam);
void NoVotados(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam);

main()
{
    char listaCandidatos[CANT_CANDIDATOS][MAX_CHAR];
    int votos[CANT_CANDIDATOS][CANT_CARRERAS] = {0};

    IngresarCandidatos(listaCandidatos, CANT_CANDIDATOS);
    Votacion(votos, CANT_CANDIDATOS);
    Ganador(votos, listaCandidatos, CANT_CANDIDATOS);
    MostrarResultados(votos, listaCandidatos, CANT_CANDIDATOS);
    NoVotados(votos, listaCandidatos, CANT_CANDIDATOS);
}

void IngresarCandidatos (char listaCandidatos[][MAX_CHAR], int tam)
{
    int i;
    printf("\n\tIngreso de los candidatos. ");
    for (i = 0; i < tam; i++) {
        printf("\nIngrese el nombre del candidato de la carrera %d: ", i);
        fflush(stdin);
        gets(listaCandidatos[i]);
    }
}

void Votacion (int votos[][CANT_CARRERAS], int tam)
{
    int i = 0, candidato, carrera;
    printf("\nIngrese el codigo del candidato que desee votar (17 para terminar): ");
    candidato = ValidarCodigos();
    while (candidato != 17 && i < MAX_ALUMNOS) {
        printf("\nIngrese a que carrera usted pertenece: ");
        carrera = ValidarCodigos();

        votos[candidato][carrera]++;
        i++;

        printf("\nIngrese el codigo del candidato que desee votar (17 para terminar): ");
        candidato = ValidarCodigos();
    }
}

int ValidarCodigos(void)
{
    int codigo, band = 0;
    do {
        if(!band)
            band++;
        else
            printf("Codigo no valido. Ingrese nuevamente: ");
        scanf("%d", &codigo);
    } while ((codigo < 0 || codigo > 9) && codigo != 17);
    return codigo;
}

void Ganador(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam)
{
    int i, j, sumaVotos, mayorVotos, mayorPos;
    for (i = 0; i < tam; i++) {
        sumaVotos = 0;
        for (j = 0; j < CANT_CARRERAS; j++) {
            sumaVotos += votos[i][j];
        }
        if (i == 0 || sumaVotos > mayorVotos) {
            mayorVotos = sumaVotos;
            mayorPos = i;
        }
    }
    printf("\nEl candidato ganador es: %s", listaCandidatos[mayorPos]);
}

void MostrarResultados(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam)
{
    int i, j;
    printf("\n\nResultados de la votacion.\n%-30s", "Candidato");
    for (j = 0; j < CANT_CARRERAS; j++)
        printf(" Votos C%d", j);

    for (i = 0; i < tam; i++) {
        printf("\n%-30s", listaCandidatos[i]);
        for (j = 0; j < CANT_CARRERAS; j++)
            printf(" %8d", votos[i][j]);
    }
}

void NoVotados(int votos[][CANT_CARRERAS], char listaCandidatos[][MAX_CHAR], int tam)
{
    int i, j, sumaVotos;
    printf("\n\nLos candidatos no votados fueron: ");
    for (i = 0; i < tam; i++) {
        sumaVotos = 0;
        for (j = 0; j < CANT_CARRERAS; j++) 
            sumaVotos += votos[i][j];
        if (sumaVotos == 0)
            printf("%s, ", listaCandidatos[i]);
    }
}