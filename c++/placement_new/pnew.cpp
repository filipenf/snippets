/***
 * Simple example of memory allocation using placement new with new operator
 *
 * **/

#include <iostream>

using namespace std;

class Arena {
    private:
        char buffer[1000];
        size_t pos;
    public:
        Arena() {
            pos = 0;
            cout << "New arena allocated " << hex << this << endl;
            cout << "Buffer address: " << hex << &buffer << endl;
        };

        void* allocate(size_t) {
            return (void*) &buffer[pos++ * sizeof(int)];
        }
        void deallocate(void* x) {
            cout << "request to deallocate " << hex << x << endl;
        }
        // ...
};

template<class T> void destroy(T* p, Arena& a)
{
    if (p) {
        p->~T();        // explicit destructor call
        a.deallocate(p);
    }
}

void* operator new(size_t sz, Arena& a)
{
    cout << "Allocating memory with placement new" << endl;
    return a.allocate(sz);
}

int main(int argc, char* argv[]) {
    Arena a1;
    Arena a2;

    int *x = new (a1) int;
    int *y = new (a1) int;
    int *z = new (a2) int;
    *x = 10;
    *y = 100;
    *z = 2 << 24;
    cout << "Address of x: " << hex << x << " value: " << dec << *x << endl;
    cout << "Address of y: " << hex << y << " value: " << dec << *y << endl;
    cout << "Address of z: " << hex << z << " value: " << dec << *z << endl;
    destroy(x, a1);
    destroy(y, a1);
    destroy(z, a2);


    //char* buf = new char[1000];
    char buf[1000];
    string *xstr = new(buf) string;
    *xstr = " this is the string ";
    cout << "Address of buf: " << hex << (void*) buf << " to: " << (void*) buf + 1000 << endl;
    cout << "Address of xstr: " << hex << xstr << endl;
    cout << "Address of xstr.c_str(): " << hex << (void*)xstr->c_str() << endl;
    //delete [] buf;
}

