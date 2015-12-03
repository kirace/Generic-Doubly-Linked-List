/*
	Kevin Irace
	Prof. Signorile
	stock.c (Assignment 4)
	March 18, 2015

*/

#include "stock.h"

stock_t * newStock(char * name, float closingSharePrice, float openingSharePrice, int numberOfShares){
	stock_t *newStock = (stock_t*)malloc(sizeof(stock_t));
	char * a;
	a = (char*)malloc(MAX * sizeof(char));
	a = name;
	newStock->stockSymbol = a;
	newStock->closingSharePrice = closingSharePrice;
	newStock->openingSharePrice = openingSharePrice;
	newStock->numberOfShares = numberOfShares;
	return newStock;
}

float getPrice(void * S){
	stock_t * stock;
	stock = (stock_t*)S;
	return stock->closingSharePrice;
}

float getTotalDollarAmount(void * S){
	stock_t * stock;
	stock = (stock_t*)S;
	float csp = stock->closingSharePrice;
	float nos = stock->numberOfShares;
	return (csp * nos);
}

float getPercentChange(void * S){
	stock_t * stock;
	stock = (stock_t*)S;
	float csp = stock->closingSharePrice;
	float osp = stock->openingSharePrice;
	return ((csp - osp)/osp)*100;
}

char *toString(void *S){
	stock_t * stock;
	stock = (stock_t*)S;
	return stock->stockSymbol;
}
