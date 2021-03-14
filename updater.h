#ifndef UPDATER_H
#define UPDATER_H

#include <QDialog>

namespace Ui {
class updater;
}

class updater : public QDialog
{
    Q_OBJECT

public:
    explicit updater(QWidget *parent = nullptr);
    ~updater();

private slots:

    void on_pushButton_clicked();

private:
    Ui::updater *ui;
};

#endif // UPDATER_H
