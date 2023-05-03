#ifndef CD_H
#define CD_H
#include "Item.h"

class CD : public Item
{
private:
	int tracks, playTime;
	const double CD_MARKUP = 0.30;
public:
	CD() : Item(0, 0.0, "", "", ""), tracks(0), playTime(0)
	{
		setMarkUp(CD_MARKUP);
	}
	CD(string, string, string, int, int, int, double);
	int getTracks() const;
	int getPlayTime() const;
	void setTracks(int);
	void setPlayTime(int);
	virtual void printReport() const override;

	~CD() {}
};
#endif
