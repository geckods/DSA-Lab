#include <../exer_1/mixedsort.h>
void mixedSort(Employee arr[], int n, int s){
	quickSort(arr,n,s);
	insertionSort(arr,n);
}