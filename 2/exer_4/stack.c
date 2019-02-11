/*stack.c*/
#include <stack.h>
struct stack* createStack(){
	struct linkedList* ll = (struct linkedList*) malloc(sizeof(struct linkedList));
	struct stack* newStack = (struct stack*) malloc(sizeof(struct stack));
	newStack->list = ll;
	return newStack;
}

void push(struct stack* st,int ele){
	insertFirst(st->list,ele);
}

int pop(struct stack* st){
	if(st->list->count==0){
		return -1;
	}
	return deleteFirst(st->list)->element;
}
