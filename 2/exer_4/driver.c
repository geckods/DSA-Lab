/* driver.c */
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
int main(int argc, char *argv[])
{
	// Create a file pointer and open the file read as command line argument.
	FILE * fileptr = fopen(argv[1], "r");
	// Declare a pointer to a linked list (head) and allocate memory to it.
	struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
	// In a loop read the file and insert elements into the linkedList.
	while (!feof(fileptr))
	{
		// read the next element and store into the temp variable.
		int temp;
		fscanf(fileptr, "%d ", &temp);
		// insert temp into the linked list.
		insertFirst(head,temp);
	}
	// close the file pointer
	fclose(fileptr);
	// print the linked list.
	printList(head);
	// delete the first element of the linked list.
	printf("Deleted %d\n.",deleteFirst(head)->element);
	// print the linked list again to check if delete was successful.
	printList(head);
	// print the linked list to a new file.
	FILE * newfileptr = fopen(argv[2], "w");
	struct node* ptr = head->first;
	while(ptr!=NULL){
		fprintf(newfileptr,"%d\n", ptr->element);
		ptr = ptr->next;
	}
	fclose(newfileptr);
	
}
