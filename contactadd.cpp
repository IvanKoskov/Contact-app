#include "contactadd.h"
#include "ui_contactadd.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

contactadd::contactadd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::contactadd)
{
    ui->setupUi(this);

}

contactadd::~contactadd()
{
    delete ui;
}



void contactadd::on_pushButton_clicked()
{
    QMessageBox::information(nullptr, "INFO", "ALL INFORMATION THAT YOU WILL INPUT WILL BE STOLEN BY IVAN KOSKOV))))");
}

QString nameful;
QString ageadd;
//these are non optional
QString telegramadd; //username @
QString whatsupadd; //phone number


void contactadd::on_pushButton_2_clicked()
{

    QFile filepassed("/Users/evan/status_me/topass");

    // Read the first line
    if (filepassed.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&filepassed);
        nameful = in.readLine(); // Read the first line
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


     QString filePathadd = "/Users/evan/status_me/" + nameful + ".txt";



 ageadd = QString::number(ui->spinBox->value());
    telegramadd = ui->lineEdit_3->text();
 whatsupadd = ui->lineEdit_4->text();

    QFile fileadd(filePathadd);
    if (fileadd.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&fileadd);
        out << nameful << "\n";
        out <<  ageadd << "\n";
        out << telegramadd << "\n";
        out << whatsupadd << "\n";

        fileadd.close();
        qDebug() << "File created successfully!";
    } else {
        qDebug() << "Failed to create file:" << fileadd.errorString();
    }



    QMessageBox::information(nullptr, "Success!", "The worker was added successfuly!");
    ui->pushButton_2->setVisible(false);
    this->close();
}


