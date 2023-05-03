#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int DEFAULT_SKU = 1000;

class Item
{
private:
	string title, creator, description, itemType;
	double cost, markup;
	int quantity, stockKeepUnit;
	static int objectCount;
	bool shortage = false;
public:
	Item();
	Item(int, double, string, string, string);
	Item(const Item&);
	string getTitle() const;
	string getCreator() const;
	string getDescription() const;
	string getItemType() const;
	double getCost() const;
	double getMarkUp() const;
	int getQuantity() const;
	int getSKU() const;
	bool getShortage() const;
	void setItem(int, double, string, string, string);
	void setTitle(string);
	void setCreator(string);
	void setDescription(string);
	void setItemType(string);
	void setCost(double);
	void setQuantity(int);
	void setMarkUp(double);
	void setShortage(bool);
	virtual double getPrice() const;
	double getTotal() const;
	virtual void printReport() const;
	static int getStockCount()
	{
		return objectCount;
	}
	virtual ~Item()
	{
		objectCount--;
	}

};
#endif
