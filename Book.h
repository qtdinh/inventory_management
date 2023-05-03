#ifndef BOOK_H
#define BOOK_H
#include "Item.h"

class Book : public Item
{
private:
	const double BOOK_MARKUP = 0.25;
public:
	Book() : Item(0, 0.0, "", "", "")
	{
		setMarkUp(BOOK_MARKUP);
	}
	Book(string, string, string, int, double);
	virtual void printReport() const override;

	~Book() {}
};
#endif
