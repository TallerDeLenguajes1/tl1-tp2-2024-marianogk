#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMA 5

typedef struct pc
{
    int velocidad;
    int ano;
    char *tipo;
    int nucleos;
} pc;

void cargarPc(pc p[], int cant);
void mostrarPc(pc p);
pc pcMasVieja(pc p[], int cant);
pc pcMasVeloz(pc p[], int cant);

int main()
{
    pc compus[TAMA], pcVieja, pcVeloz;

    cargarPc(compus, 5);

    mostrarPc(compus[0]);
    mostrarPc(compus[1]);
    mostrarPc(compus[2]);
    mostrarPc(compus[3]);
    mostrarPc(compus[4]);

    pcVieja = pcMasVieja(compus, 5);
    printf("\n-La PC mas vieja es: \n");
    mostrarPc(pcVieja);

    pcVeloz = pcMasVeloz(compus, 5);
    printf("\n-La PC con mayor velocidad es: \n");
    mostrarPc(pcVeloz);

    return 0;
}

void cargarPc(pc p[], int cant)
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    int k;

    srand(time(NULL));

    for (int i = 0; i < TAMA; i++)
    {
        k = rand() % 6;

        p[i].velocidad = 1 + rand() % 3;
        p[i].ano = 2015 + rand() % 10;

        p[i].tipo = (char *)malloc(strlen(tipos[k]) + 1);

        strcpy(p[i].tipo, tipos[k]);
        p[i].nucleos = 1 + rand() % 8;
    }
}

void mostrarPc(pc p)
{
    printf("\n\nCOMPUTADORA \n");

    printf("\nVelocidad: %d\n", p.velocidad);
    printf("Ano de fabricacion: %d\n", p.ano);
    printf("Cantidad de nucleos: %d\n", p.nucleos);
    printf("Tipo de procesador: ");
    puts(p.tipo);
}

pc pcMasVieja(pc p[], int cant)
{
    int aux = p[0].ano, k;

    for (int i = 0; i < TAMA; i++)
    {
        if (p[i].ano < aux)
        {
            aux = p[i].ano;
            k = i;
        }
    }
    return p[k];
}

pc pcMasVeloz(pc p[], int cant)
{
    int aux = p[0].velocidad, k;

    for (int i = 0; i < TAMA; i++)
    {
        if (p[i].velocidad > aux)
        {
            aux = p[i].velocidad;
            k = i;
        }
    }
    return p[k];
}