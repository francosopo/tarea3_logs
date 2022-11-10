#include <alg1.h>

int find_median_alg1(Mediana *med){
    return 1;
}



int partition(Mediana *med, int index_pivot){
    int i=0, j = getMedianSize(med) - 1;
    int pivot = getFromMedian(med, index_pivot);
    int where_is_pivot = index_pivot;
    while( i < j){
        if(getFromMedian(med, i) > pivot && getFromMedian(med, j) <= pivot){
            swapMedian(med, i, j);
            i++;
            j--;
        }else if(getFromMedian(med, i) <= pivot && getFromMedian(med, j) <= pivot){
            i++;
        }else if(getFromMedian(med, i) >pivot && getFromMedian(med, j) > pivot){
            j--;
        }else{
            i++;
            j--;
        }
    }
    if(getFromMedian(med, j) > pivot){
        j--;
    }
    swapMedian(med, j, where_is_pivot);
    return j;
}

void testPartition(void){
    int median_size = 100;

    // generar un tamaño válido > 0 
    while(median_size == 0){
        median_size = rand();
    }

    Mediana *med = newMedian(median_size);
    int index_pivot = (int) ((double)rand()/ (double)RAND_MAX) * (median_size - 1);

    // llenando el arreglo de Mediana
    for(int i = 0; i < median_size; i++){
        setToMedian(med,i,rand());
    }

    int where_is_pivot = partition(med, index_pivot);

    //probando los menores
    printf("TESTING MENORES\n");
    for(int i = 0; i <= where_is_pivot; i++){
        testAssertTrue((getFromMedian(med, i) <= getFromMedian(med, where_is_pivot)));
    }

    //probando los mayores
    printf("TESTING MAYORES, index_pivot: %i\n", where_is_pivot);
    for(int i = where_is_pivot + 1; i < getMedianSize(med); i++){
        //printf("i: %i, val: %i, pivot %i\n", i, getFromMedian(med, i), getFromMedian(med, where_is_pivot));
        testAssertTrue((getFromMedian(med, i) > getFromMedian(med, where_is_pivot)));
    }

    destroyMedian(med);
}

int main(int argc, char *argv[]){
    //testSwap();
    srand(time(NULL));
    //test_lesser_elements();
    //test_greater_elements();
    //testSwap();
    //testSwapMedian();
    testPartition();
}