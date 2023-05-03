#include "Book.h"

Book::Book(string bookTitle, string bookAuthor, string bookDescription, int bookQuantity, double bookCost)
	: Item(bookQuantity, bookCost, bookTitle, bookAuthor, bookDescription)
{
	setMarkUp(BOOK_MARKUP);
	setItemType("Book");
}

void Book::printReport() const
{
	Item::printReport();
	cout << "Author: " << getCreator() << endl;
	cout << "Description: " << getDescription() << endl;
}