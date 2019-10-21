#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myClub.updateMembers();
    myClub.updateSalesforMembers();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MemberPurchases_Button_clicked()
{
//    //Record Name and iD from LineInputs
//    QString nameInBox;
//    nameInBox = ui->memberNameINPUT->text();
//    QString idInBox;
//    idInBox = ui->MemberIDInputMEMBERS->text();

//    //Convert Qstrings to String
//    string name, id;
//    name = nameInBox.toStdString();
//    id = idInBox.toStdString();
//    cout << "name: " << name << endl;
//    cout << "id: " << id << endl;
//    //12345

//    //MemberPurchases string
//    string memberPurchases;

//    //PROCESSING: memberPurchases will contain the purchases
//    //for the member. I get this through functions in wholesaleClub class

//    //Check whether either one is empty
//    if(name.empty() == true && id.empty() != true)
//    {
//        cout << "name is empty. id is not empty." << endl;
//        //if Name is empty but id is edited.
//        memberPurchases = myClub.totalPurchasesByMember(id);

//    }
//    else if(name.empty() != true && id.empty() == true)
//    {
//        //if id is empty but name is edited, find id for name
//        id = myClub.memberIdFromName(name);
//        memberPurchases = myClub.totalPurchasesByMember(id);
//    }
//    else
//    {

//    }

//    //Once you have string of memberPurchases, output to textBrowser

//    //First convert string to Qstring
//    QString qMemberPurchases = QString::fromStdString(memberPurchases);

//    //Now send Qstring to textBrowser
//    ui->OutputMembersText->setText(qMemberPurchases);
}
/**************************************************************************
* Mutator goToPage(int pg)
*__________________________________________________________________________
* changes the ui to the passed in page index
*__________________________________________________________________________
* PRO-CONDITIONS:
*   a page index passed in
* POST-CONDITIONS:
*   No Return
*   changes the GUI to the appropriate index
**************************************************************************/
void MainWindow::goToPage(int pg){
ui->stackedWidget->setCurrentIndex(pg);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the sales home page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Sales Home Page
**************************************************************************/
void MainWindow::on_WelcomeSalesButton_clicked()
{
    goToPage(2);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to Home Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Home Page
**************************************************************************/
void MainWindow::on_pushButton_SalesReportDone_clicked()
{
    goToPage(0);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the Daily Report page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Daily Report Page
**************************************************************************/
void MainWindow::on_pushButton_dailyReport_clicked()
{
    goToPage(4);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the Members Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Members Page
**************************************************************************/
void MainWindow::on_WelcomeMembersButton_clicked()
{
    goToPage(1);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the Home Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Home Page
**************************************************************************/
void MainWindow::on_DoneMembersButton_clicked()
{
    ui->OutputMembersText->setText("Choose an option below.");
    goToPage(0);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the sales home page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Sales Home Page
**************************************************************************/
void MainWindow::on_dailyReportPushButton_clicked()
{
    goToPage(2);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the sales home page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Sales Home Page
**************************************************************************/
void MainWindow::on_purchases_done_pushButton_clicked()
{
    goToPage(2);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the Purchases Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Purchases Page
**************************************************************************/
void MainWindow::on_pushButton_memberPurchasesReport_clicked()
{
    goToPage(3);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the Custom Report Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Custom Report Page
**************************************************************************/
void MainWindow::on_pushButton_customReportOptions_clicked()
{
    goToPage(10);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the GUI to the sales home page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Sales Home Page
**************************************************************************/
void MainWindow::on_pushButton_3_clicked()
{
    goToPage(2);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Displays the inventory
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Inventory Display Page, and displays
*   the entire inventory in the Iventroy Diplay text browser
**************************************************************************/
void MainWindow::on_WelcomeDisplayInventoryButton_clicked()
{
    stringstream ss;
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
               ss << "ID: " << id << endl;
               ss << "ITEM: " << name << endl;
               ss << "PRICE: " << priceStr << endl;
               ss << "QTY: " << quantityStr << endl;
               ss << endl << endl;
               //convert priceStr & quantityStr to double & int respectively
           }
           instream.close();
       }
       QString temp;
       temp = QString::fromStdString(ss.str());
    ui->displayInvBrows->setText(temp);
    goToPage(11);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the current GUI Page to the Home Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Home Page
**************************************************************************/
void MainWindow::on_DoneButtonDI_clicked()
{
    goToPage(0);
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Changes the current GUI Page to the Home Page
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed
* POST-CONDITIONS:
*   Changes the current GUI page to the Home Page
**************************************************************************/
void MainWindow::on_doneItemSalesButton_clicked()
{
    goToPage(0);
}
/**************************************************************************
* Mutator
*__________________________________________________________________________
* Adds a new member to the already existing data base of members. Either Basic
* or Preferred based off of user input. Then displays it to the screen for
* verification of its addition.
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed, name, membership type and experation date must
* already have been inputted by the user.
* POST-CONDITIONS:
*   Adds a new member with the specified information to the already existing
*   data base.
**************************************************************************/
void MainWindow::on_AddNewMemberPage_clicked()
{
    //REQ #9
    QString qName, qID, qExp;
    string name, id, membershipType, expiration;

    //RECORD QSTRINGS
    qName = ui->memberNameINPUT->text();
    qID = ui->MemberIDInputMEMBERS->text();
    qExp = ui->MemberExpInputLineEdit->text();

    //UPDATE STRINGS
    if(ui->radioButtonBasic->isChecked())
    {
        membershipType = "Basic";
    }
    else if(ui->radioButtonPrefered->isChecked())
    {
        membershipType = "Preferred";
    }
    else
    {
        cout << "Error. All Checked." << endl;
    }
    name = qName.toStdString();
    id = qID.toStdString();
    expiration = qExp.toStdString();

    //CREATE MEMBER
    Member newMem(name, id, membershipType, expiration);

    //SEND TO WHOLESALECLUB DATABASE TO CHECK IF ADDED
    stringstream ss;

    if(myClub.addMemberWC(newMem) == true)
    {
        ss << "New member successfully added!" << endl;
    }
    else
    {
        ss << "New member not added! Please check Name & ID Duplicate." << endl;

    }
    ss << "NAME: " << name << endl;
    ss << "ID: " << id << endl;
    ss << "MEMBERSHIP: " << membershipType << endl;
    ss << "EXPIRATION: " << expiration << endl;
    string memInfo = ss.str();
    QString addedSuccessOutput = QString::fromStdString(memInfo);

    ui->OutputMembersText->setText(addedSuccessOutput);
}

void MainWindow::on_ShowAllMembers_clicked()
{
    QString temp = "Show all member button clicked!";
    ui->OutputMembersText->setText(temp);

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Deletes the specified member from the data base
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed, as well as name, membership id and membership
*   experation must be already entered by the user
* POST-CONDITIONS:
*   Changes the current GUI page to the Sales Home Page
**************************************************************************/
void MainWindow::on_DeleteMemberPage_clicked()
{
    QString temp = "Delete member button clicked!";
    ui->OutputMembersText->setText(temp);

    QString qName, qID, qExp;
    string name, id, membershipType, expiration;

    //RECORD QSTRINGS
    qName = ui->memberNameINPUT->text();
    qID = ui->MemberIDInputMEMBERS->text();
    qExp = ui->MemberExpInputLineEdit->text();

    //UPDATE STRINGS
    if(ui->radioButtonBasic->isChecked())
    {
        membershipType = "Basic";
    }
    else if(ui->radioButtonPrefered->isChecked())
    {
        membershipType = "Preferred";
    }
    else
    {
        cout << "Error. All Checked." << endl;
    }

}

void MainWindow::on_UpdateExisitingMemberPage_clicked()
{
    QString temp = "Update  member button clicked!";
    ui->OutputMembersText->setText(temp);
}

void MainWindow::on_ShowAllPreferredMembers_clicked()
{
    QString temp = "Show preferred member button clicked!";
    ui->OutputMembersText->setText(temp);

}

void MainWindow::on_ShowAllBasicMembers_clicked()
{
    QString temp = "Show basic member button clicked!";
    ui->OutputMembersText->setText(temp);

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Tells the user, upon receiving the membership name, id and type from the user.
* Where it will then determine if a membership should switch to either Basic or
* Preferred
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed, name, membership id and membership type need to
* already been inputted
* POST-CONDITIONS:
*   writes to the screen if a membership should change to a different type, or
*   stay the same
**************************************************************************/
void MainWindow::on_MembershipRecommendationButton_clicked()
{
    QString temp = "Show member rec button clicked!";
    ui->OutputMembersText->setText(temp);

    //REQ #10 & 11
    QString qName, qID;
    string name, id, membershipType;

    //RECORD QSTRINGS
    qName = ui->memberNameINPUT->text();
    qID = ui->MemberIDInputMEMBERS->text();

    name = qName.toStdString();
    id = qID.toStdString();

    string report;
    if(ui->radioButtonBasic->isChecked())
    {
        //BASIC MEMBER REC
        membershipType = "Basic";
        //DEBUG
        cout << "Entering basicMemberRec" << endl;
        report = myClub.basicMembershipRec(name, id);

    }
    else if(ui->radioButtonPrefered->isChecked())
    {
        //PREFERRED MEMBER REC
        membershipType = "Preferred";
        cout << "Entering PreferredMemberRec" << endl;
        report = myClub.PreferredMembershipRec(name, id);
    }
    else if(ui->radioButtonAll->isChecked())
    {
        //ALL MEMBER REC
        cout << "Entering AllMemberRec" << endl;
        report = myClub.AllMembershipRec();
    }
    else
    {
        cout << "Select a button" << endl;
        report = "Please select a button.";
    }

    QString qReport = QString::fromStdString(report);
    ui->OutputMembersText->setText(qReport);

}

void MainWindow::on_ShowExpiringMembersByMonth_clicked()
{
    QString temp = "Show exp member button clicked!";
    ui->OutputMembersText->setText(temp);

}

void MainWindow::on_purchases_display_pushButton_clicked()
{
    QString temp = "Display button clicked!";
    ui->purchasesBrowser->setText(temp);

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Prints out the sales report of each member in ascending order, as well as selected
* membership type
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed, membership type selected by user
* POST-CONDITIONS:
*   Writes to the text browser the list of purchased item by each member,
*   is organized in ascending order, includes a grand total at the bottom of each
*   report
**************************************************************************/
void MainWindow::on_members_AllMemberPurchases_pushButton_clicked()
{
    double TAX = 0.0875;
    //Takes care of #3 from the Warehouse docx
        //Works apparently, according to kev. i hope it does
        cout << "\nAll Member Purchases button clicked\n";
        string id;
        string hold;
        string str;
        stringstream ss;
        Container<Member>::Iterator it;
        //For Preferred members
        if(ui->radioButtonPrefered->isChecked() == false
                && ui->radioButtonBasic->isChecked() == false
                && ui->radioButtonAll->isChecked() == false){
            ui->OutputMembersText->setText("Please select one of the radio buttons below!");
        }
        if(ui->radioButtonPrefered->isChecked()){

            //Testing: cout << "\n Inside Preferred if\n";
            myClub.preferredMemberDatabase.select_sort();
            it = myClub.preferredMemberDatabase.begin();
            //Should Display all the purchases of the preferredMemberDatabase
            for(int i = 0; i < myClub.preferredMemberDatabase.length();i++){
                //Testing: cout << "\nStart of 1st for loop\n";
                id = (*it).getId();
                str += id;
                str += "\n";
                str += myClub.totalPurchasesByMember(id,"Preferred");
                str += "\n\n";
                it++;
            }
            str += "\n";
            //After reaching this point the grand total should be calculated
            it = myClub.preferredMemberDatabase.begin();
            double total= 0;
            //Testing: cout << "\nEntering 2nd for loop\n";
            for(int i = 0; i < myClub.preferredMemberDatabase.length(); i++){
                //Testing: cout << "\nStart of 2nd for loop\n";
                string temp;
                temp = (*it).totalSpentWTax(TAX);
                total += stof(temp);
                it++;
            }
            //Testing: cout << "\nEnd of loops\n";
            str += "Total: ";
            ss << total;
            hold = ss.str();
            str.append(hold);
            //Testing: cout << "\nTotal was added\n";
            ui->OutputMembersText->setText(QString::fromStdString(str));

        }
    //****************************************************
        //For basic members
        else if(ui->radioButtonBasic->isChecked()){
            //Testing: cout << "\n Inside Preferred if\n";
            myClub.basicMemberDatabase.select_sort();
            it = myClub.basicMemberDatabase.begin();
            //Should Display all the purchases of the preferredMemberDatabase
            for(int i = 0; i < myClub.basicMemberDatabase.length();i++){
                //Testing: cout << "\nStart of 1st for loop\n";
                id = (*it).getId();
                str += id;
                str += "\n";
                str += myClub.totalPurchasesByMember(id,"Basic");
                str += "\n\n";
                it++;
            }
            str += "\n";
            //After reaching this point the grand total should be calculated
            it = myClub.basicMemberDatabase.begin();
            double total= 0;
            //Testing: cout << "\nEntering 2nd for loop\n";
            for(int i = 0; i < myClub.preferredMemberDatabase.length(); i++){
                //Testing: cout << "\nStart of 2nd for loop\n";
                string temp;
                temp = (*it).totalSpentWTax(TAX);
                total += stof(temp);
                it++;
            }
            //Testing: cout << "\nEnd of loops\n";
            str += "Total: ";
            ss << total;
            hold = ss.str();
            str.append(hold);
            //Testing: cout << "\nTotal was added\n";
            ui->OutputMembersText->setText(QString::fromStdString(str));
        }
    //*****************************************************
        //For ALL members
        else if(ui->radioButtonAll->isChecked()){
            //Starting with Preferred
            string finalOutput = "";
            myClub.preferredMemberDatabase.select_sort();
            it = myClub.preferredMemberDatabase.begin();
            //Should Display all the purchases of the preferredMemberDatabase
            for(int i = 0; i < myClub.preferredMemberDatabase.length();i++){
                //Test: cout << "\nStart of 1st for Preferred loop\n";
                id = (*it).getId();
                str += id;
                str += "\n";
                str += myClub.totalPurchasesByMember(id,"Preferred");
                str += "\n\n";
                it++;
            }
            str += "\n";
            //After reaching this point the grand total should be calculated
            it = myClub.preferredMemberDatabase.begin();
            double total= 0;
            //Test: cout << "\nEntering 2nd for loop\n";
            for(int i = 0; i < myClub.preferredMemberDatabase.length(); i++){
                //Test: cout << "\nStart of 2nd Preferred for loop\n";
                string temp;
                temp = (*it).totalSpentWTax(TAX);
                total += stof(temp);
                it++;
            }
            str += "Total: ";
            ss << total;
            hold = ss.str();
            str.append(hold);
            finalOutput = str;
            finalOutput += "\nBasic:\n\n";

            //Now Printing Basic members
            str = "";
            myClub.basicMemberDatabase.select_sort();
            it = myClub.basicMemberDatabase.begin();
            //Should Display all the purchases of the preferredMemberDatabase
            for(int i = 0; i < myClub.basicMemberDatabase.length();i++){
                //Test: cout << "\nStart of 1st for Preferred loop\n";
                id = (*it).getId();
                str += id;
                str += "\n";
                str += myClub.totalPurchasesByMember(id,"Basic");
                str += "\n\n";
                it++;
            }
            str += "\n";
            //After reaching this point the grand total should be calculated
            it = myClub.basicMemberDatabase.begin();
            total = 0;
            //Test: cout << "\nEntering 2nd for loop\n";
            for(int i = 0; i < myClub.basicMemberDatabase.length(); i++){
                //Test: cout << "\nStart of 2nd Preferred for loop\n";
                string temp;
                temp = (*it).totalSpentWTax(TAX);
                total += stof(temp);
                it++;
            }
            str += "Total: ";
            ss << total;
            hold = ss.str();
            str.append(hold);
            finalOutput = str;

            ui->OutputMembersText->setText(QString::fromStdString(finalOutput));
        }
}

//REQ #4
/**************************************************************************
* Accessor
*__________________________________________________________________________
* A user enters an item name and recieves the quantity sold as well as the items
* toal sales price
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Button must be pressed and user must enter an item name
* POST-CONDITIONS:
*   Prints to the screen the amount already sold as wells as the items total
*   sales price
**************************************************************************/
void MainWindow::on_inventory_search_pushButton_clicked()
{
    //Take QString from GUI
    QString item = ui->inventory_input_lineEdit->text();
    //Convert QString to string
    string strItem = item.toStdString();

    //call the itemReport from wholesaleclub that returns report
    //for that specific item
    string report;
    report = myClub.itemReport(strItem);

    //Convert itemreport string to QString
    QString itemReport = QString::fromStdString(report);

    //Set browser text to Qstring itemReport
    ui->displayInvBrows->setText(itemReport);
}
//REQ #5
void MainWindow::on_inventory_searchAll_pushButton_clicked()
{

}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Writes to the screen all PreferredMembers rebates
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Preferred member data base can not be empty
* POST-CONDITIONS:
*   Returns the rebate reports for all preferred members
**************************************************************************/
void MainWindow::on_allPreferredMemberRebatesButton_clicked()
{
    cout << "=============================" << endl;
    cout << "Preferred Member Rebates" << endl;
    QString rebateReport;
    string strReport = myClub.rebateReport();
    rebateReport = QString::fromStdString(strReport);
    ui->OutputMembersText->setText(rebateReport);
    cout << "=============================" << endl;
}
/**************************************************************************
* Accessor
*__________________________________________________________________________
* Writes to the screen the list of all membership dues, organized by membership
* type and name
*__________________________________________________________________________
* PRO-CONDITIONS:
*   Must be pressed, databases can not be empty
* POST-CONDITIONS:
*   Writes to the screen the list of all membership dues
**************************************************************************/
void MainWindow::on_membershipDuesButton_clicked()
{
    //REQUIREMENT #7 -
    string report = myClub.memberDuesReport();
    QString qReport = QString::fromStdString(report);
    ui->OutputMembersText->setText(qReport);
}
