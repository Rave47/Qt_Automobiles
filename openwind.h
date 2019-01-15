#ifndef OPENWIND_H
#define OPENWIND_H

#include <QDialog>
#include <list>
#include "Automobile.h"

namespace Ui {
class OpenWind;
}

class OpenWind : public QDialog
{
    Q_OBJECT

public:
    explicit OpenWind(QWidget *parent = 0, list<Automobile*>* = nullptr);
    ~OpenWind();

signals:
    void filePath(list<Automobile*>*, const QString);

private slots:
    void on_cancelBut_clicked();
    void on_confirmBut_clicked();

private:
    list<Automobile*>* data1;
    Ui::OpenWind *ui;
};

#endif // OPENWIND_H
