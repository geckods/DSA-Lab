//2017A7PS1176P Abhinav Ramachandran
#include"node.h"
#include<stdio.h>
#include<stdlib.h>
Locality * ReadFileintoLists(char *filename)
{
	Locality* firstLocal = (Locality*) malloc(sizeof(Locality));
	firstLocal->count=0;
	firstLocal->first=NULL;
	firstLocal->next=NULL;
	
	//read N lines of the input file
	int x,temp;
	FILE* myFile = fopen(filename,"r");
	
	Locality* currLoc=firstLocal;
	Locality* newLoc;
	Member* lastMem;	//in order to get time complexity O(M*N), keep a temp variable pointing to the end of current linked list, so that insert operations are constant time
	
	for(int line=0;line<N;line++){
		if(line>0){
			newLoc = (Locality*)malloc(sizeof(Locality));
			currLoc->next = newLoc;
			currLoc=newLoc;
		}
		lastMem=NULL;
		fscanf(myFile,"%d",&x);
		fgetc(myFile);//remove comma from input buffer
		
		for(int i=0;i<x;i++){
			fscanf(myFile,"%d",&temp);
			fgetc(myFile);//remove comma from input buffer
			Member* newMem = (Member*)malloc(sizeof(Member));
			newMem->id=temp;
			newMem->next=NULL;
			if(lastMem==NULL){
				currLoc->first = newMem;
				currLoc->count++;
				lastMem=newMem;
			}
			else{
				currLoc->count++;
				lastMem->next=newMem;
				lastMem=newMem;
			}
		}
	}
	fclose(myFile);
	return firstLocal;	
}

void PrintLists (Locality *start)
{
	Locality* temp=start;
	Member* tempMem;
	int i=0;
	while(temp){
		printf("Linked List #%d, has %d elements.\n",++i,temp->count);
		tempMem=temp->first;
		while(tempMem){
			printf("%d ",tempMem->id);
			tempMem=tempMem->next;
		}
		temp=temp->next;
		putchar('\n');
	}
}
