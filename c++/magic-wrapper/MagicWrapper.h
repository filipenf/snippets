#ifndef __MAGIC_WRAPPER_CPP
#define __MAGIC_WRAPPER_CPP
#include <magic.h>

#include <string>
#include <stdexcept>

class Magic {
public:
    Magic();
    ~Magic();

    std::string getFileType(const std::string&);
private:
    magic_t cookie;
};

typedef std::runtime_error MagicError;

#endif /// __MAGIC_WRAPPER_CPP

