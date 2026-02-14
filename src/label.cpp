#include "label.hpp"

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QPointer>

Label::Label() : label(nullptr) {}

Label::Label(QLabel *label) : label(label){}

Label::~Label(){}

void Label::link(QLabel *label){
    this->label = label;
}

void Label::hide() const {
    QPointer<QLabel> slabel = label;
    QMetaObject::invokeMethod(
                slabel,
                "hide",
                Qt::QueuedConnection
            );
}

void Label::show() const {
    QPointer<QLabel> slabel = this->label;
    QMetaObject::invokeMethod(
                slabel,
                "show",
                Qt::QueuedConnection
            );
}

void Label::setText(const std::string &text, bool trigShow) const {
    QString qtext = QString::fromStdString(text);
    this->setText(qtext, trigShow);
}

void Label::setText(const QString &text, bool trigShow) const {
    QPointer<QLabel> slabel = this->label;
    QMetaObject::invokeMethod(
                slabel,
                "setText",
                Qt::QueuedConnection,
                Q_ARG(QString, text)
            );
    if (trigShow)
        this->show();
}

void Label::setRupiah(unsigned int value, const std::string &prefix, bool trigShow) const {
    QPointer<QLabel> slabel = label;
    QLocale locale(QLocale::Indonesian, QLocale::Indonesia);
    QString qtext;
    if (prefix.empty())
        qtext = "Rp" + locale.toString(value);
    else
        qtext = QString(prefix.c_str()) + " Rp" + locale.toString(value);
    return this->setText(qtext, trigShow);
}

void Label::setPAN(unsigned long long value, const std::string &prefix, bool trigShow) const {
    QPointer<QLabel> slabel = label;
    QString padded = QString("%1").arg(value, 16, 10, QChar('0'));
    QString formated;
    formated.reserve(19);
    for (int i = 0; i < padded.size(); ++i) {
        if (i > 0 && i % 4 == 0) {
            formated.append(' ');
        }
        formated.append(padded[i]);
    }
    QString qtext;
    if (prefix.empty())
        qtext = formated;
    else
        qtext = QString(prefix.c_str()) + " " + formated;
    return this->setText(qtext, trigShow);
}
