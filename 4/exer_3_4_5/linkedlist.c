/* linkedlist.c */

#include "linkedlist.h"

void insertFirst(struct linkedList * head, int ele){
//create a node
	struct node *link = (struct node*) myalloc (sizeof(struct node)); /* by this
	you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;
	//point it to old first node
	link->next = head->first;
	//point first to new first node
	head -> first = link;
	head -> count ++;
}

void insertLast(struct linkedList * head, int ele){
//create a node
	struct node *link = (struct node*) myalloc (sizeof(struct node)); /* by this
	you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;

	struct node* traverse = head->first;
	if(traverse==NULL){
		head->first = link;
		return;
	}

	while(traverse->next != NULL){
		traverse = traverse->next;
	}

	traverse->next = link;

	head -> count ++;
}

//delete first item
struct node* deleteFirst(struct linkedList * head){
	struct node* temp = head->first;
	head->first = temp->next;
	head->count --;
	return temp;
	// exercise to implement this operation.
}

//display the list
void printList(struct linkedList* head){
	struct node *ptr = head->first;
	printf("\n[ ");
//start from the beginning
	while(ptr != NULL){
		printf("%d, ", ptr->element);
		ptr = ptr->next;
	}
	printf(" ]");
}

struct linkedList* createList(int N){
	struct linkedList* list = (struct linkedList*) myalloc(sizeof(struct linkedList));
	list->count = 0;
	list->first = NULL;
	int random;
	for(int i=0;i<N;i++){
//		printf("i:%d\n",i);
		random = rand();
		insertFirst(list, random);
	}
	return list;
}

struct linkedList * createCycle(struct linkedList * head){
	int random = rand();
	if(random>RAND_MAX/2){
		printf("NOT CYCLIC.\n");
		return head;//no change
	}
	else{
		printf("CYCLIC.\n");
		int arr[head->count];
		int i=0;
		struct node* traverse = head->first;
		while(traverse->next != NULL){
			arr[i]=traverse->element;
			i++;
			traverse=traverse->next;
		}//this puts everything in the array

		random = rand();
		double ratio = ((double)head->count)/RAND_MAX;
		random*=ratio;

		int tocycle = arr[random];
		struct node* tocyclenode = NULL;
		traverse = head->first;

		while(traverse->next != NULL){
			if(traverse->element == tocycle){
				tocyclenode = traverse;
			}
			traverse=traverse->next;
		}

		traverse->next = tocyclenode;
		return head;
	}
}



struct node* search (struct linkedList * head, int ele){
	struct node* traverse = head->first;
	while(traverse!=NULL){
		if(traverse->element==ele){
			return traverse;
		}
		traverse=traverse->next;
	}
	return traverse;
}

