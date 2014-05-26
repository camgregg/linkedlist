// linkedlist.c

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"



struct LinkedList* newLinkedList() {
 struct LinkedList *newLinkedList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
 newLinkedList->firstListItem = NULL;
 return newLinkedList;
}

void deleteLinkedList(struct LinkedList* list) {
 if ( list->firstListItem != NULL) {
  deleteListItem(list->firstListItem);
 }
 free(list);
}

void deleteListItem(struct ListItem* item) {
 if ( item->next != NULL) {
  deleteListItem(item->next);
 }
 free(item);
}


void addListItem(struct LinkedList* list, int data) {
 struct ListItem *newListItem = (struct ListItem*)malloc(sizeof(struct ListItem));
 newListItem->data = data;
 newListItem->next = NULL;
 struct ListItem *lastListItem = getLastItem(list);
 if (lastListItem == NULL) {
  list->firstListItem = newListItem;
 } else {
  lastListItem->next = newListItem;
 }
}

struct ListItem* getLastItem(struct LinkedList* list) {
// returns NULL if there is nothing in the list
 struct ListItem* lastItem = list->firstListItem;
 if ( lastItem !=NULL ) {
  while ( lastItem->next != NULL) {
   lastItem = lastItem->next;
  }
 } 
 return lastItem;
}

void printList(struct LinkedList* list) {
 if ( list != NULL ) {
  struct ListItem* currentListItem = list->firstListItem;
  while ( currentListItem != NULL) {
   printf("%d\n",currentListItem->data);
   currentListItem = currentListItem->next;
  }
 } else {
  printf("The list is empty.\n");
 }
}

void BubbleSortList(struct LinkedList* list) {
// sort items from lowest to highest
 if ( (list != NULL) & (list->firstListItem != NULL) & (list->firstListItem->next !=NULL) ) {
 int length = getListLength(list);

  while ( length > 1 ) {

   struct ListItem** currentItemPtr = &(list->firstListItem);
   struct ListItem** nextItemPtr = &(list->firstListItem->next);
   struct ListItem* tempItem = NULL;

   int count = length;
   while ( count > 1) {
    if ( (*currentItemPtr)->data < (*nextItemPtr)->data ) {
     // swap items
     tempItem = *currentItemPtr;
     *currentItemPtr = (*currentItemPtr)->next;
     *nextItemPtr = (*nextItemPtr)->next;
     (*currentItemPtr)->next = tempItem;
    } else {
    // move along one
     nextItemPtr = &((*nextItemPtr)->next);
    }
    count--;
    // move along one
    currentItemPtr = &((*currentItemPtr)->next);
   }
   length--;
  }
 
 }  

}

void ptrTest(struct LinkedList* list) {

 struct ListItem** currentItemPtr = &list->firstListItem;



 printf("currentItemPtr: %p\n",*currentItemPtr);
 printf("currentItemPtr*: %p\n",list->firstListItem);
// printf("list: %p\n",list);
/* int **a = (int**)malloc(sizeof(int**));
 int *b = (int*)malloc(sizeof(int*));
 int c = 2;
 b = &c;
 a = &b;
 printf("%p\n",&c);
 printf("%p\n",b);
 printf("%p\n",*a); */
}


int getListLength(struct LinkedList* list) {
 int length = 0;
 struct ListItem* currentListItem;
 if ( (list != NULL) & (list->firstListItem != NULL) ) {
  currentListItem = list->firstListItem;
  length = 1;
  while (currentListItem->next != NULL) {
   length++;
   currentListItem = currentListItem->next;
  }
 }
 return length;
}




