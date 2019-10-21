#include "wholesaleclub.h"
#include <sstream>
#include <iomanip>

wholesaleClub::wholesaleClub()
{

}

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
    Container<Member>::Iterator iter;
    for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
    {
        cout << "NAME:" << (*iter).getName() << endl;
    }
}

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
       if(!instream.fail())
       {
           cout << "File did not open successfully." << endl;
       }
       else
       {
           cout << "File opened with success: " << fileNames[i] << endl;
       }
       while(getline(instream, date))
       {
           getline(instream, id);
           getline(instream, name);
           getline(instream, priceStr, '\t');
           getline(instream, quantityStr);
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

void wholesaleClub::addItemToMember(Item a, string iD)
{
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();

    cout << "database size: " << basicMemberDatabase.length();
    for(it = basicMemberDatabase.begin(); it != basicMemberDatabase.end(); it++)
        if ((*it).getId() == iD)
            (*it).addItem(a);
}


string wholesaleClub::dateSalesSum(string date, string membership)
{
    double totalAgg = 0;
    Container<Member>::Iterator it;
    for(it = basicMemberDatabase.begin(); it != basicMemberDatabase.end(); it++)
        totalAgg += (*it).sumPurchasesDate(date);
    string answer;

    answer = to_string(totalAgg);
    return answer;
    //Convert totalAgg to a string.
    //Then string would be converted to Qstring for GUI.

}

void wholesaleClub::displayMembers()
{

    //REMEMBER TO INCLUDE END ITERATOR ITEM OR ELSE WON"T WORK
    Container<Member>::Iterator useMe;
    for(useMe = basicMemberDatabase.begin(); useMe != basicMemberDatabase.end(); useMe++)
    {

        cout << (*useMe).getName() << endl;
    }
    useMe = basicMemberDatabase.end();
    cout << (*useMe).getName() << endl;

}



string wholesaleClub::memberPurchasesReport(string membership)
{
    string result;
    stringstream myStream;
    Container<Member>::Iterator iter;
    //sort membership
    //memberDatabase.select_sort();
    if(membership == "basic"){
        myStream  << "ID:" << setw(30) << setfill('_')
        << "Name:" << setw(30) << setfill('_');
        result = myStream.str();
        for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
        {
            myStream << "\n" << (*iter).getId() << setw(30) << setfill('.')
                << (*iter).getName() << setw(30) << setfill('.')
                << (*iter).getItems() << "\n";
            result += myStream.str();
        }
        result = myStream.str();
        cout << result << endl;
        return result;
    }
    else if(membership == "preferred"){
        myStream  << "ID:" << setw(30) << setfill('_')
        << "Name:" << setw(30) << setfill('_');
        result = myStream.str();
        for(iter = preferredMemberDatabase.begin(); iter != preferredMemberDatabase.end(); iter++)
        {
            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
                << (*iter).getName() << setw(30) << setfill('.')
                << (*iter).getItems() << "\n";
            result += myStream.str();
            //member id, name, membership type
            //item name, quantity, price
        }
        result = myStream.str();
        cout << result << endl;
        return result;
    }
    else{   //Print both memberships
        myStream  << "ID:" << setw(30) << setfill('_')
        << "Name:" << setw(30) << setfill('_');
        result = myStream.str();
        for(iter = preferredMemberDatabase.begin(); iter != preferredMemberDatabase.end(); iter++)
        {
            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
                << (*iter).getName() << setw(30) << setfill('.')
                << (*iter).getItems() << "\n";
            result += myStream.str();
            //member id, name, membership type
            //item name, quantity, price
        }
        result = myStream.str();
        //cout << result << endl;

        myStream  << "ID:" << setw(30) << setfill('_')
        << "Name:" << setw(30) << setfill('_');
        result = myStream.str();
        for(iter = basicMemberDatabase.begin(); iter != basicMemberDatabase.end(); iter++)
        {
            myStream << "\n"<< (*iter).getId() << setw(30) << setfill('.')
                << (*iter).getName() << setw(30) << setfill('.')
                << (*iter).getItems() << "\n";
            result += myStream.str();
            //member id, name, membership type
            //item name, quantity, price
        }
        result = myStream.str();
        cout << result << endl;
        return result;

    }
}



//SALES REPORTS
string wholesaleClub::totalPurchasesByMember(string id, string membership)
{
    string totalPurchases;
    
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();

    for(; it != basicMemberDatabase.end(); it++)
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
    }
    return "Member not found.";
}

string wholesaleClub::memberIdFromName(string name, string membership)
{
    string id;
    Container<Member>::Iterator it;
    it = basicMemberDatabase.begin();
    for(; it != basicMemberDatabase.end(); it++)
    {
        if((*it).getName() == name)
        {
            id = (*it).getId();
            return id;
        }
    }
    return "Member not found.";
}

//REBATE REPORT
string wholesaleClub::rebateReport()
{
    cout << "WholeSaleClub Rebate Report" << endl;
    //REBATE REPORT NEEDS Preferred Members to be sorted
    preferredMemberDatabase.select_sort();

    //Then Output ID, then member report;
    double rebatePct = 0.05;
    string report = "blank report";
    stringstream ssReport;
    Container<Member>::Iterator it;

    for(it = preferredMemberDatabase.begin();
        it != preferredMemberDatabase.end(); it++)
    {
        //DEBUG
        cout << (*it).getId() << endl;
        cout << (*it).rebateAmt(rebatePct) << endl;
        cout << endl;

        ssReport << (*it).getId() << endl;
        ssReport << (*it).rebateAmt(rebatePct) << endl;
        ssReport << endl;
    }
    string strReport = ssReport.str();
    return strReport;

}

//Membership Expiration Report
//User inputs a month number and we display all the
//memberships that expire on that month.
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
    cout << report.str();
    return "Nothing yet";
}
