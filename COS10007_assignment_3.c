#include <stdio.h>
#include <stdlib.h>

struct studentid
{
  int id;
  struct studentid *next;
};

typedef struct studentid STUDENTID;
typedef STUDENTID *STUDENTIDPtr;

void insert(STUDENTIDPtr *sPtr, int id);
void print(STUDENTIDPtr sPtr);
void bubbleSort(STUDENTIDPtr start);
void swap(STUDENTIDPtr a, STUDENTIDPtr b);

int main(int argc, char const *argv[])
{
  STUDENTIDPtr list = NULL;
  insert(&list, 8);
  insert(&list, 9);
  insert(&list, 6);
  insert(&list, 7);
  insert(&list, 4);
  printf("Old list\n");
  print(list);

  bubbleSort(list);
  printf("New list\n");
  print(list);

  return 0;
}

void insert(STUDENTIDPtr *sPtr, int id)
{
  STUDENTIDPtr newPtr = malloc(sizeof(STUDENTIDPtr));
  newPtr->id = id;
  newPtr->next = NULL;

  if (newPtr != NULL)
  {
    STUDENTIDPtr previousPtr = NULL;
    STUDENTIDPtr currentPtr = *sPtr;

    while (currentPtr != NULL)
    {
      previousPtr = currentPtr;
      currentPtr = currentPtr->next;
    }

    if (previousPtr == NULL)
    {
      newPtr->next = *sPtr;
      *sPtr = newPtr;
    }
    else
    {
      previousPtr->next = newPtr;
      newPtr->next = currentPtr;
    }
  }
  else
  {
    fprintf(stderr, "No memory found to allocate newPtr of id:%i\n", id);
  }
}

void print(STUDENTIDPtr sPtr)
{
  STUDENTIDPtr currentPtr = sPtr;
  printf("ID: ");
  while (currentPtr != NULL)
  {
    printf("%i -> ", currentPtr->id);
    currentPtr = currentPtr->next;
  }
  printf("END\n");
}

void bubbleSort(STUDENTIDPtr start)
{
  int swapped, i;
  STUDENTIDPtr ptr1;
  STUDENTIDPtr lptr = NULL;

  if (start == NULL)
  {
    return;
  }

  do
  {
    swapped = 0;
    ptr1 = start;

    while (ptr1->next != lptr)
    {
      if (ptr1->id > ptr1->next->id)
      {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

void swap(STUDENTIDPtr a, STUDENTIDPtr b)
{
  int temp = a->id;
  a->id = b->id;
  b->id = temp;
}
