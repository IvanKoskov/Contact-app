#include "previewadd.h"
#include "ui_previewadd.h"
#include <QFile>
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QFileDialog>
QString namefull;

previewadd::previewadd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::previewadd)
{
    ui->setupUi(this);


    QString userhere = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);


    QPixmap pix7(":/rec/User22qt.png");
    if (pix7.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->label_4->setPixmap(pix7.scaled(60, 60, Qt::KeepAspectRatio));
    }


    QFile filepassed("/Users/evan/topass");

    // Read the first line
    if (filepassed.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&filepassed);
        namefull = in.readLine(); // Read the first line
        filepassed.close();
    } else {
        qDebug() << "Failed to open file.";
        return;
    }

    // Delete the file
    if (QFile::remove("/Users/evan/status_me/topass")) {
        qDebug() << "File deleted successfully.";
    } else {
        qDebug() << "Failed to delete file.";
    }


    QString filePathadd = userhere + QDir::separator() + "status_me" + QDir::separator() + namefull + ".txt";

    QFile filefinal(filePathadd);
    if (!filefinal.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(this, "File Open Error", "Could not open file for reading!");
        return;
    }

    QTextStream in(&filefinal);

    // Read the first line
    QString firstLine = in.readLine();
    ui->label_6->setText(firstLine);

    // Read the second line
    QString secondLine = in.readLine();
    ui->label_10->setText(secondLine);

    // Read the third line
    QString thirdLine = in.readLine();
    ui->tele->setText(thirdLine);

    // Read the fourth line
    QString fourthLine = in.readLine();
    ui->what->setText(fourthLine);

filefinal.close();

}

previewadd::~previewadd()
{
    delete ui;
}











void previewadd::on_pushButton_clicked()
{
    this->close();

}

