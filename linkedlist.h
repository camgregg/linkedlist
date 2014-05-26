// linkedlist.h

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct  ListItem {
	int data;
	struct ListItem *next;
};

struct LinkedList {
	char *ListName;
	struct ListItem *firstListItem;
};

// create new list
struct LinkedList* newLinkedList();

// destroy list
void deleteLinkedList(struct LinkedList* list);

// add an item to an already exisiting list
void addListItem(struct LinkedList* list, int data);

void deleteListItem(struct ListItem* item);

struct ListItem* getLastItem(struct LinkedList* list);

void printList(struct LinkedList* list);

void BubbleSortList(struct LinkedList* list);

int getListLength(struct LinkedList* list);
#endif
