/// Aquí van todas las utilidades que ocuparán todos los algoritmos

#include <stdio.h>
#include <stdlib.h>

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
    int *arr;
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
int getFromArray(Array *a, int index);

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
void setToArray(Array *a, int index, int newValue);

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
 * getFromMedian
 * 
 * Obtiene el index-ésimo elemento del arreglo 
 * correspondiente a la estructura Mediana
 * 
 * @param med: La estructura Mediana
 * @param index: El índice a consultar
*/
int getFromMedian(Mediana *med, int index);

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
void setToMedian(Mediana *med, int index, int newValue);


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

// Función dummy
void holi();

