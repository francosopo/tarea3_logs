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