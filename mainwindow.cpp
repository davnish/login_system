#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->response_label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_button_clicked()
{
    QString username = ui->username_edit->text();
    QString password = ui->password_edit->text();

    if(username == "text" && password == "test"){
        ui->response_label->show();
        ui->response_label->setText("logged in");
    }
    else {
        ui->response_label->setText("Please enter correct credentials");
        }

    }


