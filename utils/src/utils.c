#include <utils.h>

Array *newArray(int len){
    int *arr = calloc(len, sizeof(int));
    if(arr == NULL){
        perror("arary not created");
        exit(-1);
    }
    Array *a = malloc(sizeof(Array));
    if(a == NULL){
        perror("Array struct not created");
    }
    a->arr = arr;
    a->len = len;

    return a;
}

void destroyArray(Array *arr){
    free(arr->arr);
    free(arr);
}

Mediana *newMedian(int array_size){
    Array *arr = newArray(array_size);
    Mediana *med = (Mediana*) malloc(sizeof(Mediana));
    if (med == NULL){
        perror("mediana struct");
        destroyArray(arr);
        exit(-1);
    }
    med -> arr = arr;
    med ->med = 0;

    return med;
}

void destroyMedian(Mediana *med){
    destroyArray(med->arr);
    free(med);
}

int getFromArray(Array *a, int index){
    return (a->arr)[index];
}

void setToArray(Array *a, int index, int newValue){
    a->arr[index] = newValue;
}

int getArraySize(Array *a){
    return a->len;
}

int getMedianSize(Mediana *med){
    return getArraySize(med->arr);
}

int getFromMedian(Mediana *med, int index){
    return getFromArray(med->arr, index);
}

void setToMedian(Mediana *med, int index, int newValue){
    setToArray(med->arr, index, newValue);
}

void swap(int *a, int *b){
    int prov = *a;
    *a = *b;
    *b = prov;
}

void swapArray(Array *a, int i, int j){
    swap(&(a->arr[i]), &(a->arr[j]));
}

void swapMedian(Mediana *med, int i, int j){
    swapArray(med->arr, i,j);
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

int partitionQuicksort(Array *arr, int index_pivot, int index_start, int index_end){
    int i=index_start, j = index_end;
    int pivot = getFromArray(arr, index_pivot);
    int where_is_pivot = index_pivot;
    while( i < j){
        if(getFromArray(arr, i) > pivot && getFromArray(arr, j) <= pivot){
            swapArray(arr, i, j);
            i++;
            j--;
        }else if(getFromArray(arr, i) <= pivot && getFromArray(arr, j) <= pivot){
            i++;
        }else if(getFromArray(arr, i) >pivot && getFromArray(arr, j) > pivot){
            j--;
        }else{
            i++;
            j--;
        }
    }
    if(getFromArray(arr, j) > pivot){
        j--;
    }
    swapArray(arr, j, where_is_pivot);
    return j;
}

void quicksortIndexes(Array *arr, int index_start, int index_end){
    if(index_start > index_end){
        return ;
    }
    int index = (int)( ( (double) rand() ) / ( RAND_MAX ) ) * ( index_end - index_start) + index_start;
    int index_pivot = partitionQuicksort(arr,index, index_start, index_end);
    quicksortIndexes(arr, index_start, index_pivot - 1);
    quicksortIndexes(arr, index_pivot + 1, index_end);
}

void quicksort(Array *arr){
    quicksortIndexes(arr, 0, getArraySize(arr) - 1);
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
    printf("TESTING MAYORES\n");
    for(int i = where_is_pivot + 1; i < getMedianSize(med); i++){
        //printf("i: %i, val: %i, pivot %i\n", i, getFromMedian(med, i), getFromMedian(med, where_is_pivot));
        testAssertTrue((getFromMedian(med, i) > getFromMedian(med, where_is_pivot)));
    }

    destroyMedian(med);
}

void testSetGetToMedian(void){
    int array_size = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};

    Mediana *med = newMedian(array_size);
    for(int i = 0; i < array_size; i++){
        setToMedian(med, i, a[i]);
    }

    for(int i = 0; i < array_size; i++){
        test("set get to median ", a[i], getFromMedian(med,i));
    }
    printf("\n");

    destroyMedian(med);
}

void testSwap(void){
    int a = 9;
    int b = 10;
    swap(&a, &b);
    test("Assert Equals Swap",10, a);
    test("Assert Equals Swap",9, b);
}

void testSwapMedian(void){
    int size = 9;
    Mediana *med = newMedian(size);
    //llenando med
    for(int i= 0; i < getMedianSize(med); i++){
        setToMedian(med, i, i);
    }

    //cambiando los valores
    swapMedian(med, 0, size - 1);

    test("Test swap median", 8, getFromMedian(med,0));
    test("Test swap median", 0, getFromMedian(med,size - 1));
}

void testSort(void){
    int size = ((double) rand() /RAND_MAX) * 500;
    printf("Size: %i\n", size);
    Array *arr = newArray(size);

    // llenando el arreglo arr
    for(int i = 0; i < size; i++){
        setToArray(arr, i, rand());
    }

    quicksort(arr);

    // compobando que está ordenado
    for (int i = 0; i < size - 1; i++){
        testAssertTrue(getFromArray(arr, i) < getFromArray(arr, i + 1));
    }
    printf("Test Ordenar pasado\n");
    destroyArray(arr);

}

void test(char *name, int expected, int got){
    if(expected != got) fprintf(stderr, "\nTest %s: Expected %i, got %i",name, expected, got);
    else printf("\nTest %s pasado", name);
}

void testAssertTrue(int value){
    if (value == 0) fprintf(stderr, "Expected != 0, got %i\n", value);
    //else printf("Test Assert True pasado\n");
}

void holi(){
    printf("\nHoli\n");
}