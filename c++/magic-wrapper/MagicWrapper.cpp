#include "MagicWrapper.h"
#include <stdio.h>
#include <string>
#include <magic.h>

using std::string;

Magic::Magic() {
    cookie = magic_open(MAGIC_MIME);
    if (cookie == NULL) {
        throw MagicError("Unable to open magic");
    }
    if (magic_load(cookie, NULL) != 0) {
        magic_close(cookie);
        throw MagicError(string("cannot load magic database").append(
                    magic_error(cookie)));
    }

}

Magic::~Magic() {
    magic_close(cookie);
}

string Magic::getFileType(const string& file) {
    return magic_file(cookie, file.c_str());
}


