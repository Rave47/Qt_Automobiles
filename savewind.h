#ifndef SAVEWIND_H
#define SAVEWIND_H

#include <QDialog>

namespace Ui {
class SaveWind;
}

class SaveWind : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWind(QWidget *parent = 0);
    ~SaveWind();

private slots:
    void on_cancelBut_clicked();

    void on_confirmBut_clicked();

signals:
    void savePath(const QString);

private:
    Ui::SaveWind *ui;
};

#endif // SAVEWIND_H
