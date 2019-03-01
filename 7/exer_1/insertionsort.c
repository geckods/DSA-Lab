#include <../exer_1/insertionsort.h>

void insertSorted(Employee arr[], int n, Employee newEmp){
	Employee curr = newEmp;
	Employee temp;
	for(int i=0;i<n;i++){
		if(curr.empID < arr[i].empID || i==n-1){
			temp = curr;
			curr = arr[i];
			arr[i]=temp;
		}
	}
}

void insertionSort(Employee arr[],int n){
	for(int i=0;i<n;i++){
		insertSorted(arr,i+1,arr[i]);
	}
}
