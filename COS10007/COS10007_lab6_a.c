#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bankEmployee {
    char name[20];
    int salary;
    struct bankEmployee *next;
};

typedef struct bankEmployee BANKEmployee;
typedef BANKEmployee *BANKEmployeePtr;

void insert(BANKEmployeePtr *sPtr, char name[20], int salary);
void print(BANKEmployeePtr *sPtr);
void reverse(BANKEmployeePtr *sPtr);

int main() {
    BANKEmployeePtr startPtr = (BANKEmployeePtr) malloc(sizeof(BANKEmployee));
    strcpy(startPtr->name, "Justin");
    startPtr->salary = 1000;
    startPtr->next = NULL;

    insert(&startPtr, "Sam", 700);
    insert(&startPtr, "Antony", 200);
    insert(&startPtr, "Tony", 300);
    insert(&startPtr, "Peter", 400);
    insert(&startPtr, "John", 600);
    insert(&startPtr, "Richard", 900);
    insert(&startPtr, "gilfoyle", 680);

    printf("Original linked list\n");
    print(&startPtr);

    reverse(&startPtr);

    printf("Reversed linked list\n");
    print(&startPtr);

    return 0;
}

void insert(BANKEmployeePtr *sPtr, char name[20], int salary) {
    BANKEmployeePtr newPtr = malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, name);
    newPtr->salary = salary;
    newPtr->next = NULL;

    if (newPtr != NULL) {
        BANKEmployeePtr previousPtr = NULL;
        BANKEmployeePtr currentPtr = *sPtr;

        while (currentPtr != NULL && strcmp(name, currentPtr->name) > 0) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == NULL) {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr->next = newPtr;
            newPtr->next = currentPtr;
        }

    } else {
        fprintf(stderr, "No memory found to allocate newPtr of name:%s and salary:%i\n", name, salary);
    }
}


void print(BANKEmployeePtr *sPtr) {
    BANKEmployeePtr currentPtr = *sPtr;
    while (currentPtr != NULL) {
        printf("Name: %s, Salary: %i\n", currentPtr->name, currentPtr->salary);
        currentPtr = currentPtr->next;
    }
}

/**
 * Reverse a linked list
 */
void reverse(BANKEmployeePtr *sPtr) {
    /**
     * Set prev, current and next of type BANKEmployeePtr
     */
    BANKEmployeePtr prev   = NULL;
    BANKEmployeePtr current = *sPtr;
    BANKEmployeePtr next = NULL;

    /**
     * while current isn't NULL we haven't reached the end of the list
     */
    while (current != NULL) {
        /**
         * 1 -> 2 -> 3 -> 4
         *
         * 1  | 2 -> 3 -> 4
         * 1 <- 2 -> 3 -> 4
         *
         * 1 <- 2  | 3 -> 4
         * 1 <- 2 <- 3 -> 4
         *
         * 1 <- 2 <- 3  | 4
         * 1 <- 2 <- 3 <- 4
         */
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    /**
     * set start pointer to prev ( prev = current ) while current != NULL
     * this will make prev the last element in the old linked list
     * which will be the start of the new linked list
     */
    *sPtr = prev;
}
