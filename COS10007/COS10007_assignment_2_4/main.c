#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "sort.h"
#include "search.h"

// show the list of available options to the user
void showOptions()
{
    printf(GRN "Option 1: Sort the uselessArray of elements (choose for more details)\n");
    printf(GRN "Option 2: Search for a uselessInt (linear/binary search)\n");
    printf(GRN "Option 3: Insert an uselessArray into the stack\n");
    printf(GRN "Option 4: Insert sorted list into a linked list\n");
    printf(GRN "Option 5: Insert one or more struct into the linked list\n");
    printf(GRN "Option 6: Quit\n");
}

// save the inputs from uselessArray to file
void saveRecord(USELESS *uselessArray, const char *filename)
{
    FILE *myFile;
    myFile = fopen(filename, "a+");
    char buffer[300];
    char id[10];
    char mark[10];
    sprintf(id, "%i", uselessArray->uselessInt);
    sprintf(mark, "%.3f", uselessArray->uselessFloat);
    fputs(uselessArray->uselessString, myFile);
    fputs(" ", myFile);
    fputs(id, myFile);
    fputs(" ", myFile);
    fputs(mark, myFile);
    fputs("\n", myFile);
    printf(RED "RECORD SAVED\n");
    fclose(myFile);
}

// fill up the uselessArray and if needed save to file
void addRecord(USELESS *uselessArray, int save)
{
    // if save = 0 then file wont be saved
    printf(CYN "Enter a useless string: ");
    scanf("%s", uselessArray->uselessString);
    printf(CYN "Enter a useless integer: ");
    scanf("%i", &uselessArray->uselessInt);
    printf(CYN "Enter a useless float: ");
    scanf("%f", &uselessArray->uselessFloat);
    if (save != 0) {
        printf(RED "SAVING RECORD\n");
        saveRecord(uselessArray, "data.txt");
    }
}

// price single uselessArray to the terminal
void printSingleRecord(USELESS uselessArray)
{
    printf(RED "PRINTING RECORD\n");
    printf(BLU "uselessString: %s, uselessInt: %i, uselessFloat: %.3f\n", uselessArray.uselessString, uselessArray.uselessInt, uselessArray.uselessFloat);
}

// search for a uselessInt. linear and binary search available
void searchInt(USELESS *uselessArray, unsigned int size)
{
    int search, index, uselessInt = 0;
    printf(CYN "Enter a uselessInt: ");
    scanf("%i", &uselessInt);
    printf(CYN "Enter 1 for linear search and 2 for binary search: ");
    scanf("%i", &search);
    printf(RED "SEARCHING RECORD\n");
    if (search == 1)
    {
        index = linearSearch(uselessArray, size, uselessInt);
    }
    else {
        index = binarySearch(uselessArray, size, 0, uselessInt);
    }
    int found = 0;
    if (index != -1)
    {
        printSingleRecord(uselessArray[index]);
        found = 1;
    }
    if (found == 0)
    {
        printf(RED "Unable to find uselessInt\n");
    }
}

// insert a new uselessArray and as if the user wants to search anything or print in reverse order to file
void insertElement(USELESS* uselessArray, unsigned int size)
{
    addRecord(&uselessArray[size - 1], 1);
    printf(CYN "Enter 0 for no search. 1 for char search and 2 for int search: ");
    int search;
    scanf("%i", &search);
    if (search == 1) {
        char uselessString[256];
        int found = 0;
        printf(CYN "Enter a uselessStirng: ");
        scanf("%s", uselessString);
        for(size_t i = 0; i < size; ++i)
        {
            if (strcmp(uselessArray[i].uselessString, uselessString) == 0) {
                printSingleRecord(uselessArray[i]);
                found = 1;
            }
        }
        if (found == 0) {
            printf(RED "Unable to find uselessString\n");
        }
    } else if (search == 2) {
        int uselessInt;
        printf(CYN "Enter uselessInt: ");
        scanf("%i", &uselessInt);
        int index = linearSearch(uselessArray, size, uselessInt);
        if (index != -1) {
            printSingleRecord(uselessArray[index]);
        } else {
            printf(RED "Unable to find uselessInt\n");
        }
    } else {
        printf(RED "Your choice\n");
    }
}

// prints a reverse order of the uselessArray to a file
// saved the array in forward and reverse order
void reverseOrder(USELESS *uselessArray, unsigned int size)
{
    int shouldPrint = 0;
    printf(CYN "Do you want to print the elements in reverse order onto a seperate file (0 for yes and 1 for no): ");
    scanf("%i", &shouldPrint);
    if (shouldPrint == 0)
    {
        for(size_t i = 0; i < size; ++i)
        {
            saveRecord(&uselessArray[i], "dataReverse.txt");
        }
        for(size_t j = 0; j < size; ++j)
        {
            saveRecord(&uselessArray[size - j - 1], "dataReverse.txt");
        }
    }
}

// sorts the uselessArray
// 3 useless sorting algorithm available for the useless user
void sort(USELESS* uselessArray, unsigned int size)
{
    /**
     * descending = 0;
     * ascending = 1;
     */
    int order = 0;
    /**
     * bubble sort = 0;
     * selection sort = 1;
     * insertion sort = 2;
     */
    int sortAlgo = 0;
    /**
     * uselessInt = 0;
     * uselessFloat = 1;
     */
    int uselessType = 0;
    printf(CYN "Do you want to sort in ascending or descending order (0 for descending and 1 for ascending): ");
    scanf("%i", &order);
    printf(CYN "Do you want to use bubble sort or selection sort or insertion sort (0 for bubble and 1 for selection and 2 for insertion): ");
    scanf("%i", &sortAlgo);
    printf(CYN "Do you want to sort with respect to uselessInt or uselessFloat (0 for uselessInt and 1 for uselessFloat): ");
    scanf("%i", &uselessType);
    if (sortAlgo == 0) {
        bubbleSort(uselessArray, size, order, uselessType);
    } else if(sortAlgo == 1) {
        selectionSort(uselessArray, size, order, uselessType);
    } else {
        insertionSort(uselessArray, size, order, uselessType);
    }
    for(size_t i = 0; i < size; ++i)
    {
        saveRecord(&uselessArray[i], "dataSort.txt");
    }
}

// inserts a uselessArray into the useless Linked List
void insertToList(LINKEDLIST **sPtr, USELESS uselessArray)
{
    LINKEDLIST* newPtr = malloc(sizeof(LINKEDLIST));
    strcpy(newPtr->useless.uselessString, uselessArray.uselessString);
    newPtr->useless.uselessInt = uselessArray.uselessInt;
    newPtr->useless.uselessFloat = uselessArray.uselessFloat;
    newPtr->next = NULL;

    if (newPtr != NULL) {
        LINKEDLIST* previousPtr = NULL;
        LINKEDLIST* currentPtr = *sPtr;

        while (currentPtr != NULL && uselessArray.uselessInt > currentPtr->useless.uselessInt) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (previousPtr == NULL) {
            newPtr->next = *sPtr;
            *sPtr = newPtr;
        } else {
            printf(RED "INSERTED\n");
            previousPtr->next = newPtr;
            newPtr->next = currentPtr;
        }

    } else {
        fprintf(stderr, RED "No memory found to allocate newPtr\n");
    }
}

// prints the useless linked list
void printList(LINKEDLIST *sPtr) {
    LINKEDLIST* currentPtr = sPtr;
    if (currentPtr == NULL) {
        printf(RED "NULL PROVIDED\n");
    }
    while (currentPtr != NULL) {
        printSingleRecord(currentPtr->useless);
        currentPtr = currentPtr->next;
    }
}

// the main useless function
int main(int argc, char const *argv[])
{
    unsigned int size = 5;
    USELESS* uselessArray = (USELESS*)malloc(size * sizeof(USELESS));
    LINKEDLIST* uselessList = NULL;
    for(size_t i = 0; i < size; ++i)
    {
        addRecord(&uselessArray[i], 1);
    }
    int option = 0;
    unsigned int amount = 0;
    USELESS justOneUselessArray;
    do {
        showOptions();
        scanf("%i", &option);
        switch (option)
        {
            case 1:
                sort(uselessArray, size);
                break;
            case 2:
                searchInt(uselessArray, size);
                break;
            case 3:
                uselessArray = (USELESS*)realloc(uselessArray, (size + 1) * sizeof(USELESS));
                size += 1;
                insertElement(uselessArray, size);
                reverseOrder(uselessArray, size);
                break;
            case 4:
                selectionSort(uselessArray, size, 1, 0);
                for(size_t i = 0; i < size; ++i)
                {
                    insertToList(&uselessList, uselessArray[i]);
                }
                printList(uselessList);
                break;
            case 5:
                printf(GRN "How many elements do you want to insert into the linked list: ");
                scanf("%i", &amount);
                for(size_t i = 0; i < amount; ++i)
                {
                    addRecord(&justOneUselessArray, 0);
                    insertToList(&uselessList, justOneUselessArray);
                }
                printList(uselessList);
                break;
            default:
                printf(RED "UNKOWN OPTION\n");
                break;
        }
    } while (option != 6);
    printf(RED "QUITTING\n");
    return 0;
}
