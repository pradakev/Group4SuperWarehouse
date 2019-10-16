#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>
#include <sstream>
#include "item.h"
#include "container.h"

using namespace std;

class Member
{
public:
	/*******************
	* CONSTRUCTOR(S)
	********************/
	Member();
	Member(std::string paramName,
		std::string paramId);

    Member(std::string paramName,
            std::string paramId,
            std::string paramMembership,
            std::string expiration);

	Member(std::string paramName,
		std::string paramId,
        std::string paramMembership,
		std::string expiration,
		float paramTotal);

	/*******************
	* ACCESSOR(S)
	********************/
	std::string getName();
    std::string getId();
    std::string getMembership();
    std::string getExpiration();
	void outputMemberInfo();
    bool operator<(Member& rhs) const;
    bool operator>(Member& rhs) const;

    //Sales Accessors
    double sumPurchasesDate(string date);
    double sumTotalPurchases();
    int totalNumItemsBought(string itemName);

    //ItemsBought Container
    void addItem(Item thing);
    string allPurchasesReport();
	
	/*******************
	* MUTATOR(S)
	********************/
	void setName(std::string paramName);
    void setId(std::string paramId);
    void setMembership(std::string paramMembership);
	void setExpiration(std::string expiration);
	void setTotalSpent(float paramTotal);

	/*******************
	* MEMBER DATA
	********************/

private:
	std::string name;		//IN OUT - Name of Member
	std::string iD;			//IN OUT - iD of Member
    std::string membership;		//IN OUT - membership type 'b'or 'p'
	std::string expiration;		//IN OUT - expiration date mm/dd/yyyy
	float totalSpent;		//IN OUT - total spent

    //Added
    Container<Item> itemsBought;


};


#endif //MEMBER_H
