#include <stdio.h>
#include <stdlib.h>
#include "program.c"

typedef enum { false, true } bool;

int main(int argc, const char *argv[])
{
	FILE *filePointer;
	char ch;
	bool commenting = false;
	filePointer = fopen(argv[1], "r");

	// readfile and call program
	while ((ch = fgetc(filePointer)) != EOF) {
		// comments
		if (ch == ';') commenting = !commenting;
		if (commenting == true) continue;

		// string reader
		switch (ch) {		
			case '0':
				func0();
				break;

			case '1':
				func1();
				break;

			case ' ':
				push();
				break;
			
			case '$':
				exit(0);
				break;
		}
	}

	fclose(filePointer); // close file

	printf("\n=====End=====\n.");
	return 0;
}