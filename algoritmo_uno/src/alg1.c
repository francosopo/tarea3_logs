#include <alg1.h>
int getMedianIndexFromArrayIndexes(Mediana *med, int index_start, int index_end){
    int size = index_end - index_start + 1;
    int ret;
    /*if(((size << 31) & (-1)) == 0){// el size es par
        double ret1 = getFromMedian(med, ( (index_start + size) / (2)));
        double ret2 = getFromMedian(med, ( (index_start + size) / (2)) + 1);
        ret = (ret1 + ret2) / 2;
    }else{ // el largo es impar
        ret = getFromMedian(med, (index_start + size) / (2));
    }*/
    // retorna como mediana el numero con el menor indice
    ret = index_start + (size - 1) / 2;
    return ret;
}
int find_median_alg1(Mediana *med, int c, int index_start, int index_end, int k){
    int size = index_end - index_start + 1;
    if(index_start >= index_end){
        return index_end; // verificar que sea el index_end el que se retorna correctamente
    }

    if(size < c){
        quicksortIndexes(getArray(med), index_start, index_end);
        //if(((size << 31) & -1) ==0){ //size es par
        int idx = index_start + (size - 1)/2;
        return idx;
    }

    /*if (size < c){
        return index_start + size/2 - 1;
    }*/
    int index_pivot = find_pivot(med, c, k, index_start, index_end);
    int my_med = partition(med, index_pivot, index_start, index_end);
    if(my_med == (k)){
        return my_med;
    }else{
    // para escoger el indice del pivot se requiere saber si el 
    // tamaño es o no par
        if(size % 2 == 0){// el size es par
            if(my_med >= k ){
                // buscar el pivote en los menores a él
                return find_median_alg1(med, c, index_start, my_med, k);
            }else{
                return find_median_alg1(med, c, my_med, index_end, k);
            }
        }else{
            if(my_med >= k){
                return find_median_alg1(med, c, index_start, my_med, k);
            }else{
                return find_median_alg1(med, c, my_med, index_end, k);
            }
        }
    }
}


int find_pivot(Mediana *med, int c, int k, int index_start, int index_end){
    int size = index_end - index_start + 1;
    if(size == 1){
        return index_start;
    }
  // c es impar
    // obtener los indices para cortar el arreglo 
    // dentro de med
    int indexes[size/c + 1];

    // medians es el arreglo c
    Mediana *medians = newMedian(size/c);

    // obtenemos los indices para cortar el arreglo
    for(int i = 0; i < size/c; i++){
        indexes[i] = index_start + c * i;
    }
    
    indexes[size/c] = index_start + size - 1;

    // ordenamos cada subarreglo
    for(int i = 0; i < size/c - 1; i++){
        quicksortIndexes(getArray(med),indexes[i], indexes[i + 1] - 1);
    }

    //obtenemos la mediana de cada subarreglo
    for(int i = 0; i < size/c - 1; i++){
        setToMedian(medians,i, getMedianIndexFromArrayIndexes(med, indexes[i], indexes[i + 1] - 1));
    }
    int ret = find_median_alg1(medians, c, 0, size/c - 1, (size/c)/2);
    destroyMedian(medians);

    // retorna el índice menor de la mediana
    return index_start + c * ret + 1;
}

double median(Mediana *med, int c){
    int size = getMedianSize(med);
    int k = (size - 1)/2;
    if(((size << 31 ) & -1) == 0){
        int m = find_median_alg1(med, c, 0, size - 1, k);
        double menor = getFromMedian(med, m);
        for(int i = 0; i < size; i++){
            if(abs(getFromMedian(med, i) - menor) < 0.00001){
                setToMedian(med, i, DBL_MAX);
                break;
            }
        }
        int m2 = find_median_alg1(med, c, 0, size - 1,k);
        double mayor = getFromMedian(med, m2);
        return (menor + mayor) / 2;
    }else{
        return getFromMedian(med, find_median_alg1(med, c, 0, size - 1, k));
    }
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
    int c = 3;
    int expected_1 = 5;
    int got_1 = median(&med_1, c);
    testAssertTrue(abs(expected_1 - got_1) < 0.00001);

    int expected_2 = 6;
    int got_2 =  median(&med_2, c);
    testAssertTrue(abs(expected_2- got_2) < 0.00001);

    //double b_par[30]
}

void test_median_even(void){
    double a_par[8] = {5,10,15,20,25,30,35,40};
    Array a_arr_par = {8, a_par};
    Mediana med_3 = {0, &a_arr_par};
    int c = 5;

    double expected_3 = 22.5;
    double got_3 = median(&med_3,c);
    printf("Expected: %0.3f, got %0.3f\n", expected_3, got_3);
    testAssertTrue(abs(expected_3 - got_3) < 0.00001);

    double b_par[16]= {28,8,26,2,22,12,6,24,20,14,4,16,30,10,18,32};
    Array a ={16,b_par};
    Mediana med_4 = {0,&a};
    double expected_4 = 17.0;
    double got_4 = median(&med_4, c);
    printf("Expected: %0.3f, got %0.3f\n", expected_4, got_4);
    testAssertTrue(abs(expected_4 - got_4) < 0.00001);
}

void test_esfuerzo(void){
    int c = 9;
    for (int i = 0; i < 500; i++){
        int max_number = 501;
        double median_number = (rand() / RAND_MAX) * max_number;
        int max_size = 501;
        double vals[max_size];
        
        for (int i = 0; i < max_size / 2; i++){
            vals[i] = (rand() / RAND_MAX) * (median_number - 1);
            vals[i + max_size/2 + 1] = median_number + (rand()/RAND_MAX)* (median_number - 1);
        }

        vals[90] = median_number;
        
        Array a = {max_size,vals};
        Mediana med = {0, &a};
        double m = median(&med, c);
        testAssertTrue(abs(median_number - m) < 0.00001);
    }

    for (int i = 0; i < 500; i++){
        int max_number = 500;
        double median_number = (rand() / RAND_MAX) * max_number;
        int max_size = 500;
        double vals[max_size];
        
        for (int i = 0; i < max_size / 2; i++){
            vals[i] = (rand() / RAND_MAX) * (median_number - 1);
            vals[i + max_size/2 + 1] = median_number + (rand()/RAND_MAX)* (median_number - 1);
        }

        vals[90] = median_number;
        
        Array a = {max_size,vals};
        Mediana med = {0, &a};
        double m = median(&med, c);
        testAssertTrue(abs(median_number - m) < 0.00001);
    }

}

void generate_stats(void){
    int MAX_C_SIZE = 15;
    int MAX_VALUE = INT_MAX;
    int c[MAX_C_SIZE];
    for(int i = 0; i < MAX_C_SIZE; i++){
        c[i] = 2*(i + 1) + 1; // c es siempre impar
    }
    FILE *out = fopen("./alg1.csv", "w");
    if(out == NULL){
        perror("file:");
        exit(-1);
    }
    fprintf(out, "%s,%s,%s\n","max_size", "c", "time");
    // generando numeros aleatorios
    for (int r = 0; r <= 4; r++){ // i = 20 max
        int MAX_SIZE = 1 << (16 + r);
        Mediana *med = newMedian(MAX_SIZE);
        
        
        printf("\n [!] Generando los numeros para SIZE = %i\n", MAX_SIZE);
        for( int i = 0; i < MAX_SIZE; i++){
            setToMedian(med, i, (((double) rand()) / RAND_MAX) * MAX_VALUE);
        }
        for(int i = 0; i < MAX_C_SIZE; i++){
            printf("\n [!] Calculando estadisticas para c = %i\n", c[i]);
            Array *proms = newArray(MAX_C_SIZE);
            for (int k = 0; k < 50;k++){ // promedio para un solo c
                clock_t begin = clock();
                    median(med,c[i]);
                clock_t end = clock();
                double delta = ((double) (end - begin)) / CLOCKS_PER_SEC;
                setToArray(proms,i,delta);
            }

            // obtenido el promedio de ejecuciones para un solo c
            double prom = promedios(proms);
            fprintf(out, "%i,%i, %0.9f\n",MAX_SIZE, c[i], prom);
            destroyArray(proms);
        }
        fprintf(stdout, "Completado %0.2f\r", (((double) (r + 1))) /(4) * 100);
        destroyMedian(med);
    }
    fclose(out);
    
}

int main(int argc, char *argv[]){
    //srand(time(NULL));
    //testSetGetToMedian();
    //testSwap();
    
    //testSwapMedian();
    //testPartition();
    //testSort();

    //test_find_median_alg1();
    //test_median_even();

    //test_esfuerzo();
    generate_stats();
}