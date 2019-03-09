#ifndef _NODE_H_
#define _NODE_H_
#define N 50  // N Denotes number of records in input file 
#define M 15  // M indicates maxiumum entries in any row in input file
typedef struct node1 Member;
typedef struct node2 Locality;
typedef enum { FALSE, TRUE} BOOL;
int * Arr[N];
int Num_Elements[N];
struct node1
{
  int id;
  Member * next;
};

struct node2
{
  int count;
  Member *first;
  Locality *next;
};

void PrintLists(Locality * start); // Prints all members in all localities where start points to the first locality

//Read from input file filename into lists 
Locality * ReadFileintoLists(char *filename);

//Convert from list to array by populating the Arr
void ConvertListstoArray(Locality * masterlist); 
 

//Returns TRUE if id1 is "lesser" than id2 based on group number followed by member number
BOOL IsLower_GM( int id1, int id2);

//Applies InsertionSort on a given row  by  sorting on the fields group number followed by member number
void InsertionSort_GM(int * row, int size);

// Invokes InsertionSort_GM for every row of Arr
void InsertionSort_Arr();

// Merges two arrays arr1 and arr2 sorted by Group number and member number
//void Merge_GM(int * arr1, int * arr2, int * result);
void Merge_GM(int *Ls1, int sz1, int * Ls2, int sz2, int* Ls);

//Invokes Merge_GM for merging all rows of Arr
int * Merge_Arr();

#endif
