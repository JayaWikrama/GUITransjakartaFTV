#include <iostream>
#include <sstream>
#include <iomanip>
#include "gui.hpp"
#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QPointer>

Gui::Gui() : isStop(false),
             isReady(false),
             mtx(),
             cond(),
             mwindow(),
             labelTitle(),
             labelTariff(),
             labelBalance(),
             labelCardNumber(),
             labelStatus(),
             labelVersion(),
             labelFletCode(),
             labelTerminalId(),
             transactionCounter(),
             transactionPendingSummary(),
             message()
{
}

Gui::~Gui(){
}


void Gui::waitObjectReady(){
    std::unique_lock<std::mutex> guard(this->mtx);

    if (this->isReady)
        return;

    this->cond.wait(guard, [this](){
        return this->isReady;
    });
}

int Gui::begin(int argc, char **argv){
    QApplication app(argc, argv);

    this->mwindow.reset(new MainWindow());

    this->labelTitle.link(this->mwindow->labelTitle());
    this->labelTariff.link(this->mwindow->labelAmount());
    this->labelBalance.link(this->mwindow->labelBalance());
    this->labelCardNumber.link(this->mwindow->labelCardNumber());
    this->labelStatus.link(this->mwindow->labelStatus());
    this->labelVersion.link(this->mwindow->labelVersion());
    this->labelFletCode.link(this->mwindow->labelFletCode());
    this->labelTerminalId.link(this->mwindow->labelTerminalId());
    this->transactionCounter.label.link(this->mwindow->labelTransactionCounter());
    this->transactionPendingSummary.label.link(this->mwindow->labelTransactionPendingSummary());

    this->message.link(this->mwindow->containerMessage(),
                       this->mwindow->containerMainInfo(),
                       {
                           this->mwindow->labelMessage0(),
                           this->mwindow->labelMessage1(),
                           this->mwindow->labelMessage2(),
                           this->mwindow->labelMessage3(),
                           this->mwindow->labelMessage4()
                       });

    this->labelStatus.hide();
    this->labelCardNumber.hide();
    this->labelBalance.hide();
    this->message.hide();

    this->mwindow->show();

    {
        std::lock_guard<std::mutex> guard(this->mtx);
        this->isReady = true;
    }
    this->cond.notify_one();

    int ret = 0;

    try {
        app.exec();
    }
    catch (const std::exception &e){
        std::cout << __func__ << ": " << e.what() << std::endl;
    }

    std::lock_guard<std::mutex> guard(this->mtx);
    this->isStop = true;

    return ret;
}

bool Gui::isStoped(){
    std::lock_guard<std::mutex> guard(this->mtx);
    return this->isStop;
}
