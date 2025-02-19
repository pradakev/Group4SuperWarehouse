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

    //ITEMS REQ #4
    string itemReport(string itemUsed);

    //REQ #6
    string memberDuesReport();

    //REQ #9 - Bool to return true if member added, false if not added
    bool addMemberWC(Member newMember);
    void writeOut();
    //#10
    string basicMembershipRec(string name, string id);
    string PreferredMembershipRec(string name, string id);
    string AllMembershipRec();
    //Initialize databases
    Container<Member> basicMemberDatabase;
    Container<Member> preferredMemberDatabase;
};

#endif // WHOLESALECLUB_H

//This class
