#include <stdio.h>

const int RESULT_FOUND = 0;
const int RESULT_NOT_FOUND = 1;
const int ARRAY_NOT_ORDERED = 2;
const int INVALID_ARRAY_SIZE = 3;

/** Recursive binary search */
int binarySearch(int value, int *begin, int *end, int** result) {
    if ( begin == 0 || end == 0 ) return INVALID_ARRAY_SIZE;
    if ( begin > end ) return INVALID_ARRAY_SIZE;
    if ( begin == end ) {
        if ( value == *begin ) {
            *result = begin;
            return RESULT_FOUND;
        } else return RESULT_NOT_FOUND;
    }
    int *half = begin + ((end - begin)/2);
    if ( value == *half ) *result = half;
    else if ( value > *half ) return binarySearch(value, half+1, end, result);
    else if ( value < *half ) return binarySearch(value, begin, half-1, result); 
    return RESULT_FOUND;
}

/** Iterative binary search */
int binarySearchIt(int value, int* begin, int*end, int** result) {
    while (1) {
        int *half = begin + ((end - begin) / 2);
        if ( *half == value ) {
            *result = half;
            return RESULT_FOUND;
        } else if ( value > *half ) {
            begin = half + 1;
        } else if ( value < *half ) {
            end = half - 1;
        }
    }
}

int main(int argc, char* argv[]) {
    int xxx[7] = {10, 20, 21, 25, 50, 52, 70};
    int * location;
    int err = binarySearch(21, &xxx[0], &xxx[7], &location);
    printf("The item is on position: %d\n", location - &xxx[0]);
    binarySearchIt(50, &xxx[0], &xxx[7], &location);
    printf("The item is on position: %d\n", location - &xxx[0]);
    return 0;
}

