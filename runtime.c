#include <stdio.h>
#include "program.c"

int main(int argc, const char *argv[])
{
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
