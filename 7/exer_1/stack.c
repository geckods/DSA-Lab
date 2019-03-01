#include <../exer_1/stack.h>
#include <stdlib.h>

IntPairStack* newStack(){
	IntPairStack* stack = (IntPairStack*)malloc(sizeof(IntPairStack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void push(IntPairStack* stack, int a, int b){
	IntPairNode* newNodePointer = (IntPairNode*)malloc(sizeof(IntPairNode));
	newNodePointer->l = a;
	newNodePointer->r = b;

	newNodePointer->next = stack->top;
	stack->top=newNodePointer;
	stack->size++;
}

IntPairNode pop(IntPairStack* stack){
	IntPairNode newNode;
	if(stack->size==0){
		newNode.l = -1;
		newNode.r = -1;
		newNode.next = NULL;
		return newNode;
	}

	newNode=*(stack->top);
	stack->top = (stack->top)->next;
	(stack->size)--;
	return newNode;
}