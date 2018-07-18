#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Number {
    int number;
    struct Number *next;
};

typedef struct Number Numbers;
typedef Numbers *NumbersPtr;

void generate(NumbersPtr *sPtr, int n);
void reversePrint(NumbersPtr sPtr);

int main() {
    NumbersPtr startPtr = (NumbersPtr) malloc(sizeof(NumbersPtr));
    startPtr->number = 0;
    startPtr->next = NULL;

    generate(&startPtr, 2);
    generate(&startPtr, 2);
    generate(&startPtr, 2);
    generate(&startPtr, 2);
    generate(&startPtr, 2);
    generate(&startPtr, 2);

    reversePrint(startPtr);

    return 0;
}

void generate(NumbersPtr *sPtr, int n) {
    NumbersPtr previousPtr = NULL;
    NumbersPtr currentPtr = *sPtr;

    while (currentPtr != NULL) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    int lastNumber = previousPtr == NULL ? currentPtr->number : previousPtr->number;

    NumbersPtr newPtr = malloc(sizeof(Numbers));
    newPtr->number = (lastNumber + n);
    newPtr->next = NULL;

    if (previousPtr == NULL) {
        newPtr->next = *sPtr;
        *sPtr = newPtr;
    } else {
        previousPtr->next = newPtr;
        newPtr->next = currentPtr;
    }
}

/**
 * ReversePrint a linked list
 */
void reversePrint(NumbersPtr sPtr) {
    if (sPtr != NULL) {
        if (sPtr->next != NULL) {
            reversePrint(sPtr->next);
        }
        printf("Number: %i\n", sPtr->number);
    }
}
