#include <alg1.h>

double find_median_alg1(Mediana *med){
    return 1;
}

void test_find_median_alg1(void){
    
    // tamaño impar
    double a_impar[9] = {1,2,3,4,5,6,7,8,9};
    double b_impar[11] = {11,9,3,5,4,2,6,7,10,1,8};

    Array a_arr_impar = {9, a_impar};
    Array b_arr_impar = {11, b_impar};

    Mediana med_1 = {0, &a_arr_impar};
    Mediana med_2 = {0, &b_arr_impar};

    // Tamaño par
    //int c[10] = {10,15,13,16,12,17,19,18,11,14};
    testAssertTrue(abs(4 - find_median_alg1(&med_1)) < 0.00001);
    testAssertTrue(abs(6 - find_median_alg1(&med_2)) < 0.00001);
}

int main(int argc, char *argv[]){
    //testSetGetToMedian();
    //testSwap();
    srand(time(NULL));;
    //estSwap();
    //testSwapMedian();
    testPartition();
    //testSort();
}