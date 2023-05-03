#include "Inventory.h"

void Inventory::start()
{
	int menuChoice = 0;
	char itemChoice = 'M';
	cout << " 1) To enter a new item, enter 1" << endl;
	cout << " 2) To enter an order, enter 2" << endl;
	cout << " 3) For Sale, enter 3" << endl;
	cout << " 4) For a complete report, enter 4" << endl;
	cout << " 5) To quit, enter 5" << endl;
	cin >> menuChoice;
	cout << endl;
	switch (menuChoice)
	{
	case 1:
		itemMenu(itemChoice);
			switch (itemChoice)
			{
				case 'B':
					bookInput();
					break;
				case 'C':
					cdInput();
					break;
				case 'D':
					dvdInput();
					break;
				case 'M':
					start();
					break;
				default:
					cout << "Please input one of the options displayed." << endl;
					itemMenu(itemChoice);
					break;
			}
			break;
	case 2:
		orderInput();
		break;
	case 3:
		sale();
		break;
	case 4:
		printReport();
		start();
		break;
	case 5:
		return;
	default:
		cout << "Please input one of the options displayed." << endl;
		start();
		break;
	}

}

void Inventory::itemMenu(char& myChoice)
{
	cout << " 1) To add a new Book, enter B" << endl;
	cout << " 2) To add a new CD, enter C" << endl;
	cout << " 3) To add a new DVD, enter D" << endl;
	cout << " 4) To return to the main menu, enter M" << endl;
	cin >> myChoice;
	myChoice = toupper(myChoice);
	cin.ignore();
	cout << endl;
}

void Inventory::orderInput()
{
	if (numItems == 0) {
		cout << "Inventory is empty." << endl;
		start();
		return;
	}

	int sku = 0, quantity = 0;
	double cost = 0;
	bool found = false;

	cout << "Enter SKU for new order: " << endl;
	cin >> sku;

	for (int i = 0; i < numItems; i++) {
		if (inventory[i]->getSKU() == sku) {
			found = true;
			break;
		}
	}
	if (found) {
	cout << "Enter the quantity received (0 if none): " << endl;
	cin >> quantity;
	while (quantity < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> quantity;
	}
	cout << "Enter the cost: " << endl;
	cin >> cost;
	while (cost < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> cost;
	}
	cin.ignore();
	inventory[sku - DEFAULT_SKU]->setQuantity((inventory[sku - DEFAULT_SKU]->getQuantity() + quantity));
	if (cost != inventory[sku - DEFAULT_SKU]->getCost())
		inventory[sku - DEFAULT_SKU]->setCost(cost);
	cout << "Your order has been received." << endl;
	}
	else {
		cout << "Item with SKU not found." << endl;
		start();
		return;
	}
	start();
}

void Inventory::bookInput()
{
	string title, author, description;
	double cost = 0;
	int quantity = 0;
	cout << "Enter title of the book: ";
	getline(cin, title);
	cout << "Enter author of the book: ";
	getline(cin, author);
	cout << "Enter a short description of the book: ";
	getline(cin, description);
	cout << "Enter the cost: ";
	cin >> cost;
	while (cost < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> cost;
	}
	cout << "Enter the quantity (0 if none): ";
	cin >> quantity;
	while (quantity < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> quantity;
	}
	inventory[numItems] = new Book(title, author, description, quantity, cost);
	numItems++;
	start();
}

void Inventory::cdInput()
{
	string title, artist, genre;
	int tracks = 0, playTime = 0, quantity = 0;
	double cost;
	cout << "Enter the title of the CD: ";
	getline(cin, title);
	cout << "Enter the name of the artist: ";
	getline(cin, artist);
	cout << "Enter the genre: ";
	getline(cin, genre);
	cout << "Enter the number of tracks: ";
	cin >> tracks;
	while (tracks < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> tracks;
	}
	cout << "Enter the playing time (in minutes): ";
	cin >> playTime;
	while (playTime < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> playTime;
	}
	cout << "Enter the quantity (0 if none): ";
	cin >> quantity;
	while (quantity < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> quantity;
	}
	cout << "Enter the cost: ";
	cin >> cost;
	while (cost < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> cost;
	}
	cin.ignore();
	inventory[numItems] = new CD(title, artist, genre, tracks, playTime, quantity, cost);
	numItems++;
	start();
}

void Inventory::dvdInput()
{
	string title, director, leadActor, genre;
	int playTime = 0, quantity = 0;
	double cost = 0;
	cout << "Enter the title of the DVD: ";
	getline(cin, title);
	cout << "Enter the name of the director: ";
	getline(cin, director);
	cout << "Enter the genre: ";
	getline(cin, genre);
	cout << "Enter the name of the lead actor: ";
	getline(cin, leadActor);
	cout << "Enter the playing time (in minutes): ";
	cin >> playTime;
	while (playTime < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> playTime;
	}
	cout << "Enter the quantity (0 if none): ";
	cin >> quantity;
	while (quantity < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> quantity;
	}
	cout << "Enter the cost: ";
	cin >> cost;
	while (cost < 0) {
		cout << "Must be a non-negative number!" << endl;
		cin >> cost;
	}
	cin.ignore();
	inventory[numItems] = new DVD(title, director, genre, leadActor, playTime, quantity, cost);
	numItems++;
	start();
}

void Inventory::sale()
{
	if (numItems == 0) {
		cout << "Inventory is empty." << endl;
		start();
		return;
	}

	int skuSold[MAX_SIZE] = { 0 };

	int sku, quantity = 0;
	bool processingSale = true, found = false;
	double subtotal = 0, total = 0, tax = 0;

	cout << "Enter the SKU of the item to sell: ";
	cin >> sku;

	while (processingSale) {
		found = false;

		for (int i = 0; i < numItems; i++) {
			if (inventory[i]->getSKU() == sku) {
				found = true;
				cout << "Enter the quantity to sell: ";
				cin >> quantity;
				if (inventory[i]->getQuantity() < quantity) {
					inventory[i]->setQuantity(0);
					inventory[i]->setShortage(true);
				}
				else
					inventory[i]->setQuantity(inventory[i]->getQuantity() - quantity);
					skuSold[inventory[i]->getSKU() - DEFAULT_SKU] += quantity;
			}
		}

		if (!found) {
			cout << "Item with SKU not found." << endl;
			start();
			return;
		}

		cout << "Next SKU or O to total: ";
		cin >> sku;
		if (sku == 0)
			processingSale = false;
	}

	for (int i = 0; i < numItems; i++) {
		if (skuSold[i] > 0) {
			total += inventory[i]->getPrice() * skuSold[i];
			printReceipt(inventory[i]->getSKU(), skuSold[i], inventory[i]->getPrice(), total, inventory[i]->getShortage());
		}
	}	

	if (found) {
		subtotal = total * (1 + SALES_TAX);
		tax = total * SALES_TAX;
		cout << "Total " << setw(32) << "$" << total << endl;
		cout << "Tax "  << setw(34) << "$" << tax << endl;
		cout << "Subtotal " << setw(29) << "$" << subtotal << endl;
	}
	start();
}

void Inventory::printReceipt(int mySKU, int soldQuantity, double myPrice, double myTotal, bool myShortage) const
{

	cout << mySKU << setw(10) << soldQuantity << setw(10) << "$" << myPrice << setw(10) << "$" << myTotal;
	if (myShortage)
		cout << " (Supply wasn't enough for demand)";
	cout << endl;

}

void Inventory::printReport() const
{
	if (numItems > 0)
	{
		for (int i = 0; i < numItems; i++)
		{
			inventory[i]->printReport();
			cout << "-------------------------------------------------------";
			cout << endl;
		}
	}
}