#ifndef CONTACTADD_H
#define CONTACTADD_H

#include <QDialog>

namespace Ui {
class contactadd;
}

class contactadd : public QDialog
{
    Q_OBJECT

public:
    explicit contactadd(QWidget *parent = nullptr);
    ~contactadd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::contactadd *ui;
};

#endif // CONTACTADD_H
