#include <stdio.h>
#include <stdlib.h>

typedef struct StackItem {
    struct StackItem *next;
    void* data;
} StackItem;

struct StackItem *g_head;
struct StackItem *g_tail;

int pop(void** result) {
    if ( g_head == 0 ) return 0;
    StackItem *item = g_head;
    *result = item->data;
    g_head = item->next;
    free(item);
    return 1;
}

StackItem* push(void* data) {
    StackItem *result = (StackItem*) malloc(sizeof(StackItem));
    if ( result == 0 ) return 0;
    result->data = data;
    result->next = g_head;
    g_head = result;
    return result;
}

int removeItem(StackItem* si) {
    StackItem *current = g_head;
    if ( si == current ) {
        g_head = current->next;
        free(current);
        return 1;
    }
    while ( current != 0 ) {
        if ( current->next == si ) {
            StackItem *tmp = current->next;
            current->next = current->next->next;
            if ( current->next == 0 ) g_tail = current;
            free(tmp);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int insertAfter(StackItem* item, void* data) {
    if ( item == NULL ) return 0;
    StackItem *current = g_head;
    while ( current != 0 ) {
        if (current == item) {
            StackItem *result = (StackItem*) malloc(sizeof(StackItem));
            if ( result == 0 ) return 0; // memory allocation failed
            result->next = current->next;
            if ( result->next == 0 ) g_tail = 0;
            result->data = data;
            current->next = result;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

StackItem* findFromEnd(unsigned int m) {
    StackItem *current = g_head;
    StackItem *mth = g_head;
    unsigned int counter = 1;
    while ( current != 0 ) {
        if ( current->next == 0 ) { // this is the end
            return mth;
        }
        if ( counter < m ) counter++;
        else mth = mth->next;
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    g_head = 0;
    g_tail = 0;
    StackItem *first = push( "first inserted item");
    StackItem *second = push("second inserted item");
    StackItem *third = push("third inserted item");
    insertAfter(second, "4th ( insertAfter )");
    push("5th item");
    push("6th item");
    push("7th item");

    StackItem* found = findFromEnd(5);
    printf("findFromEnd(5) = %s\n", found->data);

//    removeItem(second);

    void *result;
    while ( pop(&result) ) {
        printf("popped: %s\n", (char*) result);
    }
}
