#include "mainwindow.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QCoreApplication>
#include <QStandardPaths>
#include <QFileDialog>

//that is the main logic brunch DONT TOUCH IT!
// Declare variables outside the function
QString userHome = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
QString pathtosave = userHome + QDir::separator() + "directoryqt";
QString fileName = pathtosave + QDir::separator() + "saveddir";
QString filePathCheck = userHome + QDir::separator() + "status_me" + QDir::separator() + "userinfome";
void createDirectoryIfNotExists(const QString& dirPath) {
    QDir dir;

    // Check if the directory already exists
    if (!dir.exists(dirPath)) {
        // Try to create the directory
        if (!dir.mkpath(dirPath)) {
            qDebug() << "Failed to create the directory here!";
        } else {
            qDebug() << "Directory created successfully!";
        }
    } else {
        qDebug() << "Directory already exists!";
    }
}

int additionalCheck() {
    // Create a directory
QDir dirr(pathtosave);
    createDirectoryIfNotExists(pathtosave);



    // Create and open the file
    QFile filefol(fileName);
    if (filefol.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&filefol);
        out << filePathCheck; // Write a line to the file
        filefol.close(); // Close the file
        qDebug() << "File created and text written successfully!";
    } else {
        qDebug() << "Failed to create the file!";
    }

    return 0;
}









int main(int argc, char *argv[]) {





    QApplication a(argc, argv); // Initialize QApplication first
    a.setWindowIcon(QIcon(":/rec/minionicon.icns"));
    QString dirPath = userHome + "status_me";
    createDirectoryIfNotExists(dirPath);

    QFile filecheck(filePathCheck);

    if (filecheck.exists()) {
        // Create a dialog to show when the file exists
        secondwindow secondwindow;
        secondwindow.setModal(true);
        secondwindow.setFixedSize(400, 600);
        secondwindow.setWindowTitle("ContactME");

        QVBoxLayout layout(&secondwindow);


        secondwindow.resize(300, 200);
        secondwindow.exec();
    } else {
        // Show the main window when the file does not exist
        additionalCheck();
        MainWindow w;
        w.show();


        return a.exec();
    }


    return 0; // This line is generally not reached btw lol
}


