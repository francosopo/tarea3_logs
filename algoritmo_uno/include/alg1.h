/// Se definen todas las estructuras y funciones que usará el algoritmo uno
/// En utils.h se define lo que se usará en todos los algoritmos.
#include <utils.h>



/**
 * find_median_alg
 * 
 * Encuentra el indice de la mediana del alg 1
 * 
 * @param m Estructura mediana
 * @param c el parametro a cortar
*/
int find_median_alg1(Mediana *m, int c);

/**
 * find_pivot
 * 
 * Encuentra el indice del pivote de una Mediana
*/
int find_pivot(Mediana *med, int c);

/**
 * Test de find_median
*/
void test_find_median_alg1(void);

/**
 * copy_medians
 * 
 * Copia las medianas obtenidas de @param arr en
 * un nuevo arreglo, retornándolo
 * 
 * @param arr: El arreglo de medianas
 * @param size: El tamaño del arreglo de medianas
*/
int *copy_medians(int *arr, int size);