#include <measureTimeAndSpace.h>
#include <insertionSort.h>
#include <readRecords.h>

int main(int argc, char* argv[]){
	timeForReadingTest(argv[1],argv[2]);
	timeForSortingTest(argv[1],argv[2]);
	spaceForSortingTest(argv[1],argv[2]);
}