#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addwind.h"
#include "editwind.h"
#include "confirmdialog.h"
#include "openwind.h"
#include "savewind.h"

#include "Automobile.h"
#include "UsedAuto.h"
#include "NewAuto.h"
#include "DamagedAuto.h"

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidget>
#include <QAction>

#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actOpen, SIGNAL(triggered()), SLOT(actionOpen()));
    connect(ui->actSave, SIGNAL(triggered()), SLOT(actionSave()));
    connect(ui->actSaveAs, SIGNAL(triggered()), SLOT(actionSaveAs()));
    connect(ui->actEnd, SIGNAL(triggered()),SLOT(close()));
    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(ButEnabled()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::print(list<Automobile *> data){

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Vehicle Brand" << "Model" << "Status"
                                               << "Release" << "Engine Capacity, l" << "Power, hp"
                                               << "Warranty, y" << "Mileage, km" << "Integrity, %");

    auto it = data.begin();
    string str;
    for(int i = 0; i < ui->tableWidget->rowCount(); ++i, ++it){

        str = (*it)->getMark();
        QTableWidgetItem *itm1 = new QTableWidgetItem(str.c_str());
        ui->tableWidget->setItem(i,0,itm1);

        str = (*it)->getModel();
        QTableWidgetItem *itm2 = new QTableWidgetItem(str.c_str());
        ui->tableWidget->setItem(i,1,itm2);

        str = (*it)->getType();
        QTableWidgetItem *itm3 = new QTableWidgetItem(str.c_str());
        ui->tableWidget->setItem(i,2,itm3);

        QTableWidgetItem *itm4 = new QTableWidgetItem(tr("%1").arg((*it)->getYear()));
        ui->tableWidget->setItem(i,3,itm4);

        str = to_string((*it)->getEC());
        str.erase(3,6);
        QTableWidgetItem *itm5 = new QTableWidgetItem(str.c_str());
        ui->tableWidget->setItem(i,4,itm5);

        QTableWidgetItem *itm6 = new QTableWidgetItem(tr("%1").arg((*it)->getPower()));
        ui->tableWidget->setItem(i,5,itm6);

        QTableWidgetItem *itm7 = new QTableWidgetItem(tr("%1").arg((*it)->getExt()));
        if((*it)->getType() == "New"){
            ui->tableWidget->setItem(i,6,itm7);
        }
        else {((*it)->getType() == "Pre-Owned")?(ui->tableWidget->setItem(i,7,itm7)):(ui->tableWidget->setItem(i,8,itm7));}
    }
}

void MainWindow::load(list<Automobile*>* data, QString path) {
    data->clear();
    ifstream file(path.toStdString());

    if(!file){
        QMessageBox::information(this, "Error!", "Не удалось открыть файл");
    }

    while (file) {
        string str;
        getline(file, str);
        if (str.empty()) break;
        string mark = str;

        getline(file, str);
        string model = str;

        getline(file, str);
        string type = str;

        getline(file, str);
        int year = atoi(str.c_str());

        getline(file, str);
        float engine_capacity = stof(str);

        getline(file, str);
        int power = atoi(str.c_str());

        getline(file, str);
        int smt = atoi(str.c_str());

        if (type == "New") {
            NewAuto *obj = new NewAuto(mark, model, year, engine_capacity, power, smt);
            data->push_back(obj);
        }
        else {
            if (type == "Pre-Owned") {
                UsedAuto *obj = new UsedAuto(mark, model, year, engine_capacity, power, smt);
                data->push_back(obj);
            }
            else {
                if (type == "Damaged") {
                    DamagedAuto *obj = new DamagedAuto(mark, model, year, engine_capacity, power, smt);
                    data->push_back(obj);
                }
            }
        }

        getline(file, str);

    }
    file.close();
    print(*data);
    ui->actSaveAs->setEnabled(true);
}

void MainWindow::on_addButt_clicked()
{
   AddWind *wnd = new AddWind(this, &data);
   wnd->show();

   connect(wnd, SIGNAL(newInfo(list<Automobile*>*, const QString*)), this, SLOT(add(list<Automobile*>*, const QString*)));
}

void MainWindow::on_delButt_clicked()
{
    if(!data.empty()){
        ConfirmDialog *wnd = new ConfirmDialog(this, &data);
        wnd->show();
        connect(wnd, SIGNAL(delConfirm(list<Automobile*>*)), this, SLOT(deleteObj(list<Automobile*>*)));
    }
    else QMessageBox::information(this, "Error!", "База данных пуста");

}

void MainWindow::on_editButt_clicked()
{
    if(!data.empty()){
        editWind *wnd = new editWind(this, ui->tableWidget->currentItem());
        wnd->show();
        connect(wnd, SIGNAL(saveEdit(QTableWidgetItem*)), this, SLOT(edit(QTableWidgetItem*)));
    }
    else QMessageBox::information(this, "Error!", "База данных пуста");
}

void MainWindow::add(list<Automobile*>* data, const QString* info){

    if (info[6] == "New"){
        NewAuto *obj = new NewAuto(info[0].toStdString(), info[1].toStdString(), info[2].toInt(),
            info[3].toFloat(), info[4].toInt(), info[5].toInt());
        data->push_back(obj);
    }
    if (info[6] == "Pre-Owned"){
        UsedAuto *obj = new UsedAuto(info[0].toStdString(), info[1].toStdString(), info[2].toInt(),
            info[3].toFloat(), info[4].toInt(), info[5].toInt());
        data->push_back(obj);
    }
    if (info[6] == "Damaged"){
        DamagedAuto *obj = new DamagedAuto(info[0].toStdString(), info[1].toStdString(), info[2].toInt(),
                                           info[3].toFloat(), info[4].toInt(), info[5].toInt());
        data->push_back(obj);
    }
    ui->actSave->setEnabled(true);
    print(*data);
}

void MainWindow::deleteObj(list<Automobile*>* data){
    auto it = data->begin();
    for(int k = 0; k < ui->tableWidget->currentRow(); ++k)
        ++it;
    delete(*it);
    data->erase(it);
    ui->actSave->setEnabled(true);
    print(*data);
}

void MainWindow::actionSave(){
    save(data, "C:\\Qt Projects\\1\\ver7\\base.txt");
}

void MainWindow::actionSaveAs(){
    SaveWind *wnd = new SaveWind;
    wnd->show();

    connect(wnd, SIGNAL(savePath(QString)), this, SLOT(saveAs(QString)));
}

void MainWindow::edit(QTableWidgetItem *itm){
    auto it = data.begin();
    for (int k = 0; k < itm->row(); ++k)
        ++it;
    switch (itm->column()) {
    case 0:
        (*it)->editMark(itm->text().toStdString());
        break;
    case 1:
        (*it)->editModel(itm->text().toStdString());
        break;
    case 3:
        (*it)->editYear(itm->text().toInt());
        break;
    case 4:
        (*it)->editEC(itm->text().toFloat());
        break;
    case 5:
        (*it)->editPower(itm->text().toInt());
        break;
    case 6:
        (*it)->editExtra(itm->text().toInt());
        break;
    case 7:
        (*it)->editExtra(itm->text().toInt());
        break;
    case 8:
        (*it)->editExtra(itm->text().toInt());
        break;
    }
    ui->actSave->setEnabled(true);
}

void MainWindow::ButEnabled(){
    ui->editButt->setEnabled(ui->tableWidget->currentColumn()!=2 &&
                             ui->tableWidget->item(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())&&
                             !data.empty());
    ui->delButt->setEnabled(ui->tableWidget->currentColumn() == 0 && !data.empty());
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    if(ui->tableWidget->currentColumn() != 2){
        on_editButt_clicked();
    }
}

void MainWindow::save(list<Automobile*> data, QString path) {
    ofstream fout(path.toStdString(), ios_base::trunc);
    if(!fout){
        QMessageBox::information(this, "Error!", "Не удалось открыть файл");
    }
    fout.close();
    for (auto it = data.begin(); it != data.end(); ++it) {
        (*it)->addToFile(path.toStdString());
    }
    ui->actSave->setEnabled(false);
}

void MainWindow::saveAs(const QString str){
    save(data, str);
}

void MainWindow::actionOpen(){
    OpenWind *wnd = new OpenWind(this, &data);
    wnd->show();

    connect(wnd, SIGNAL(filePath(list<Automobile*>*, QString)), this, SLOT(load(list<Automobile*>*, QString)));
}



