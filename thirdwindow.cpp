#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <QMessageBox>
#include <QFile>
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>
thirdwindow::thirdwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thirdwindow)
{
    ui->setupUi(this);
}

thirdwindow::~thirdwindow()
{
    delete ui;
}

QString newname;
QString newsurname;
QString newage;
//these are optional and can be actually not even used in the rest of the app
QString newtelegram; //username @
QString newwhatsup; //phone number


QString userHomeee = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
QString filedelete = userHomeee + QDir::separator() + "status_me" + QDir::separator() + "userinfome";


void deleteFile(const QString &filePath) {
    QFile file(filePath);
    if (file.exists()) {
        if (file.remove()) {
            qDebug() << "File deleted successfully.";
        } else {
            QMessageBox::warning(nullptr, "Deletion Error", "Failed to delete the file.");
        }
    } else {
        QMessageBox::warning(nullptr, "File Error", "File does not exist.");
    }
}


void thirdwindow::on_pushButton_clicked()
{
    deleteFile(filedelete);


    newname = ui->lineEdit->text();
    newsurname = ui->lineEdit_2->text();
    newage = QString::number(ui->spinBox->value());
    newtelegram = ui->lineEdit_3->text();
    newwhatsup = ui->lineEdit_4->text();

    QFile fileupdate(filedelete);
    if (fileupdate.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&fileupdate);
        out << newname << "\n";
        out << newsurname << "\n";
        out << newage  << "\n";
        out << newtelegram << "\n";
        out << newwhatsup << "\n";

        fileupdate.close();

    } else {
        qDebug() << "Failed to create file:" << fileupdate.errorString();
    }

    this->close();

    secondwindow secondwindow;
    secondwindow.setModal(true);
    secondwindow.setFixedSize(400, 600);
    secondwindow.setWindowTitle("ContactME");

    QVBoxLayout layout(&secondwindow);


    secondwindow.resize(300, 200);
    secondwindow.exec();

}

