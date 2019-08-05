#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/*
int test(char fileName) {

}
*/ 



int main(int argc, char * argv[]) {
   FILE *fp; 
   char reading[100000]; 
   int currentArg = 2; 
   int numberOfTimes = 0; 
   char *c;
   int fd, sz;
   char *fileName;

   fileName = argv[1]; 

   int k;
   k = strcmp(argv[argc-1], "false"); 




	while(currentArg < argc-1) {
		numberOfTimes = 0; 
		char *stringPattern; 
		stringPattern = argv[currentArg]; 
		int sizeOfPattern = 0; 
		sizeOfPattern = strlen(stringPattern);
		int sizeOfFile = 0; 

	if(k == 0){
		fp = fopen(fileName, "r"); 
		fseek(fp, 0, SEEK_SET);
		fread(reading, sizeof(reading), 1, fp);


		


		sizeOfFile = strlen(reading);

		for (int i = 0; i <= sizeOfFile - sizeOfPattern; i++) {  
			int j; 
			for (j = 0; j < sizeOfPattern; j++) {
			    if (reading[i+j] != stringPattern[j]) {
				break; 
			    }
			}
			if (j == sizeOfPattern) { 
			   numberOfTimes++; 
			   j = 0; 
			} 
		} 




	     currentArg++; 

	} else {

		c = (char *) calloc(1000, sizeof(char)); // allocate 100 char-size buffer

		fd = open(fileName, O_RDONLY, 0);

		if (fd < 0) { 
			perror("r1"); 
			exit(1); 
		}

		sz = read(fd, c, 200);

		printf("Returned that %d bytes were read.\n", sz);
		c[sz] = '\0';

		printf("Those bytes are as follows: %s\n", c);
		sizeOfFile = strlen(c);

		for (int i = 0; i <= sizeOfFile - sizeOfPattern; i++) {  
			int j; 
			for (j = 0; j < sizeOfPattern; j++) {
			    if (c[i+j] != stringPattern[j]) {
				break; 
			    }
			}
			if (j == sizeOfPattern) { 
			   numberOfTimes++; 
			   j = 0; 
			} 
		} 
	     currentArg++; 

	}
}

printf("%d\n", numberOfTimes); 

if(k == 0){
	fclose(fp); 
}
		





return 0; 

}
