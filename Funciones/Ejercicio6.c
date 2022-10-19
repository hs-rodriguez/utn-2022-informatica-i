/*
    Ejercicio 6:
    Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo identifica
    y el resultado de los disparos efectuados. El ingreso finaliza con un número de participante negativo.
    Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.
    No considere disparos sobre los ejes, pero sí en el centro (si es sobre los ejes las coordenadas
    deberán volver a ingresarse).
    Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas y
    retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.
    Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la
    cantidad disparos en cada eje y en el centro. La función debe retornar el puntaje obtenido según la
    siguiente escala:
    Cuadrantes 1 y 2: 50 puntos
    Cuadrantes 3 y 4: 40 puntos
    Centro: 100 puntos
    Determinar:
    El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
    Mostrar el número del participante ganador y el puntaje obtenido.
    Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)
*/

#include <stdio.h>

int ingresoParticipante (void);
int cuadrante(float, float);
int puntaje (int, int, int, int, int);

int main (void)
{
    int participante, puntos, tirosPrimer, tirosSegundo, tirosTercer, tirosCuarto, tirosCentro; 
    int ganador, puntajeGanador, totalTirosCentro = 0, band = 0;
    float x, y;

    participante = ingresoParticipante();
    while (participante >= 0)
    {
        tirosPrimer = tirosSegundo = tirosTercer = tirosCuarto = tirosCentro = 0;
        for (int i = 1; i <= 5; i++)
        {
            do
            {
                printf("Disparo %d. Ingrese las coordenadas: ", i);
                scanf("%f %f", &x, &y);
            } while ((x == 0 && y != 0) || (y == 0 && x != 0));
            
            switch (cuadrante(x, y))
            {
                case 1:
                    tirosPrimer++;
                    break;
                case 2:
                    tirosSegundo++;
                    break;
                case 3:
                    tirosTercer++;
                    break;
                case 4:
                    tirosCuarto++;
                    break;
                case 0:
                    tirosCentro++;
            }
        }

        totalTirosCentro += tirosCentro;
        puntos = puntaje(tirosPrimer, tirosSegundo, tirosTercer, tirosCuarto, tirosCentro);
        printf("\nPuntos: %d\nDisparos cuad. 1: %d\nDisparos cuad. 2: %d\nDisparos cuad. 3: %d\nDisparos cuad. 4: %d\nDisparos en el centro: %d", puntos, tirosPrimer, tirosSegundo, tirosTercer, tirosCuarto, tirosCentro);

        if (band == 0)
        {
            ganador = participante;
            puntajeGanador = puntos;
        }
        else if (puntos > puntajeGanador)
        {
            ganador = participante;
            puntajeGanador = puntos;
        }

        participante = ingresoParticipante();     
    }

    printf("\n\nEl ganador fue el participante %d con %d puntos.", ganador, puntajeGanador);

    return 0;
}

int ingresoParticipante ()
{
    int participante;
    printf("\nIngrese el numero de participante: ");
    scanf("%d", &participante);
    return participante;
}

int cuadrante (float x, float y)
{
    if (x > 0 && y > 0)
        return 1;
    else if (x < 0 && y > 0)
        return 2;
    else if (x < 0 && y < 0)
        return 3;
    else if (x > 0 && y < 0)
        return 4;
    else 
        return 0;
}

int puntaje (int primer, int segundo, int tercero, int cuarto, int centro)
{
    int puntos;
    puntos = (primer + segundo) * 50 + (tercero + cuarto) * 40 + centro * 100;
    return puntos; 
}