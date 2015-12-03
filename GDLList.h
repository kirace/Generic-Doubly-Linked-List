/*
	Kevin Irace
	Prof. Signorile
	GDLList.h (Assignment 4)
	March 18, 2015

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct node{
	void * item;
	struct node * next;
	struct node * prev;
}node_t;


typedef struct gdlList{
	node_t * head;
	node_t * tail;
}gdlList_t;

typedef gdlList_t * List; 

List gdlList_new(void); //creates a new Generic Doubly-Linked List

void insertNodeEnd(List list, void * item); //inserts item into a node at the end of the list 

void traverseForward(List list); //

void traverseBackward(List list); // 

void deleteNode(List list, void * targetItem); //searches for specific item, deletes node from list 

void * getItem(List list, int targetNodeIndex);
