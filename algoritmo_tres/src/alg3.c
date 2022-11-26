#include <alg3.h>

int find_median_alg3(Mediana *arr, double epsilon, double alpha,double *prob_empirica, int *resp_index){
    
    double prob = 1 - epsilon;
    double exitos = 0;
    double total = 100;
    double prob_tentativa = exitos/ total;
    double size = (double) getMedianSize(arr);
    double mediana = 0;
    int index_pivot = 0;
    for (int c = 3; c < size; c= c + 2){
        int counter = 0;
        while(prob_tentativa < prob ){
            if(counter > total){
                break;
            }
            Mediana *aux = newMedian(c);

            // se obtienen los c indices al azar
            for(int i = 0; i < c; i++){
                int index = ((double) rand() / RAND_MAX) * (c - 1);
                setToMedian(aux, i, getFromMedian(arr, index));
            }

            quicksort(getArray(aux));
            mediana = getFromMedian(aux, c/2);
            
            // obtener el indice del pivote encontrado
            int idx = getIndex(arr,mediana);
            index_pivot = partition(arr, idx, 0, c - 1);
            if((1- alpha) * (size/2) < (double) index_pivot && (double) index_pivot < (1 + alpha) * (size/2)){
                printf("\n [!] Exito %0.3f\n", exitos);
                exitos += 1;
            }
            prob_tentativa = exitos / total;
            counter++;
            *resp_index = index_pivot;
            destroyMedian(aux);
        }
        if(prob_tentativa >= prob){
            *prob_empirica = prob_tentativa;
            *resp_index = index_pivot;
            printf("\n [!] c: %i\n", c);
            return c;
        }
    }
    *resp_index = index_pivot;
    *prob_empirica = prob_tentativa; 
    return mediana;
}

void test_esfuerzo(void){
    int MAX_VALUE = INT_MAX;
    int MAX_SIZE = 1000;
    int START = 500;
    double exitos = 0;
    double prob_empirica = 0;
    int index_pivot = 0;
    for (int j = START; j < MAX_SIZE; j++ ){
        printf("[!] Iteracion %i\n ", j - START);
        double mediana = ((double)rand()) /RAND_MAX * MAX_VALUE;
        Mediana *med = newMedian(j);
        for(int i = 0; i < j/2; i++){
            double value1 = ((double) rand()) / RAND_MAX * (mediana - 1);
            double value2 = mediana + ((double) rand()) / RAND_MAX * (mediana - 1);
            setToMedian(med, i,  value1);
            setToMedian(med, i + (j - 1) / 2, value2);
        }
        setToMedian(med, 300,mediana);
        if((find_median_alg3(med, 0.1,0.01, &prob_empirica, &index_pivot) - mediana) < 0.00001){
            exitos += 1;
            printf("\n [!] probabilidad empirica: %0.6f, index_pivot: %i\n", prob_empirica, index_pivot);
        }
        
    }
    printf("\n [!] Exitos: %0.3f\n", exitos/(MAX_SIZE - START));
}


int main(int argc, char *argv[]){
    test_esfuerzo();
}