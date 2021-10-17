#ifndef LOGGEDIN_H
#define LOGGEDIN_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class LoggedIn;
}

class LoggedIn : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedIn(QWidget *parent = nullptr);
    ~LoggedIn();

private slots:
    void on_DodajZadanie_clicked();

    void on_UsunZadanie_clicked();

    void on_wstawZadanie_clicked();

private:
    Ui::LoggedIn *ui;
    QStringListModel *model;
};

#endif // LOGGEDIN_H
