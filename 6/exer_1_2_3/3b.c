#include <element.h>
#include <stdio.h>
#include <stdlib.h>

/*
b) Write a mergeFiles procedure that performs a merge operation where the input lists are in files and the output has to be a new file:
open file F1;
open file F2;
open file Out;
read record r1 from F1;
read record r2 from F2;
repeat {
     if (r1.key <= r2.key) { 
          write r1 to Out;  read r1 from F1;
     } else {
	    write r2 to Out; read r2 from F2;
     }
  } until (F1 is empty OR F2 is empty);
  while (F1 is not empty) { read r1 from F1; write r1 to Out; }
  while (F2 is not empty) { read r2 from F2; write r2 to Out; }
  close files F1, F2, and Out.
*/

void mergeFiles(char* infile1name, char* infile2name, char* outfilename){
	FILE* infile1 = fopen(infile1name,"r");
	FILE* infile2 = fopen(infile2name,"r");
	FILE* outfile = fopen(outfilename,"w");

	Element a;
	Element b;

	fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);
	fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);

	while(!feof(infile1) && !feof(infile2)){
		if(a.cgpa<b.cgpa){
			fprintf(outfile,"%s,%f",a.name,a.cgpa);
			fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);
		}
		else{
			fprintf(outfile,"%s,%f",b.name,b.cgpa);
			fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);
		}
	}

	if(feof(infile1)){
		while(!feof(infile2)){
			fprintf(outfile,"%s,%f",b.name,b.cgpa);
			fscanf(infile2,"%[^,],%f",b.name,&b.cgpa);	
		}
	}

	if(feof(infile2)){
		while(!feof(infile1)){
			fprintf(outfile,"%s,%f",a.name,a.cgpa);
			fscanf(infile1,"%[^,],%f",a.name,&a.cgpa);	
		}
	}

	fclose(infile1);
	fclose(infile2);
	fclose(outfile);
}

int main(int argc, char* argv[]){
	mergeFiles(argv[1], argv[2],argv[3]);
}