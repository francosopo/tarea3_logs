#include <alg2.h>


int generate_random_pivot(Mediana *med, int c, int index_start, int index_end, int k){
    double possible_pivots[c];
    int size= index_end-index_start+1;
    for(int i =0; i<c;i++){
        possible_pivots[i]= med->arr[index_start+rand()%size];
    }
    quicksort(possible_pivots);
    
}
//algoritmo para obtener 
int find_median_alg2(Mediana *med,int c,int index_start, int index_end, int k){
    int size= index_end-index_start+1;
    if (index_start >= index_end){
        return index_end;
    }
    int index_pivot = generate_random_pivot(med,c,k,index_start,index_end);
    int P= partition(med,index_pivot,index_start,index_end);
    
    return 2; 
}

int main(int argc, char *argv[]){
    int medianSize = 30;
    Mediana *med = newMedian(medianSize);
    int median = find_median_alg2(med,0,len(med->arr),0);
    test("dummy_test_2", 2, median);
    destroyMedian(med);
    destroyMedian(med);
}