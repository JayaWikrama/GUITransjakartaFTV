#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLabel *labelTitle() const;
    QLabel *labelStatus() const;
    QLabel *labelCardNumber() const;
    QLabel *labelBalance() const;
    QLabel *labelAmount() const;
    QLabel *labelTransactionCounter() const;
    QLabel *labelTransactionPendingSummary() const;
    QLabel *labelVersion() const;
    QLabel *labelFletCode() const;
    QLabel *labelTerminalId() const;

private:
    Ui::MainWindow *ui;
    QTimer *timer;

private slots:
    void updateTime();
};

#endif // MAINWINDOW_H
