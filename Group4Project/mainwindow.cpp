#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wholesaleClub myClub;
    myClub.updateMembers();
    myClub.updateSalesforMembers();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_MemberPurchases_Button_clicked()
{

}
