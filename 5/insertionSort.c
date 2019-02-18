#include <insertionSort.h>

void insertInOrder(CREDIT_CARD* card_array, int n, CREDIT_CARD newcard){
	CREDIT_CARD card = newcard;
	CREDIT_CARD tempcard;
	for(int i=0;i<n;i++){
		if(card.card_no < card_array[i].card_no || i==n-1){
			tempcard = card;
			card = card_array[i];
			card_array[i] = tempcard;
		}
	}
}

void insertionSort(CREDIT_CARD* card_array,int n){
	if(n==0){
		topofstack = &n;
		return;
	}
	insertionSort(card_array,n-1);
	insertInOrder(card_array,n,card_array[n-1]);
}