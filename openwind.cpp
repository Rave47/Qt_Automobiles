#include "openwind.h"
#include "ui_openwind.h"

OpenWind::OpenWind(QWidget *parent, list<Automobile*>* data) :
    QDialog(parent),
    ui(new Ui::OpenWind)
{
    ui->setupUi(this);

    data1 = data;
}

OpenWind::~OpenWind()
{
    delete ui;
}

void OpenWind::on_cancelBut_clicked()
{
    close();
}

void OpenWind::on_confirmBut_clicked()
{
    emit(filePath(data1, ui->openLine->text()));
    close();
}
