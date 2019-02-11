/* File: test.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for(int i=0;i<argc;i++){
		if((argv[i][0]-'0')>=0 && (argv[i][0]-'0')<=9){
			printf("%d\n",atoi(argv[i]));
		}
		else{
			printf("%s\n", argv[i]);
		}
	}
}
