#include <stdio.h>
#include <string.h>

void revertString(char* begin, char* end) {
    if ( begin == 0 || end == 0) return;
    while ( begin < end ) {
        char c = *begin;
        *begin++ = *end;
        *end-- = c;
    }
}

void revertWords(char* str) {
    unsigned int len  = strlen(str);
    char* begin = &str[0];
    char* end = &str[strlen(str)-1];
    revertString(begin, end);
    char* current = begin;
    while ( current <= end ) {
        if (*current == ' ') {
            revertString(begin, current-1);
            begin = ++current;
        }
        current++;
    }
    if (begin <= end) revertString(begin, end);
}

int main(int argc, char* argv[]) {
    if ( argc < 2 ) {
        printf("Please specify the string to be reverted\n");
        return -1;
    }
    char str[1000];
    strcpy(&str[0], argv[1]);
    printf("%s\n", str);
    revertWords(&str[0]);
    printf("%s\n", str);
    return 0;
}

