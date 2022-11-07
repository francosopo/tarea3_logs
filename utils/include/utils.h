/// Aquí van todas las utilidades que ocuparán todos los algoritmos

#include <stdio.h>
#include <stdlib.h>

// struct mediana
typedef struct mediana{
    int med;
    int *arr;
}Mediana;

//Tiempo del algoritmo
typedef double (*tiempo_alg)();

//constructores y destructores
Mediana *newMedian(int array_size);
void destroyMedian(Mediana *med);

// test
void test(char *name, int expected, int got);

