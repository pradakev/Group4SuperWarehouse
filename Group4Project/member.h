#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>
#include <sstream>
#include "item.h"
#include "container.h"
#include <vector>

using namespace std;

class Member
{
public:
	/*******************
	* CONSTRUCTOR(S)
	********************/
	Member();
	Member(string paramName,
		string paramId);

    Member(string paramName,
            string paramId,
            string paramMembership,
            string expiration);

//	Member(string paramName,
//		string paramId,
//        string paramMembership,
//		string expiration,
//		float paramTotal);
    /*******************
	* ACCESSOR(S)
	********************/
	string getName();
    string getId();
    string getMembership();
    string getExpiration();
    Container<Item> getItems() const;
    bool operator<(Member& rhs) const;
    bool operator>(Member& rhs) const;
    friend ostream& operator<<(ostream& os, const Member& paramMember);

    //Sales Accessors
    double sumPurchasesDate(string date);
    double sumTotalPurchases();
    int totalNumItemsBought(string itemName);

    //ItemsBought Container
    void addItem(const Item& thing);
    string allPurchasesReport();

    //REBATE
    string totalSpentWTax(float tax);
    double getTotalSpentPreTax();
    string rebateAmt(double rebPct);
    double rebateAmtNUM(double rebPct);

    //REQ #4 Item Report HELPERS
    double getQuantityItemsSold(string itemUsed);
    double getTotalItemPrice(string itemUsed);
	
	/*******************
	* MUTATOR(S)
	********************/
	void setName(string paramName);
    void setId(string paramId);
    void setMembership(char paramMembership);
	void setExpiration(string expiration);
	void setTotalSpent(float paramTotal);

	/*******************
	* MEMBER DATA
	********************/

private:
	string name;		//IN OUT - Name of Member
	string iD;			//IN OUT - iD of Member
    string membership;		//IN OUT - membership type 'b'or 'p'
	string expiration;		//IN OUT - expiration date mm/dd/yyyy
    double totalSpentPreTax;		//IN OUT - total spent before tax

    //REQ #7 Sort by name. Will change operator< to sort dependent on this bool

    //Added
    Container<Item> itemsBought;


};


#endif //MEMBER_H
