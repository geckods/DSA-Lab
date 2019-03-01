#include <../exer_1/quicksort.h>
#include <stdio.h>

void swap(Employee* a, Employee* b){
	Employee temp = *a;
	*a=*b;
	*b=temp;
}

int partition(Employee arr[], int l, int r){
	int x = arr[r].empID;
	int i = l-1;
	for(int j=l;j<r;j++){
		if(arr[j].empID<=x){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[++i],&arr[r]);
	return i;
}

void quickSort(Employee arr[], int n, int s){
	IntPairStack* myStack = newStack();
	IntPairNode temp;
	int l,r,next;
	push(myStack,0,n-1);

	while(myStack->size > 0){
		temp = pop(myStack);
		l = temp.l;
		r = temp.r;
		if(r-l>s/*l<r*/){
			next = partition(arr,l,r);
			push(myStack,l,next-1);
			push(myStack,next+1,r);
		}
//		printf("stack:%d l:%d r:%d\n",myStack->size,l,r);
	}
}