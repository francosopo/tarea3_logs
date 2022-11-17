/// Aquí van todas las utilidades que ocuparán todos los algoritmos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/**
 * Estructura Array
 * 
 * Representa un array con su largo
 * 
 * @param len: Largo del array
 * @param arr: El arreglo
*/
typedef struct array{
    int len;
    double *arr;
}Array;

/**
 * Estructura Mediana
 * 
 * Representa una estructura para el problema de la mediana
 * 
 * @param med: La mediana del arreglo
 * @param a: El Array
*/
typedef struct mediana{
    int med;
    Array *arr;
}Mediana;

//Tiempo del algoritmo
typedef double (*tiempo_alg)();

//constructores y destructores

/**
 * newMedian 
 * 
 * Entrega una nueva estructura del problema
 * 
 * @param array_size: El tamaño del arreglo
*/
Mediana *newMedian(int array_size);

/**
 * Destruye una estructura del problema
 * 
 * @param med: La estructura mediana
*/
void destroyMedian(Mediana *med);

/**
 * newArray
 * 
 * Crea un array de largo len
 * 
 * @param len: El tamaño del arreglo
 * 
*/
Array *newArray(int len);

/**
 * destroyArray
 * 
 * Destruye la estructura Array
 * 
 * @param arr: La estructura Array
*/
void destroyArray(Array *arr);

/**
 * getFromArray 
 * 
 * Obtiene el index-ésimo elemento del array
 * 
 * @param a: El Array
 * @param index: El índice
*/
double getFromArray(Array *a, int index);

/**
 * setToArray
 * 
 * Cambia el valor del arreglo indicado por index 
 * a el valor newValue
 * 
 * @param a: El Array
 * @param index: El índice
 * @param newValue: El nuevo valor
*/
void setToArray(Array *a, int index, double newValue);

/**
 * getArraySize
 * 
 * Obtiene el tamaño del arreglo Arr
 * 
 * @param a: El Arreglo
*/
int getArraySize(Array *a);

/**
 * getMedianSize
 * 
 * Retorna el tamaño del arreglo correspondiente
 * a la estructura Mediana
*/
int getMedianSize(Mediana *med);

/**
 * getArray
 * 
 * Obtiene el arreglo que está dentro de med
*/
Array *getArray(Mediana *med);

/**
 * getFromMedian
 * 
 * Obtiene el index-ésimo elemento del arreglo 
 * correspondiente a la estructura Mediana
 * 
 * @param med: La estructura Mediana
 * @param index: El índice a consultar
*/
double getFromMedian(Mediana *med, int index);

/**
 * getMedian
 * 
 * Obtiene la mediana de un Mediana dentro de un 
 * sub intrevalo de indices. El arreglo dentro de
 * med debe estar ordenado previamente
 * 
 * @param med: Estructura Mediana
 * @param start_index: Índice del inicio
 * @param end_index: Índice del final
*/
double getMedian(Mediana *med, int start_index, int end_index){
    int median_size = end_index - start_index + 1;
    double median;
    // hay una cantidad par de elementos
    if(median_size % 2 == 0){
        median = (getFromMedian(med, median_size/2) + getFromMedian(med, median_size/2 + 1))/2;
    }else{
        median = getFromMedian(med, median_size/2);
    }
    return median;
}

/**
 * setToMedian
 * 
 * Cambia o establece el valor indicado por index en el 
 * arreglo a newValue de la estructura Mediana
 * 
 * @param med: La estructura Mediana
 * @param index: El índice del arreglo que se quiere cambiar
 * @param newValue: El nuevo valor al que se quiere actualizar
*/
void setToMedian(Mediana *med, int index, double newValue);

/**
 * swap
 * 
 * Intercambia dos valores
 * 
 * @param a: El primer valor
 * @param b: El segundo valor
*/
void swap(double *a, double *b);

/**
 * swapMedian
 * 
 * Intercambia dos valores de una estructura Mediana
 * med indicada por sus índices i y j
*/
void swapMedian(Mediana *med, int i, int j);

/**
 * swapArray
 * 
 * Intercambia dos valores de Array indicados por el índice
*/
void swapArray(Array *a, int i, int j);

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
int partition(Mediana *med, int index_pivot);

/**
 * partitionQuicksort
 * 
 * Particiona el arreglo arr mediante el pivot indicado
 * por el index_pivot
 * 
 * @param arr: El arreglo a particionar
 * @param index_pivot: El índice del pivote seleccionado
*/
int partitionQuicksort(Array *arr, int index_pivot, int index_start, int index_end);

/**
 * quicksortIndexes
 * 
 * Ordena el arreglo arr en el rango [index_start, index end]
 * 
 * @param arr: El arreglo a ordenar
 * @param index_start: El índice del inicio
 * @param index_end: El índice del final
*/
void quicksortIndexes(Array *arr, int index_start, int index_end);

/**
 * quicksort
 * 
 * Ejecuta quicksortIndexes en el rango del arreglo 0, arr->size - 1 
*/
void quicksort(Array *arr);

/**
 * testPartition
 * 
 * prueba la particion
*/ 
void testPartition(void);


/**
 * Test que prueba el correcto funcionamiento de median
*/
void testSetGetToMedian(void);

/**
 * test
 * 
 * funcion para probar funcionalidades
 * 
 * @param name: Nombre del test
 * @param expected: Lo que se espera
 * @param got: Lo que se obtuvo
*/
void test(char *name, int expected, int got);

/**
 * testSwap
 * 
 * Testea si swap funciona bien
*/
void testSwap(void);

/**
 * testSwapMedian
 * 
 * Testea si swapMedian funciona bien
*/
void testSwapMedian(void);

/**
 * test Sort
 * 
 * Comprueba que un arreglo esté ordenado
*/
void testSort(void);

/**
 * testAssertTrue
 * 
 * Prueba que el valor sea diferente de cero
 * 
 * @param value
*/
void testAssertTrue(int value);

// Función dummy
void holi();

