#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QDate"
#include "QDateTime"
#include "QList"
#include "QVector"
#include "QMessageBox"
#include "QDebug"
#include <QScreen>

using namespace std;

QList<User> usersList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Zaloguj się");
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::on_pushButton_clicked()
//{
    //QDateTime dt = QDateTime::fromString("1.30.1", "M.d.s");
    //Todo newTodo("Dentysta", dt, false);
    //User1.todolist.append(newTodo);
    //ui->pushButton->setText(User1.todolist[0].name);
//}

void print(QList<User> list)
{
    for(auto someclass : list) {
        qDebug() << someclass.name << someclass.password;
    }
    qDebug() << "";
}


void MainWindow::on_pushButtonLogin_clicked()
{
    User User1 ("Andrzej", "123", QVector<Todo>());
    User User2 ("Michał", "456", QVector<Todo>());
    User User3 ("Paweł", "789", QVector<Todo>());

    usersList << User1 << User2 << User3;

    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    User checkUser (username, password, QVector<Todo>());
    //print(usersList);

    auto userExists = std::find_if(
      usersList.begin(), usersList.end(),
      [&username, &password](User o) { return o.name == username && o.password == password; }
    );
    if (userExists != usersList.end())
    {
      // object was found, use *itObj (or itObj->) to access it/its members
        //znaleziono użytkownika, użyj *userExists lub userExists-> by dostać się do jego metod
        //QMessageBox::information(this, "Login", "Correct");
        hide();
        loggedIn = new LoggedIn(this);
        loggedIn->show();
    }
    else
    {
      QMessageBox::warning(this, "Login", "Podano błędne dane logowania");
    }

}


void MainWindow::on_actionDodaj_u_ytkownika_triggered()
{
    addUser = new AddUser(this);
    addUser->show();
}

