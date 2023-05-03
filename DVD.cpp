#include "DVD.h"

DVD::DVD(string dvdTitle, string director, string genre, string dvdActor, int dvdPlayTime, int dvdQuantity, double dvdCost)
	: Item(dvdQuantity, dvdCost, dvdTitle, director, genre), leadActor(dvdActor), playTime(dvdPlayTime)
{
	setMarkUp(DVD_MARKUP);
	setItemType("DVD");
}

string DVD::getLeadActor() const
{
	return leadActor;
}

int DVD::getPlayTime() const
{
	return playTime;
}

void DVD::setLeadActor(string myActor)
{
	leadActor = myActor;
}

void DVD::setPlayTime(int myPlayTime)
{
	playTime = myPlayTime;
}

void DVD::printReport() const
{
	Item::printReport();
	cout << "Director: " << getCreator() << endl;
	cout << "Lead actor: " << getLeadActor() << endl;
	cout << "Playing time: " << getPlayTime() << endl;
	cout << "Genre: " << getDescription() << endl;
}
