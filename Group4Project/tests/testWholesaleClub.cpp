#include <iostream>
#include "wholesaleclub.h"

int main()
{
    wholesaleClub club;
    club.updateMembers();
    //club.displayMembers();
    club.updateSalesforMembers();
    club.writeOut();
    //club.sort_alpha();
    //club.memberPurchasesReport("Preffered");
    //club.membershipExpirationReport(12);
    return EXIT_SUCCESS;
}
