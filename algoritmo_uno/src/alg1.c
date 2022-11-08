#include <alg1.h>

int find_median_alg1(Mediana *med){
    return 1;
}

int *lesser_elements(Mediana *med, int index_pivot){
    int *ret_prev = calloc(getMedianSize(med), sizeof(int));
    int j_ret = 0;
    for(int i = 0; i < getMedianSize(med); i++){
        if(getFromMedian(med, i) < getFromMedian(med, index_pivot)){
            ret_prev[j_ret] = getFromMedian(med, i);
            j_ret++;
        }
    }
    //copiar el arreglo hasta el tamaño indicado por size
    int size = j_ret + 1;
    int *ret = calloc(size, sizeof(int));
    for(int i = 0; i < size; i++){
        ret[i] = ret_prev[i];
    }
    //librar el arreglo provisorio
    free(ret_prev);

    // retornar el arreglo limpio
    return ret;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);

    testSetGetToMedian();

    destroyMedian(med);
}