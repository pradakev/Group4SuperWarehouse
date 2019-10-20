#ifndef WHOLESALECLUB_H
#define WHOLESALECLUB_H

#include <fstream>
#include <iostream>
#include <string>
#include "member.h"
#include "container.h"



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

    string memberPurchasesReport(string membership);
    string dateSalesSum(string date, string membership);
    string totalPurchasesByMember(string id, string membership);
    string memberIdFromName(string name, string membership);
    string membershipExpirationReport(int month);

    //REBATES
    string rebateReport();  //MEMBERS ONLY
    /*REQ. #2
     * A user should be able to enter
     * a membership number or name and
     * get a list of the total purchases
     *  per that member.
     * */

    //Initialize databases
    Container<Member> basicMemberDatabase;
    Container<Member> preferredMemberDatabase;
};

#endif // WHOLESALECLUB_H

//This class
