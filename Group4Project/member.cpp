#include "member.h"

//Default CTOR
Member::Member():name("Default Name"), iD("00000"){}

Member::Member(std::string name, std::string iD):name(name), iD(iD)
{
}

Member::Member(std::string paramName,
                std::string paramId,
                std::string paramMembership,
                std::string expiration)
{
    name = paramName;
    iD = paramId;
    membership = paramMembership;
    this->expiration = expiration;
}

Member::Member(std::string paramName,
                std::string paramId,
                std::string paramMembership,
                std::string expiration,
                float paramTotal)
{

}
//Sales Accessors
double Member::sumPurchasesDate(string date)
{
    double total = 0;
    Container<Item>::Iterator it;
    for(it = itemsBought.begin(); it != itemsBought.end();
        it++)
    {
        if((*it).getDateBought() == date)
        {
            total += (*it).getPrice();
        }

    }
    return total;

}

void Member::addItem(Item thing)
{
    cout << "Adding item to member's ItemsBought database." << endl;
    itemsBought.push_back(thing);
}

/*******************
* ACCESSOR(S)
********************/
std::string Member::getName()
{
	return name;
}

std::string Member::getId()
{
	return iD;
}

void Member::outputMemberInfo()
{
    std::cout << "Member Name: " << name << std::endl;
    std::cout << "Member iD: " << iD << std::endl;
}

char getMembership();
std::string getExpiration();
/*******************
* MUTATOR(S)
********************/
void Member::setName(std::string paramName)
{
	name = paramName;
}
void Member::setId(std::string paramId)
{
	iD = paramId;
}

bool Member::operator<(Member& rhs) const
{
    return(stoi(iD) < stoi(rhs.getId()));
}

bool Member::operator>(Member& rhs) const
{
    return(stoi(iD) > stoi(rhs.getId()));
}
void setMembership(char paramMembership);
void setExpiration(std::string expiration);
void setTotalSpent(float paramTotal);

//ItemsBoughtContainer
string Member::allPurchasesReport()
{
    string report;
    stringstream ss;
    Container<Item>::Iterator it;
    for(it = itemsBought.begin(); it != itemsBought.end();
        it++)
    {
        cout << (*it).allInfo() << endl;
        ss << (*it).allInfo() << endl;
    }
    report = ss.str();
    cout << "report: " << report << endl;
    return report;

}
