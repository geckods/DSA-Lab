#include"node.h"
#include<stdio.h>
#include<stdlib.h>
extern int *Arr[N];
extern int Num_Elements[N];
void ConvertListstoArray(Locality *start)
{
	Locality* temp=start;
	Member* tempMem;
	int i=0;
	int j;
	while(temp){
		tempMem=temp->first;
		Num_Elements[i]=temp->count;
		Arr[i]=(int*)malloc(sizeof(int)*Num_Elements[i]);
	
		j=0;		
		while(tempMem){
			Arr[i][j++] = tempMem->id;
			tempMem=tempMem->next;
		}
		temp=temp->next;
		i++;
	}
 
}
