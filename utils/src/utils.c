#include <utils.h>

Array *newArray(int len){
    double *arr = calloc(len, sizeof(double));
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

double getFromArray(Array *a, int index){
    return (a->arr)[index];
}

void setToArray(Array *a, int index, double newValue){
    a->arr[index] = newValue;
}

int getArraySize(Array *a){
    return a->len;
}

int getMedianSize(Mediana *med){
    return getArraySize(med->arr);
}

Array *getArray(Mediana *med){
    return med->arr;
}

double getFromMedian(Mediana *med, int index){
    return getFromArray(med->arr, index);
}

void setToMedian(Mediana *med, int index, double newValue){
    setToArray(med->arr, index, newValue);
}

void swap(double *a, double *b){
    double prov = *a;
    *a = *b;
    *b = prov;
}

void swapArray(Array *a, int i, int j){
    swap(&(a->arr[i]), &(a->arr[j]));
}

void swapMedian(Mediana *med, int i, int j){
    swapArray(med->arr, i,j);
}

int partition(Mediana *med, int index_pivot, int index_start, int index_end){
    int i=index_start, j = index_end;
    double pivot = getFromMedian(med, index_pivot);
    swapMedian(med, index_pivot, i);
    int where_is_pivot = i; // el pivote se deja en el inicio
    i++;
    double diferencia_permitida = 0.000001;
    while( i < j){
        if((getFromMedian(med, i) - pivot) > diferencia_permitida && (pivot - getFromMedian(med, j)) >= diferencia_permitida){
            swapMedian(med, i, j);
            i++;
            j--;
        }else if((pivot - getFromMedian(med, i)) >= diferencia_permitida && (pivot - getFromMedian(med, j)) >= diferencia_permitida){
            i++;
        }else if((getFromMedian(med, i) - pivot) > diferencia_permitida && (getFromMedian(med, j) - pivot) > diferencia_permitida){
            j--;
        }else{
            i++;
            j--;
        }
    }
    if(getFromMedian(med, j) - pivot >= diferencia_permitida){
        j--;
    }
    swapMedian(med, j, where_is_pivot);
    return j;
}

int partitionQuicksort(Array *arr, int index_pivot, int index_start, int index_end){
    int i=index_start, j = index_end;
    double pivot = getFromArray(arr, index_pivot);
    swapArray(arr, index_pivot,i);
    int where_is_pivot = i;
    i++;
    double diferencia_permitida = 0.00001;
    while( i < j){
        if(getFromArray(arr, i) - pivot > diferencia_permitida && pivot - getFromArray(arr, j) >= diferencia_permitida){
            swapArray(arr, i, j);
            i++;
            j--;
        }else if(pivot - getFromArray(arr, i) >= diferencia_permitida && pivot - getFromArray(arr, j) >= diferencia_permitida){
            i++;
        }else if(getFromArray(arr, i) - pivot > diferencia_permitida && getFromArray(arr, j) - pivot > diferencia_permitida){
            j--;
        }else{
            i++;
            j--;
        }
    }
    if(getFromArray(arr, j) - pivot >= diferencia_permitida ){
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

double promedios(Array *arr){
    double sum = 0;
    int size = getArraySize(arr);
    for(int i = 0; i < size; i++){
        sum += getFromArray(arr,i);
    }
    return sum/size;
}

int getIndex(Mediana *med, double value){
    int size = getMedianSize(med);
    int ret = -1;
    for(int i= 0; i < size; i++){
        if(fabs(getFromMedian(med, i) - value) < 0.00001){
            return i;
        }
    }
    return ret;
}

double my_max(double a, double b){
    return a > b ? a: b;
}
void testPartition(void){
    int median_size = 100;
    double tolerancia = 0.00001;

    // generar un tamaño válido > 0 
    while(median_size == 0){
        median_size = rand();
    }

    Mediana *med = newMedian(median_size);
    int index_pivot = (int) (((double)rand()/ (double)RAND_MAX) * (median_size - 1));

    // llenando el arreglo de Mediana
    for(int i = 0; i < median_size; i++){
        setToMedian(med,i,( (double) rand() / RAND_MAX));
    }

    int where_is_pivot = partition(med, index_pivot, 0, median_size - 1);

    //probando los menores
    printf("TESTING MENORES\n");
    for(int i = 0; i < where_is_pivot; i++){
        if((getFromMedian(med, where_is_pivot) - getFromMedian(med, i) > tolerancia) == 0){
            printf("from_median: %f, index %i\n", getFromMedian(med, i), i);
        }
        testAssertTrue(( getFromMedian(med, where_is_pivot) - getFromMedian(med, i) > tolerancia));
    }
    //printf("Index pivot: %i, valor: %f\n", where_is_pivot, getFromMedian(med, where_is_pivot));
    //probando los mayores
    printf("TESTING MAYORES\n");
    for(int i = where_is_pivot + 1; i < getMedianSize(med); i++){
        //printf("i: %i, val: %i, pivot %i\n", i, getFromMedian(med, i), getFromMedian(med, where_is_pivot));
        //printf("pivot: %f, from_median: %f\n", getFromMedian(med, where_is_pivot), getFromMedian(med, i));
        if( (( getFromMedian(med, i) - getFromMedian(med, where_is_pivot)) > tolerancia) == 0){
            printf("from_median: %f, index %i\n", getFromMedian(med, i), i);
        }
        testAssertTrue((getFromMedian(med, i) - getFromMedian(med, where_is_pivot) > tolerancia));
    }

    destroyMedian(med);
}

void testSetGetToMedian(void){
    int array_size = 10;
    double a[] = {1,2,3,4,5,6,7,8,9,10};
    double tolerancia = 0.00001;

    Mediana *med = newMedian(array_size);
    for(int i = 0; i < array_size; i++){
        setToMedian(med, i, a[i]);
    }

    for(int i = 0; i < array_size; i++){
        testAssertTrue( fabs(a[i] - getFromMedian(med,i)) < tolerancia);
    }
    printf("\n");

    destroyMedian(med);
}

void testSwap(void){
    double a = 9;
    double b = 10;
    int tolerancia = 0.00001;
    swap(&a, &b);
    testAssertTrue(fabs(10 - a) <= tolerancia); 
    testAssertTrue(fabs(9 - b) <= tolerancia);
}

void testSwapMedian(void){
    int size = 9;
    Mediana *med = newMedian(size);
    double tolerancia = 0.00001;
    //llenando med
    for(int i= 0; i < getMedianSize(med); i++){
        setToMedian(med, i, (double) i);
    }

    //cambiando los valores
    swapMedian(med, 0, size - 1);

    testAssertTrue(8 - getFromMedian(med, 0) < tolerancia);
    testAssertTrue( 0 - getFromMedian(med,size - 1) < tolerancia);
}

void testSort(void){
    int size = ((double) rand() /RAND_MAX) * 500;
    printf("Size: %i\n", size);

    int tolerancia = 0.00001;
    Array *arr = newArray(size);

    // llenando el arreglo arr
    for(int i = 0; i < size; i++){
        setToArray(arr, i, (double) rand());
    }

    quicksort(arr);

    // compobando que está ordenado
    for (int i = 0; i < size - 1; i++){
        testAssertTrue(getFromArray(arr, i + 1) - getFromArray(arr, i) > tolerancia);
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