#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QMessageBox>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->scanButton, &QPushButton::clicked, this, &MainWindow::scanDevices);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openDevice);
    connect(ui->unloadButton, &QPushButton::clicked, this, &MainWindow::unloadCartridge);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeDevice);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scanDevices()
{
    executeCommand("sudo lsscsi -g");
}

void MainWindow::openDevice()
{
    QString device = ui->deviceLineEdit->text();
    if (device.isEmpty()) {
        ui->messageLabel->setText("Please enter a device name");
        return;
    }
    executeCommand("sudo sg_start --start --immed " + device);
    ui->messageLabel->setText("Device opened: " + device);
}

void MainWindow::unloadCartridge()
{
    QString device = ui->deviceLineEdit->text();
    if (device.isEmpty()) {
        ui->messageLabel->setText("Please enter a device name");
        return;
    }

    // Check if the tape drive is empty
    QString statusOutput = executeCommandSync("sudo sg_inq " + device);
    if (statusOutput.contains("Not ready to ready change")) {
        ui->messageLabel->setText("Device is empty or not ready");
        return;
    }

    // Unload cartridge
    executeCommand("sudo sg_start --stop " + device);
    ui->messageLabel->setText("Cartridge unloaded from device: " + device);
}

void MainWindow::closeDevice()
{
    QString device = ui->deviceLineEdit->text();
    if (device.isEmpty()) {
        ui->messageLabel->setText("Please enter a device name");
        return;
    }
    executeCommand("sudo sg_start --stop " + device);
    ui->messageLabel->setText("Device closed: " + device);
}


QString MainWindow::executeCommandSync(const QString &command)
{
    QProcess process;
    QStringList arguments = QProcess::splitCommand(command);
    QString program = arguments.takeFirst();  // Extract the program (first element) from arguments
    process.start(program, arguments);
    process.waitForFinished();
    QString output(process.readAllStandardOutput());
    QString error(process.readAllStandardError());
    if (!error.isEmpty()) {
        ui->outputTextEdit->append("\nError:\n" + error);
    }
    return output;
}


void MainWindow::executeCommand(const QString &command)
{
    ui->messageLabel->setText("Executing: " + command);
    QProcess process;
    QStringList arguments = command.split(" ");
    QString program = arguments.takeFirst();  // Extract the program (first element) from arguments
    process.start(program, arguments);
    process.waitForFinished();
    QString output(process.readAllStandardOutput());
    QString error(process.readAllStandardError());
    ui->outputTextEdit->setText(output);

    if (process.exitCode() != 0) {
        QString errorMessage = "Command failed with exit code: " + QString::number(process.exitCode());
        if (!error.isEmpty()) {
            errorMessage += "\nError output:\n" + error;
        }
        ui->messageLabel->setText(errorMessage);
    } else {
        ui->messageLabel->setText("Command executed successfully");
    }
}

