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
void delete(BANKEmployeePtr sPtr);

int main() {
    BANKEmployeePtr startPtr = (BANKEmployeePtr) malloc(sizeof(BANKEmployee));
    strcpy(startPtr->name, "Justin");
    startPtr->salary = 1000;

    BANKEmployeePtr newPtr = (BANKEmployeePtr) malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, "Sam");
    newPtr->salary = 700;

    startPtr->next = newPtr;

    insert(&startPtr, "Antony", 200);
    insert(&startPtr, "Tony", 300);
    insert(&startPtr, "Peter", 400);

    print(&startPtr);

    delete(startPtr);

    return 0;
}

/**
 * @description Created a new node of name @value and of salary @salary
 * and inserts into the linked list chain of @sPtr in alphabetic order
 *
 * @param sPtr pointer of type BANKEmployeePtr
 * is the start pointer for the old linked list chain
 *
 * @param name string of 20 characters
 *
 * @param salary integer salary for 'char name[20]'
 */
void insert(BANKEmployeePtr *sPtr, char name[20], int salary) {
    /**
     * Create a new ptr to store value of @value and @salary
     */
    BANKEmployeePtr newPtr = malloc(sizeof(BANKEmployee));
    strcpy(newPtr->name, name);
    newPtr->salary = salary;
    newPtr->next = NULL;

    if (newPtr != NULL) {
        /**
         * currentPtr and nextPtr is used to hold pointers from sPtr while inserting a new node
         */
        BANKEmployeePtr previousPtr = NULL;
        /**
         * currentPtr node which will be compared to @name
         */
        BANKEmployeePtr currentPtr = *sPtr;

        /**
         * checks if we have reached the end of the list or if the @currentPtr->name > @name
         */
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

/**
 * @description Prints Name: %s, Salary: %s for each node in the linked list chain
 *
 * @param sPtr pointer of type BANKEmployeePtr
 * is the start pointer for the old linked list chain
 */
void print(BANKEmployeePtr *sPtr) {
    /**
     * set currentPtr to sPtr and then change currentPtr to the next ptr
     */
    BANKEmployeePtr currentPtr = *sPtr;
    /**
     * check that currentPtr is not NULL
     * if sPtr is NULL then it is already handled but does not throw error
     * is currenPtr->next is NULL then it stops printing
     */
    while (currentPtr != NULL) {
        printf("Name: %s, Salary: %i\n", currentPtr->name, currentPtr->salary);
        currentPtr = currentPtr->next;
    }
}

/**
 * @description Deletes every node in the linked list chain provided by sPtr
 *
 * @param sPtr pointer of type BANKEmployeePtr
 * is the start pointer for the old linked list chain
 */
void delete(BANKEmployeePtr sPtr) {
    BANKEmployeePtr currentPtr = NULL;
    while (sPtr != NULL) {
        currentPtr = sPtr;
        sPtr = sPtr->next;
        free(currentPtr);
    }
}
