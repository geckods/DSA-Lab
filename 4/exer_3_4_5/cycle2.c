#include <cycle.h>

int testCyclic(struct linkedList* list){
	struct node* traverse = list->first;
	if(traverse==NULL) return 0;

	struct node* previous = list->first;
	struct node* prevprev = NULL;	

	while(traverse->next != NULL){
		if(previous!=list->first)
			previous->next = prevprev;
		prevprev = previous;
		previous = traverse;
		traverse = traverse->next;
		if(traverse==list->first){
			return 1;
		}
	}
	return 0;
}