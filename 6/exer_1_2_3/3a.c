#include <element.h>
#include <merge.h>
#include <stdio.h>
#include <stdlib.h>

/*
repeat {
    read  K records from the input file into an array
    sort the array using MergeSort
    store the result in a new temporary file
} until (all elements in the input file are sorted);
K is the size of the array that can be allocated in memory */

/*COMPILE INSTRUCTIONS
	gcc 3a.c merge.c mergesortIter.c
*/

int main(int argc, char* argv[]){
	FILE* infile = fopen(argv[1],"r");
	FILE* outfile = fopen(argv[2],"w");

	printf("Enter k:\n");
	int k;
	scanf("%d",&k);

	Element arr[k];
	int done=0;

	while(1){
		for(int i=0;i<k;i++){
			if(feof(infile)){
				done=i;
				break;
			}
			fscanf(infile,"%[^,],%f",arr[i].name,&arr[i].cgpa);
		}

		if(done){
			k=done;
		}

		mergeSortIter(arr,k);
		for(int i=0;i<k;i++){
			fprintf(outfile,"%s,%f",arr[i].name,arr[i].cgpa);
		}

		if(done)break;
	}

	fclose(infile);
	fclose(outfile);
}