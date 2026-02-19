#ifndef __GUI_H__
#define __GUI_H__

#include <string>
#include <memory>
#include <mutex>
#include <array>
#include <condition_variable>

#include "label.hpp"
#include "transaction-counter.hpp"
#include "transaction-pending-summary.hpp"
#include "message.hpp"
#include "network-icon.hpp"

class MainWindow;

class Gui {
private:
    bool isStop;
    bool isReady;
    std::mutex mtx;
    std::condition_variable cond;
    std::unique_ptr<MainWindow> mwindow;

public:
    Label labelTitle;
    Label labelTariff;
    Label labelBalance;
    Label labelCardNumber;
    Label labelStatus;
    Label labelVersion;
    Label labelFletCode;
    Label labelTerminalId;

    TransactionCounter transactionCounter;
    TransactionPendingSummary transactionPendingSummary;

    NetworkIconManager gsmNetworkLevel;

    Message message;

    Gui();
    ~Gui();

    void waitObjectReady();

    int begin(int argc, char **argv);

    bool isStoped();
};

#endif
