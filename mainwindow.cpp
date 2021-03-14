#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include"updater.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->response_label->hide();
    QSqlDatabase Database;
    Database = QSqlDatabase::addDatabase("QSQLITE");
    Database.setDatabaseName("C:/sqlite3/company.db");
    Database.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_login_button_clicked()
{

    QString username,password;
    username = ui->username_edit->text();
    password = ui->password_edit->text();



    QSqlQuery query;

  /*  query.exec("select from information where name = '"+username+"' and password = '"+password+"';");*/
 //QString entername = query.value("name").toString();
   // QString enterpassword = query.value(1).toString();
    /*query.exec("insert into information values('"+username+"','"+password+"');");*/

    if(query.exec("select * from information where name = '"+username+"' and password = '"+password+"'")) {

    int count = 0;
    while(query.next()){
        count++;
    }
            if(count == 1){
            /*ui->response_label->setText("");*/
            QMessageBox::information(this,"Successfull","ACCESS GRANTED");
            hide();
            updater secDialog;
            secDialog.setModal(true);
            secDialog.exec();
            this->close();
}

            else if(count<1){
            ui->response_label->setText("Enter Correct username and password");
            QMessageBox::critical(this,"Failed","ACCESS DENIED");

}
    }

   /* if(entername == "" and enterpassword == ""){
        ui->response_label->show();
        ui->response_label->setText("Enter Correct username and password");


    }
    else {
        if(entername == ""){
            ui->response_label->setText("Enter Correct username");
        }
        else if(enterpassword == ""){
        ui->response_label->setText("Enter Correct password");

        }
        else{

             ui->response_label->setText("");
             QMessageBox::information(this,"Successfull","lol");
        }

        }*/
  /*query.exec("select from information where name = '"+username+"' and password = '"+password+"'");*/
  //  QString entername = query.value(0).toString();
   /* QString enterpassword = query.value(1).toString();*/
    /*if(query.exec("select * from information where name = '"+username+"';")) {
        QMessageBox::information(this,"Successfull","lol");
        ui->response_label->setText("yes");
    }
    else{
        ui->response_label->setText("not");
    }*/
    }



