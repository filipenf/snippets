/*
 * ===========================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  call code for quicksort
 *
 *        Version:  1.0
 *        Created:  10/03/2013 19:51:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Filipe N. Felisbino (fnf), filipenf@gmail.com
 *
 * ===========================================================================
 */

#include "quicksort.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	if ( argc < 2 ) {
		printf("Usage: %s [input_size]\n", argv[0]);
		return -1;
	}
	step = 0;
	int LEN = atoi(argv[1]);
	int numbers[LEN];
	for ( int i = 0; i < LEN; i++ ) {
		numbers[i] = rand() % LEN;
	}
	print_array(numbers, LEN, 0);
	sort(numbers, LEN);
	print_array(numbers, LEN, 0);
	return 0;
}

