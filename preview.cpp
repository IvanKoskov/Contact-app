#include "preview.h"
#include "ui_preview.h"
#include <QFile>
#include <QMessageBox>
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>
preview::preview(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::preview)
{
    ui->setupUi(this);
    QPixmap pix6(":/rec/telegaqt2.png");
    if (pix6.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->tele->setPixmap(pix6.scaled(60, 60, Qt::KeepAspectRatio));
    }

    QPixmap pix7(":/rec/whatqt2.png");
    if (pix7.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->what->setPixmap(pix7.scaled(60, 60, Qt::KeepAspectRatio));
    }

    QString userHomee = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString filePath = userHomee + QDir::separator() + "status_me" + QDir::separator() + "userinfome";


    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Open Error", "Could not open file for reading!");
        return;
    }

    QTextStream in(&file);

    // Read the first line
    QString firstLine = in.readLine();
    ui->label_6->setText(firstLine);

    // Read the second line
    QString secondLine = in.readLine();
    ui->label_9->setText(secondLine);

    // Read the third line
    QString thirdLine = in.readLine();
    ui->label_10->setText(thirdLine);

    // Read the fourth line
    QString fourthLine = in.readLine();
    ui->label_7->setText(fourthLine);

    // Read the fifth line
    QString fifthLine = in.readLine();
    ui->label_8->setText(fifthLine);

    file.close();


}

preview::~preview()
{
    delete ui;
}


void preview::on_pushButton_clicked()
{
    this->close();

    secondwindow secondwindow;
    secondwindow.setModal(true);
    secondwindow.setFixedSize(400, 600);
    secondwindow.setWindowTitle("ContactME");

    QVBoxLayout layout(&secondwindow);


    secondwindow.resize(300, 200);
    secondwindow.exec();


}

