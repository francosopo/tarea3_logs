#include <alg2.h>
//Get median debe asume que el arreglo es impar ya que el c utilizado debe ser impar
double middleIndexPivot(double *arr, int c){
    int lenght= c;
    return arr[(lenght-1)/2];
}
//consigo c valores al azar del rango, ordeno el arreglo obtenido y saco el indice
//de la mediana.
int generate_random_pivot(Mediana *med, int c, int index_start, int index_end, int k){
    int size= index_end-index_start+1;
    Array *possible_pivots= newArray(c);
    for(int i =0; i<c;i++){
        double random = ((double) rand())/RAND_MAX * (index_end - index_start) + index_start;
        setToArray(possible_pivots, i, med->arr->arr[(long long)random]);
    }
    quicksort(possible_pivots);
    double pivot= middleIndexPivot(possible_pivots->arr, c);
    destroyArray(possible_pivots);
    return getIndex(med,pivot);
}

//algoritmo para obtener 
int find_median_alg2(Mediana *med,int c,int index_start, int index_end, int k){
    int size= index_end-index_start+1;
    if (index_start >= index_end){
        return index_end;
    }

    if(size < c){
        quicksortIndexes(getArray(med),index_start,index_end);
        int idx= index_start+(size-1)/2;
        return idx;
    }
    int index_pivot = generate_random_pivot(med,c,index_start,index_end,k);
    int P= partition(med,index_pivot,index_start,index_end);
    if(P==(k)){
        return P;
    }else{
        if(P >=k){
            return find_median_alg2(med, c, index_start,P,k);
        }
        else{
            return find_median_alg2(med,c,P,index_end,k);
        }

    }
    return 2; 
}

double median(Mediana *med, int c){
    int size=getMedianSize(med);
    int k= (size-1)/2;
    if (((size << 31)& -1)==0){
        int m= find_median_alg2(med,c,0,size-1,k);
        double menor= getFromMedian(med,m);
        for(int i =0; i<size;i++){
            if(abs(getFromMedian(med, i)-menor)<0.0001){
                setToMedian(med,i,DBL_MAX);
                break;
            }
        }
        int m2= find_median_alg2(med,c,0,size-1,k);
        double mayor=getFromMedian(med,m2);
        return (menor+mayor)/2;
    }else{
        return getFromMedian(med,find_median_alg2(med,c,0,size-1,k));
    } 

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
    FILE *out = fopen("./alg2.csv", "w");
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
    //test_esfuerzo();
    generate_stats();
}