#include <cstring>
#include <cstdlib>
#include "transaction-counter.hpp"

#define TRANSACTION_COUNTER_FORMAT "T : %04i + %04i + %04i / %04i"

void TransactionCounter::_setLabel(){
    static char text[32];
    memset(text, 0x00, sizeof(text));
    snprintf(text,
             sizeof(text) - 1,
             TRANSACTION_COUNTER_FORMAT,
             this->tapInRegularCounter,
             this->tapInEconomicalCounter,
             this->tapInFreeCounter,
             this->tapOutCounter);
    this->label.setText(text);
}

TransactionCounter::TransactionCounter() : tapInRegularCounter(0),
                                           tapInEconomicalCounter(0),
                                           tapInFreeCounter(0),
                                           tapOutCounter(0) {}

TransactionCounter::~TransactionCounter() {}

void TransactionCounter::setTapInRegularCounter(int value){
    this->tapInRegularCounter = value;
    this->_setLabel();
}

void TransactionCounter::setTapInEconomicalCounter(int value){
    this->tapInEconomicalCounter = value;
    this->_setLabel();
}

void TransactionCounter::setTapInFreeCounter(int value){
    this->tapInFreeCounter = value;
    this->_setLabel();
}

void TransactionCounter::setTapOutCounter(int value){
    this->tapOutCounter = value;
    this->_setLabel();
}

void TransactionCounter::incTapInRegularCounter(){
    this->setTapInRegularCounter(++(this->tapInRegularCounter));
}

void TransactionCounter::incTapInEconomicalCounter(){
    this->setTapInRegularCounter(++(this->tapInEconomicalCounter));
}

void TransactionCounter::incTapInFreeCounter(){
    this->setTapInRegularCounter(++(this->tapInFreeCounter));
}

void TransactionCounter::incTapOutCounter(){
    this->setTapInRegularCounter(++(this->tapOutCounter));
}
