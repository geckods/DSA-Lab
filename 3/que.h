#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

struct queue{
	Node* first;
	Node* last;
	int size;
};

typedef struct queue Queue;


Queue newQ(); // returns an empty Queue

bool isEmptyQ(Queue q); // tests whether q is empty

Queue delQ(Queue q); // deletes the element from the front of the Queue;returns the modified Queue

Node front(Queue q); // returns the element from the front of the Queue;

Queue addQ(Queue q , Node e); // adds e to the rear of the Queue; returns the modified Queue

int lengthQ(Queue q); // returns the length of the Queue

Node newNode(int data); //convenience function