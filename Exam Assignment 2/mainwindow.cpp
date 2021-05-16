#include "mainwindow.h"
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QDebug>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QFont>
#include<dialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Image icon for username
    QLabel *lab=new QLabel(this);
    lab->setMinimumSize(70,50);
    lab->move(100,50);
    QPixmap pixx("C://Users//yeshu//Desktop//username.jpg");
    lab->setPixmap(pixx.scaled(20,20));

    //Set image icon in center
    QLabel *mlabel=new QLabel(this);
    mlabel->move(180,25);
    mlabel->setAlignment(Qt::AlignHCenter);
    QPixmap pix("C://Users//yeshu//Desktop//login.png");
    mlabel->setPixmap(pix.scaled(50,20));

    //QLabel for username
    QLabel *unlabel=new QLabel("UserName",this);
    unlabel->setMinimumSize(70,50);
    unlabel->move(130,50);
    QPalette l1;
    l1.setColor(QPalette::WindowText,Qt::red);
    unlabel->setPalette(l1);

    //QLineEdit for username
    QLineEdit *unLineEdit=new QLineEdit(this);
    unLineEdit->setMinimumSize(200,50);
    unLineEdit->move(220,50);

    //set the lineedit border to red color
    unLineEdit->setStyleSheet("border: 2px solid red");

    //Image icon for password
    QLabel *labb=new QLabel(this);
    labb->setMinimumSize(200,50);
    labb->move(100,110);
    QPixmap pixxx("C://Users//yeshu//Desktop//password.png");
    labb->setPixmap(pixxx.scaled(20,20));

    //QLabel for password
    QLabel *pwd=new QLabel("Password",this);
    pwd->setMinimumSize(70,50);
    pwd->move(130,110);
    QPalette l2;
    l2.setColor(QPalette::WindowText,Qt::green);
    pwd->setPalette(l2);

    //QlineEdit for password
    QLineEdit *pass=new QLineEdit(this);
    pass->setMinimumSize(200,50);
    pass->move(220,110);
    pass->setEchoMode(QLineEdit::Password);

    //set the lineedit border to green color
    pass->setStyleSheet("border: 2px solid green");

    //QLabel
    QLabel *account=new QLabel("Don't have account",this);
    account->setMinimumSize(100,50);
    account->move(130,170);

    //QPushButton for SignUp
    QFont button("Times",8,QFont::Bold);
    QPushButton *button1=new QPushButton("SignUp",this);
    button1->setFont(button);
    button1->move(220,180);
    connect(button1,&QPushButton::clicked,[=](){
        Dialog *dialog=new Dialog(this);
        dialog->exec();

    });

    //QPushButton for Login
    QFont buttons("Times",18,QFont::Bold);
    QPushButton *button2=new QPushButton("Login",this);
    button2->setFont(buttons);
    button2->move(220,280);
    connect(button2,&QPushButton::clicked,[=](){
        QString userName=unLineEdit->text();
        QString password=pass->text();
        if(userName=="Student"&&password=="Student")
        {
            QMessageBox::information(this,"Login","UserName and password is correct");
        }
        else
        {
            QMessageBox::information(this,"Login","UserName and password is incorrect");
        }
    });
    //Hint Text
    unLineEdit->setPlaceholderText("username");
    pass->setPlaceholderText("password");
}

MainWindow::~MainWindow()
{
}

