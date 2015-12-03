/*
	Kevin Irace
	Prof. Signorile
	Assignment 4 Part B
	March 18, 2015
*/
#include "GDLList.h"
#include "stock.h"

//Unfortunately, my toString function only represents each stock by its name

int test_eof(char a);
int test_eol(char a);
void * parseItem(char **s);
char * returnLine(FILE *fp);
stock_t * lineToStock(char * s);
void printLine(char *line);

int main(){
	
	List stockList;
	stock_t * newStock;
	stockList = gdlList_new(); 	 
	
	char * line;
	FILE *file;
	stock_t * nS;

	/* opening file for reading */
	file = fopen("stocks.txt", "r");
	if(file == NULL){
		perror("Error opening file");
		return(-1);
	}

	line = returnLine(file);
	//printLine(line);
	while(line != NULL){
		nS = lineToStock(line);
		insertNodeEnd(stockList, nS);
		line = returnLine(file);
		
	}
	fclose(file);
	


	node_t *current = stockList->head;
	stock_t * stock;
	float q;
	//int b = 1;

	int choice = -1;
	choice = menu();
	while(choice != 4){
		switch(choice){
		case 1:
			printf("Enter amount: ");
			scanf("%f", &q);
			if(current == NULL){ printf("NONE FOUND"); break;}
			while(current->next != NULL){
				stock = (stock_t*)current->item;
				if(getPrice(stock) > q){
					printf("%s\n", (char*)toString(stock));
				}
				//b++;
				current = current->next;
			}
			current = stockList->head;
			break;
		case 2:
			printf("Enter amount: ");
			scanf("%f", &q);
			if(current == NULL){break;}
			while(current->next != NULL){
				stock = (stock_t*)current->item;
				//printf("%f", getPercentChange(stock));
				if(getPercentChange(stock) > q){
					printf("%s\n", (char*)toString(stock));
				}
				//b++;
				current = current->next;
			}
			current = stockList->head;
			break;
		case 3:
			printf("Complete list of stocks: \n");
			if(current == NULL){ printf("EMPTY LIST"); break;}
			while(current->next != NULL){
				stock = (stock_t*)current->item;
				printf("%s\n", (char*)toString(stock));
				current = current->next;
			}
			current = stockList->head;
			break;
		case 4:
			printf("Goodbye.\n");
			return 0;
		}
		printf("\n");
		choice = menu();
	}
	printf("Goodbye.\n");
	return 0;
}

int menu(){
	int a;
	char carraigeReturn;
	puts("Welcome to Kevin's Stocks");
	puts("please choose from the following choices");
	puts("1. Search/print stock with closing price > some amount");
	puts("2. Search/print stock with % > some amount");
	puts("3. List all of the stocks using toString");
	puts("4. Quit and leave");
	scanf("%d%c", &a, &carraigeReturn);
	return a;
}

char * returnLine(FILE *fp){
	char c;
	char *line;
	int size = 0;
	line = NULL;
	line = realloc(line, sizeof(char));
	c = fgetc(fp); 
	if(test_eof(c)==1)
		return NULL;
	while(test_eol(c)==0){
		*(line+size) = c;
		size++;
		line = realloc(line, sizeof(char)*(size+1));
		c = fgetc(fp);
	}
	*(line+size) = '\0';
	return line;
}

	
int test_eol(char a){
	if(a == '\n')
		return 1;
	else 
		return 0;
}
int test_eof(char a){
	if(a == EOF)
		return 1;
	else
		return 0;
}
 
stock_t * lineToStock(char * s){ 
	char *name; 
	float openingPrice; 
	float closingPrice; 
	int numberOfShares; 
	int i = 0;  
	stock_t * nStock; 
	name = (char *)malloc(sizeof(char)); 
	while(*(s+i) !=' '&& *(s+i) != '\0'){ 
		*(name+i) = *(s+i); 
		i++; 
		name = realloc(name,i+1); 
	}
	*(name+i) = '\0'; 
	i++;
	openingPrice = (float)strtof(s+i,NULL);
	while(*(s+i) !=' ' && *(s+i) != '\0'){
		i++;
	}
	i++;
	closingPrice = (float)strtof(s+i, NULL);
	while(*(s+i) !=' ' && *(s+i) != '\0'){
		i++;
	}
	i++;
	numberOfShares = (int)atoi(s+i);
nStock = newStock(name, closingPrice, openingPrice, numberOfShares);
return nStock; 
}


void printLine(char *line){
  int i=0;
  while (*(line+i) != '\0'){
    printf("%c",*(line+i)); 
    i++;
  }
  printf("\n");
}
