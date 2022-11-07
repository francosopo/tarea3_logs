#include <alg3.h>

int find_median_alg3(Mediana *med){
    return 3;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    for(int i = 0; i < medianSize; i++){
        (med->arr)[i] = i;
    }
    printf("%i\n", find_median_alg3(med));
    destroyMedian(med);
}