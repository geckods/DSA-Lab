#include <que.h>

int main(){
	Queue q = newQ();
	Node e;
	e.data = 1;
	e.next = NULL;
	q = addQ(q, e);
	e.data = 2;
	q = addQ(q, e);
	q = delQ(q);
	printf("%d\n",front(q).data);
}