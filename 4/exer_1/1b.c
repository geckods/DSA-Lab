#include <stdio.h>

void call(int x){
	printf("x is %d, &x is %u.\n",x,&x);
	call(x+1);
}

int main(){
	call(0);
}