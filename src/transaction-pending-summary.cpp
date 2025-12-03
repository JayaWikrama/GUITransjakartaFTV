#include <cstring>
#include <cstdlib>
#include "transaction-pending-summary.hpp"

#define TRANSACTION_PENDING_SUMMARY_FORMAT "K : %04i / %04i"

void TransactionPendingSummary::_setLabel(){
    static char text[32];
    memset(text, 0x00, sizeof(text));
    snprintf(text,
             sizeof(text) - 1,
             TRANSACTION_PENDING_SUMMARY_FORMAT,
             this->sentCounter,
             this->pendingCounter);
    this->label.setText(text);
}

TransactionPendingSummary::TransactionPendingSummary() : sentCounter(0), pendingCounter(0) {}

TransactionPendingSummary::~TransactionPendingSummary() {}

void TransactionPendingSummary::setSentCounter(int value) {
    this->sentCounter = value;
    this->_setLabel();
}

void TransactionPendingSummary::setPendingCounter(int value) {
    this->pendingCounter = value;
    this->_setLabel();
}

void TransactionPendingSummary::incSentCounter() {
    this->sentCounter++;
    this->pendingCounter--;
    this->_setLabel();
}

void TransactionPendingSummary::incPendingCounter() {
    this->setPendingCounter(++(this->pendingCounter));
}
