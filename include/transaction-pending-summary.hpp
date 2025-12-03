#ifndef __TRANSACTIONPENDINGSUMMARY_HPP__
#define __TRANSACTIONPENDINGSUMMARY_HPP__

#include "label.hpp"

class TransactionPendingSummary {
private:
    int sentCounter;
    int pendingCounter;

    void _setLabel();
public:
    Label label;

    TransactionPendingSummary();
    ~TransactionPendingSummary();

    void setSentCounter(int value);
    void setPendingCounter(int value);

    void incSentCounter();
    void incPendingCounter();
};

#endif
