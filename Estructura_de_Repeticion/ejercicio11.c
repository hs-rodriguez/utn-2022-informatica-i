/*
    Ejercicio 11:
    Se realizó un concurso de tiro al blanco. Existen 5 participantes y 
    cada uno de ellos efectúa 3 disparos, registrándose las 
    coordenadas X-Y de cada disparo.
    Determinar:
    a-) Cuantos disparos se efectuaron en cada cuadrante por cada participante
    b-) Cuantos disparos se efectuaron en total en el centro.
    NOTA: no considere disparos sobre los ejes.
*/

#include <stdio.h>

int main (void)
{
    float x, y;
    int cuad1, cuad2, cuad3, cuad4, centro = 0;

    for (int i = 1; i <= 5; i++)
    {
        printf("\nParticipante %d de 5\n", i);
        cuad1 = cuad2 = cuad3 = cuad4 = 0;
        for (int j = 1; j <= 3; j++)
        {
            printf("Disparo %d. Ingrese las coordenadas: ", j);
            scanf("%f %f", &x, &y);

            if (x > 0 && y > 0)
                cuad1++;
            else if (x < 0 && y > 0)
                cuad2++;
            else if (x < 0 && y < 0)
                cuad3++;
            else if (x > 0 && y < 0)
                cuad4++;
            else 
                centro++;
        }

        printf("\nDisparos al primer cuadrante: %d", cuad1);
        printf("\nDisparos al segundo cuadrante: %d", cuad2);
        printf("\nDisparos al tercer cuadrante: %d", cuad3);
        printf("\nDisparos al cuarto cuadrante: %d", cuad4);

        printf("\n\n\t\t-----------------------------\n");
        
    }

    printf("\nTotal de disparos al centro: %d", centro);

    return 0;
}