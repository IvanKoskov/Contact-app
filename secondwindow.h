#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>



namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::secondwindow *ui;
    void loadNames();
};




#endif // SECONDWINDOW_H
