#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    timer->start();

    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    QDate currentDate = QDate::currentDate();
    QTime currentTime = QTime::currentTime();

    QString dateText = currentDate.toString("yyyy-MM-dd");
    QString timeText = currentTime.toString("HH:mm:ss");

    ui->label_date->setText(dateText);
    ui->label_time->setText(timeText);
}

QLabel *MainWindow::labelTitle() const {
    return ui->label_title;
}

QLabel *MainWindow::labelStatus() const {
    return ui->label_status;
}

QLabel *MainWindow::labelCardNumber() const {
    return ui->label_card_number;
}

QLabel *MainWindow::labelBalance() const {
    return ui->label_balance;
}

QLabel *MainWindow::labelAmount() const {
    return ui->label_fare;
}

QLabel *MainWindow::labelTransactionCounter() const {
    return ui->label_tsc_counter;
}

QLabel *MainWindow::labelTransactionPendingSummary() const {
    return ui->label_transaction_pending_summary;
}

QLabel *MainWindow::labelVersion() const {
    return ui->label_app_version;
}

QLabel *MainWindow::labelFletCode() const {
    return ui->label_fleet_code;
}

QLabel *MainWindow::labelTerminalId() const {
    return ui->label_terminal_id;
}
