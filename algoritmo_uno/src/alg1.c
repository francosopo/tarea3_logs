#include <alg1.h>

int find_median_alg1(Mediana *med){
    return 1;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    for(int i = 0; i < medianSize; i++){
        (med->arr)[i] = i;
    }
    printf("%i\n", find_median_alg1(med));
    destroyMedian(med);
}