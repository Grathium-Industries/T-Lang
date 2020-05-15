#include <stdio.h>
#include <stdlib.h>
#include "program.c"

int main(int argc, const char *argv[])
{

	// MAIN
	FILE *filePointer;
    char ch;
    filePointer = fopen(argv[1], "r");

    // readfile and call program
    while ((ch = fgetc(filePointer)) != EOF) {
    	if (ch == '0')
    	{
    		func0();
    	} else if (ch == '1') {
    		func1();
    	}
    }

    fclose(filePointer); // close file

	printf("\n=====End=====\n.");
	return 0;
}

int countChar(char filename[128]) {
	FILE* fp; 
  
    // Character counter (result) 
    int count = 0;
    char c; 
  
    fp = fopen(filename, "r"); 
    if (fp == NULL) { 
        printf("Could not open file %s", 
               filename); 
        return 0; 
    } 
  
    // Extract characters from file 
    // and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
  
        // Increment count for this character 
        count = count + 1; 
  
    // Close the file 
    fclose(fp); 
  
    return count; 
}