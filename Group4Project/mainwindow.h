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
    ~MainWindow();

private slots:
    void on_MemberPurchases_Button_clicked();

private:
    Ui::MainWindow *ui;
    wholesaleClub myClub;

};
#endif // MAINWINDOW_H
