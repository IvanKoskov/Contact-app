#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwindow(QWidget *parent = nullptr);
    ~thirdwindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
