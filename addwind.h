#ifndef ADDWIND_H
#define ADDWIND_H

#include <QDialog>
#include "mainwindow.h"
#include <list>
#include "Automobile.h"

namespace Ui {
class AddWind;
}

class AddWind : public QDialog
{
    Q_OBJECT

private:
    list<Automobile*>* data1;

public:

    explicit AddWind(QWidget *parent = 0, list<Automobile*>* = nullptr);
    ~AddWind();

signals:
    void newInfo(list<Automobile*>*, const QString*);

private slots:
    void on_addCancelBut_clicked();
    void on_newBut_clicked(bool checked);
    void on_ownBut_clicked(bool checked);
    void on_damBut_clicked(bool checked);
    void confirmEnabled();
    void addConfirmBut_clicked();

private:
    Ui::AddWind *ui;
};

#endif // ADDWIND_H
