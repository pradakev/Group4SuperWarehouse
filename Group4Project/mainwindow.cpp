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
    QString temp = "Add new member button clicked!";
    ui->OutputMembersText->setText(temp);
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
    //Takes care of #3 from the Warehouse docx
//    string id;
//    string str;
//    Container<Member>::Iterator it;
//    myClub.memberDatabase.select_sort();
//    for(it = myClub.memberDatabase.begin(); it != myClub.memberDatabase.end();it++){
//        id = (*it).getId();
//        str += myClub.totalPurchasesByMember(id);
//        str += "\n\n";
//    }
//    str += "\n";
//    it = myClub.memberDatabase.begin();
//    str += (*it).sumTotalPurchases();
//    ui->OutputMembersText->setText(QString::fromStdString(str));
}

void MainWindow::on_inventory_search_pushButton_clicked()
{
//    QString temp = ui->inventory_input_lineEdit->text();
//    string str = temp.toStdString();

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


