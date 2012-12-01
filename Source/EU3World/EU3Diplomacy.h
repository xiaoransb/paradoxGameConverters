#ifndef EU3DIPLOMACY_H_
#define EU3DIPLOMACY_H_


#include "..\Date.h"
#include <vector>
using namespace std;

class Object;



struct EU3Agreement
{
	EU3Agreement();
	void output(FILE*);

	string	type;
	string	country1;
	string	country2;
	date		startDate;
};


class EU3Diplomacy
{
	public:
		EU3Diplomacy();
		void output(FILE*);
	private:
		vector<EU3Agreement>	agreements;
};

// Types of agreements:
//open_market - eventually care
//casus_belli - care
//royal_marriage - care
//guarantee - don't know
//alliance - don't know
//union - care
//sphere - don't know
//vassal - care

#endif