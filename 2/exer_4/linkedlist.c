/* linkedlist.c */
#include "linkedlist.h"
void insertFirst(struct linkedList * head, int ele){
//create a node
	struct node *link = (struct node*) malloc (sizeof(struct node)); /* by this
	you are creating a node whose address is being stored in the link pointer. */
	link->element = ele;
	//point it to old first node
	link->next = head->first;
	//point first to new first node
	head -> first = link;
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

int search (struct linkedList * head, int ele){
	struct node* temp = head->first;
	while(temp!=NULL){
		if(temp->element==ele) return 1;
		temp = temp->next;
	}
	return 0;
}

struct node* delete(struct linkedList * head, int ele){/* deletes the first node in the list that contains the element = ele and retuns it. If the element is not found it returns an error message saying element not found. */
	struct node* prev = head->first;
	struct node* temp = head->first;
	
	while(temp!=NULL){
		if(temp->element==ele){
			head->count--;
			if(temp==head->first){
				head->first=temp->next;
				return temp;
			}
			else{
				prev->next=temp->next;
				return temp;
			}
		}
		prev=temp;
		temp = temp->next;
	}

	printf("Element not found!\n");
	return NULL;	
}

