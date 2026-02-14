#include "container.hpp"

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QPointer>

Container::Container() : container(nullptr) {}

Container::Container(QWidget *container) : container(container){}

Container::~Container(){}

void Container::link(QWidget *container){
    this->container = container;
}

void Container::hide() const {
    QPointer<QWidget> swidget = this->container;
    QMetaObject::invokeMethod(
                swidget,
                "hide",
                Qt::QueuedConnection
            );
}

void Container::show() const {
    QPointer<QWidget> swidget = this->container;
    QMetaObject::invokeMethod(
                swidget,
                "show",
                Qt::QueuedConnection
            );
}
