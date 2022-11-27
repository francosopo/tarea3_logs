#include <alg3.h>

int find_median_alg3(Mediana *arr, double epsilon, double alpha,double *prob_empirica, int *resp_index, int *ret_c){
    
    double prob = 1 - epsilon;
    double exitos = 0;
    double total = 1/epsilon;
    double prob_tentativa = exitos/ total;
    double size = (double) getMedianSize(arr);
    double mediana = getFromMedian(arr, 0);
    int index_pivot = 0;
    
    int start = size/2;
    if(((start << 31) & -1) == 0){ //start es par
        start++;
    }

    for (int c = start; c < size; c= c + 2){
        int counter = 0;
        while(prob_tentativa < prob ){
            if(counter > total){
                break;
            }
            Mediana *aux = newMedian(c);

            // se obtienen los c indices al azar
            for(int i = 0; i < c; i++){
                int index = (int) (((double) rand() / RAND_MAX) * (size - 1));
                setToMedian(aux, i, getFromMedian(arr, index));
            }

            quicksort(getArray(aux));
            mediana = getFromMedian(aux, c/2);
            
            // obtener el indice del pivote encontrado
            int idx = getIndex(arr,mediana);
            
            index_pivot = partition(arr, idx, 0, size - 1);
            if((1- alpha) * ((size - 1 )/2) < (double) index_pivot && (double) index_pivot < (1 + alpha) * ((size - 1)/2)){
                exitos += 1;
                prob_tentativa = exitos/total;
                *resp_index = index_pivot;
                *prob_empirica = prob_tentativa;
            }
            counter++;
            destroyMedian(aux);
        }
        if(prob_tentativa >= prob){
            prob_tentativa = exitos/total;
            *prob_empirica = prob_tentativa;
            *resp_index = index_pivot;
            //printf("\n [!] c: %i\n", c);
            *ret_c = c;
            return 0;
        }
    }
    *resp_index = index_pivot;
    *prob_empirica = prob_tentativa;
    *ret_c= -1;
    return 0;
}

void test_un_arreglo(void){
    int SIZE = 500;
    int MAX_VALUE = INT_MAX;
    Mediana *med = newMedian(SIZE);
    int c;

    double mediana_candidate = ((double)rand()) / RAND_MAX * MAX_VALUE;

    for(int i = 0; i < SIZE / 2; i++){
        setToMedian(med, i, ((double) rand() / RAND_MAX)* (mediana_candidate - 1));
        setToMedian(med, i + (SIZE - 1)/2, mediana_candidate + ((double)rand())/ RAND_MAX * ((mediana_candidate -1) /2));
    }
    setToMedian(med, 300, mediana_candidate);

    double mediana;
    int index_mediana;
    double prob_empirica;
    //double exito;
    double epsilon = 0.001;
    double alpha = 0.05;

    find_median_alg3(med, epsilon, alpha,&prob_empirica, &index_mediana, &c);
    mediana = getFromMedian(med, index_mediana);
    printf(" [!] index_mediana: %i, mediana_encontrada: %0.3f, mediana_candidate: %0.3f\n", index_mediana, mediana, mediana_candidate);
    printf(" [!] error: %0.3f, epsilon: %0.3f\n", fabs(mediana - mediana_candidate)/my_max(mediana, mediana_candidate), epsilon);

    if( fabs(mediana - mediana_candidate)/(my_max(mediana, mediana_candidate)) < epsilon){
        //exito = prob_empirica;
        printf("Mediana encontrada: %0.3f\n", mediana);
    }
    destroyMedian(med);
}

void test_esfuerzo(void){
    int MAX_VALUE = INT_MAX;
    int MAX_SIZE = 1000;
    int START = 500;
    double prob_empirica = 0;
    double prob = 0;
    int index_pivot = 0;
    double epsilon= 0.001;
    double alpha = 0.05;
    int c;

    for (int j = START; j < MAX_SIZE; j++ ){
        printf("\n [!] Iteracion %i\n ", j - START + 1);

        double mediana = ((double)rand()) /RAND_MAX * MAX_VALUE;
        Mediana *med = newMedian(j);

        for(int i = 0; i < j/2; i++){
            double value1 = ((double) rand()) / RAND_MAX * (mediana - 1);
            double value2 = mediana + ((double) rand()) / RAND_MAX * (mediana - 1);
            setToMedian(med, i,  value1);
            setToMedian(med, i + (j - 1) / 2, value2);
        }
        setToMedian(med, 300,mediana);
        find_median_alg3(med, epsilon, alpha, &prob, &index_pivot, &c);
        prob_empirica += prob;
    }
    printf("\n [!] prob_empirica: %0.3f\n", prob_empirica/(MAX_SIZE - START));
}

void generate_stats(void){
    int ITERACIONES = 20;
    int START = 1<< 16 ;
    int MAX_SIZE = 1<< 26;
    int MAX_VALUE = INT_MAX;
    double epsilon[ITERACIONES];
    double alpha[ITERACIONES];
    double prob_empirica;

    int index_pivot;
    for(int i = 0; i < ITERACIONES; i++){
        epsilon[i] = alpha[i] = ((double)(i + 1)) / (2*ITERACIONES);
    }

    FILE *out= fopen("./alg3.csv", "w");
    fprintf(out, "%s,%s,%s,%s,%s,%s\n", "epsilon", "alpha", "prob_empirica", "array_size","c", "time");

    for (int j = START; j < MAX_SIZE; j = j << 1){
        printf("\n [!] j = %0.3f\n", log2(j));
        double mediana = ((double)rand()) /RAND_MAX * MAX_VALUE;
        Mediana *med = newMedian(j);

        for(int i = 0; i < j/2; i++){
            double value1 = ((double) rand()) / RAND_MAX * (mediana - 1);
            double value2 = mediana + ((double) rand()) / RAND_MAX * (mediana - 1);
            setToMedian(med, i,  value1);
            setToMedian(med, i + (j - 1) / 2, value2);
        }
        setToMedian(med, 300,mediana);

        for(int k = 0; k < ITERACIONES; k++){
            for(int l = 0; l < ITERACIONES; l++){
                int c;
                clock_t begin = clock();
                find_median_alg3(med, epsilon[k], alpha[l],&prob_empirica, &index_pivot, &c);
                clock_t end = clock();
                double delta = end - begin / CLOCKS_PER_SEC;
                if(c != -1){
                    fprintf(out,"%0.6f, %0.6f, %0.6f, %i, %i, %0.6f\n", epsilon[k],alpha[l],prob_empirica,j, c, delta);
                    fflush(out);
                }
            }
        }
        destroyMedian(med);
        printf("Completado: %0.3f", log2(j) / log2(MAX_SIZE));
    }

    fclose(out);
}


int main(int argc, char *argv[]){
    srand(time(NULL));
    //test_esfuerzo();
    //test_un_arreglo();
    generate_stats();
}