#include "wholesaleclub.h"
#include <sstream>
#include <iomanip>

wholesaleClub::wholesaleClub()
{

}
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Reads through a file of members, adding basic members to the basic
* memberDatabase and preferred to the preferredMemberDatabase
*__________________________________________________________________________
* PRO-CONDITIONS:
*   warehouseshoppers.txt must exist
* POST-CONDITIONS:
*   basicMemberDatabase is filled with basic members, preferredMemberDatabase
*   is filled with preferred members.
**************************************************************************/
void wholesaleClub::updateMembers()
{
    ifstream reader;
    reader.open("warehouse shoppers.txt");
    if(reader.fail()){
        cout << "Failed to open file: "<< endl;
    }
    else
    {
        cout << "Successfully opened file warehouse shoppers." << endl;
    }

    string name;
    string id;
    string memberShip;
    string expDate;

    //IMPORTANT NOTE WHEN READING FILE:
    //The file lines are written so that \r and \n are at the end of each line.
    //ex:
    //Sally Shopper
    //is actually written as:
    //Sally Shopper\r\n

    //\r and \n are characters that needs to be accounted for.
    //So the delimiter char for each line is \r, and we need to ignore
    //the \n in order to correctly store each variable. Now we can correctly
    //store each string.
    //SUCCESS! - kZan

    //LINK TO HELPSITE:
    // https://cboard.cprogramming.com/cplusplus-programmin
    // g/165621-std-getline-discards-delimiter-when-extracting-characters-stream.html

    //Read in a loop until there is nothing to get from the file.
    while(getline(reader, name, '\r'))
    {
        //Get Info
        reader.ignore(1, '\n');
        getline(reader, id, '\r');
        reader.ignore(1, '\n');
        getline(reader, memberShip, '\r');
        reader.ignore(1, '\n');
        getline(reader, expDate, '\r');
        reader.ignore(1, '\n');
        //Testing
//        cout << id << endl;
//        cout << memberShip << endl;
//        cout << expDate << endl;

        //Add to database
        Member temp(name, id, memberShip, expDate);
        //This needs to be adjusted so that it will occur to not only basic
        //but so that it will also occur to preferred, on a case by case basis
        string strPreferred;
        strPreferred = "Preferred";
//        strPreferred += "\n";

        //DEBUG STATEMENTS
        cout << "Storing members!" << endl;
        cout << "." << memberShip << "..." << endl;
        if(temp.getMembership() == strPreferred)
        {
            cout << temp.getName() << " is a Preferred member." << endl;
            cout << temp.getMembership() << endl;
            preferredMemberDatabase.push_back(temp);
        }
        else
        {
            cout << temp.getName() << " is a Basic member." << endl;
            cout << temp.getMembership() << endl;
            basicMemberDatabase.push_back(temp);
        }
    }
//    cout << "database size: " << memberDatabase.length();
    //Close file.
    reader.close();
    Container<Member>::Iterator iter = basicMemberDatabase.begin();
    //NOTE: We are using a new form of a FOR LOOP. The old form is commented,
    //New form is used below!

//    for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
//    {
//        cout << "NAME:" << (*iter).getName() << endl;
//    }
    cout << "BASIC:" << endl;
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        cout << "NAME:-" << (*iter).getName() << "-" << endl;
        iter++;
    }
    cout << endl;
    cout << "PREFERRED:" << endl;
    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        cout << "NAME:-" << (*iter).getName() << "-"<< endl;
        iter++;
    }


}
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Fills the itemsbought container for the correct corresponding members
*__________________________________________________________________________
* PRO-CONDITIONS:
*   basicMemberDatabase and preferredMemberDatabase must already be filled with
*   with members.
* POST-CONDITIONS:
*   Any item purchased by a member will be stored in their itemsBought container
**************************************************************************/
void wholesaleClub::updateSalesforMembers()
{
    string date,
              id,
              name,
              priceStr,
              quantityStr;
   double price;
   int quantity;
   //date, id, item name, price and quantity,
   ifstream instream;

   string fileNames[] = {"day1.txt", "day2.txt", "day3.txt", "day4.txt",
                      "day5.txt"};


   for(int i = 0; i < 5; i++)
   {
       instream.open(fileNames[i]);
       //CHECK IF FILE OPENED SUCCESSFULY
       if(instream.fail())
       {
           cout << "File did not open successfully." << endl;
       }
       else
       {
           cout << "File opened with success: " << fileNames[i] << endl;
       }
       while(getline(instream, date, '\r'))
       {
           instream.ignore(1, '\n');
           getline(instream, id, '\r');
           instream.ignore(1, '\n');
           getline(instream, name, '\r');
           instream.ignore(1, '\n');
           getline(instream, priceStr, '\t');
           getline(instream, quantityStr, '\r');
           instream.ignore(1, '\n');

           cout << "date: " << date << endl;
           cout << "id: " << id << endl;
           cout << "name: " << name << endl;
           cout << "price: " << priceStr << endl;
           cout << "quantity: " << quantityStr << endl;
           //convert priceStr & quantityStr to double & int respectively
           price = stod(priceStr);
           quantity = stoi(quantityStr);
           addItemToMember(Item(name, price, quantity, date), id);

       }
       instream.close();
   }
   cout << "=========Done Updating===========" << endl;
}
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Adds an item to an existing member's itemsBought container
*__________________________________________________________________________
* PRO-CONDITIONS:
*   an item and a member id must be passed in
* POST-CONDITIONS:
*   adds the passed in item to the member's itemsBought container
**************************************************************************/
void wholesaleClub::addItemToMember(Item a, string iD)
{
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();

    //DEBUG statement
    cout << "basic member database size: " << basicMemberDatabase.length() << endl;

    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        if ((*it).getId() == iD)
        {
            (*it).addItem(a);
            return;
        }
        it++;
    }

    it = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        if ((*it).getId() == iD)
        {
            (*it).addItem(a);
            return;
        }
        it++;
    }

    cout << "ID NOT FOUND WHEN ADDING ITEM TO MEMBER" << endl;

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns the total amount of money made on a specific date
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A date must be passed in
* POST-CONDITIONS:
*   Returns the amount of money made on that specific date
**************************************************************************/
string wholesaleClub::dateSalesSum(string date, string membership)
{
    double totalAgg = 0;
    Container<Member>::Iterator it = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        totalAgg += (*it).sumPurchasesDate(date);
        it++;
    }

    it = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        totalAgg += (*it).sumPurchasesDate(date);
        it++;
    }
    string answer;

    answer = to_string(totalAgg);
    return answer;
    //Convert totalAgg to a string.
    //Then string would be converted to Qstring for GUI.

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Displays a list of names of members
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Member databases must already be filled with information.
* POST-CONDITIONS:
*   Returns a list of all Member's names
**************************************************************************/
void wholesaleClub::displayMembers()
{

    //REMEMBER TO INCLUDE END ITERATOR ITEM OR ELSE WON"T WORK
    Container<Member>::Iterator useMe = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {

        cout << (*useMe).getName() << endl;
        useMe++;
    }

    useMe = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {

        cout << (*useMe).getName() << endl;
        useMe++;
    }

}

//string wholesaleClub::memberPurchasesReport(string membership)
//{
//    string result;
//    stringstream myStream;
//    Container<Member>::Iterator iter;
//    //sort membership
//    //memberDatabase.select_sort();
//    if(membership == "basic"){
//        myStream  << "ID:" << setw(30) << setfill('_')
//        << "Name:" << setw(30) << setfill('_');
//        result = myStream.str();
//        for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
//        {
//            myStream << "\n" << (*iter).getId() << setw(30) << setfill('.')
//                << (*iter).getName() << setw(30) << setfill('.')
//                << (*iter).getItems() << "\n";
//            result += myStream.str();
//        }
//        result = myStream.str();
//        cout << result << endl;
//        return result;
//    }
//    else if(membership == "preferred"){
//        myStream  << "ID:" << setw(30) << setfill('_')
//        << "Name:" << setw(30) << setfill('_');
//        result = myStream.str();
//        for(iter = preferredMemberDatabase.begin(); iter != preferredMemberDatabase.end(); iter++)
//        {
//            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
//                << (*iter).getName() << setw(30) << setfill('.')
//                << (*iter).getItems() << "\n";
//            result += myStream.str();
//            //member id, name, membership type
//            //item name, quantity, price
//        }
//        result = myStream.str();
//        cout << result << endl;
//        return result;
//    }
//    else{   //Print both memberships
//        myStream  << "ID:" << setw(30) << setfill('_')
//        << "Name:" << setw(30) << setfill('_');
//        result = myStream.str();
//        for(iter = preferredMemberDatabase.begin(); iter != preferredMemberDatabase.end(); iter++)
//        {
//            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
//                << (*iter).getName() << setw(30) << setfill('.')
//                << (*iter).getItems() << "\n";
//            result += myStream.str();
//            //member id, name, membership type
//            //item name, quantity, price
//        }
//        result = myStream.str();
//        //cout << result << endl;

//        myStream  << "ID:" << setw(30) << setfill('_')
//        << "Name:" << setw(30) << setfill('_');
//        result = myStream.str();
//        for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
//        {
//            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
//                << (*iter).getName() << setw(30) << setfill('.')
//                << (*iter).getItems() << "\n";
//            result += myStream.str();
//            //member id, name, membership type
//            //item name, quantity, price
//        }
//        result = myStream.str();
//        cout << result << endl;
//        return result;

//    }
//}

//SALES REPORTS
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a purchases report of a specific member
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Member must exist, member Id and type must be passed in
* POST-CONDITIONS:
*   Returns a purchase report of a specific member
**************************************************************************/
string wholesaleClub::totalPurchasesByMember(string id, string membership)
{
    string totalPurchases;
    
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();

    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        cout << (*it).getId() << "." << endl;
        cout << id << "." << endl;
        if (id != (*it).getId())
        {
            cout << "Not Found" << endl;
        }
        if (id == (*it).getId())
        {
            cout << "ID Found for total purchases." << endl;
            totalPurchases = (*it).allPurchasesReport();
            return totalPurchases;
        }
        it++;
    }

    it = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        cout << (*it).getId() << "." << endl;
        cout << id << "." << endl;
        if (id != (*it).getId())
        {
            cout << "Not Found" << endl;
        }
        if (id == (*it).getId())
        {
            cout << "ID Found for total purchases." << endl;
            totalPurchases = (*it).allPurchasesReport();
            return totalPurchases;
        }
        it++;
    }

    return "Member not found.";
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a member's ID based off the passed in name and membership type
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A name and membership type must be passed in
* POST-CONDITIONS:
*   Returns the member's ID based off of the passed in name and membership type
**************************************************************************/
string wholesaleClub::memberIdFromName(string name, string membership)
{
    string id;
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        if((*it).getName() == name)
        {
            id = (*it).getId();
            return id;
        }
        it++;
    }

    it = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        if((*it).getName() == name)
        {
            id = (*it).getId();
            return id;
        }
        it++;
    }
    return "Member not found.";
}

//REBATE REPORT - REQUIREMENT #6
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a rebate report of preferred members sorted by membership ID
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Preferred member data base must contain preferred members with purchase hist
* POST-CONDITIONS:
*   Returns a rebate report for preferred members sorted by membership ID
**************************************************************************/
string wholesaleClub::rebateReport()
{
    cout << "WholeSaleClub Rebate Report" << endl;
    //REBATE REPORT NEEDS Preferred Members to be sorted
    preferredMemberDatabase.select_sort();

    //Then Output ID, then member report;
    double rebatePct = 0.05;
    string report = "blank report";
    stringstream ssReport;
    Container<Member>::Iterator it = preferredMemberDatabase.begin();

    ssReport << "REBATE REPORT FOR PREFERRED MEMBERS" << endl;
    ssReport << endl;

    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        //DEBUG
        cout << "NAME: " << (*it).getName() << endl;
        cout << "ID: "<< (*it).getId() << endl;
        cout << "TOTAL SPENT: $" <<(*it).getTotalSpentPreTax() << endl;
        cout << "REBATE AMT: $" << (*it).rebateAmt(rebatePct) << endl;
        cout << endl;

        ssReport << "NAME: "<< (*it).getName() << endl;
        ssReport << "ID: " << (*it).getId() << endl;
        ssReport << "TOTAL SPENT: $"<< (*it).getTotalSpentPreTax() << endl;
        ssReport << "REBATE AMT: $" << (*it).rebateAmt(rebatePct) << endl;
        ssReport << endl;

        it++;
    }
    string strReport = ssReport.str();
    return strReport;

}

//Membership Expiration Report
//User inputs a month number and we display all the
//memberships that expire on that month.
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns all memberships that will expire within the passed in month
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A date must be passed in
* POST-CONDITIONS:
*   Returns a list of memberships that will expire within the given month
**************************************************************************/
string wholesaleClub::membershipExpirationReport(int month)
{
    Container<Member>::Iterator iter;
    stringstream report;
    iter = basicMemberDatabase.begin();
    string monthStored;

    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        monthStored = (*iter).getExpiration()[0];
        monthStored += (*iter).getExpiration()[1];
        iter++;
        if(stoi(monthStored) == month)
            report << (*iter).getName() << " - " << (*iter).getExpiration() << endl;
    }
    //cout << report.str();
    return report.str();
}

//REQUIREMENT #4
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns the quantity of an item sold as well as the total sales price
*__________________________________________________________________________
* PRO-CONDITIONS:
*   An existing item name must be passed in
* POST-CONDITIONS:
*   Returns the quantity of an item sold as well as the total sales price
**************************************************************************/
string wholesaleClub::itemReport(string itemUsed)
{
    //declare totals that will later be converted to string
    double totalQuantitySold = 0;
    double totalItemPrice = 0;

    //Iterate through both databases

    Container<Member>::Iterator iter;
    iter = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        //Add individual member itemsBought to totals
        totalQuantitySold += (*iter).getQuantityItemsSold(itemUsed);
        totalItemPrice += (*iter).getTotalItemPrice(itemUsed);
        iter++;
    }

    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        //Add individual member itemsBought to totals
        totalQuantitySold += (*iter).getQuantityItemsSold(itemUsed);
        totalItemPrice += (*iter).getTotalItemPrice(itemUsed);
        iter++;
    }

    //NOW Make doubles to strings. First use stringstream
    stringstream ss;
    ss << "Item:" << itemUsed << endl;
    ss << "Total Quantiy Sold: " << totalQuantitySold << endl;
    ss << "Total Price Sold: " << totalItemPrice << endl;

    string itemR;
    itemR = ss.str();

    return itemR;
}

//REQ #7
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a report showing the amount paid in membership dues by member type
* and then name
*__________________________________________________________________________
* PRO-CONDITIONS:
*   member data bases can not be empty
* POST-CONDITIONS:
*   Returns a report showing the amount paid in membership dues by a member type
* and then name
**************************************************************************/
string wholesaleClub::memberDuesReport()
{
    stringstream ss;
    ss << "MEMBERSHIP DUES REPORT:" << endl << endl;
    Container<Member>::Iterator iter;
    iter = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        ss << "NAME: "<< (*iter).getName() << endl;
        ss << "ID: " << (*iter).getId() << endl;
        ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
        ss << "DUES: $60" << endl;
        ss << endl;
        iter++;
    }

    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        ss << "NAME: "<< (*iter).getName() << endl;
        ss << "ID: " << (*iter).getId() << endl;
        ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
        ss << "DUES: $75" << endl;
        ss << endl;
        iter++;
    }

    string mReport = ss.str();
    return  mReport;
}

//REQ #9
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Adds a new member to the data base based off the selected membership type,
* only adds if the member does not already have a membership
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A "existing" member must be passed in
* POST-CONDITIONS:
*   Returns true if the member was succesfully added and adds the new member
* to the correct data base.
**************************************************************************/
bool wholesaleClub::addMemberWC(Member newMember)
{
    //Get membership type, iterate through respective database
    //Then make sure if new member is not duplicate (id, name)
    string membershipType = newMember.getMembership();
    Container<Member>::Iterator iter;
    iter = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        cout << "Checking Basic Members" << endl;
        if(newMember.getName() == (*iter).getName())
            return false;
        if(newMember.getId() == (*iter).getId())
            return false;
        iter++;
    }

    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        if(newMember.getName() == (*iter).getName())
            return false;
        if(newMember.getId() == (*iter).getId())
            return false;
        iter++;
    }

    if(newMember.getMembership() == "Preferred")
    {
        preferredMemberDatabase.push_back(newMember);
    }
    else
    {
        basicMemberDatabase.push_back(newMember);
    }

    //Member is not duplicate
    return true;


}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a recommendation for basic members on if they should upgrade
* or stay with their current membership
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A member's name and id must be passed in
* POST-CONDITIONS:
*   Returns a recommendation to upgrade or stay the with the same membership
* type
**************************************************************************/
string wholesaleClub::basicMembershipRec(string name, string id)
{
    double tax = 0.05;
    string report;
    stringstream ss;

    Container<Member>::Iterator iter;
    iter = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        if(name == (*iter).getName() || id == (*iter).getId())
        {
            //IF FOUND
            ss<< "NAME: " << (*iter).getName() << endl;
            ss<< "POTENTIAL REBATE AMT: " << (*iter).rebateAmt(tax) << endl;
            ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
            if((*iter).rebateAmtNUM(tax) >= 15)
            {
                ss << "You should convert to a Preferred Membership!" << endl;
            }
            else
            {
                ss << "You should stay on Basic Membership!" << endl;
            }
            ss << endl;
        }
            iter++;
    }

    report = ss.str();
    return report;
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a recommendation for preferred members on if they should downgrade
* membership or stay with the same membership
*__________________________________________________________________________
* PRO-CONDITIONS:
*   A already existing member name and id must be passed in
* POST-CONDITIONS:
*   Returns a recommendation for preferred members on if they should downgrade
* ot stay with the same membership
**************************************************************************/
string wholesaleClub::PreferredMembershipRec(string name, string id)
{
    double tax = 0.05;
    string report;
    stringstream ss;

    Container<Member>::Iterator iter;
    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        if(name == (*iter).getName() || id == (*iter).getId())
        {
            //IF FOUND
            ss << "NAME: " << (*iter).getName() << endl;
            ss << "REBATE AMT: " << (*iter).rebateAmt(tax) << endl;
            ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
            if((*iter).rebateAmtNUM(tax) < 15)
            {
                ss << "You should convert to a Basic Membership!" << endl;
            }
            else
            {
                ss << "You should stay on Preferred Membership!" << endl;
            }
            ss << endl;
        }
            iter++;
    }

    report = ss.str();
    return report;

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Returns a recommendation for members on if they should downgrade
* or upgrade membership
*__________________________________________________________________________
* PRO-CONDITIONS:
*   member databases can not be empty
* POST-CONDITIONS:
*   returns recommendations for all members on if they should upgrade/downgrade
* or stick with the same membership
**************************************************************************/
string wholesaleClub::AllMembershipRec()
{
    double tax = 0.05;
    string report;
    stringstream ss;

    Container<Member>::Iterator iter;
    iter = basicMemberDatabase.begin();
    for(int i = 0; i < basicMemberDatabase.length(); i++)
    {
        cout << "Entering AllMemberRec BASIC" << endl;
        ss << "NAME: " << (*iter).getName() << endl;
        ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
        ss << "POTENTIAL REBATE AMT: $" << (*iter).rebateAmt(tax) << endl;
        if((*iter).rebateAmtNUM(tax) >= 15)
        {
            ss << "You should convert to a Preferred Membership!" << endl;
        }
        else
        {
            ss << "You should stay on Basic Membership!" << endl;
        }
        ss << endl;

        iter++;
    }

    iter = preferredMemberDatabase.begin();
    for(int i = 0; i < preferredMemberDatabase.length(); i++)
    {
        cout << "Entering AllMemberRec PREFERRED" << endl;
        ss << "NAME: " << (*iter).getName() << endl;
        ss << "MEMBERSHIP: " << (*iter).getMembership() << endl;
        ss << "REBATE AMT: $" << (*iter).rebateAmt(tax) << endl;
        if((*iter).rebateAmtNUM(tax) < 15)
        {
            ss << "You should convert to a Basic Membership!" << endl;
        }
        else
        {
            ss << "You should stay on Preferred Membership!" << endl;
        }
        ss << endl;

        iter++;
    }

    cout << "Reached end of ALLMEMBERSREC" << endl;
    report = ss.str();
    cout << report << endl;
    return report;
}
