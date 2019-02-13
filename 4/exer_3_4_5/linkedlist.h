/* linkedlist.h */
/*Reusing Linked List implementation from Lab 2, exercise 4*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// structure definitions
// structure of a linked list node. It contains an element
struct node {
	int element;
	struct node * next;
};

/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */
struct linkedList {
	int count;
	struct node * first;
};

// function declarations
void* myalloc(int x);
void myfree(void* x);
struct linkedList* createList(int N);

struct linkedList * createCycle(struct linkedList * head);
void insertFirst (struct linkedList * head, int ele);
/* inserts a given element at the beginning of the list */

void insertLast (struct linkedList * head, int ele);
/* inserts a given element at the end of the list */

struct node * deleteFirst(struct linkedList * head);
/* deletes the first element of the list and returns pointer to the deleted
node. */

void printList (struct linkedList * head);
/* prints all the elements in the list */

struct node* search (struct linkedList * head, int ele);
/* searches for a given element in the linked list. Returns pointer if found, NULL otherwise. Only works on non-cyclic linkedlists */