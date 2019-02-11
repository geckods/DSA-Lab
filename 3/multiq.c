#include <multiq.h>

MultiQ createMQ(int num){
	MultiQ mq;
	mq.size = num;
	mq.qarr = malloc(sizeof(Queue)*num);
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t){
	//the Queue corresponding to priority p is mq[p-1]
	Node nn = newNode(t.tid);
	mq.qarr[t.p-1] = addQ(mq.qarr[t.p-1],nn);
	return mq;
} // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.


Task nextMQ(MultiQ mq){
	if(isEmptyMQ(mq)){
		Task emptyTask;
		emptyTask.tid = -1;
		emptyTask.p = -1;
		return emptyTask;
	}
	else{
		int i=mq.size-1;
		while(isEmptyQ(mq.qarr[i])) i--;
		Task newTask;
		newTask.tid =  front(mq.qarr[i]).data;
		newTask.p = i+1;
		return newTask;
	}
} // returns the front of the non-empty Queue in mq with the highest priority.

MultiQ delNextMQ(MultiQ mq){
	if(isEmptyMQ(mq)){
		return mq;
	}
	else{
		int i=maxPriority-1;
		while(isEmptyQ(mq.qarr[i])) i--;
		mq.qarr[i] = delQ(mq.qarr[i]);
		return mq;
	}
} // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ

bool isEmptyMQ(MultiQ mq){
	for(int i=mq.size-1;i>=0;i--){
		if(isEmptyQ(mq.qarr[i])){
		}
		else{
			return false;
		}
	}
	return true;
} // tests whether all the Queues in mq are empty

int sizeMQ(MultiQ mq){
	int size=0;
	for(int i=mq.size-1;i>=0;i--){
		size+=lengthQ(mq.qarr[i]);
	}
	return size;
} // returns the total number of items in the MultiQ

int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ(mq.qarr[p-1]);
} //returns the number of items in mq with the priority p.


Queue getQueueFromMQ(MultiQ mq, Priority p){
	return mq.qarr[p-1];
}// returns the Queue with priority p.