#include <iostream>
#include <sstream>
#include <iomanip>
#include <QMetaObject>
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
             labelFleetCode(),
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
    this->labelFleetCode.link(this->mwindow->labelFleetCode());
    this->labelTerminalId.link(this->mwindow->labelTerminalId());
    this->labelTerminalName.link(this->mwindow->labelTerminalName());
    this->transactionCounter.label.link(this->mwindow->labelTransactionCounter());
    this->transactionPendingSummary.label.link(this->mwindow->labelTransactionPendingSummary());
    this->gsmNetworkLevel.link(this->mwindow->labelNetworkIcon());
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

void Gui::setWindowBackground(bool show) {
    QMainWindow* window = mwindow.get();
    if (!window)
        return;

    QPointer<QMainWindow> safeWindow = window;

    QTimer::singleShot(0, window, [safeWindow, show]() {
        if (!safeWindow)
            return;

        QWidget* central = safeWindow->centralWidget();
        if (!central)
            return;

        if (show) {
            central->setStyleSheet(
                "#main_container {"
                "background-image: url(\":/asset/images/background.png\");"
                "background-repeat: no-repeat;"
                "background-position: center;"
                "}"
            );
        }
        else {
            central->setStyleSheet("");
        }
    });
}

void Gui::setUnderMaintenance(bool show)
{
    this->message.hide();
    if (show){
        this->message.show({"DEVICE",
                            "UNDER MAINTENANCE",
                            "",
                            "",
                            ""});
        this->setWindowBackground(true);
    }
    else {
        this->setWindowBackground(false);
        this->message.hide();
    }
}
