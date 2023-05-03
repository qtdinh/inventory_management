#ifndef DVD_H
#define DVD_H
#include "Item.h"

class DVD : public Item
{
private:
	string leadActor;
	int playTime;
	const double DVD_MARKUP = 0.40;
public:
    DVD() : Item(0, 0.0, "", "", ""), leadActor(""), playTime(0)
	{
		setMarkUp(DVD_MARKUP);
	}
	DVD(string, string, string, string, int, int, double);
	string getLeadActor() const;
	int getPlayTime() const;
	void setLeadActor(string);
	void setPlayTime(int);
	virtual void printReport() const override;

	~DVD() {}
};
#endif

