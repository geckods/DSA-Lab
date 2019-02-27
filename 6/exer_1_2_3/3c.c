#include <element.h>
#include <merge.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
repeat {
    read  K records from the input file into an array
    sort the array using MergeSort
    store the result in a new temporary file
} until (all elements in the input file are sorted);
K is the size of the array that can be allocated in memory */

/*COMPILE INSTRUCTIONS
	gcc 3c.c merge.c mergesortIter.c
*/

/*Run instructions
	./a.out (DATA_FILENAME)
*/

/*
Note that the program currently does not work with values of k that are not factors of the number of elements
*/


void mergeFiles(char* infile1name, char* infile2name, char* outfilename){
	FILE* infile1 = fopen(infile1name,"r");
	FILE* infile2 = fopen(infile2name,"r");
	FILE* outfile = fopen(outfilename,"w");

	Element a;
	Element b;

	fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);
	fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);

	while(!feof(infile1) && !feof(infile2)){
		
		if(a.name[0]=='\n'){
			strcpy(a.name,a.name+1);
		}
		if(b.name[0]=='\n'){
			strcpy(b.name,b.name+1);
		}

		if(a.cgpa<b.cgpa){
			fprintf(outfile,"%s,%f\n",a.name,a.cgpa);
			fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);
		}
		else{
			fprintf(outfile,"%s,%f\n",b.name,b.cgpa);
			fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);
		}
	}

	if(feof(infile1)){
		while(!feof(infile2)){
			fprintf(outfile,"%s,%f\n",b.name,b.cgpa);
			fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);	
			if(b.name[0]=='\n'){
				strcpy(b.name,b.name+1);
			}
		}
	}

	if(feof(infile2)){
		while(!feof(infile1)){
			fprintf(outfile,"%s,%f\n",a.name,a.cgpa);
			fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);	
			if(a.name[0]=='\n'){
				strcpy(a.name,a.name+1);
			}
		}
	}

	fclose(infile1);
	fclose(infile2);
	fclose(outfile);
}

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char* argv[]){
	FILE* infile = fopen(argv[1],"r");

	printf("Enter k:\n");
	int k;
	scanf("%d",&k);

	Element arr[k];
	int done=0;

	char filename[1000];

	int j;

	for(j=0;;j++){
		sprintf(filename,"data:%d_%d.txt",j,j);
		FILE* outfile = fopen(filename,"w");
		for(int i=0;i<k;i++){
			if(feof(infile)){
				done=i;
				break;
			}
			fscanf(infile,"%[^,],%f",arr[i].name,&arr[i].cgpa);
//			getchar();
			if(arr[i].name[0]=='\n'){
				strcpy(arr[i].name,arr[i].name+1);
			}
		}

		if(done){
			k=done;
		}

		mergeSortIter(arr,k);
		for(int i=0;i<k;i++){
			fprintf(outfile,"%s,%f\n",arr[i].name,arr[i].cgpa);
		}

		fclose(outfile);
		if(done)break;
	}
	fclose(infile);

	int mid,right;
	char filea[1000],fileb[1000],filec[1000];
	for(int curr_size=1;curr_size<j;curr_size*=2){
		for(int start=0;start<j;start+=2*curr_size){
			mid = min(start+curr_size-1,j-1);
			right = min(start+2*curr_size-1,j-1);
			sprintf(filea,"data:%d_%d.txt",start,mid);
			sprintf(fileb,"data:%d_%d.txt",mid+1,right);
			sprintf(filec,"data:%d_%d.txt",start,right);
			if(!(exists(filea)&&exists(fileb))) continue;
			printf("%d %d %d %s %s %s\n",curr_size,start,mid,filea,fileb,filec);
			fflush(stdout);
			mergeFiles(filea,fileb,filec);
			remove(filea);
			remove(fileb);
		}
	}


}