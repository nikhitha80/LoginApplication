#include "dialog.h"
#include "ui_dialog.h"
#include<QString>
#include<QLineEdit>
#include<QDebug>
#include<QApplication>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_Confirm_Button_clicked()
{
    QString email=ui->Email_lineEdit->text();
    QString pwd=ui->Pass_lineEdit->text();
    QString confirmpwd=ui->Confirm_lineEdit->text();
    qDebug()<<"Email :"<<email;
    qDebug()<<"password :"<<pwd;
    qDebug()<<"Confirmpassword :"<<confirmpwd;
    if(!email.isEmpty()&&!pwd.isEmpty()&&!confirmpwd.isEmpty())
    {

    }
    else
    {
        qDebug()<<"One field is empty";
    }
}

void Dialog::on_Exit_Button_clicked()
{
    QApplication::quit();
}
