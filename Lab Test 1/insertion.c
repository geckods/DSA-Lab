#include "node.h"
#include<stdio.h>

extern int * Arr[N];
extern int Num_Elements[N];

void InsertionSort_GM(int arr[], int n) 
{
	int i,j,key;
	for(int i=0;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&IsLower_GM(key,arr[j])){
//			printf("MADE A CHANGE\n");
 			arr[j+1]=arr[j];
 			j--;
 		}
 		arr[j+1]=key;
 	}
} 

void InsertionSort_Arr()
{
	for(int i=0;i<N;i++)
		InsertionSort_GM(Arr[i],Num_Elements[i]);

}


