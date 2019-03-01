#include <../exer_1/employee.h>
#include <../exer_1/stack.h>
#include <../exer_1/quicksort.h>
#include <../exer_1/insertionsort.h>
#include <../exer_1/mixedsort.h>
#include <stdio.h>
/*
void mixedSort(Employee arr[], int n, int s){
	quickSort(arr,n,s);
	insertionSort(arr,n);
}
*/

/*COMPILATION COMMAND:
gcc main.c quicksort.c insertionsort.c stack.c mixedsort.c
*/

int main(){


//CODE FOR TESTING SORTS
	Employee arr[10];
	arr[0].empID = 9;
	arr[1].empID = 8;
	arr[2].empID = 6;
	arr[3].empID = 99;
	arr[4].empID = 5;
	arr[5].empID = 4;
	arr[6].empID = 3;
	arr[7].empID = 2;
	arr[8].empID = 1;
	arr[9].empID = 33;

	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
	putchar('\n');
//	mixedSort(arr,10,5);
//	quickSort(arr,10,0);
//	insertionSort(arr,10);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}
	putchar('\n');

}