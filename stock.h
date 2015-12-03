/*
	Kevin Irace
	Prof. Signorile
	stock.h (Assignment 4)
	March 18, 2015

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 10

typedef struct stock{
	char * stockSymbol;
	float closingSharePrice;
	float openingSharePrice;
	int numberOfShares;
	float (* getPrice)(void * S);
	float (* getTotalDollarAmount)(void * S);
	float (* getPercentChange)(void * S);
	char *(* toString)(void *S);
}stock_t;

stock_t * newStock(char * name, float closingSharePrice, float openingSharePrice, int numberOfShares);

float getPrice(void * S);

float getTotalDollarAmount(void * S);

float getPercentChange(void * S);

char *toString(void *S);
