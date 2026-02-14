#include "message.hpp"

Message::Message() : messageContainer(), invContainer(), labels() {}

Message::~Message() {}

void Message::link(QWidget *m, QWidget *i, const std::array<QLabel *, 5> &l){
    this->messageContainer.link(m);
    this->invContainer.link(i);
    for (std::size_t i = 0; i < l.size(); i++){
        this->labels[i].link(l[i]);
    }
}

void Message::show(const std::array<std::string, 5> &lines){
    for (std::size_t i = 0; i < lines.size(); i++){
        this->labels[i].setText(lines[i]);
    }
    this->invContainer.hide();
    this->messageContainer.show();
}

void Message::hide(){
    this->messageContainer.hide();
    this->invContainer.show();
}
