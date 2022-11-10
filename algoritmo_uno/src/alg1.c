#include <alg1.h>

int find_median_alg1(Mediana *med){
    return 1;
}

Array *lesser_elements(Mediana *med, int index_pivot){
    int *ret_prev = calloc(getMedianSize(med), sizeof(int));
    if (ret_prev == NULL){
        perror("ret_prev");
    }
    int j_ret = 0;

    //obtener los elementos menores
    for(int i = 0; i < getMedianSize(med); i++){
        if(getFromMedian(med, i) < getFromMedian(med, index_pivot)){
            ret_prev[j_ret] = getFromMedian(med, i);
            j_ret++;
        }
    }
    //copiar el arreglo hasta el tamaño indicado por size
    int size = j_ret;
    Array *ret = newArray(size);
    for(int i = 0; i < size; i++){
        setToArray(ret, i, ret_prev[i]);
    }
    //librar el arreglo provisorio
    free(ret_prev);

    // retornar el arreglo limpio
    return ret;
}

Array *greater_elements(Mediana *med, int index_pivot){
    int *ret_prev = calloc(getMedianSize(med), sizeof(int));
    if (ret_prev == NULL){
        perror("ret_prev");
    }
    int j_ret = 0;

    // obtener los elementos mayores
    for (int i = 0; i < getMedianSize(med); i++){
        if(getFromMedian(med, i) > getFromMedian(med, index_pivot)){
            ret_prev[j_ret] = getFromMedian(med, i);
            j_ret++;
        }
    }

    //copiar el arreglo ret_prev hasta el tamaño indicado por size
    int size = j_ret;
    Array *ret = newArray(size);
    for(int i = 0; i< size; i++){
        setToArray(ret, i ,ret_prev[i]);
    }

    // liberar el arreglo provisorio
    free(ret_prev);

    //retornar el arreglo limpio
    return ret;
}

void test_lesser_elements(void){
    printf("\n TEST LESSER ELEMENTS\n");
    int array_size = 11;
    Mediana *med = newMedian(array_size);
    int pivot = 6;
    for(int i = 0; i < array_size; i++){
        int rnd = rand();
        setToMedian(med, i, rnd);
    }
    Array *lesser = lesser_elements(med, pivot);
    for(int i = 0; i< getArraySize(lesser); i++){
        testAssertTrue((getFromArray(lesser, i) < getFromMedian(med,pivot)));
    }

    destroyArray(lesser);
    destroyMedian(med);
    
}

void test_greater_elements(void){
    printf("\n TEST GREATER ELEMENTS\n");

    int array_size = 11;
    Mediana *med = newMedian(array_size);
    int pivot = 6;

    for(int i = 0; i < array_size; i++){
        int rnd = rand();
        setToMedian(med, i, rnd);
    }

    Array *greater = greater_elements(med, pivot);
    for(int i = 0; i< getArraySize(greater); i++){
        testAssertTrue((getFromArray(greater, i) > getFromMedian(med,pivot)));
    }

    destroyArray(greater);
    destroyMedian(med);
}

int main(int argc, char *argv[]){
    srand(time(NULL));
    test_lesser_elements();
    test_greater_elements();
    
}