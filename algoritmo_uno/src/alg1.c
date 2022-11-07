#include <alg1.h>

int find_median_alg1(Mediana *med){
    return 1;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    int median = find_median_alg1(med);
    test("dummy_test", 1, median);
    destroyMedian(med);
}