#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = nullptr);
    ~AddUser();

private slots:
    void on_Cancel_clicked();

    void on_Add_clicked();

private:
    Ui::AddUser *ui;
};

#endif // ADDUSER_H
