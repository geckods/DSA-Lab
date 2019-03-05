#include "List.h"

void printList(List list)
{
	Node temp = list->first;
	while(temp!=NULL)
	{
		printf("Name: %s, Marks: %f\n", temp->record->name, temp->record->marks);
		temp=temp->next;
	}

	return;
}

char *randstring(int length) 
{    
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyz";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    // randomString = malloc(sizeof(char) * (length +1));
    randomString = myalloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;
        int n = 0;
        for (n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;        
    }
    else {
        printf("No memory");
        exit(1);
    }
}

float randfloat(int i)
{
    float a = 20;
    float new;
    new = ((float)rand()/(float)(RAND_MAX)) * a;
    
    return new;
}


Student generateData(int arraySize)
{
	// Student studentArray = (Student) malloc(sizeof(struct student)*arraySize);
	Student studentArray = (Student) myalloc(sizeof(struct student)*arraySize);
	int i = 0;

	srand((unsigned int)time(NULL));
	
	for(i=0;i<arraySize;i++)
	{		
		studentArray[i].name = randstring(10);
		studentArray[i].marks = randfloat(i);

	}	

	return studentArray;
}


/*Compile instructions:
gcc main.c List.c
Run instructions:
./a.out
*/

int main()
{
	globalCounter = 0;

	// Randomly generates student records=arraySize
	int arraySize = 10;
	Student studArray = generateData(arraySize);

	// measuring heap memory
	printf("Heap size is %d bytes\n", globalCounter);

	// create a list using the array.
	List list1 = createList(studArray, arraySize);

	// printing the list
	printList(list1);

	// measuring heap memory
	printf("Heap size is %d bytes\n", globalCounter);
	

	// insertion sort.
	list1 = insertionSort(list1);

//	printf("%lf %lf %d\n",list1->first->record->marks,list1->last->record->marks,list1->count);
	
	printf("Printing Sorted Array:\n");
	printList(list1);

	double proftime = measureSortingTime(list1);
	
	// profiling the time
	printf("The profiling time is : %lf\n", proftime);

	// measuring heap memory
	printf("Heap size is %d bytes\n", globalCounter);

	return 0;
}

