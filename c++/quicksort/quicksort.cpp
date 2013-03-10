/*
 * ===========================================================================
 *
 *       Filename:  quicksort.cpp
 *
 *    Description:  implementation of quicksort in-place sorting using pointers
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

#include <iostream>

using namespace std;

int step;

int print_array(int v[], int len, int pivot) {
#ifdef DEBUG
	for ( int i = 0; i < step; i++ )
		cout << ">";
#endif
	for ( int i = 0; i < len; i++ ) {
		cout << v[i] << " ";
	}
#ifdef DEBUG
	cout << " : " << pivot;
#endif

	cout << endl;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* partition(int* start, int* end) {
	int value = *start;
	int* i = start + 1;
	int* j = end;
	while ( true ) {
		while (*i <= value) {
			if ( ++i == end ) break;
		}
		while (*j > value) {
			if ( --j == start ) break;
		}
		if ( i >= j ) break;
		swap(i, j);
	}
	swap(start, j);
	return j;
}

void sort(int v[], int len) {
	if ( len <= 1 ) return;
	step++;
	int* j = partition(v, &v[len-1]);
#ifdef DEBUG
	print_array(v, len, *j);
#endif
	sort(v, j - &v[0]);
	sort(j + 1, (&v[len-1]) -j);
	step--;
}

