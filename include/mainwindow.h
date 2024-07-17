#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void scanDevices();
    void openDevice();
    void unloadCartridge();
    void closeDevice();

private:
    Ui::MainWindow *ui;

    QString executeCommandSync(const QString &command);
    void executeCommand(const QString &command); // Declaration of executeCommand
};

#endif // MAINWINDOW_H

