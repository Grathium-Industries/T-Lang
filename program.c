/*
	To Compile:
	gcc ./runtime.c -o Tlang

	Run Program Syntax:
	./Tlang [program name]
*/

// called when pointer reads '0'
int func0(reg, state) {
	/* Code */
	return 0; // update current state of program
}

// called when pointer reads '1'
int func1(reg, state) {
	/* Code */
	return 0; // update current state of program
}

// called when pointer reads ' ' or {SPACE}
int push(reg, state) {
	/* Code */
	return 0; // update current state of program
}