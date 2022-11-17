#include <alg1.h>

int find_median_alg1(Mediana *med, int c){
    int size = getMedianSize(med);
    if(size == 1){
        return 0;
    }
    int index_pivot = find_pivot(med, c);
    int my_med = partition(med, index_pivot);
    if((size << 31) & (-1) == 0){// el size es par
        
    }
}

int find_pivot(Mediana *med, int c){
    int size = getMedianSize(med);
    if(size == 1){
        return 0;
    }
  // c es impar
    // obtener los indices para cortar el arreglo 
    // dentro de med
    int indexes[size/c];
    Mediana *medians = newMedian(c);

    // obtenemos los indices para cortar el arreglo
    for(int i = 0; i < c; i++){
        indexes[i] = c * i;
    }
    
    indexes[c - 1] = size - 1;

    // ordenamos cada subarreglo
    for(int i = 0; i < c - 1; i++){
        quicksortIndexes(getArray(med),indexes[i], indexes[i + 1] - 1);
    }

    for(int i = 0; i < c - 1; i++){
        setToMedian(medians,i, getMedian(med,indexes[i], indexes[i + 1] - 1));
    }

    int ret = find_median_alg1(medians,c);
    destroyMedian(medians);
    return ret;
}

void test_find_median_alg1(void){
    
    // tamaño impar
    double a_impar[9] = {1,2,3,4,5,6,7,8,9};
    double b_impar[11] = {11,9,3,5,4,2,6,7,10,1,8};

    Array a_arr_impar = {9, a_impar};
    Array b_arr_impar = {11, b_impar};

    Mediana med_1 = {0, &a_arr_impar};
    Mediana med_2 = {0, &b_arr_impar};

    // Tamaño par
    //int c[10] = {10,15,13,16,12,17,19,18,11,14};
    testAssertTrue(abs(4 - find_median_alg1(&med_1)) < 0.00001);
    testAssertTrue(abs(6 - find_median_alg1(&med_2)) < 0.00001);
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    //testSetGetToMedian();
    //testSwap();
    
    //testSwapMedian();
    //testPartition();
    //testSort();
}