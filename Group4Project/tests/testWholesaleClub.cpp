#include <iostream>
#include "wholesaleclub.h"

int main()
{
    wholesaleClub club;
    club.updateMembers();
    //club.displayMembers();
    club.updateSalesforMembers();
    club.memberPurchasesReport();
    return EXIT_SUCCESS;
}
