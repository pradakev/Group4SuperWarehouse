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
    //Record Name and iD from LineInputs
    QString nameInBox;
    nameInBox = ui->memberNameINPUT->text();
    QString idInBox;
    idInBox = ui->MemberIDInputMEMBERS->text();

    //Convert Qstrings to String
    string name, id;
    name = nameInBox.toStdString();
    id = idInBox.toStdString();
    cout << "name: " << name << endl;
    cout << "id: " << id << endl;
    //12345

    //MemberPurchases string
    string memberPurchases;

    //PROCESSING: memberPurchases will contain the purchases
    //for the member. I get this through functions in wholesaleClub class

    //Check whether either one is empty
    if(name.empty() == true && id.empty() != true)
    {
        cout << "name is empty. id is not empty." << endl;
        //if Name is empty but id is edited.
        memberPurchases = myClub.totalPurchasesByMember(id);

    }
    else if(name.empty() != true && id.empty() == true)
    {
        //if id is empty but name is edited, find id for name
        id = myClub.memberIdFromName(name);
        memberPurchases = myClub.totalPurchasesByMember(id);
    }
    else
    {

    }

    //Once you have string of memberPurchases, output to textBrowser

    //First convert string to Qstring
    QString qMemberPurchases = QString::fromStdString(memberPurchases);

    //Now send Qstring to textBrowser
    ui->OutputMembersText->setText(qMemberPurchases);
}
