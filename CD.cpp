#include "CD.h"

CD::CD(string discTitle, string artistName, string genre, int discTracks, int discTime, int discQuantity, double discCost)
	: Item(discQuantity, discCost, discTitle, artistName, genre), tracks(discTracks), playTime(discTime)
{
	setMarkUp(CD_MARKUP);
	setItemType("CD");
}

int CD::getTracks() const 
{
	return tracks;
}

int CD::getPlayTime() const
{
	return playTime;
}

void CD::setTracks(int myTracks)
{
	tracks = myTracks;
}

void CD::setPlayTime(int myPlayTime)
{
	playTime = myPlayTime;
}

void CD::printReport() const
{
	Item::printReport();
	cout << "Artist name: " << getCreator() << endl;
	cout << "Number of tracks: " << getTracks() << endl;
	cout << "Playing time: " << getPlayTime() << endl;
	cout << "Genre: " << getDescription() << endl;
}
