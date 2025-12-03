#ifndef __TRANSACTIONCOUNTER_HPP__
#define __TRANSACTIONCOUNTER_HPP__

#include "label.hpp"

class TransactionCounter {
private:
    int tapInRegularCounter;
    int tapInEconomicalCounter;
    int tapInFreeCounter;
    int tapOutCounter;

    void _setLabel();

public:
    TransactionCounter();
    ~TransactionCounter();

    Label label;

    void setTapInRegularCounter(int value);
    void setTapInEconomicalCounter(int value);
    void setTapInFreeCounter(int value);
    void setTapOutCounter(int value);

    void incTapInRegularCounter();
    void incTapInEconomicalCounter();
    void incTapInFreeCounter();
    void incTapOutCounter();
};

#endif
