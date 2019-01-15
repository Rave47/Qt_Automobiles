#include "savewind.h"
#include "ui_savewind.h"

SaveWind::SaveWind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWind)
{
    ui->setupUi(this);
}

SaveWind::~SaveWind()
{
    delete ui;
}

void SaveWind::on_cancelBut_clicked()
{
    close();
}

void SaveWind::on_confirmBut_clicked()
{
    emit(savePath(ui->saveLine->text()));
    close();
}
