CC = gcc
CFLAGS = -lm

compile: main.o readRecords.o insertionSort.o measureTimeAndSpace.o
	$(CC) main.o readRecords.o insertionSort.o measureTimeAndSpace.o -o creditcard $(CFLAGS) 

run: compile
	./creditcard

main.o : main.c
	$(CC) -c main.c $(CFLAGS) 

readRecords.o : readRecords.c readRecords.h
	$(CC) -c readRecords.c $(CFLAGS)

insertionSort.o : insertionSort.c insertionSort.h
	$(CC) -c insertionSort.c $(CFLAGS) 

measureTimeAndSpace.o : measureTimeAndSpace.c measureTimeAndSpace.h
	$(CC) -c measureTimeAndSpace.c $(CFLAGS) 

testcompile: test.o readRecords.o insertionSort.o measureTimeAndSpace.o
	$(CC) test.o readRecords.o insertionSort.o measureTimeAndSpace.o -o creditcardtest $(CFLAGS)
