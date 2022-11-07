#include <alg3.h>

int find_median_alg3(Mediana *med){
    return 3;
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    int median = find_median_alg3(med);
    test("dummy_test_3", 3, median);
    destroyMedian(med);
    holi();
}