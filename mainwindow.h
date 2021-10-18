#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loggedin.h"
#include "adduser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

extern QList<User> usersList;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pushButtonLogin_clicked();

    void on_actionDodaj_u_ytkownika_triggered();

private:
    Ui::MainWindow *ui;
    LoggedIn *loggedIn;
    AddUser *addUser;

};
#endif // MAINWINDOW_H
