#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

long long heapspace = 0;

void* myalloc(int x){
	heapspace+=x;
	int* asd = malloc(x+4);
	*asd = x;
	return (((void*)asd)+4);
}

void myfree(void* x){
	int* toread = (int*)(x-4);
	int size = *toread;
	heapspace-=size;
	free(toread);
}

int main(){
	srand(time(0));

	int random;
	int *data;
	double ratio=15000.0/RAND_MAX;
	while(1){
		random = rand()*ratio;
		random+=10000;
//		printf("random is %d.\n",random);
		data = myalloc(sizeof(int)*random);
		printf("First address:%p, Last address:%p, Heapspace is %lld\n",data,data+random,heapspace);

		//If you comment out the following line, the program will run untill the RAM and the SWAP memory are completely filled, then terminate.
		//Otherwise, it just allocates the same location each time.		
//		myfree(data);
	}
}