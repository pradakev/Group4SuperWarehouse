#include "sales.h"

//Default CTOR
int cap = 40;           //the max cap of the array
                        //arbitrarily picked, the contenets of the array are
                        //reset upon "day advancement"
/* Apparently dont need to close and reopen files can use
 *
 *  ifile.clear();
 *  ifile.seekg(0, ios::beg);
 * once eof has been thrown can use ^^^ and it will reset to the beginning of the
 * file?
 * try later
 *
 */
using namespace std;
Sales::Sales(string temp)
{
    sz = 10;
    file = temp;
    reader.open(temp);
    if(reader.fail()){
        cout << "Failed to open file: "<<temp<<endl;
    }
    getline(reader,date);
    reader.close();
    reader.open(temp);

    writer.open("Sales.txt");
    //Sales1, Sales2, etc.
    //Theres 5 day files?
    //
    //"03/05/2010"
    //
    //
    if(writer.fail()){
        cout << "Failed to open file: Sales.txt" <<endl;
    }
    writer << date <<endl;
    process();
}

/*Runs through a "day" ex: "day1.txt"
condenses information down so instead of separate purchases one right after another
by potentially different customers or even the same customer, all purchases
now appear in blocks.

First sale of any given day will always have the date displayed above it
i.e
03/05/2013                         <-------------- DATE
12345
1 gallon milk
2.49	13
Seinfeld Collection
39.95	1
EPSON Printer
59.99	1

67899
Potato Bread
1.79	20
The Alamo
19.95	6
Most Basic DVD Player
59.99	1
Instant Coffee
6.75	5

etc...
*/


void Sales::process(){
   //Used to find all purchases made by a specific member
   //set up a loop so that if temp - the member id- is found within the array
   //then it will skip over it, therefore there will be no repeated purchase records
   //then try to implement with gui
   //possibly try to find way to "advance"days
    string temp;

    int line = 0;       //Used as a means to keep track of the line last left on
    int iterator = 0;
    bool repeat = false;

    int profit = 0;

    while(getline(reader, temp)){       //First run, grabs date line
        getline(reader, temp);          //First run skips over date line(grabs member ID)

        member = temp;
        //Makes sure no 1 transaction was recorded multiple times
        //does so by checking the array for the previous used member ID
        //if a previously used ID is found, the transaction is skipped over and the
        //program will move onto the next one
        for(int i = 0; i < sz; i++){
            if(arr[i] == member){
               repeat = true;
            }
        }

        if(repeat == false){
            if(iterator == sz && sz*2 <= cap){
                sz *=2;
                arr[iterator] = temp;
                iterator++;

                sort(profit);
                line++;
                //The following for loop returns getline to its previous position before
                //sort() was called
                reader.open(file);
                for(int i = 0; i < 4*line; i++){
                    getline(reader,temp);
                }

            }
            else if(sz == 40){
                cout << "Storage is full" <<endl;
                return;
            }
            else{
                arr[iterator] = temp;
                iterator++;

                sort(profit);
                line++;
                //The following for loop returns getline to its previous position before
                //sort() was called
                reader.open(file);
                for(int i = 0; i < 4*line; i++){
                    getline(reader,temp);
                }

            }

        }


        //Skips the current transaction and moves onto the next
        else{
            getline(reader,temp);
            getline(reader,temp);
            repeat = false;
        }


    }
    reader.close();
    writer.close();
}


/*Runs through a day file searching for the passed in member ID, referred to as
 * prevLine = member ID currently searching for purchase history
 * When the member ID is found the purchase transaction is recorded under their
 * ID in our sales report.
 */
void Sales::sort (int& profit){
    //When this function is called the idea is that it will go to the next line after the member ID
    writer << member <<endl;
    string line;
    bool correct_ID = true; //true if the found ID matches the ID passed in -prevLine
    //This while loop should run through the file, and find every transaction with the coresponding
    //Member ID then add it to our sales file
    while(getline(reader,line)){    //is now on the line just after member ID, should be


        if(correct_ID){
            //string firstHlf;
            //string secondHlf;
            writer << line <<endl;      //writes the Product name
            getline(reader,line);
            /* right here the line that contains the price and the quant.
             * will be broken into 2 parts, firstHlf and secondHlf
             * that way they can be converted to usable ints and the total
             * can actually be calculated
             */
            writer << line <<endl;      //writes the price and quant.

            getline(reader, line);

        }
        getline(reader,line);

        if(line == member){
            correct_ID = true;
        }
        else{
            correct_ID = false;
        }
    }
    writer <<endl<<endl;
    reader.close();
}

void Sales::reset(){
    sz = 10;
    for(int i = 0; i < cap; i++){
        arr[i] = "";
    }
}
