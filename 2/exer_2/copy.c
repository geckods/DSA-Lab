#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	if(argc!=3){
		printf("Encountered incorrect number of arguments. Terminating.\n");
		exit(0);
	}
	
	char* source = argv[1];
	char* destination = argv[2];
	
	FILE *srcptr;
	srcptr = fopen(source,"r");
	if (srcptr == NULL){
		printf("Error opening file for reading");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	
	FILE *dstptr;
	dstptr = fopen(destination,"w");
	if (dstptr == NULL){
		printf("Error opening file for writing");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	
	char line[1000];
	while(fscanf(srcptr,"%[^\n]",line) != EOF){
		fgetc(srcptr);
		fprintf(dstptr,"%s\n",line);
	}
}

