#include <utils.h>

Mediana *newMedian(int array_size){
    int *a = (int *) calloc(array_size, sizeof(Mediana)); 
    if( a == NULL){
        perror("array_mediana");
        exit(-1);
    }
    Mediana *med = (Mediana*) malloc(sizeof(Mediana));
    if (med == NULL){
        perror("mediana struct");
        free(a);
        exit(-1);
    }
    med -> arr = a;
    med ->med = 0;

    return med;
}
void destroyMedian(Mediana *med){
    free(med->arr);
    free(med);
}