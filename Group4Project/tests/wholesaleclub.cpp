#include "wholesaleclub.h"
#include <sstream>
#include <iomanip>

#define ITEM_READ_COMMENTS 0        //change 0 to 1 to display these commments

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

        //Add to database
        memberDatabase.push_back(Member(name, id, memberShip, expDate));
    }    
    reader.close();
}

void wholesaleClub::updateSalesforMembers()
{
    cout << "=========Updating Member Purchases===========" << endl;
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
#if ITEM_READ_COMMENTS
           cout << "date: " << date << endl;
           cout << "id: " << id << endl;
           cout << "name: " << name << endl;
           cout << "price: " << priceStr << endl;
           cout << "quantity: " << quantityStr << endl;
#endif
           //convert priceStr & quantityStr to double & int respectively
           price = stod(priceStr);
           quantity = stoi(quantityStr);
           addItemToMember(Item(name, price, quantity, date), id);
       }
       instream.close();
   }
   cout << "=========Done Updating===========" << endl;
}

void wholesaleClub::addItemToMember(const Item& a, string iD)
{
    Container<Member>::Iterator it;
    it = memberDatabase.begin();
    cout << a << endl;

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
}

void wholesaleClub::displayMembers()
{
    cout << memberDatabase << endl;
}

string wholesaleClub::memberPurchasesReport()
{
    string result;
    stringstream myStream;
    Container<Member>::Iterator iter;
    
    //sort membership
    memberDatabase.select_sort();
    
    myStream  << "ID:" << setw(30) << setfill('_')
    << "Name:" << setw(30) << setfill('_') << endl;
    for(iter = memberDatabase.begin(); iter != memberDatabase.end(); iter++)
    {
        myStream << (*iter).getId() << setw(30) << setfill('.') 
            << (*iter).getName() << setw(30) << setfill('.');
        //needs a function in member class to return a string of
        //all items and their info for all items of the currently
        //accessed member

        //item name, quantity, price
    }
    result = myStream.str();
    cout << "RESULT: " << result << endl; 
    for(iter = memberDatabase.begin(); iter != memberDatabase.end(); iter++)
    {
        cout << "\n\n======Purchases by " << (*iter).getName() << "======\n";
        cout << (*iter).getItems() << endl;
    }
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

