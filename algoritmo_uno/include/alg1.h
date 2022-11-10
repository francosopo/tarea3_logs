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
 * partition
 * 
 * Particiona el arreglo asociado a la estructura Mediana
 * med con respecto al pivote pivot, modificándola, retornando 
 * donde quedó el pivot
 * 
 * @param med: La estructura Mediana
 * @param pivot: El pivot
*/
int partition(Mediana *med, int pivot);

/**
 * testPartition
 * 
 * prueba la particion
*/ 
void testPartition(void);

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