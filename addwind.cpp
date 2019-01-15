#include "addwind.h"
#include "ui_addwind.h"

AddWind::AddWind(QWidget *parent, list<Automobile*> *data) :
    QDialog(parent),
    ui(new Ui::AddWind)
{
    ui->setupUi(this);

    data1 = data;

    QRegExp markExp("[A-Z]{1}[a-z]{2,11}||[A-Z]{1}[a-z]{2,11}[ ][A-Z]{1}[a-z]{2,11}||[A-Z]{3,5}");
    ui->markLine->setValidator(new QRegExpValidator(markExp,this));

    QRegExp modelExp("[A-Z]{1}[a-z]{0,11}||[A-Z]{0,3}[1-9][0-9]{0,2}");
    ui->modelLine->setValidator(new QRegExpValidator(modelExp,this));

    QRegExp releaseExp("[1][9][4-9][0-9]||[2][0][0-1][0-9]");
    ui->yearLine->setValidator(new QRegExpValidator(releaseExp,this));

    QRegExp ecExp("[1-6][.][0-9]");
    ui->ecLine->setValidator(new QRegExpValidator(ecExp,this));

    QRegExp powerExp("[1-9][0-9][0-9]{0,1}");
    ui->powerLine->setValidator(new QRegExpValidator(powerExp,this));

    QRegExp warExp("[1-5]");
    ui->warLine->setValidator(new QRegExpValidator(warExp,this));

    QRegExp milExp("[1-9][0-9][0-9][0-9]{0,3}");
    ui->milLine->setValidator(new QRegExpValidator(milExp,this));

    QRegExp intgrExp("[0-9][0-9]{0,1}");
    ui->intgrLine->setValidator(new QRegExpValidator(intgrExp,this));

    connect(ui->markLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->modelLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->yearLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->ecLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->powerLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->warLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->intgrLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));
    connect(ui->milLine, SIGNAL(textChanged(QString)), this, SLOT(confirmEnabled()));

    ui->extraBox1->setVisible(false);
    ui->extraBox2->setVisible(false);
    ui->extraBox3->setVisible(false);

    connect(ui->addConfirmBut, SIGNAL(clicked()), SLOT(addConfirmBut_clicked()));

}

AddWind::~AddWind()
{
    delete ui;
}

void AddWind::on_addCancelBut_clicked()
{
    close();
}

void AddWind::on_newBut_clicked(bool checked)
{
    ui->extraBox2->setVisible(false);
    ui->extraBox3->setVisible(false);
    ui->extraBox1->setVisible(true);
}

void AddWind::on_ownBut_clicked(bool checked)
{
    ui->extraBox1->setVisible(false);
    ui->extraBox3->setVisible(false);
    ui->extraBox2->setVisible(true);
}

void AddWind::on_damBut_clicked(bool checked)
{
    ui->extraBox1->setVisible(false);
    ui->extraBox2->setVisible(false);
    ui->extraBox3->setVisible(true);
}

void AddWind::confirmEnabled(){
    ui->addConfirmBut->setEnabled((ui->markLine->hasAcceptableInput())&&
                           !(ui->markLine->text().isEmpty())&&
                           (ui->modelLine->hasAcceptableInput())&&
                           !(ui->modelLine->text().isEmpty())&&
                           (ui->yearLine->hasAcceptableInput())&&
                           !(ui->yearLine->text().isEmpty())&&
                           (ui->ecLine->hasAcceptableInput())&&
                           !(ui->ecLine->text().isEmpty())&&
                           (ui->powerLine->hasAcceptableInput())&&
                           !(ui->powerLine->text().isEmpty())&&
                           ((ui->milLine->hasAcceptableInput())&&
                           !(ui->milLine->text().isEmpty())||
                           (ui->intgrLine->hasAcceptableInput())&&
                           !(ui->intgrLine->text().isEmpty())||
                           (ui->warLine->hasAcceptableInput())&&
                           !(ui->warLine->text().isEmpty())));
}

void AddWind::addConfirmBut_clicked()
{
    QString info[7];
    info[0] = ui->markLine->text();
    info[1] = ui->modelLine->text();
    info[2] = ui->yearLine->text();
    info[3] = ui->ecLine->text();
    info[4] = ui->powerLine->text();
    if (ui->newBut->isChecked()){
        info[5] = ui->warLine->text();
        info[6] = {"New"};
    }
    if (ui->ownBut->isChecked()){
        info[5] = ui->milLine->text();
        info[6] = {"Pre-Owned"};
    }
    if (ui->damBut->isChecked()){
        info[5] = ui->intgrLine->text();
        info[6] = {"Damaged"};
    }

    emit newInfo(data1, info);
    close();
}
