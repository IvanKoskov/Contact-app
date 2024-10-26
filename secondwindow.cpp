#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QDesktopServices>
#include <QUrl>
#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "preview.h"
#include "ui_preview.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
#include "contactadd.h"
#include "ui_contactadd.h"
#include <QPixmap>
#include <QDir>
#include <QListWidgetItem>
#include "previewadd.h"
#include "ui_previewadd.h"
#include <QStandardPaths>
#include <QFileDialog>



secondwindow::secondwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    loadNames();

    connect(ui->listWidget, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            ui->listWidget->item(i)->setBackground(Qt::white);  // Reset all
        }
        item->setBackground(Qt::red);  // Highlight selected item

        QString selectedName = item->text();  // Get the selected name
        QMessageBox::information(this, "Selected Name", selectedName);  // Show message box
    });





  QPixmap pix3(":/rec/userinqt2.png");
    if (pix3.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->userbased->setPixmap(pix3.scaled(60, 60, Qt::KeepAspectRatio));
    }

    QPixmap pix4(":/rec/greycol2.jpeg");
    if (pix4.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->label->setPixmap(pix4.scaled(300, 300, Qt::KeepAspectRatio));
    }

    QPixmap pix10(":/rec/deveqt2.png");
    if (pix10.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        ui->label_7->setPixmap(pix10.scaled(60, 60, Qt::KeepAspectRatio));
    }




    QFile file("/Users/evan/status_me/userinfome");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Open Error", "Could not open file for reading!");
        return;
    }

    QTextStream in(&file);

    // Read the first line
    QString firstLine = in.readLine(); // Read the first line
    ui->label_2->setText(firstLine);

    // Read the second line
    QString secondLine = in.readLine();
    ui->label_3->setText(secondLine);

    file.close(); // Close the file





}

secondwindow::~secondwindow()
{
    delete ui;
}


QString userdome = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
QString dirstatus = userdome + QDir::separator() + "status_me";



void secondwindow::loadNames() {
    QDir directory(dirstatus); // Specify your directory path

    if (!directory.exists()) {
        qDebug() << "Directory does not exist!";
        return; // Exit if the directory doesn't exist
    }

    QStringList files = directory.entryList(QDir::Files); // List all files
    for (const QString &fileName : files) {
        QFile file(directory.filePath(fileName)); // Create QFile object
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString name = in.readLine(); // Read the first line
            if (!name.isEmpty()) { // Ensure the name is not empty
                // Create QListWidgetItem with an icon and name
                QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/User22qt.png"), name);
                ui->listWidget->addItem(item); // Add to QListWidget
            }
            file.close(); // Close the file
        } else {
            qDebug() << "Could not open file:" << fileName; // Error handling
        }
    }
}















void secondwindow::on_pushButton_3_clicked()
{
    QUrl url("https://ko-fi.com/");
    QDesktopServices::openUrl(url);
}


void secondwindow::on_pushButton_4_clicked()
{
    this->close();
}



void secondwindow::on_pushButton_clicked()
{
this->close();
    thirdwindow updatewindow;
    updatewindow.setModal(true);
    updatewindow.setFixedSize(400, 600);
    updatewindow.setWindowTitle("Editor");
    updatewindow.resize(300, 200);
    updatewindow.exec();

}


void secondwindow::on_pushButton_5_clicked()
{
    this->close();

    preview seeprofi;
    seeprofi.setModal(true);
    seeprofi.setFixedSize(400, 600);
    seeprofi.setWindowTitle("PREVIEW");
    seeprofi.resize(300, 200);
    seeprofi.exec();



}



void secondwindow::on_pushButton_7_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(nullptr, "New contact", "Enter their name with surname:", QLineEdit::Normal, "", &ok);

    // If the user pressed OK and entered some text
    if (ok && !text.isEmpty()) {
        QMessageBox::information(nullptr, "Input Received", "You entered: " + text);
        QListWidgetItem *item = new QListWidgetItem(QIcon(":/rec/User22qt.png"), text);

        ui->listWidget->addItem(item);

        // Specify the directory where the file will be saved
        QString filePath = dirstatus + QDir::separator() + text + ".txt";  // File path

        QFile file(filePath);  // Create the file object
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << text;  // Write the user's input to the file
            file.close(); // Close the file
        } else {
            QMessageBox::warning(this, "Error", "Could not create file: " + file.errorString());
        }
    }

    QFile filepassing("/Users/evan/status_me/topass");
    if (filepassing.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&filepassing);
        out << text; // Write the line
        filepassing.close();
    } else {
        qDebug() << "Failed to create file.";
    }


    contactadd addcontact;
    addcontact.setModal(true);
    addcontact.setFixedSize(400, 600);
    addcontact.setWindowTitle("Fill additional info");
    addcontact.resize(300, 200);

    addcontact.exec();


}












//i do not know if i even need it, but let it be anyways im a noob programmer((((((

void shareContactViaEmail(const QString &tosendpath) {

    QString mailto = QString("mailto:?subject=Contact Information&body=Please find the contact information attached from the file: %1").arg(tosendpath);
    QUrl url(mailto);

    // Attempt to open the default email client that shoyld work if permissions are granted
    if (!QDesktopServices::openUrl(url)) {
        QMessageBox::warning(nullptr, "Email Error", "Could not open the email client.");
    }
}



void secondwindow::on_pushButton_6_clicked()
{
    QMessageBox::information(
        nullptr,  // Parent widget
        "Your Title",  // Title of the message box
        "In order to share, open your user/yournamehere/status_me/filename that corresponds to a contact when you will attach the card!",  // Message text
        QMessageBox::Ok  // Button(s) to show
        );
    QListWidgetItem *currentthing = ui->listWidget->currentItem();
    if (currentthing) {
        QString nameemail = currentthing->text();
        QString tosendpath = dirstatus + QDir::separator() + nameemail + ".txt";
        shareContactViaEmail(tosendpath);
    }
    else {
        QMessageBox::warning(this, "Error", "No contact selected.");
    }


}





void secondwindow::on_pushButton_9_clicked()
{
    // Get the currently selected item
    QListWidgetItem *currentItem = ui->listWidget->currentItem();

    if (currentItem) {
        // Get the text (name) from the selected item
        QString name = currentItem->text();

        // Specify the file path to be deleted
        QString filePathss = dirstatus + QDir::separator() + name + ".txt"; // Same path as before

        // Ask for confirmation
        if (QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete " + name + "?",
                                  QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            // Remove the item from the list
            delete currentItem;

            // Delete the file
            QFile file(filePathss);
            if (!file.remove()) {
                QMessageBox::warning(this, "Error", "Could not delete file: " + file.errorString());
            } else {
                QMessageBox::information(this, "Deleted", name + " has been deleted.");
            }
        }
    } else {
        QMessageBox::warning(this, "Error", "No contact selected.");
    }



}


//this function below will display the info

void secondwindow::on_pushButton_8_clicked()
{

    bool okk;
    QString textx = QInputDialog::getText(nullptr, "New contact", "Enter their name with surname:", QLineEdit::Normal, "", &okk);

    // If the user pressed OK and entered some text
    if (okk && !textx.isEmpty()) {
        QMessageBox::information(nullptr, "Input Received", "You entered: " + textx);



        QFile filepassings(userdome + "/topass");
        if (filepassings.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&filepassings);
            out << textx; // Write the line
            filepassings.close();

            previewadd previewpersona;
            previewpersona.setModal(true);
            previewpersona.setFixedSize(400, 600);
            previewpersona.setWindowTitle("Fill additional info");
            previewpersona.resize(300, 200);

            previewpersona.exec();
        } else {
            qDebug() << "Failed to create file.";
        }
    }



}

