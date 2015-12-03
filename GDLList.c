/*
	Kevin Irace
	Prof. Signorile
	GDLList.c (Assignment 4)
	March 18, 2015

*/


#include "GDLList.h"


List gdlList_new(void){
	List oList;
	oList = (List)malloc(sizeof(gdlList_t));
	oList->head = NULL;
	return oList;
}

node_t* node_new(void){
	node_t* oNode;
	oNode = (node_t*)malloc(sizeof(node_t));
	return oNode;
}

void insertNodeEnd(List oList, void * item){
	node_t * newNode = node_new();
	newNode->item = item;
	if(oList->head == NULL){
		oList->head = newNode;
		oList->tail = newNode;
	}
	else{
		
		oList->tail->next = newNode;
		newNode->prev = oList->tail;
		oList->tail = newNode;
	}
}

void deleteNode(List oList, void * targetItem){
	node_t * current = oList->head;
	node_t * n;
	node_t * p;
	if(oList == NULL){
		printf("ERROR: EMPTY LIST");
		return;
	}
	else if(oList->head->next == NULL){
		if(current->item == targetItem){
			oList->head = NULL;
			oList->tail = NULL;
		}
		else{
			printf("Only one node in list, no match\n");
			return;}
	}
	else{
		while(current->next != NULL){
		      	if(current->item == targetItem){
				n = current->next;
				p = current->prev;
				current->prev->next = n;
				current->next->prev = p;
				return;
			}
			else{current = current->next;}
		}
		if(current->item == targetItem){
			oList->tail = current->prev;
			current->prev->next = NULL;
		}
		else{
			printf("Last node in list, no match\n");
			return;}
		
	}
}

void traverseForward(List oList){
	node_t *current;
	if(oList->head == NULL){
		printf("ERROR: EMPTY LIST\n");
		return;
	}
	current = oList->head;
	printf("%s\t",(char*)current->item);
	while(current->next != NULL){
		current = current->next;
		printf("%s\t",(char*)(current->item));
	}
printf("\n");
return;
}	

void traverseBackward(List oList){
	node_t *node;
	if(oList->tail == NULL){
		printf("ERROR: EMPTY LIST\n");
		return;
	}
	node = oList->tail;
	char * c;
	int x;
	printf("%s\t",(char*)(node->item));
	while(node->prev != NULL){
		node = node->prev;
		printf("%s\t",(char*)(node->item));
	}
printf("\n");
return;
}


int list_isEmpty(List list){
	if(list->head == NULL){	
		return 1; 
	}
	else{ 
		return 0; 
	}
}


int list_length(List list){
	int x = 0;
	node_t * current = list->head;
	if(current == NULL) return 0;
	if(current->next == NULL) return 1;
	while(current->next != NULL){
		current = current->next;
		x++;
	}
	return x+1;
}

void * getItem(List oList, int targetNodeIndex){
	node_t * current;
	current = oList->head;
	int target = targetNodeIndex;
	void * item;
	int x;
	for(x = 0; x < (target-1); x++){
		current = current->next;
	}
	item = (void*)current->item;
	
	return item;
}
