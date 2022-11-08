/// Se definen todas las estructuras y funciones que usará el algoritmo uno
/// En utils.h se define lo que se usará en todos los algoritmos.
#include <utils.h>



/**
 * find_median_alg
 * 
 * Encuentra la mediana del alg 1
 * 
 * @param m Estructura mediana
*/
int find_median_alg1(Mediana *m);

/**
 * Test de find_median
*/
void test_find_median_alg1(void);

/**
 * lesser_elements
 * 
 * Parte la @param med con respecto a un pivot indicado
 * en el @param index_pivot, entregando un arreglo de int's 
 * alocado en el heap con los elementos menores que el pivot
 * 
 * @param med: Estructura mediana
 * @param index_pivot: El índice del pivot
*/
Array *lesser_elements(Mediana *med, int index_pivot);

/**
 * Test de lesser elements
*/
void test_lesser_elements(void);

/**
 * greater_elements
 * 
 * Parte la @param med con respecto a un pivot indicado 
 * en el @param index_pivot, entregando un arreglo de int's 
 * alocado en el heap con los elementos mayores que el pivot
 * 
 * @param med: Estructura mediana
 * @param index_pivot: El índice del pivot
*/
Array *greater_elements(Mediana *med, int index_pivot);

/**
 * Test de greater_elements
*/
void test_greater_elements(void);

/**
 * cut_b
 * 
 * Corta el @param arr de tamano m, en m/c pequeños grupos
 * de tamaño c 
 * 
 * @param arr: El arreglo a cortar
 * @param c: El número c
*/
int **cut_b(int *arr, int c);

/**
 * sort
 * 
 * Ordena un arreglo @param arr
 * 
 * @param arr: El arreglo a ordenar
*/
int *sort(int *arr);

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