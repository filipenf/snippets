libmagic C++ Wrapper
==================

Simple C++ wrapper for libmagic that allows one to get the mime-type of a file

Usage
====================
You just need an instance of Magic class and a call to getFileType()
```c++
    Magic magic;
    magic.getFileType("your-file-name");
```

PS: It's probably a good idea to make the magic object singleton so it doesn't have
to load the magic database each time you instantiate it

Pre-requisites:
===================
    * libmagic
    * file-dev(el)


