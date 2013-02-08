#include <stdio.h>
#include <stdlib.h>

bool endianness() {
	union {
		int theInteger;
		char singleByte;
	} endianTest;
	endianTest.theInteger = 1;
	return endianTest.singleByte;
}

bool endianness_with_cast() {
	int theInteger = 1;
	char* theChar = (char*) &theInteger;
	return *theChar;
}

int main(int argc, char** argv) {
	printf("The endianness of this machine is: %d\n", endianness());
	printf("The endianness(cast) of this machine is: %d\n",
			endianness_with_cast());
	return 0;
}
