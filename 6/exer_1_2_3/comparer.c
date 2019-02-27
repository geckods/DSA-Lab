#include <stdio.h>
#include <element.h>
#include <merge.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>


int main(){
	int N;
	printf("How many elements do you want to sort?\n");
	scanf("%d",&N);

	printf("Generating random element array.\n");

	Element recarr[N];
	Element iterarr[N];
	float myrand,myrand2;
	srand(time(0));
	for(int i=0;i<N;i++){
		myrand = rand();
		myrand2 = rand()/100000000;
		recarr[i].cgpa=myrand+myrand2;
		iterarr[i].cgpa=myrand+myrand2;
	}


	struct timeval t1, t2;
	double elapsedTime;
	iterspace=0;
	recspace=0;

	gettimeofday(&t1, NULL);
	mergeSortRec(recarr, 0,N-1);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Recursive mergeSorted %d elements in %lf milliseconds.\n",N,elapsedTime);
	printf("Space used by Recursive MergeSort: %d\n",recspace);

	gettimeofday(&t1, NULL);
	mergeSortIter(iterarr,N);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Iterative mergeSorted %d elements in %lf milliseconds.\n",N,elapsedTime);
	printf("Space used by Iterative MergeSort: %d\n",iterspace);
}