#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <list>
#include "Automobile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    list<Automobile*> data;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void load(list<Automobile*>*, const QString);
    void print(list<Automobile*>);
    void add(list<Automobile*>*, const QString*);
    void deleteObj(list<Automobile*>*);
    void edit(QTableWidgetItem*);
    void save(list<Automobile*>, QString);
    void saveAs(const QString);

    void actionOpen();
    void actionSave();
    void actionSaveAs();
    void ButEnabled();
    void on_addButt_clicked();
    void on_delButt_clicked();
    void on_editButt_clicked();   
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
