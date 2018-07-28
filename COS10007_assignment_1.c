#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * genre enum and string
 */
enum GenreEnum { action, adventure, rpg, simulation };
const char *GenreString[] = {
  "Action game",
  "Text adventure game",
  "Role-playing action game",
  "Construction and management simulation"
};

typedef enum GenreEnum Genre;

/** 
 * Game linked list
 */
struct game_list
{
  char name[256];
  enum GenreEnum genre;
  struct game_list *next;
};

typedef struct game_list Game;
typedef Game *GamePtr;


/**
 * Game orders queue list
 */
struct game_orders
{
  char name[256];
  struct game_orders *next;
};

typedef struct game_orders GameOrders;
typedef GameOrders *GameOrdersPtr;


/**
 * Game purchases stack list
 */
struct game_purchases
{
  char name[256];
  struct game_purchases *next;
}; 

typedef struct game_purchases GamePurchases;
typedef GamePurchases *GamePurchasesPtr;

void enqueue(GameOrdersPtr *ordersHead, GameOrdersPtr *ordersTail, char name[256]);
char* dequeue(GameOrdersPtr *ordersHead, GameOrdersPtr *ordersTail);
char* top(GameOrdersPtr ordersHead);
void printQueue(GameOrdersPtr currentPtr);

void insertGameAtTail(GamePtr *GamesHead, GamePtr *GamesTail, char name[256], Genre genre);
void insertGameAtHead(GamePtr *GamesHead, GamePtr *GamesTail, char name[256], Genre genre);
char* deleteGameAtHead(GamePtr *GamesHead, GamePtr *GamesTail);
char* deleteGameAtTail(GamePtr *GamesHead, GamePtr *GamesTail);
void deleteGameByName(GamePtr *GamesHead, GamePtr *GamesTail, char name[256]);
void printGames(GamePtr currentPtr);

void pushPurchases(GamePurchasesPtr *PurchaseHead, GamePurchasesPtr *PurchaseTail, char name[256]);
char* popPurchases(GamePurchasesPtr *GamesHead, GamePurchasesPtr *GamesTail);
char* topPurchases(GamePurchasesPtr ordersHead);
void printPurchases(GamePurchasesPtr currentPtr);


int main(int argc, char const *argv[]) {
  GameOrdersPtr ordersHead = NULL;
  GameOrdersPtr ordersTail = NULL;

  enqueue(&ordersHead, &ordersTail, "game 12");
  enqueue(&ordersHead, &ordersTail, "game 9");
  enqueue(&ordersHead, &ordersTail, "game 7");
  enqueue(&ordersHead, &ordersTail, "game 5");

  // dequeue(&ordersHead, &ordersTail);
  // printQueue(ordersHead);

  // dequeue(&ordersHead, &ordersTail);
  // printQueue(ordersHead);

  // printf("TOP: %s\n", top(ordersHead));

  GamePtr gameHead = NULL;
  GamePtr gameTail = NULL;

  insertGameAtHead(&gameHead, &gameTail, "game 5", action);
  insertGameAtHead(&gameHead, &gameTail, "game 7", adventure);

  insertGameAtTail(&gameHead, &gameTail, "game 9", rpg);
  insertGameAtTail(&gameHead, &gameTail, "game 12", simulation);


  // printGames(gameHead);

  // deleteGameAtHead(&gameHead, &gameTail);
  // printGames(gameHead);
  
  // deleteGameAtTail(&gameHead, &gameTail);
  // printGames(gameHead);
  
  // deleteGameByName(&gameHead, &gameTail, "game 5");
  // printGames(gameHead);

  GamePurchasesPtr purchaseHead = NULL;
  GamePurchasesPtr purchaseTail = NULL;

  // pushPurchases(&purchaseHead, &purchaseTail, "game 1");
  // pushPurchases(&purchaseHead, &purchaseTail, "game 2");
  // pushPurchases(&purchaseHead, &purchaseTail, "game 3");
  // pushPurchases(&purchaseHead, &purchaseTail, "game 4");
  // pushPurchases(&purchaseHead, &purchaseTail, "game 5");

  // printf("TOP PURCHASE: %s\n", topPurchases(purchaseHead)); // should print TOP PURCHASE: game 5

  // printPurchases(purchaseHead);

  // popPurchases(&purchaseHead, &purchaseTail);
  // popPurchases(&purchaseHead, &purchaseTail);

  // printf("TOP PURCHASE: %s\n", topPurchases(purchaseHead)); // should print TOP PURCHASE: game 3

  // printPurchases(purchaseHead);

  // we will print the queue to see the orders
  // and print the list of games available
  printQueue(ordersHead);
  printGames(gameHead);

  // there are 6 orders
  char currentOrderName[256];
  printf("Processing orders\n");
  for(size_t i = 0; i < 4; i++) {
    strcpy(currentOrderName, dequeue(&ordersHead, &ordersTail));
    deleteGameByName(&gameHead, &gameTail, currentOrderName);
    pushPurchases(&purchaseHead, &purchaseTail, currentOrderName);
    printf("Proceesed order with name: %s\n", currentOrderName);
  }

  // print the queue to make sure all the orders are processed
  // should print `Queue is empty.`
  printQueue(ordersHead);

  // we will print the games in the linked list
  // to see the available games after all orders are processed
  printGames(gameHead);
  
  for(size_t j = 0; j < 4; j++) {
    printf("LAST PURCHASE: %s\n", topPurchases(purchaseHead));
    // will remove the last purchase so we can see the purchase before that
    popPurchases(&purchaseHead, &purchaseTail);
  }
  
  
  return 0;
}

/**
 * queue
 */
void enqueue(GameOrdersPtr *ordersHead, GameOrdersPtr *ordersTail, char name[256]) {
  GameOrdersPtr newOrder = malloc(sizeof(GameOrdersPtr));
  
  if (newOrder != NULL) {
    strcpy(newOrder->name, name);
    newOrder->next = NULL;

    if ((*ordersHead) == NULL) {
      (*ordersHead) = newOrder;
    } else if ((*ordersTail) != NULL) {
      (*ordersTail)->next = newOrder;
    }

    *ordersTail = newOrder;
  } else {
    printf("Unable to add new order with name: %s. No memory available.\n", name);
  }
}

char* dequeue(GameOrdersPtr *ordersHead, GameOrdersPtr *ordersTail) {
  static char name[256];
	GameOrdersPtr tempOrder;
  strcpy(name, (*ordersHead)->name);
	tempOrder = *ordersHead;
	*ordersHead = (*ordersHead)->next;

	if (*ordersHead == NULL) {
		*ordersTail = NULL;
	}

	free(tempOrder);
	return name;
}

char* top(GameOrdersPtr ordersHead) {
  if (ordersHead == NULL) {
    return "";
  } else {
    return ordersHead->name;
  }
}

void printQueue(GameOrdersPtr currentPtr) {
	if (currentPtr == NULL) {
		puts("Queue is empty.\n");
	} else {
		printf("The queue is: ");
		while (currentPtr != NULL) {
			printf("%s --> ", currentPtr->name);
			currentPtr = currentPtr->next;
		}
		printf("END\n");
  }
}

/**
 * linked list
 */
void insertGameAtTail(GamePtr *GamesHead, GamePtr *GamesTail, char name[256], Genre genre) {
  GamePtr newGame = malloc(sizeof(GamePtr));

  if (newGame != NULL) {
    strcpy(newGame->name, name);
    newGame->genre = genre;
    newGame->next = NULL;

    if ((*GamesHead) == NULL) {
      (*GamesHead) = newGame;
    } else if ((*GamesTail) != NULL) {
      (*GamesTail)->next = newGame;
    }

    *GamesTail = newGame;
  } else {
    printf("Unable to add new game with name: %s. No memory available.\n", name);
  }
}

void insertGameAtHead(GamePtr *GamesHead, GamePtr *GamesTail, char name[256], Genre genre) {
  GamePtr newGame = malloc(sizeof(GamePtr));

  if (newGame != NULL) {
    strcpy(newGame->name, name);
    newGame->genre = genre;
    newGame->next = NULL;

    if ((*GamesHead) != NULL) {
      newGame->next = *GamesHead;
    } else {
      *GamesTail = newGame;
    }

    *GamesHead = newGame;
  } else {
    printf("Unable to add new game with name: %s. No memory available.\n", name);
  }
}

char* deleteGameAtHead(GamePtr *GamesHead, GamePtr *GamesTail) {
  static char name[256];
  GamePtr tempOrder;
  strcpy(name, (*GamesHead)->name);
	tempOrder = *GamesHead;
	*GamesHead = (*GamesHead)->next;

	if (*GamesHead == NULL) {
		*GamesTail = NULL;
	}

	free(tempOrder);
	return name;
}

char* deleteGameAtTail(GamePtr *GamesHead, GamePtr *GamesTail) {
  static char name[256];
  GamePtr currentPtr = *GamesHead;

  if (currentPtr != NULL) {
    /**
     * Check if it is only node in the list then delete
     * else then iterate till the next element matches the tail
     * and free the tail
     */
    strcpy(name, (*GamesTail)->name);
    if (currentPtr->next == NULL) {
      free(currentPtr);
      *GamesHead = NULL;
      *GamesTail = NULL;
    } else {
      while(currentPtr->next != (*GamesTail)){
        currentPtr = currentPtr->next;
      }
      free(currentPtr->next);
      currentPtr->next = NULL;
      (*GamesTail) = currentPtr;
    }
    return name;
  }
  return "";
}

void deleteGameByName(GamePtr *GamesHead, GamePtr *GamesTail, char name[256]) {
  /**
   * Loop throught the node as long as its not NULL (not the end)
   * and check if the name matches
   * If name matches then stop and do the following
   * if it is found and only one node then remove it and NULLify both pointers
   * if it is at head then free it and change the head pointer position
   * if it is at tail then change free next and set to NULL
   * otherwise just free the node and connect previousGame to currentGame->next
   */
  if ((*GamesHead) != NULL) {
    GamePtr previousGame = NULL;
    GamePtr currentGame = *GamesHead;

    while (currentGame->next != NULL && strcmp(name, currentGame->name) != 0) {
      previousGame = currentGame;
      currentGame = currentGame->next;
    }

    /**
     * The above loop could have stopped since it is the end of the list
     * so we need to check if it matches before removing
     * if true then we found the node else just ignore
     */
    if (strcmp(name, currentGame->name) == 0) {
      if (previousGame == NULL && currentGame->next == NULL) { // only one node
        free(currentGame);
        *GamesHead = NULL;
        *GamesTail = NULL;
      } else if (previousGame == NULL && currentGame->next != NULL) { // node at head
        *GamesHead = currentGame->next;
        free(currentGame);
      } else if (currentGame->next == NULL) { // node at tail
        previousGame->next = NULL;
        *GamesTail = previousGame;
        free(currentGame);
      } else { // node at random position
        previousGame = currentGame->next;
        free(currentGame);
      }
    } 
  }
}

void printGames(GamePtr currentPtr) {
	if (currentPtr == NULL) {
		puts("Game list is empty.\n");
	} else {
		printf("The game list is: ");
		while (currentPtr != NULL) {
			printf("%s --> ", currentPtr->name);
			currentPtr = currentPtr->next;
		}
		printf("END\n");
  }
}

/**
 * Stack
 */
void pushPurchases(GamePurchasesPtr *PurchaseHead, GamePurchasesPtr *PurchaseTail, char name[256]) {
  GamePurchasesPtr newPurchase = malloc(sizeof(GamePurchasesPtr));

  if (newPurchase != NULL) {
    strcpy(newPurchase->name, name);
    newPurchase->next = NULL;

    if ((*PurchaseHead) != NULL) {
      newPurchase->next = *PurchaseHead;
    } else {
      *PurchaseTail = newPurchase;
    }

    *PurchaseHead = newPurchase;
  } else {
    printf("Unable to add new purchase with name: %s. No memory available.", name);
  }
}

char* popPurchases(GamePurchasesPtr *PurchaseHead, GamePurchasesPtr *PurchaseTail) {
  static char name[256];
  GamePurchasesPtr tempOrder;
  strcpy(name, (*PurchaseHead)->name);
	tempOrder = *PurchaseHead;
	*PurchaseHead = (*PurchaseHead)->next;

	if (*PurchaseHead == NULL) {
		*PurchaseTail = NULL;
	}

	free(tempOrder);
	return name;
}

char* topPurchases(GamePurchasesPtr purchaseHead) {
  if (purchaseHead == NULL) {
    return "";
  } else {
    return purchaseHead->name;
  }
}

void printPurchases(GamePurchasesPtr currentPtr) {
	if (currentPtr == NULL) {
		puts("Game purchases is empty.\n");
	} else {
		printf("The game purchases is: ");
		while (currentPtr != NULL) {
			printf("%s --> ", currentPtr->name);
			currentPtr = currentPtr->next;
		}
		printf("END\n");
  }
}
