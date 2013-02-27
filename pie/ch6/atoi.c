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

int toInt(const char* str) {
    int len = strlen(str);
    int value = 0;
    int i = 0;
    int isNegative = ( str[i] == '-' );
    if ( isNegative ) i++;
    for ( i; i < len; i++ ) {
        if ( isdigit(str[i]) ) {
            value *= 10;
            value += (str[i] - '0');
        } else break;
    }
    if ( isNegative ) value *= -1;
    return value;
}

void toStr(int value, char* result) {
    char* pos = result;
    int isNegative = value < 0;
    if ( isNegative ) value *= -1;
    while ( value > 0 ) {
        int calc = value % 10;
        *pos++ = '0' + (value % 10);
        value /= 10;
    }
    if ( isNegative ) *pos++ = '-';
    revertString(result, pos-1);
    *pos = '\0';
}

int main(int argc, char* argv[]) {
    const char* strvalue = "-22039";
    int value = toInt(strvalue);
    printf("toInt = %d\n", value);
    char buffer[20];
    toStr(39401, buffer);
    printf("toStr = %s\n", buffer);
    toStr(-94301, buffer);
    printf("toStr = %s\n", buffer);
}
