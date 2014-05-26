#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
 struct LinkedList *numberlist = newLinkedList();
 addListItem(numberlist,666);
 addListItem(numberlist,6);
 addListItem(numberlist,7999);
 addListItem(numberlist,8);
 addListItem(numberlist,47);
 addListItem(numberlist,92383);
 addListItem(numberlist,309);
 addListItem(numberlist,54903);
 addListItem(numberlist,83);
 addListItem(numberlist,8333);
 addListItem(numberlist,333);
 addListItem(numberlist,8333);
 addListItem(numberlist,8);
 addListItem(numberlist,97);
 addListItem(numberlist,101);
 printList(numberlist);
 printf("Length: %d\n",getListLength(numberlist));
 BubbleSortList(numberlist);
// ptrTest(numberlist);
printList(numberlist);
 deleteLinkedList(numberlist);
 return 0;
}; 
