#include "mainwindow.h"
#include <QApplication>

#include "Automobile.h"
#include "NewAuto.h"
#include "UsedAuto.h"
#include "DamagedAuto.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <list>
#include <fstream>
#include <iterator>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow;
    w->show();

    return a.exec();
}

