#include <que.h>

Queue newQ(){
	Queue q;
	q.first = NULL;
	q.last = NULL;
	q.size=0;
	return q;
}


bool isEmptyQ(Queue q){
	if(q.size==0){
		return true;
	}
	else{
		return false;
	}
}

Queue delQ(Queue q){
	if(isEmptyQ(q)){
		return q;
	}
	else{
		if(q.size==1){
			q.size=0;
			q.first=NULL;
			q.last=NULL;
			return q;
		}
		else{
			q.first = q.first->next;
			q.size--;
			return q;
		}
	}
}

Node front(Queue q){
	return *(q.first);
}

Queue addQ(Queue q , Node e){

	Node* newE = malloc(sizeof(Node));
	newE->data = e.data;
	newE->next = e.next;

	if(isEmptyQ(q)){
//		printf("HIHI");
//		fflush(stdout);
		q.size=1;
		q.first = q.last = newE;
	}
	else{
		q.size++;
		q.last->next = newE;
		q.last=newE;
	}
	return q;
}

int lengthQ(Queue q){
	return q.size;
}

Node newNode(int data){
	Node n;
	n.data = data;
	n.next = NULL;
	return n;
}