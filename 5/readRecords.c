#include <readRecords.h>

CREDIT_CARD* read_cards(CREDIT_CARD* card_array,char* filename, int* finalsize){
	int size=5;
	card_array = (CREDIT_CARD*)malloc(sizeof(CREDIT_CARD)*size);
	FILE* f = fopen(filename,"r");

	if(f==NULL){
		printf("ERROR WITH OPENING THE FILE.");
		exit(0);
	}

	CREDIT_CARD newcard;

	/*There's a bug here, where if the last line is a newline, then the program reads the last struct twice*/
	/*Update: seem to have fixed it by adding \n to the back of scanf string*/
	int i=0;
	while(!feof(f)){
//		fgetc(f);
		fscanf(f,"\"%llu,%[^,],%[^,],%[^,],%[^\"]\"\n",&(newcard.card_no),newcard.bank_code,newcard.expiry_date,newcard.first_name,newcard.last_name);
//		fgetc(f); //reads a newline character
		card_array[i++]=newcard;

//		printf("%d %llu\n",i-1,card_array[i-1].card_no );

		if(i==size){
			size*=2;
			card_array = realloc(card_array,sizeof(CREDIT_CARD)*size);
		}
	}
/*
	for(int j=0;j<i;j++){
		printf("%llu\n",card_array[j].card_no);
	}
*/
	fclose(f);
	*finalsize = i;
	return card_array;
}