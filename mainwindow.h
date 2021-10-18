#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loggedin.h"
#include "adduser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
