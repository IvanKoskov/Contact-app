#ifndef PREVIEW_H
#define PREVIEW_H

#include <QDialog>

namespace Ui {
class preview;
}

class preview : public QDialog
{
    Q_OBJECT

public:
    explicit preview(QWidget *parent = nullptr);
    ~preview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::preview *ui;
};



#endif // PREVIEW_H
