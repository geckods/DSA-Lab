#include<stdio.h>
#include"node.h"

extern int * Arr[N];
extern int Num_Elements[N];


void PrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d ", Arr[i][j]);
     printf("\n");
  }
}

void MyPrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d %d ", Arr[i][j]%10000, (Arr[i][j]/10000)%1000);
     printf("\n");
  }
}

int main()
{
	printf("PRINTING INPUTTED LINKED LIST.\n");
	Locality* myLoc = ReadFileintoLists("file.txt");
	PrintLists(myLoc);
	
	ConvertListstoArray(myLoc);
	printf("PRINTING ARRAY.\n");
	PrintArr();
	
	printf("PRINTING SORTED ARRAY.\n");
	InsertionSort_Arr();
	MyPrintArr();//MyPrintArr();

//	int arr1[] = {109823227,126333440,127894112,149413227,125012896};
//	int arr2[] = {102391710,143632332,119833510,106343444,137924145,139483510,135032939};
	
//	int arr3[12];
	
//	Merge_GM(arr1,5,arr2,7,arr3);

//	for(int i=0;i<12;i++){
//		printf("%d %d\n",arr3[i]%10000,(arr3[i]/10000)%1000);
//	}
	
//	printf("ISLOWERTEST %d %d %d\n",119251296,149621296,IsLower_GM(119251296,149621296));
	
	printf("PRINTING MERGE SORTED ARRAY.\n");
	int* finalArr = Merge_Arr();
	int sum=0;
	for(int i=0;i<N;i++) sum+=Num_Elements[i];
	
	for(int i=0;i<sum;i++){
		printf("%.4d: ID:%d Group:%d Member:%d\n",i+1,finalArr[i],finalArr[i]%10000,(finalArr[i]/10000)%1000);
		//printf("%d %d\n",finalArr[i]%10000, (finalArr[i]/10000)%1000);
	}
}

  
