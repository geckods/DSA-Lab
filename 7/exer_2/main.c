#include <../exer_1/employee.h>
#include <../exer_1/stack.h>
#include <../exer_1/quicksort.h>
#include <../exer_1/insertionsort.h>
#include <../exer_1/mixedsort.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void testRun(Employee arr[], int n, double results[]){
	struct timeval t1, t2;
	double elapsedTime;

	//create a copy of the original array, since we're going to be sorting it twice

	Employee newarr[n];
	for(int i=0;i<n;i++)
		newarr[i]=arr[i];

	gettimeofday(&t1, NULL);

	quickSort(arr,n,0);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	results[0]=elapsedTime;

	gettimeofday(&t1, NULL);

	insertionSort(newarr,n);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	results[1]=elapsedTime;

}

int estimateCutoff(Employee arr[], int n){
	double results[2];

	Employee newarr[n];

	int min=0;
	int max=n;

	int mid=(min+max)/2;
	int prevmid = -1;

	double resultleft,resultcenter,resultright;

	while(mid!= prevmid){
		prevmid = mid;
		fflush(stdout);
		for(int i=0;i<(min+mid)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		// I assume that a plot of abs(IStime-QStime) will be U-shaped, with a well defined minumum
		testRun(newarr, (min+mid)/2, results);
		resultleft=fabs(results[0]-results[1]);
		
		for(int i=0;i<mid;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, mid, results);
		resultcenter=fabs(results[0]-results[1]);
		
		for(int i=0;i<(mid+max)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, (mid+max)/2, results);
		resultright=fabs(results[0]-results[1]);

		printf("mid is %d, %lf,%lf,%lf\n",mid,resultleft,resultcenter,resultright);

		if(resultcenter<=resultleft && resultcenter <= resultright){
			//We've found our minimum
			return mid;
		}
		else{
			if(resultleft<=resultcenter){
				max = mid; //go left
			}
			else{
				min = mid;
			}
		}
		mid = (min+max)/2;
	}
	return mid; //mid is equal to prevmid, so return mid
}

/*COMPILATION COMMAND:
gcc main.c ../exer_1/quicksort.c ../exer_1/insertionsort.c ../exer_1/stack.c ../exer_1/mixedsort.c

RUNNING COMMAND:
./a.out INPUTFILENAME OUTPUTFILENAME
*/

int main(int argc, char* argv[]){
	FILE* inputfile = fopen(argv[1],"r");

	int n=10;
	Employee* arr = malloc(sizeof(Employee)*n);

	int j=0;
	while(!feof(inputfile)){
		fscanf(inputfile,"%[^ ] %d\n",arr[j].name,&arr[j].empID);
//		printf("%d\n",arr[i].empID);
//		fflush(stdout);
		j++;
		if(j==n-1){
			n*=2;
			arr = realloc(arr, sizeof(Employee)*n);
		}
	}

//	printf("INPUT DONE");
//	fflush(stdout);

	//Note that this estimateCutoff function is currently very succeptible to noise and randomness. It doesn't deterministically return the same value each time.
	//It can be improved by taking the mean of multiple measurements, but that has not yet been implemented 
	int theCutoff = estimateCutoff(arr,j);
	printf("%d\n",theCutoff);

	fclose(inputfile);

	FILE* outputfile = fopen(argv[2],"w");

	struct timeval t1, t2;
	double elapsedTime;	

	gettimeofday(&t1, NULL);

	mixedSort(arr,j,theCutoff);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	fprintf(outputfile, "Time Taken to sort %d elements with mixedSort cutoff %d: %lf milliseconds.\n",j,theCutoff,elapsedTime);
	printf("Time Taken to sort %d elements with mixedSort cutoff %d: %lf milliseconds.\n",j,theCutoff,elapsedTime);

	for(int i=0;i<j;i++){
		fprintf(outputfile, "%s %d\n",arr[i].name,arr[i].empID);
	}

}