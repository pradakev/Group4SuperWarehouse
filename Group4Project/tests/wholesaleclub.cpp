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
        cout << "Successfully opened file" << endl;
    }

    string name;
    string id;
    string memberShip;
    string expDate;

    //Read in a loop until there is nothing to get from the file.
    while(getline(reader, name))
    {
        //Get Info
        getline(reader, id);
        getline(reader, memberShip);
        getline(reader, expDate);

        //Testing
//        cout << "Name: " << name << endl;
//        cout << id << endl;
//        cout << memberShip << endl;
//        cout << expDate << endl;

        //Add to database
        Member temp(name, id, memberShip, expDate);
        memberDatabase.push_back(temp);
    }
//    cout << "database size: " << memberDatabase.length();
    //Close file.
    reader.close();
    Container<Member>::Iterator iter;
    for(iter = memberDatabase.begin(); iter != memberDatabase.end(); iter++)
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
           cout << "File open success" << endl;
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
    it = memberDatabase.begin();

    cout << "database size: " << memberDatabase.length();
    for(it = memberDatabase.begin(); it != memberDatabase.end(); it++)
        if ((*it).getId() == iD)
            (*it).addItem(a);
}


string wholesaleClub::dateSalesSum(string date)
{
    double totalAgg = 0;
    Container<Member>::Iterator it;
    for(it = memberDatabase.begin(); it != memberDatabase.end(); it++)
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
    for(useMe = memberDatabase.begin(); useMe != memberDatabase.end(); useMe++)
    {

        cout << (*useMe).getName() << endl;
    }
    useMe = memberDatabase.end();
    cout << (*useMe).getName() << endl;

}



string wholesaleClub::memberPurchasesReport()
{
    string result;
    stringstream myStream;
    Container<Member>::Iterator iter;
    //sort membership
    //memberDatabase.select_sort();
    myStream  << "ID:" << setw(30) << setfill('_')
    << "Name:" << setw(30) << setfill('_') << endl;
    result = myStream.str();
    for(iter = memberDatabase.begin(); iter != memberDatabase.end(); iter++)
    {
        myStream << (*iter).getId() << setw(30) << setfill('.') 
            << (*iter).getName() << setw(30) << setfill('.');
        result += myStream.str();
        //member id, name, membership type
        //item name, quantity, price
    }
    result = myStream.str();
    cout << result << endl;
    return result;
}



//SALES REPORTS
string wholesaleClub::totalPurchasesByMember(string id)
{
    string totalPurchases;
    
    Container<Member>::Iterator it;
    it = memberDatabase.begin();

    for(; it != memberDatabase.end(); it++)
    {
        if ((*it).getId() == id)
        {
            totalPurchases = (*it).allPurchasesReport();
            return totalPurchases;
        }
    }
    return "Member not found.";
}

