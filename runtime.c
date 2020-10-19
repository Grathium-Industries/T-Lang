#include <stdio.h>
#include <stdlib.h>
#include "program.c"

typedef enum { false, true } bool;

// pointer and scanning function
// returns whether or not program is recursive
bool pointer(const char *programFile)
{
	FILE *filePointer;
	char ch;
	bool commenting = false;
	filePointer = fopen(programFile, "r");

	// global variables
	// these variables can be transmitted between functions
	int currentRegister = 0;
	int currentState = 0;

	// readfile and call corresponding code block
	while ((ch = fgetc(filePointer)) != EOF) {

		// comments code blocking
		// MUST BE AT TOP OF POINTER TESTS
		if (ch == ';') commenting = !commenting; // code commenting toggle
		if (commenting == true) continue; // move pointer and skip iteration

		/* POINTER */
		// checks currently reading char
		// then calls corresponding code block
		// code blocks return the state of the program
		switch (ch) {
			// false or '0' code block
			case '0':
				currentState = func0(currentRegister, currentState);
				break;

			// true OR '1' code block
			case '1':
				currentState = func1(currentRegister, currentState);
				break;

			// push calling code block
			case '.':
				currentState = push(currentRegister, currentState);
				break;
			
			// exit program code block
			// closes program file and exits current existing runtime
			// if no child runtime exists, the program will be terminated
			case '$':
				fclose(filePointer);
				return true;
				break;
		}

		currentRegister++;
	}

	// close program file
	fclose(filePointer);
	return false;
}

// main/entrypoint
int main(int argc, const char *argv[])
{
	// get program file name from command arguments
	bool rec = pointer(argv[1]);

	// if recursive program, move onto next child iteration
	if (rec) {
		return 1;
		exit(0);
	} else {
		// terminate at end of program
		// and print end statement
		printf("\n=====End=====\n.");
		return 0;
	}

	return 0;
}
