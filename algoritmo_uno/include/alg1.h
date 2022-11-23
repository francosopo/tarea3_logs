/// Se definen todas las estructuras y funciones que usará el algoritmo uno
/// En utils.h se define lo que se usará en todos los algoritmos.
#include <utils.h>



/**
 * find_median_alg
 * 
 * Encuentra el valor de la mediana del alg 1
 * 
 * @param m Estructura mediana
 * @param c el parametro a cortar
*/
double find_median_alg1(Mediana *m, int c, int index_start, int index_end, int k, int *iteraciones);

/**
 * find_pivot
 * 
 * Encuentra el indice del pivote de una Mediana
 * 
 * @param med Estructura mediana
 * @param c el parámetro c
 * @param k el k-ésimo
*/
int find_pivot(Mediana *med, int c, int k, int index_start, int index_end);

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

/**
 * getMedianFromArrayIndexes
 * 
 * obtiene la mediana de un subarreglo indicado por los indices 
 * index_start e index_end previamente ordenado
 * 
 * @param med: La estructura Mediana
 * @param index_start: El indice del inicio
 * @param index_end: El índice del final
*/
int getMedianIndexFromArrayIndexes(Mediana *med, int index_start, int index_end);