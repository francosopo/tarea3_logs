#include <alg2.h>
//Get median debe asume que el arreglo es impar ya que el c utilizado debe ser impar
double middleIndexPivot(double *arr){
    int lenght= len(arr);
    return arr[(lenght-1)/2];
}
//consigo c valores al azar del rango, ordeno el arreglo obtenido y saco el indice
//de la mediana.
int generate_random_pivot(Mediana *med, int c, int index_start, int index_end, int k){
    int size= index_end-index_start+1;
    Array *possible_pivots= newArray(c);
    for(int i =0; i<c;i++){
        setToArray(possible_pivots, i, med->arr->arr[index_start+rand()%size]);
    }
    quicksort(possible_pivots);
    double pivot= middleIndexPivot(possible_pivots->arr);
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
    int index_pivot = generate_random_pivot(med,c,k,index_start,index_end);
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

int main(int argc, char *argv[]){
    int medianSize = 30;
    //Mediana *med = newMedian(medianSize);
    //int median = find_median_alg2(med,5,0,len(med->arr),0);
    //test("dummy_test_2", 2, median);
    //destroyMedian(med);
    //destroyMedian(med);
}