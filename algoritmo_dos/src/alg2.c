#include <alg2.h>

int find_median_alg2(Mediana *med){
    return 2;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    for(int i = 0; i < medianSize; i++){
        (med->arr)[i] = i;
    }
    printf("%i\n", find_median_alg2(med));
    destroyMedian(med);
}