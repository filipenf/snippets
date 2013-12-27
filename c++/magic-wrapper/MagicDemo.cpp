#include "MagicWrapper.h"

#include <stdio.h>

int main(int argc, char** argv)
{
    if ( argc < 2 ) {
        printf("Usage: %s file1 file2 fileN\n", argv[0]);
        return 0;
    }
    Magic magic;
    for ( int i = 0; i < argc; i++ ) {
        printf("%-30.30s|%-64.64s\n", argv[i],
                magic.getFileType(argv[i]).c_str());
    }
    return 0;
}

