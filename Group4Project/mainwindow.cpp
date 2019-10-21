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

void MainWindow::goToPage(int pg){
ui->stackedWidget->setCurrentIndex(pg);
}

void MainWindow::on_WelcomeSalesButton_clicked()
{
    goToPage(2);
}

void MainWindow::on_pushButton_SalesReportDone_clicked()
{
    goToPage(0);
}

void MainWindow::on_pushButton_dailyReport_clicked()
{
    goToPage(4);
}

void MainWindow::on_WelcomeMembersButton_clicked()
{
    goToPage(1);
}

void MainWindow::on_DoneMembersButton_clicked()
{
    ui->OutputMembersText->setText("Choose an option below.");
    goToPage(0);
}

void MainWindow::on_dailyReportPushButton_clicked()
{
    goToPage(2);
}

void MainWindow::on_purchases_done_pushButton_clicked()
{
    goToPage(2);
}

void MainWindow::on_pushButton_memberPurchasesReport_clicked()
{
    goToPage(3);
}

void MainWindow::on_pushButton_customReportOptions_clicked()
{
    goToPage(10);
}

void MainWindow::on_pushButton_3_clicked()
{
    goToPage(2);
}

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

void MainWindow::on_DoneButtonDI_clicked()
{
    goToPage(0);
}

void MainWindow::on_doneItemSalesButton_clicked()
{
    goToPage(0);
}

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

void MainWindow::on_members_AllMemberPurchases_pushButton_clicked()
{
    double TAX = 0.0875;
    //Takes care of #3 from the Warehouse docx
        //Works apparently, according to kev. i fucking hope it does
        cout << "\nAll Member Purchases button clicked\n";
        string id;
        string str;
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
            str += total;
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
            str += total;
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
            str += total;
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
            str += total;
            finalOutput = str;

            ui->OutputMembersText->setText(QString::fromStdString(finalOutput));
        }
}

//REQ #4
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

void MainWindow::on_inventory_searchAll_pushButton_clicked()
{

}

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



void MainWindow::on_membershipDuesButton_clicked()
{
    //REQUIREMENT #7 -
    string report = myClub.memberDuesReport();
    QString qReport = QString::fromStdString(report);
    ui->OutputMembersText->setText(qReport);
}
