#include <alg2.h>

int find_median_alg2(Mediana *med){
    return 2;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    int median = find_median_alg2(med);
    test("dummy_test_2", 2, median);
    destroyMedian(med);
    destroyMedian(med);
}