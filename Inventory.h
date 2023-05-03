#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include "CD.h"
#include "DVD.h"

const int MAX_SIZE = 1000;

class Inventory
{
private:
	const double SALES_TAX = 0.0925;
	Item* inventory[MAX_SIZE];
	int numItems = 0;
public:
	void start();
	void itemMenu(char&);
	void orderInput();
	void bookInput();
	void cdInput();
	void dvdInput();
	void sale();
	void printReceipt(int, int, double, double, bool) const;
	void printReport() const;

};
#endif