/*
	To Compile:
	gcc ./runtime.c -o Tlang

	Run Program Syntax:
	./Tlang [program name]
*/

// called when pointer reads '0'
int func0(int reg, int state) {
	printf("Hello World!\n");
	return 0; // update current state of program
}

// called when pointer reads '1'
int func1(int reg, int state) {
	/* Code */
	return 0; // update current state of program
}

// called when pointer reads ' ' or {SPACE}
int push(int reg, int state) {
	/* Code */
	return 0; // update current state of program
}
