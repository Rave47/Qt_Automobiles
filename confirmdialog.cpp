#include "confirmdialog.h"
#include "ui_confirmdialog.h"
#include "mainwindow.h"

ConfirmDialog::ConfirmDialog(QWidget *parent, list<Automobile*>* data) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);

    data1 = data;
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

void ConfirmDialog::on_CancelBut_clicked()
{
   close();
}

void ConfirmDialog::on_delConfirmBut_clicked()
{
    emit(delConfirm(data1));
    close();
}
