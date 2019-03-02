#include <stdio.h>
#include <element.h>
#include <merge.h>

int main(){



//ALL THIS CODE IS FOR TESTING SORT
	Element arr[10];
	arr[0].cgpa =  9;
	arr[1].cgpa =  7;
	arr[2].cgpa =  8;
	arr[3].cgpa =  2;
	arr[4].cgpa =  1;
	arr[5].cgpa =  4;
	arr[6].cgpa =  3;
	arr[7].cgpa =  3;
	arr[8].cgpa =  2;
	arr[9].cgpa =  3;

//THIS SECTION IS FOR TESTING MERGE
	Element newarr[3];
	merge(arr,2,arr+2,1,newarr);

	for(int i=0;i<3;i++){
		printf("%lf ",newarr[i].cgpa);
	}
	putchar('\n');

	for(int i=0;i<10;i++){
		printf("%lf ",arr[i].cgpa);
	}
	putchar('\n');

	/*Comment out the not required one, based on what you're building*/
    mergeSort(arr,10);
//    mergeSortIter(arr, 10);

	for(int i=0;i<10;i++){
		printf("%lf ",arr[i].cgpa);
	}
	putchar('\n');

}