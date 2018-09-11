
#ifndef COS10007_COMMON_H
#define COS10007_COMMON_H

// colors
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define BLU "\x1B[34m"
#define CYN "\x1B[36m"

// uselessStruct and uselessLinkedList
struct uselessStruct {
    char uselessString[256];
    int uselessInt;
    float uselessFloat;
};

struct uselessLinkedList {
    struct uselessStruct useless;
    struct uselessLinkedList* next;
};

// useless typedefs
typedef struct uselessStruct USELESS;
typedef struct uselessLinkedList LINKEDLIST;

#endif
