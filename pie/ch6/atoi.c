#include <stdio.h>
#include <string.h>

int toInt(const char* str) {
    int len = strlen(str);
    int value = 0;
    int i;
    for ( i = 0; i < len; i++ ) {
        if ( isdigit(str[i]) ) {
            value *= 10;
            value += (str[i] - '0');
        } else break;
    }
    return value;
}

int main(int argc, char* argv[]) {
    const char* strvalue = "2039";
    int value = toInt(strvalue);
    printf("Value = %d", value);
}
