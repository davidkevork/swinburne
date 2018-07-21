#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackNode
{
	char data[2];
	struct stackNode *next;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void insert(StackNodePtr *sPtr, char data[2]);
void print(StackNodePtr *sPtr);

int main(int argc, char const *argv[])
{
    StackNodePtr startPtr = NULL;

    printf("Please enter a text: ");
    char ch = getchar();
    while(ch != '\n') {
        insert(&startPtr, &ch);
        ch = getchar();
    }

    print(&startPtr);
    
    return 0;
}

void insert(StackNodePtr *sPtr, char data[2]) {
    StackNodePtr newPtr = malloc(sizeof(StackNodePtr));
    strncpy(newPtr->data, data, sizeof(char));

    newPtr->next = NULL;
    if (newPtr != NULL) {
        if (sPtr != NULL) {
          newPtr->next = *sPtr;
        }
        *sPtr = newPtr;
    }
}

void print(StackNodePtr *sPtr) {
    StackNodePtr currentPtr = *sPtr;
    char text[256];
    char temp[256];

    char reversed[256];
    printf("Reverse string using stack: ");
    while (currentPtr != NULL) {
        strcpy(temp, text);
        strcpy(text, currentPtr->data);
        strncat(text, temp, sizeof(char)*256);

        strncat(reversed, currentPtr->data, sizeof(char)*256);

        printf("%s", currentPtr->data);
        currentPtr = currentPtr->next;
    }
    printf("\nIs the input palindrome string?: %s", (strcmp(reversed, text) == 0 ? "true" : "false"));
}
