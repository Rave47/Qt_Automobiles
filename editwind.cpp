#include "editwind.h"
#include "ui_editwind.h"

editWind::editWind(QWidget *parent, QTableWidgetItem* itm) :
    QDialog(parent),
    ui(new Ui::editWind)
{
    ui->setupUi(this);

    itm1 = itm;

    switch(itm->column()){
    case 0:
    {
         QRegExp markExp("[A-Z]{1}[a-z]{2,11}||[A-Z]{1}[a-z]{2,11}[ ][A-Z]{1}[a-z]{2,11}||[A-Z]{3,5}");
         ui->editLine->setValidator(new QRegExpValidator(markExp,this));
         break;
    }
    case 1:
    {
         QRegExp modelExp("[A-Z]{1}[a-z]{0,11}||[A-Z]{0,3}[1-9][0-9]{0,2}");
         ui->editLine->setValidator(new QRegExpValidator(modelExp,this));
         break;
    }
    case 3:
    {
         QRegExp releaseExp("[1][9][4-9][0-9]||[2][0][0-1][0-9]");
         ui->editLine->setValidator(new QRegExpValidator(releaseExp,this));
         break;
    }
    case 4:
    {
        QRegExp ecExp("[1-6][.][0-9]");
        ui->editLine->setValidator(new QRegExpValidator(ecExp,this));
        break;
    }
    case 5:
    {
         QRegExp powerExp("[1-9][0-9][0-9]{0,1}");
         ui->editLine->setValidator(new QRegExpValidator(powerExp,this));
         break;
    }
    case 6:
    {
         QRegExp warExp("[1-5]");
         ui->editLine->setValidator(new QRegExpValidator(warExp,this));
         break;
    }
    case 7:
    {
         QRegExp milExp("[1-9][0-9][0-9][0-9]{0,3}");
         ui->editLine->setValidator(new QRegExpValidator(milExp,this));
         break;
    }
    case 8:
    {
         QRegExp intgrExp("[0-9][0-9]{0,1}");
         ui->editLine->setValidator(new QRegExpValidator(intgrExp,this));
         break;
    }
    }
    connect(ui->editLine, SIGNAL(textChanged(QString)), this, SLOT(confEnabled()));

    ui->editLine->setText(itm1->text());
}

editWind::~editWind()
{
    delete ui;
}

void editWind::on_CancelBut_clicked()
{
  close();
}

void editWind::on_confirmBut_clicked()
{
    itm1->setText(ui->editLine->text());
    emit(saveEdit(itm1));
    close();
}

void editWind::confEnabled(){
    ui->confirmBut->setEnabled((ui->editLine->hasAcceptableInput())&&
                               !(ui->editLine->text().isEmpty()));
}



