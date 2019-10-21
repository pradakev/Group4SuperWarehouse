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
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Takes in a date as a string, and then returns the total of all items sold
* on that date
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A date must be passed in
* POST-CONDITIONS:
*   Returns a double of the total price of all the items sold on the passed in
*  date
**************************************************************************/
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
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Adds an item to the members itemsBought container
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Item thing needs to have been passed in
* POST-CONDITIONS:
*   Adds the item to the member's itemsBought container for later use, also
*   prints to the screen that an item as been added for verification.
**************************************************************************/
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
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns an ostream (os) of a formatted member. Containing the name, id,
* membership, membership expiration date and the total spent without taxes.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   a member must already exist with a purchase history
* POST-CONDITIONS:
*   returns a formatted list of member information
**************************************************************************/
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
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a list of all items purchased by a member
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A member must already exist and have purchased items
* POST-CONDITIONS:
*   Returns a report of all items purchased by a user
**************************************************************************/
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
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns the total amount of money spent by a member, including taxes
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A member must already exist with a purchase history
* POST-CONDITIONS:
*   Returns the total amount spent by a user, including taxes
**************************************************************************/
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
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a members rebate amount, based off the passed in %
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A member must already exist with a purchase history and a rebate % must be
* passed in
* POST-CONDITIONS:
*   Returns the members rebate amount
**************************************************************************/
string Member::rebateAmt(double rebPct)
{
        double rebAmt = 0;
        rebAmt = rebPct * totalSpentPreTax;
        string rebReport = to_string(rebAmt);
        return rebReport;
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a members rebate amount, based off the passed in %
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A member must already exist with a purchase history and a rebate % must be
* passed in
* POST-CONDITIONS:
*   Returns the members rebate amount
**************************************************************************/
double Member::rebateAmtNUM(double rebPct)
{
    double rebAmt = 0;
    rebAmt = rebPct * totalSpentPreTax;
    return rebAmt;
}

//REQ #4 Item Report
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns the quantity of an item already sold with its name passed in
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Item needs to have been purchased by a member
* POST-CONDITIONS:
*   Returns the amount of units sold of a particular item
**************************************************************************/
double Member::getQuantityItemsSold(string itemUsed)
{
    double totalQuantity = 0;
    //Iterate through itemsBought. If item found, add to totalQuantity
    Container<Item>::Iterator iter;
    iter = itemsBought.begin();
    for(int i = 0; i < itemsBought.length(); i++)
    {
        if(itemUsed == (*iter).getName())
        {
            cout << "ITEM FOUND. Adding to total."<< (*iter).getName() << endl;
            cout << "ITEM FOUND. Adding to total Quantity"<< endl;
            totalQuantity++;
        }
        iter++;
    }
    return totalQuantity;

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns the total price of the items sold
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Item needs to have been purchased by a member with it's name passed in
* POST-CONDITIONS:
*   Returns the the total amount spent on a particular item by a member
**************************************************************************/
double Member::getTotalItemPrice(string itemUsed)
{
    double totalItemPrice = 0;
    //Iterate through itemsBought. If item found, add to totalPrice
    Container<Item>::Iterator iter;
    iter = itemsBought.begin();
    for(int i = 0; i < itemsBought.length(); i++)
    {
        if(itemUsed == (*iter).getName())
        {
            cout << "ITEM FOUND. Adding to total."<< (*iter).getName() << endl;
            cout << "ITEM FOUND. Adding to total $"<< (*iter).getPrice() << endl;
            totalItemPrice += (*iter).getPrice();
        }
        iter++;
    }
    return totalItemPrice;
}
