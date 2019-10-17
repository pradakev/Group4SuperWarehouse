#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//ADT Files
#include "container.h"
#include "item.h"
#include "member.h"
#include "preferredmember.h"
#include "sales.h"
#include "wholesaleclub.h"

#include <iostream>

using namespace std;

#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void goToPage(int pg);
    ~MainWindow();

private slots:
    void on_MemberPurchases_Button_clicked();

    void on_WelcomeSalesButton_clicked();

    void on_pushButton_SalesReportDone_clicked();

    void on_pushButton_dailyReport_clicked();

    void on_WelcomeMembersButton_clicked();

    void on_DoneMembersButton_clicked();

    void on_dailyReportPushButton_clicked();

    void on_purchases_done_pushButton_clicked();

    void on_pushButton_memberPurchasesReport_clicked();

    void on_pushButton_customReportOptions_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    wholesaleClub myClub;

};
#endif // MAINWINDOW_H
