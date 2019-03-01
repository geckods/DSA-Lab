#include <../exer_1/employee.h>

#ifndef STACK_H
#define STACK_H

struct int_pair_node{
	int l;
	int r;
	struct int_pair_node* next;
};

typedef struct int_pair_node IntPairNode;

typedef struct {
	IntPairNode* top;
	int size;
} IntPairStack;

IntPairStack* newStack();
void push(IntPairStack* stack, int a, int b);
IntPairNode pop(IntPairStack* stack);
#endif