#include "adduser.h"
#include "ui_adduser.h"
#include "mainwindow.h"
#include <QMessageBox>

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_Cancel_clicked()
{
    hide();
}


void AddUser::on_Add_clicked()
{
    User User4 ("Mikołaj", "111", QVector<Todo>());
    QString username = ui->nazwaUzytkownika->text();
    QString password = ui->haslo->text();
    auto zadania = QVector<Todo>();
    User newUser(username, password, zadania);
    usersList << newUser;
    hide();
    QMessageBox::information(this, "Sukces", "Poprawnie założono konto nowego użytkownika");
}

