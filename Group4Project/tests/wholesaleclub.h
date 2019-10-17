#ifndef WHOLESALECLUB_H
#define WHOLESALECLUB_H

#include <fstream>
#include <iostream>
#include <string>
#include "../member.h"
#include "../container.h"



using namespace std;

class wholesaleClub
{
public:
    wholesaleClub();
    void updateMembers();
    void updateSalesforMembers();
    void addItemToMember(Item a, string iD);
    void displayMembers();

    //REPORTS

    string memberPurchasesReport();
    string dateSalesSum(string date);

    string totalPurchasesByMember(string id);

    /*REQ. #2
     * A user should be able to enter
     * a membership number or name and
     * get a list of the total purchases
     *  per that member.
     * */

    //Initialize databases
    Container<Member> memberDatabase;

};

#endif // WHOLESALECLUB_H

//This class
