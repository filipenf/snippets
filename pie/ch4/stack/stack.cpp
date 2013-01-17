#include <stdio.h>
#include <stdexcept>

class Stack {
public:
    Stack() {
        head = NULL;
    }

    ~Stack() {
        while ( head != NULL ) {
            Item *next = head->next;
            delete head;
            head = next;
        }
    }

    // push 
    void push(const void* data) {
        struct Item *item = new Item();
        item->data = data;
        item->next = this->head;
        this->head = item;
    };

    // tries to pop one item - throws an exception in case of error
    const void* pop() {
        if ( isEmpty() ) throw std::runtime_error("Stack is empty");
        Item *current = head;
        head = head->next;
        const void* result = current->data;
        delete current;
        return result;
    };

    bool isEmpty() { return head == NULL; };
protected:
    struct Item {
        struct Item *next;
        const void* data;
    };
private:
    Item *head;
};

int main(int argc, char* argv[]) {
    Stack stack;
    stack.push("first inserted item");
    stack.push("second inserted item");
    stack.push("third inserted item");

    void *result;
    while ( ! stack.isEmpty() ) {
        printf("popped: %s\n", (char*) stack.pop());
    }
}
