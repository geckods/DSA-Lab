/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	
	struct stack * st = createStack();
	while (!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);
		push(st,temp);
	}
	// close the file pointer
	fclose(fileptr);

	int temp;
	while((temp=pop(st))!=-1){
		printf("%d\n",temp);
	}
	
}
