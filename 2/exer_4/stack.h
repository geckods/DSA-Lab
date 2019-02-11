/*stack.h*/
#include <linkedlist.h>

struct stack {
	struct linkedList* list;
};

struct stack* createStack();
void push(struct stack* st,int ele);
int pop(struct stack* st);

