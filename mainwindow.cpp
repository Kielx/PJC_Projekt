#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QDate"
#include "QDateTime"
#include "QVector"

using namespace std;

struct Todo {
    QString name;
    QDateTime datetime;
    bool status;
    Todo (QString _name, QDateTime _datetime, bool _status){
        name = _name;
        datetime = _datetime;
        status = _status;
    }

};

struct User {
    QString name;
    QString password;
    QVector<Todo> todolist;
    User (QString _name, QString _password, QVector<Todo> _todolist){
        name = _name;
        password = _password;
        todolist = _todolist;
    }
};

User User1 ("Andrzej", "123", QVector<Todo>());


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDateTime dt = QDateTime::fromString("1.30.1", "M.d.s");
    Todo newTodo("Dentysta", dt, false);
    User1.todolist.append(newTodo);
    ui->pushButton->setText(User1.todolist[0].name);
}

