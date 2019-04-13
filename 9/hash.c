#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int hash(wchar_t* string, int baseNumber, int tableSize){

	int myHash=0;
	for(int i=0;i<wcslen(string);i++){
		myHash+=string[i];
		myHash%=baseNumber;
	}
	myHash = myHash%tableSize;
	return myHash;
}

int collisionCount(wchar_t* strarr[],int strarrlen,int baseNumber,int tableSize){
	int seenHashes[tableSize];
	//fprintf(stdout,"AAAAAAAAAAAAAAAAAAAA");
	// for(int i=0;i<tableSize;i++){
	// 	seenHashes[i]=0;
	// }
	memset(seenHashes, 0, sizeof(int)*tableSize);
	
	FILE* outputfile = fopen("TEST1.txt","w");

	if(outputfile==NULL){
		printf("ASSSSSSSSSSSSSSSSSSSSSSSSSS");
	}
	
	int collisions=0;
	int theHash;
	for(int i=0;i<strarrlen;i++){
		theHash = hash(strarr[i],baseNumber,tableSize);
		if(seenHashes[theHash]==1){
//			printf("i:%d\n",i);
//			fprintf(stderr,"HI");
			collisions++;
		}
		else{
//			fprintf(outputfile,"%d\n",i);
			seenHashes[theHash]=1;
		}
	}
	
	fclose(outputfile);
	
	return collisions;
}

wchar_t** validStrings(char* filename,int* len){
	wchar_t** stringarr = NULL;
	FILE* inputFile = fopen(filename,"r");
	
	int currSize=10;
	stringarr = (wchar_t**)malloc(sizeof(wchar_t*)*currSize);
	
	wchar_t currString[10000] = {0};
	
	int validCount=0;
	
	wint_t mych;
	int asd=0;


	while(fwscanf(inputFile, L"%ls ", currString)!=EOF){
//		asd=0;
//		printf("%d\n",asd++);
//		wprintf(L"%ls\n", currString);
		// while((mych=fgetwc(inputFile))!=' '){
		// 	fprintf(stderr, "%d\n",mych);
		// 	wprintf(L"%c", mych);
		// 	currString[asd++]=mych;
		// }
//		wscanf(L"%ls ",currString);
//		fgetc(inputFile);
//		fprintf(stderr,"i:%d\n",validCount);
		stringarr[validCount] = (wchar_t*)malloc(sizeof(wchar_t)*(wcslen(currString)+1));
		wcscpy(stringarr[validCount],currString);
//		fprintf(stderr,"%s\n",stringarr[validCount]);
		validCount++;
		if(validCount>= currSize){
			currSize*=2;
			stringarr = (wchar_t**)realloc(stringarr,sizeof(wchar_t*)*currSize);
		}
	}
	
//	stringarr = (wchar_t**)realloc(stringarr,sizeof(wchar_t*)*validCount);
	*len = validCount;
	fclose(inputFile);
	return stringarr;
}

/*Values for profiling
tableSizes = {5000,50000,500000};
baseNumbers = {{5003,5009,5011,5000011,5000077,5000081},{50021,50023,50033,50000017,50000021,50000047},{500009,500029,500041,500000003,500000009,500000041}}
*/

int profiler(char* filename){
	int tableSizes[] = {5000,50000,500000};
	int baseNumbers[3][6] = {{5003,5009,5011,5000011,5000077,5000081},{50021,50023,50033,50000017,50000021,50000047},{500009,500029,500041,500000003,500000009,500000041}};
	int collisions[18];
	wchar_t** myArr;
	int myLen;
	int coll;
	myArr = validStrings(filename,&myLen);
	for(int i=0;i<3;i++){
		for(int j=0;j<6;j++){
			coll = collisionCount(myArr,myLen,baseNumbers[i][j],tableSizes[i]);
			printf("table:%d base:%d collisioncount:%d\n",tableSizes[i],baseNumbers[i][j],coll);
			collisions[6*i+j]=coll;
		}
	}
	/*
	all these values of tableSize and baseNumber are giving almost exactly the same number of collisions, because this is a very stupid hash function
	in the question, the minimum table Size is 5000, and baseNumber > tableSize
	thus, only if the sum of ASCII exceeds 5000 will the mod even come into effect
	But even 20 consecutive 'z's only has an ASCII sum of 2440, much less than 5000.
	So basically tableSize and baseNumber in the range we're exploring have almost no effect at all, because the hash function is stupid
	*/

	int minind=0;
	int min=collisions[0];
	for(int i=0;i<18;i++){
		if(collisions[i]<min){
			min = collisions[i];
			minind=i;
		}
	}
	return minind;
}

typedef struct node Node;
struct node
{
	int firstindex;
	int count;
	Node* next;
};

typedef struct hashtable HashTable;
struct hashtable{
	int tableSize;
	int baseNumber;
	Node** table;
	int elementCount;
	int insertionCost;
	int queryingCost;
};

Node* newNode(){
	Node* theNode = malloc(sizeof(Node));
	theNode->firstindex=0;
	theNode->count=0;
	theNode->next = NULL;
	return theNode;
}

HashTable* newHashTable(int tableSize,int baseNumber){
	HashTable* theHashTable = malloc(sizeof(HashTable));
	theHashTable->tableSize=tableSize;
	theHashTable->baseNumber = baseNumber;
	theHashTable->table=malloc(sizeof(Node*)*tableSize);
	for(int i=0;i<tableSize;i++){
		theHashTable->table[i]=NULL;
	}
	theHashTable->elementCount=0;
	theHashTable->insertionCost=0;
	theHashTable->queryingCost=0;
	return theHashTable;
}

void insertHash(wchar_t** arr, int index, HashTable* myhash){
	int theHash = hash(arr[index],myhash->baseNumber,myhash->tableSize);

	if(myhash->table[theHash]==NULL){
		myhash->table[theHash] = newNode();
		myhash->table[theHash]->count = 1;
		myhash->table[theHash]->firstindex=index;
		myhash->tableSize++;
		//if(myhash->insertionCost==0) myhash->insertionCost++;
	}
	else{
		int asd=0;
		Node* curr = myhash->table[theHash];
		while(curr->next!=NULL && (wcscmp(arr[index], arr[curr->firstindex]))){
			myhash->insertionCost++;
			curr=curr->next;
		}
		if(!(wcscmp(arr[index], arr[curr->firstindex]))){
			curr->count++;
		}
		else{
			curr->next = newNode();
			curr->next->firstindex = index;
			curr->next->count = 1;
			myhash->tableSize++;
		}
	}
}

int insertAll(wchar_t** arr, int size, HashTable* myhash){
	for(int i=0;i<size;i++){
		insertHash(arr, i, myhash);
	}
	return myhash->insertionCost;
}

Node* lookup(wchar_t** arr, int index, HashTable* myhash){
	int theHash = hash(arr[index],myhash->baseNumber,myhash->tableSize);
	Node* curr = myhash->table[theHash];
	while(curr && wcscmp(arr[index], arr[curr->firstindex])){
		myhash->queryingCost++;
		curr=curr->next;
	} 

	return curr;
}

int lookupAll(wchar_t** arr, int size, HashTable* myhash,double m){
	myhash->queryingCost=0;

	for(int i=0;i<(int)(m*size);i++){
		lookup(arr,i, myhash);
	}
	return myhash->queryingCost;
}

double lookupProfile(wchar_t** arr, int size, HashTable* myhash){
	for(double m=0;m<2.0;m+=0.1){
		if(lookupAll(arr,size,myhash,m)>myhash->insertionCost){
			return m;
		}
	}
	return 2.0;
}

HashTable* deleteStopWords(HashTable* myhash, char* stopWordsFile, wchar_t** arr){
	int stopWordsLength;
	wchar_t** stopWords = validStrings(stopWordsFile,&stopWordsLength);

	for(int i=0;i<stopWordsLength;i++){
		int theHash = hash(stopWords[i],myhash->baseNumber,myhash->tableSize);
		Node* prev = myhash->table[theHash];
		if(prev==NULL)continue;
		Node* curr = prev->next;

		if(!wcscmp(stopWords[i],arr[prev->firstindex])){
			myhash->table[theHash] = curr;
			free(prev);
			myhash->tableSize--;
		}

		while(curr && wcscmp(stopWords[i],arr[curr->firstindex])){
			prev=curr;
			curr = curr->next;
		}

		if(curr==NULL){
			continue;
		}

		prev->next = curr->next;
		free(curr);
		myhash->tableSize--;
	}
	return myhash;
}

int main(int argc, char* argv[]){

	setlocale(LC_ALL, "en_US.UTF-8");
//    freopen(argv[1], "r", stdin);
	int len=0;
	wchar_t** stringarr = validStrings(argv[1],&len);
	
//	for(int i=0;i<len;i++){
//		if(i==11409){
//			printf("%d: %ls %lu\n",i,stringarr[i],wcslen(stringarr[i]));
//		}
//		if(strlen(stringarr[i])==0){
//			printf("ERRIOR");
//		}
	
//	fprintf(stderr,"len:%d",len);
//	fprintf(stderr,"%s",stringarr[len-1]);
//	profiler(argv[1]);
//	for(int i=0;i<
//	printf("%d %d\n",len,collisionCount(stringarr,len,5003, 5000));
	
//	char* testArr[] = {"abc","asd","c"};
//	fprintf(stderr,"%d\n",collisionCount(testArr,3,5003, 5000));
	//profiler(argv[1]);
	//50000,500021
	HashTable* myHashTable = newHashTable(50000, 50021);
	fprintf(stderr,"%d\n",insertAll(stringarr, len, myHashTable));
	fprintf(stderr, "%d\n", lookup(stringarr, 4, myHashTable)->count);
	fprintf(stderr, "%d\n", lookupAll(stringarr, len, myHashTable,0.8));
	fprintf(stderr, "%lf\n", lookupProfile(stringarr, len, myHashTable));
	deleteStopWords(myHashTable, argv[2],stringarr);
	fprintf(stderr, "%d\n",myHashTable->tableSize);
	fprintf(stderr, "%lf\n", lookupProfile(stringarr, len, myHashTable));
	return 0;
}

/*RUN COMMAND:
./a.out aliceinwonderland.txt stopwords.txt
*/