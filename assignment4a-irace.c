/*
	Kevin Irace
	Prof. Signorile
	Assignment 4 Part A
	March 18, 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "GDLList.h"
//compile with GDLList.c


int main(){
	List list;
	list = gdlList_new();
	node_t * node1;
	void * item1;
	void * item2;
	void * item3;
	void * item4;
	void * item5;
	void * deleteItem;
	int ans;

	item1 = (void*)("Hello");
	item2 = (void*)("I");
	item3 = (void*)("am");
	item4 = (void*)("Kevin");
	item5 = (void*)("deleteMe");
	deleteItem = (void*)("deleteMe");
	

	insertNodeEnd(list, item1);
	insertNodeEnd(list, item2);
	insertNodeEnd(list, item3);
	insertNodeEnd(list, item5);
	insertNodeEnd(list, item4);

	printf("Forward traversal: ");
	traverseForward(list);
	printf("Backward traversal: ");
	traverseBackward(list);
	printf("Length of List: %d \n", list_length(list));
	printf("Item at Location 4: %s\n", (char*)getItem(list, 4));

	printf("\nNow, delete.\n\n");
	deleteNode(list, deleteItem);

	printf("Forward traversal: ");
	traverseForward(list);
	printf("Backward traversal: ");
	traverseBackward(list);
	printf("Length of List: %d \n", list_length(list));
	printf("Item at Location 4: %s\n", (char*)getItem(list, 4));
	
	
return 0;

}
