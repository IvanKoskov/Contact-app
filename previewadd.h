#ifndef PREVIEWADD_H
#define PREVIEWADD_H

#include <QDialog>

namespace Ui {
class previewadd;
}

class previewadd : public QDialog
{
    Q_OBJECT

public:
    explicit previewadd(QWidget *parent = nullptr);
    ~previewadd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::previewadd *ui;
};

#endif // PREVIEWADD_H
