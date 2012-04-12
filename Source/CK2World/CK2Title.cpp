#include "CK2Title.h"



void CK2Title::init(Object* obj,  map<int, CK2Character*>& characters)
{
	titleString = obj->getKey();
	vector<Object*> liegeObjs = obj->getValue("liege");
	if (liegeObjs.size() > 0)
	{
		liegeString = liegeObjs[0]->getLeaf();
	}

	independent	= true;
	inHRE			= false;

	vector<Object*> holderObjs = obj->getValue("holder");
	if (holderObjs.size() > 0)
	{
		holder = characters[ atoi( holderObjs[0]->getLeaf().c_str() ) ];
	}

	heir = NULL;
	genderLaw = obj->getLeaf("gender");
	successionLaw = obj->getLeaf("succession");
	if (successionLaw == "primogeniture")
	{
		CK2Character* tempHolder = holder;
		do
		{
			heir = tempHolder->getPrimogenitureHeir(genderLaw);
			tempHolder = tempHolder->getFather();
			if (tempHolder == NULL)
			{
				break;
			}
		} while (heir == NULL);
	}
	else if (successionLaw == "gavelkind")
	{
		heir = NULL;
	}
	else if (successionLaw == "seniority")
	{
		heir = NULL;
	}
	else if (successionLaw == "feudal_elective")
	{
		heir = NULL;
	}
	else if (successionLaw == "turkish_succession")
	{
		heir = NULL;
	}

	vector<Object*> historyObjs = obj->getValue("history");
	if (historyObjs.size() > 0)
	{
		historyObjs = historyObjs[0]->getLeaves();
		for (unsigned int i = 0; i < historyObjs.size(); i++)
		{
			CK2History* newHistory = new CK2History();
			newHistory->init(historyObjs[i], characters);
			history.push_back(newHistory);
		}
	}

	
}


void CK2Title::addLiege(CK2Title* newLiege)
{
	liege = newLiege;
	liege->addVassal(this);

	independent = false;
}


void CK2Title::addVassal(CK2Title* vassal)
{
	vassals.push_back(vassal);
}


void CK2Title::addToHRE()
{
	inHRE = true;
}


string CK2Title::getTitleString()
{
	return titleString;
}


CK2Character* CK2Title::getHolder()
{
	return holder;
}


CK2Character* CK2Title::getHeir()
{
	return heir;
}


vector<CK2History*> CK2Title::getHistory()
{
	return history;
}


string CK2Title::getLiegeString()
{
	return liegeString;
}


CK2Title* CK2Title::getLiege()
{
	return liege;
}


bool CK2Title::isIndependent()
{
	return independent;
}


bool CK2Title::isInHRE()
{
	return inHRE;
}



CK2Title::~CK2Title()
{
/*	while (vassals.size() > 0)
	{
		CK2Title* currentTitle = vassals[vassals.size() - 1];
		delete currentTitle;
		vassals.pop_back();
	}*/
}