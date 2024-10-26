#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QStandardPaths>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ContactME! Your visit card!");
    setMaximumSize(400, 600);



    setMinimumSize(400, 300);
    QPixmap pix(":/rec/User22qt.png");
    ui->labelpic->setPixmap(pix.scaled(60, 60, Qt::KeepAspectRatio));
    QPixmap pix2(":/rec/clipart29127392.png");
    ui->label_social->setPixmap(pix2.scaled(60, 60, Qt::KeepAspectRatio));
    ui->label_social->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->lineEdit_4->setVisible(false);
     ui->label_9->setVisible(false);
    ui->label_10->setVisible(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if (checked) {

        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_8->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_4->setVisible(true);
        ui->checkBox->setVisible(false);
        ui->label_9->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_social->setVisible(true);

    }

}


QString name;
QString surname;
QString age;
//these are optional and can be actually not even used in the rest of the app
QString telegram; //username @
QString whatsup; //phone number


QString userHomee = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
QString filePath = userHomee + QDir::separator() + "status_me" + QDir::separator() + "userinfome";

void MainWindow::on_pushButton_clicked()

{

    name = ui->lineEdit->text();
    surname = ui->lineEdit_2->text();
    age = QString::number(ui->spinBox->value());
    telegram = ui->lineEdit_3->text();
    whatsup = ui->lineEdit_4->text();
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << name << "\n";
        out << surname << "\n";
        out <<  age << "\n";
        out << telegram << "\n";
        out << whatsup << "\n";

        file.close();
        qDebug() << "File created successfully!";
    } else {
        qDebug() << "Failed to create file:" << file.errorString();
    }






    QMessageBox::information(this, "Setup Complete", "You are all set!");

    ui->pushButton->setVisible(false);

    secondwindow secondwindow;
    secondwindow.setModal(true);
    secondwindow.setFixedSize(400, 600);
    secondwindow.setWindowTitle("ContactME");

    QVBoxLayout layout(&secondwindow);


    secondwindow.resize(300, 200);
    secondwindow.exec();


}

