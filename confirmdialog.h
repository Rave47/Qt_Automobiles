#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include "Automobile.h"
#include <list>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT
private:
    list<Automobile*>* data1;
public:
    explicit ConfirmDialog(QWidget *parent = 0, list<Automobile*>* = nullptr);
    ~ConfirmDialog();

signals:
    void delConfirm(list<Automobile*>*);

private slots:
    void on_CancelBut_clicked();
    void on_delConfirmBut_clicked();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
