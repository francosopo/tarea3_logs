#include <alg1.h>

int find_median(int *a){
    return 0;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    for(int i = 0; i < medianSize; i++){
        (med->arr)[i] = i;
    }
    printf("%i\n", find_median(med->arr));
    destroyMedian(med);
}