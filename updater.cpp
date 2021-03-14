#include "updater.h"
#include "ui_updater.h"

updater::updater(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updater)
{
    ui->setupUi(this);
}

updater::~updater()
{
    delete ui;
}


void updater::on_pushButton_clicked()
{
    hide();
}
