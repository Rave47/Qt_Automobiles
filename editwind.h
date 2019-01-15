#ifndef EDITWIND_H
#define EDITWIND_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class editWind;
}

class editWind : public QDialog
{
    Q_OBJECT
private:
    QTableWidgetItem *itm1;
public:
    explicit editWind(QWidget *parent = 0, QTableWidgetItem* = nullptr);
    ~editWind();

signals:
   void saveEdit(QTableWidgetItem*);

private slots:
    void confEnabled();
    void on_CancelBut_clicked();
    void on_confirmBut_clicked();

private:
    Ui::editWind *ui;
};

#endif // EDITWIND_H
