#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include <array>
#include <string>

#include "label.hpp"
#include "container.hpp"

class Message {
private:
    Container messageContainer;
    Container invContainer;
    std::array<Label, 5> labels;

public:
    Message();
    ~Message();

    void link(QWidget *m, QWidget *i, const std::array<QLabel *, 5> &l);

    void show(const std::array<std::string, 5> &lines);
    void hide();
};

#endif
