#include <alg1.h>
int getMedianIndexFromArrayIndexes(Mediana *med, int index_start, int index_end){
    int size = index_end - index_start + 1;
    int ret;
    /*if(((size << 31) & (-1)) == 0){// el size es par
        double ret1 = getFromMedian(med, ( (index_start + size) / (2)));
        double ret2 = getFromMedian(med, ( (index_start + size) / (2)) + 1);
        ret = (ret1 + ret2) / 2;
    }else{ // el largo es impar
        ret = getFromMedian(med, (index_start + size) / (2));
    }*/
    // retorna como mediana el numero con el menor indice
    ret = index_start + (size - 1) / 2;
    return ret;
}
double find_median_alg1(Mediana *med, int c, int index_start, int index_end, int k, int *iteraciones){
    int size = index_end - index_start + 1;
    (*iteraciones)++;
    if(index_start >= index_end){
        return getFromMedian(med, index_end); // verificar que sea el index_end el que se retorna correctamente
    }
    int index_pivot = find_pivot(med, c, k, index_start, index_end);
    int my_med = partition(med, index_pivot, index_start, index_end);
    if(my_med == (k)){
        return getFromMedian(med, my_med);
    }else{
    // para escoger el indice del pivot se requiere saber si el 
    // tamaño es o no par
        if(size % 2 == 0){// el size es par
            if(my_med >= k ){
                // buscar el pivote en los menores a él
                return find_median_alg1(med, c, index_start, my_med, k, iteraciones);
            }else{
                return find_median_alg1(med, c, my_med, index_end, k, iteraciones);
            }
        }else{
            if(my_med >= k){
                return find_median_alg1(med, c, index_start, my_med, k, iteraciones);
            }else{
                return find_median_alg1(med, c, my_med, index_end, k, iteraciones);
            }
        }
    }
}


int find_pivot(Mediana *med, int c, int k, int index_start, int index_end){
    int size = index_end - index_start + 1;
    if(size == 1){
        return 0;
    }
  // c es impar
    // obtener los indices para cortar el arreglo 
    // dentro de med
    int indexes[size/c];

    // medians es el arreglo c
    Mediana *medians = newMedian(size/c);

    // obtenemos los indices para cortar el arreglo
    for(int i = 0; i < size/c; i++){
        indexes[i] = index_start + c * i;
    }
    
    indexes[c - 1] = index_start + size - 1;

    // ordenamos cada subarreglo
    for(int i = 0; i < size/c - 1; i++){
        quicksortIndexes(getArray(med),indexes[i], indexes[i + 1] - 1);
    }

    //obtenemos la mediana de cada subarreglo
    for(int i = 0; i < size/c - 1; i++){
        setToMedian(medians,i, getMedianIndexFromArrayIndexes(med, indexes[i], indexes[i + 1] - 1));
    }
    //ordenamos el arreglo C
    quicksort(getArray(medians));
    int ret = getMedianIndexFromArrayIndexes(medians, 0, size/c);
    //destroyMedian(medians);

    // retorna el índice menor de la mediana
    return index_start + c * ret + 1;
}

void test_find_median_alg1(void){
    
    // tamaño impar
    double a_impar[9] = {1,2,3,4,5,6,7,8,9};
    double b_impar[11] = {11,9,3,5,4,2,6,7,10,1,8};

    Array a_arr_impar = {9, a_impar};
    Array b_arr_impar = {11, b_impar};

    Mediana med_1 = {0, &a_arr_impar};
    Mediana med_2 = {0, &b_arr_impar};

    int iteraciones = 0; 
    // Tamaño par
    //int c[10] = {10,15,13,16,12,17,19,18,11,14};
    int c = 3;
    int expected_1 = 5;
    int got_1 = find_median_alg1(&med_1, c, 0, getMedianSize(&med_1) - 1, (getMedianSize(&med_1) - 1) / 2, &iteraciones);
    printf("Expected: %i, got %i\n", expected_1, got_1);
    testAssertTrue(abs(expected_1 - got_1) < 0.00001);

    int expected_2 = 6;
    int got_2 =  find_median_alg1(&med_2, c, 0, getMedianSize(&med_2) - 1, (getMedianSize(&med_2) - 1) / 2, &iteraciones);
    printf("Expected: %i, got %i\n", expected_2, got_2);
    testAssertTrue(abs(expected_2- got_2) < 0.00001);


    double a_par[8] = {5,10,15,20,25,30,35,40};
    Array a_arr_par = {8, a_par};
    Mediana med_3 = {0, &a_arr_par};

    double expected_3 = 20;
    double got_3 = find_median_alg1(&med_3,c, 0, getMedianSize(&med_3) - 1, (getMedianSize(&med_3) - 1 )/2, &iteraciones);
    printf("Expected: %f, got %f\n", expected_3, got_3);
    testAssertTrue(abs(expected_3 - got_3) < 0.00001);

    //double b_par[30]
}

void test_esfuerzo(void){
    int max_len = 500;
    double median = (rand() / RAND_MAX) * max_len;
    for (int i = 0; i < 100; i++){
        if((rand() << 31 & -1) == 0){
                        

        }
    }
    double median = rand();
    double vals[400];

    int index_median = rand()
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    //testSetGetToMedian();
    //testSwap();
    
    //testSwapMedian();
    //testPartition();
    //testSort();

    test_find_median_alg1();
}