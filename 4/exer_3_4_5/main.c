#include <cycle.h>
#include <sys/time.h>

long long heapspace = 0;

void* myalloc(int x){
	heapspace+=x;
	int* asd = (int*)malloc(x+4);
	*asd = x;
	return (((void*)asd)+4);
}

void myfree(void* x){
	int* toread = (int*)(x-4);
	int size = *toread;
	heapspace-=size;
	free(toread);
}

int cycleLength(struct linkedList* list){
	struct node* hare = list->first;
	struct node* tort = list->first;

	int isCircular = 0;

	while(hare->next != NULL && hare->next->next !=NULL){
		tort = tort->next;
		hare = hare->next->next;
		if(tort==hare){
			break;
		}
	}

	int mu=0;
	tort = list->first;
	while(tort!=hare){
		tort = tort->next;
		hare = hare->next;
		mu++;
	}
	return mu;

}

struct linkedList* makeCircularList(struct linkedList* list){
	int isCyclic=testCyclic(list);
	if(isCyclic){
		//use hare and tort to find the start of the cycle
		int cyclestart = cycleLength(list);
		int i=0;
		struct node* traverse = list->first;
		struct node* prev = NULL;
		for(int i=0;i<cyclestart;i++){
			prev=traverse;
			traverse = traverse->next;
			myfree(prev);
		}
		list->first = traverse;
		list->count-=cyclestart;
		return list;
	}
	else{
		struct node* traverse = list->first;
		while(traverse->next != NULL){
			traverse = traverse->next;
		}
		traverse->next = list->first;
		return list;
	}
}

int main(){
	srand(time(0));
	int N=1000000;
	struct linkedList* list = createList(N);

	FILE* fp = fopen("heap.txt","w");
	fprintf(fp,"Heap used before makecircular is %lld.\n",heapspace);
	fclose(fp);

	list = createCycle(list);


	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);

	int isCyclic = testCyclic(list);

	gettimeofday(&t2, NULL);
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for detection of cyclic is %f ms.\n",elapsedTime);

	if(isCyclic){
		printf("Detected Cyclic.\n");
	}
	else{
		printf("Detected Linear.\n");
	}




	list = makeCircularList(list);

	fp = fopen("heap.txt","a");
	fprintf(fp,"Heap used after makecircular is %lld.\n",heapspace);
	fclose(fp);

}