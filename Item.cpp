#include "Item.h"

int Item::objectCount = 0;

Item::Item() : quantity(0), cost(0.0), title(""), creator(""), description("")
{
	stockKeepUnit = DEFAULT_SKU + objectCount;
	markup = 0;
	itemType = "";
	objectCount++;
}

Item::Item(int myQuantity, double myCost, string myTitle, string myCreator, string myDescription)
	: quantity(myQuantity), cost(myCost), title(myTitle), creator(myCreator), description(myDescription)
{
	stockKeepUnit = DEFAULT_SKU + objectCount;
	markup = 0;
	itemType = "";
	objectCount++;
}

Item::Item(const Item& other)
{
	stockKeepUnit = DEFAULT_SKU + objectCount;
	quantity = other.quantity;
	cost = other.cost;
	title = other.title;
	creator = other.creator;
	markup = other.markup;
	objectCount++;
}

string Item::getTitle() const
{
	return title;
}

string Item::getCreator() const
{
	return creator;
}

string Item::getDescription() const
{
	return description;
}

string Item::getItemType() const
{
	return itemType;
}

double Item::getCost() const
{
	return cost;
}

double Item::getMarkUp() const
{
	return markup;
}

int Item::getQuantity() const
{
	return quantity;
}

int Item::getSKU() const
{
	return stockKeepUnit;
}

bool Item::getShortage() const
{
	return shortage;
}

void Item::setItem(int myQuantity, double myCost, string myTitle, string myCreator, string myDescription)
{
	quantity = myQuantity;
	cost = myCost;
	title = myTitle;
	creator = myCreator;
	description = myDescription;
}

void Item::setTitle(string myTitle)
{
	title = myTitle;
}

void Item::setCreator(string myCreator)
{
	creator = myCreator;
}

void Item::setDescription(string myDescription)
{
	description = myDescription;
}

void Item::setItemType(string myItemType)
{
	itemType = myItemType;
}

void Item::setCost(double myCost)
{
	cost = myCost;
}

void Item::setQuantity(int myQuantity)
{
	quantity = myQuantity;
}

void Item::setMarkUp(double myMarkUp)
{
	markup = myMarkUp;
}

void Item::setShortage(bool myShortage)
{
	shortage = myShortage;
}

double Item::getPrice() const
{
	return getCost() + (getCost() * getMarkUp());
}

double Item::getTotal() const
{
	return getQuantity() * getPrice();
}

void Item::printReport() const
{
	const int INVENTORY_LOW = 10;
	cout << "SKU " << getSKU() << " (" << itemType << ")" << endl;
	cout << "Number on hand: " << getQuantity() << endl;
	if (quantity < INVENTORY_LOW)
		cout << " (Inventory is low, place an order)" << endl;
	cout << setprecision(2) << fixed;
	cout << "Cost: " << getCost() << endl;
	cout << "Title: " << getTitle() << endl;
	cout << "Price: " << getPrice() << endl;
	cout << "Total $ value: " << getTotal() << endl;
}