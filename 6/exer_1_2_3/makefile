CC = gcc

compRecMS: mainRunner.o merge.o mergesortRec.o
	$(CC) mainRunner.o mergesortRec.o merge.o -o recursiveMerge

compIterMS: mainRunner.o merge.o mergesortIter.o
	$(CC) mainRunner.o mergesortIter.o merge.o -o iterativeMerge 

runRecMS : compRecMS
	./recursiveMerge

runIterMS : compIterMS
	./iterativeMerge

mainRunner.o : mainRunner.c
	$(CC) -c mainRunner.c

mergeRec.o : mergesortRec.c merge.h
	$(CC) -c mergesortRec.c

mergeIter.o : mergesortIter.c merge.h
	$(CC) -c mergesortIter.c

merge.o : merge.c
	$(CC) -c merge.c

comparer.o : comparer.c
	$(CC) -c comparer.c

compare : comparer.o merge.o mergesortRec.o mergesortIter.o
	$(CC) comparer.o mergesortRec.o mergesortIter.o merge.o -o compareMerge