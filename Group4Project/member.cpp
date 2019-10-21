#include <iostream>
#include "member.h"

using namespace std;

//Default CTOR
Member::Member():name("Default Name"), iD("00000"){}

Member::Member(string name, string iD):name(name), iD(iD)
{
}

Member::Member(string paramName,
                string paramId,
                string paramMembership,
                string expiration)
{
    name = paramName;
    iD = paramId;
    membership = paramMembership;
    this->expiration = expiration;
    totalSpentPreTax = 0;
}

//Member::Member(string paramName,
//                string paramId,
//                string paramMembership,
//                string expiration,
//                float paramTotal)
//{

//}

//Sales Accessors
double Member::sumPurchasesDate(string date)
{
    double total = 0;
    Container<Item>::Iterator it;
    it = itemsBought.begin();
    for(int i = 0; i < itemsBought.length(); i++)
    {
        if((*it).getDateBought() == date)
        {
            total += (*it).getPrice();
        }
        it++;

    }
    return total;

}

void Member::addItem(const Item& thing)
{
    cout << thing << endl;

    itemsBought.push_back(thing);
    cout << "========ITEM HAS BEEN PUSHED========\n";
    totalSpentPreTax += thing.getPrice();

}

/*******************
* ACCESSOR(S)
********************/
string Member::getName()
{
	return name;
}

string Member::getId()
{
	return iD;
}

string Member::getMembership(){return membership;}
string Member::getExpiration(){return expiration;}
/*******************
* MUTATOR(S)
********************/
void Member::setName(string paramName)
{
	name = paramName;
}

void Member::setId(string paramId)
{
	iD = paramId;
}

Container<Item> Member::getItems() const
{
    return itemsBought;
}

bool Member::operator<(Member& rhs) const
{
    return(stoi(iD) < stoi(rhs.getId()));
}

bool Member::operator>(Member& rhs) const
{
    return(stoi(iD) > stoi(rhs.getId()));
}

ostream& operator<<(ostream& os, const Member& paramMember)
{
    os << "\n========MEMBER OBJECT========\n"
        << "MEMBER NAME: " << paramMember.name << "\n"
        << "MEMBER ID: " << paramMember.iD << "\n"
        << "MEMBERSHIP TYPE: " <<paramMember.membership << "\n"
        << "EXPIRATION: " << paramMember.expiration << "\n"
        << "Total Spent: " << paramMember.totalSpentPreTax << "\n"
        << "ITEMS CONTAINER: \n"
        << paramMember.itemsBought << "\n"; 
    return os;
}

void Member::setMembership(char paramMembership){membership = paramMembership;}
void Member::setExpiration(string expiration){this->expiration = expiration;}
void Member::setTotalSpent(float paramTotal){this->totalSpentPreTax = paramTotal;}

//ItemsBoughtContainer
string Member::allPurchasesReport()
{
    string report;
    stringstream ss;
    Container<Item>::Iterator it;
    it = itemsBought.begin();
    for(int i = 0; i < itemsBought.length(); i++)
    {
        cout << (*it) << endl;
        ss << (*it) << endl;

        it++;
    }
    
    report = ss.str();
    return report;
}

string Member::totalSpentWTax(float tax)
{
    //Iterate through items bought and add to total
    float total = 0;
    Container<Item>::Iterator it;
    it = itemsBought.begin();
    for(int i = 0; i < itemsBought.length(); i++)
    {
        total += (*it).getPrice();
        it++;
    }
    total *= tax;

    //SS to convert from float to string
    stringstream ssTotal;
    ssTotal << total;
    //Converted to string
    string totalSpent(ssTotal.str());

    //return string
    return totalSpent;
}

double Member::getTotalSpentPreTax()
{
    return totalSpentPreTax;
}

string Member::rebateAmt(double rebPct)
{
    if(membership == "Preferred")
    {
        double rebAmt = 0;
        rebAmt = rebPct * totalSpentPreTax;
        string rebReport = to_string(rebAmt);
        return rebReport;
    }
    else
    {
        cout << "Error. Non-Preferred Member. No Rebates." << endl;
    }
}
