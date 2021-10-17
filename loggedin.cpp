#include "loggedin.h"
#include "ui_loggedin.h"

LoggedIn::LoggedIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoggedIn)
{
    ui->setupUi(this);
    this->setWindowTitle("Twój terminarz");
    model = new QStringListModel(this);
    QStringList list;
    list << "Dentysta" << "Fryzjer" << "Zakupy";

    model->setStringList(list);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
}

LoggedIn::~LoggedIn()
{
    delete ui;
}

void LoggedIn::on_DodajZadanie_clicked()
{

    int row = model->rowCount();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}


void LoggedIn::on_wstawZadanie_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}



void LoggedIn::on_UsunZadanie_clicked()
{
    model->removeRows(ui->listView->currentIndex().row(), 1);
}





