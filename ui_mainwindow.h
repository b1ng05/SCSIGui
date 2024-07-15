/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *scanButton;
    QPushButton *openButton;
    QPushButton *unloadButton;
    QPushButton *closeButton;
    QLabel *messageLabel;
    QLineEdit *deviceLineEdit;
    QTextEdit *outputTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scanButton = new QPushButton(centralwidget);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));
        scanButton->setGeometry(QRect(20, 20, 100, 30));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(20, 60, 100, 30));
        unloadButton = new QPushButton(centralwidget);
        unloadButton->setObjectName(QString::fromUtf8("unloadButton"));
        unloadButton->setGeometry(QRect(20, 100, 100, 30));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(20, 140, 100, 30));
        messageLabel = new QLabel(centralwidget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(140, 20, 200, 30));
        deviceLineEdit = new QLineEdit(centralwidget);
        deviceLineEdit->setObjectName(QString::fromUtf8("deviceLineEdit"));
        deviceLineEdit->setGeometry(QRect(140, 60, 200, 30));
        outputTextEdit = new QTextEdit(centralwidget);
        outputTextEdit->setObjectName(QString::fromUtf8("outputTextEdit"));
        outputTextEdit->setGeometry(QRect(140, 100, 200, 150));
        outputTextEdit->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SCSI GUI", nullptr));
        scanButton->setText(QCoreApplication::translate("MainWindow", "Scan Devices", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open Device", nullptr));
        unloadButton->setText(QCoreApplication::translate("MainWindow", "Unload Cartridge", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "Close Device", nullptr));
        messageLabel->setText(QString());
        deviceLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter SCSI Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
