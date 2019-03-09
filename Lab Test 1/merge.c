#include<stdio.h>
#include"node.h"
#include<stdlib.h>
extern int * Arr[N];
extern int Num_Elements[N];

void Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls)
{
	int i,j,k;
	i=j=k=0;
	
	while(i<sz1 && j<sz2){
		if(IsLower_GM(Ls1[i],Ls2[j])){
			Ls[k++]=Ls1[i++];
		}
		else{
			Ls[k++]=Ls2[j++];
		}
	}
	
	while(i<sz1)
		Ls[k++]=Ls1[i++];
		
	while(j<sz2)
		Ls[k++]=Ls2[j++];
		
}

int * Merge_Arr(){
	/*
	The idea is to merge the rows pairwise, taking care about extra rows
	i.e. from initial 50 row array (int* myArr[50]) merge to (int* myArr[25]) -> int* myArr[12] and so on, until only one array remains
	In each iteration, you merge every pair of rows

	There are much simpler ways of doing this, but this is just the one that popped into my head, that I was able to implement.
	*/
	int size=N;
	int newsize;
	
	int **myArr;
	int **prevArr=Arr;
	int *myCountArr;
	int *prevCountArr=Num_Elements;
	
	while(size>1){
//		printf("The Size is :%d.\n",size);
/*
		for(int i=0;i<size;i++){
			for(int j=0;j<prevCountArr[i];j++){
				printf(" %d %d ", prevArr[i][j]%10000, (prevArr[i][j]/10000)%1000);
			}
			putchar('\n');
		}
*/
		
		newsize=size/2;
		myArr=malloc(sizeof(int*)*newsize);
		myCountArr=malloc(sizeof(int)*newsize);
		
		for(int i=0;i<newsize;i++){
			myCountArr[i]=prevCountArr[2*i]+prevCountArr[2*i+1];
		}
		
		if(size%2==1){ //incase size has an extra row
			myCountArr[newsize-1]+=prevCountArr[size-1];
		}
		
		for(int i=0;i<newsize;i++){
			myArr[i]=malloc(sizeof(int)*myCountArr[i]);
		}
		
		for(int i=0;i<newsize-1;i++){
			Merge_GM(prevArr[2*i],prevCountArr[2*i],prevArr[2*i+1],prevCountArr[2*i+1],myArr[i]);
		}
		
		if(size%2==0){
			Merge_GM(prevArr[2*(newsize-1)],prevCountArr[2*(newsize-1)],prevArr[2*(newsize-1)+1],prevCountArr[2*(newsize-1)+1],myArr[(newsize-1)]);
		}
		else{//when there is an extra row, first merge the last two rows into a temp array, then merge that with the third last row to form the new array
			int tempArr[prevCountArr[size-1]+prevCountArr[size-2]];
			Merge_GM(prevArr[size-1],prevCountArr[size-1],prevArr[size-2],prevCountArr[size-2],tempArr);
			Merge_GM(prevArr[size-3],prevCountArr[size-3],tempArr,prevCountArr[size-1]+prevCountArr[size-2],myArr[newsize-1]);
		}
		
		prevArr = myArr;
		prevCountArr = myCountArr;
		size=newsize;
	}
	
	return myArr[0];
}

