#include <stdio.h>


int bits;

void g(){
	int goa;
	printf("Goa:%u\n",&goa);
}

void p(){
	int pilani;
	printf("Pilani:%u\n",&pilani);
	g();
}

void h(){
	int hyder;
	printf("hyder:%u\n",&hyder);
}

void d(){
	int dub;
	printf("dubai:%u\n",&dub);
}

int main(){
	p();
	h();
	d();
	printf("bits:%u\n",&bits);	
}