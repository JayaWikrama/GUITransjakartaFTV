#include "network-icon.hpp"

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QPointer>

void NetworkIconManager::applySignalLevel(QLabel *target, const NetworkIconManager::SignalLevel &level)
{
    QString iconPath;

    switch (level)
    {
        case NetworkIconManager::SignalLevel::NO_SIGNAL:
            iconPath = ":/asset/icons/gsm-no-signal.png";
            break;
        case NetworkIconManager::SignalLevel::WEAK_SIGNAL:
            iconPath = ":/asset/icons/gsm-weak-signal.png";
            break;
        case NetworkIconManager::SignalLevel::QUITE_STRONG_SIGNAL:
            iconPath = ":/asset/icons/gsm-quite-strong-signal.png";
            break;
        case NetworkIconManager::SignalLevel::STRONG_SIGNAL:
            iconPath = ":/asset/icons/gsm-strong-signal.png";
            break;
        default:
            iconPath = ":/asset/icons/gsm-no-signal.png";
            break;
    }

    QPixmap pixmap(iconPath);
    QPointer<QLabel> slabel = target;
    QMetaObject::invokeMethod(
        slabel,
        "setPixmap",
        Qt::QueuedConnection,
        Q_ARG(QPixmap, pixmap)
    );
}

NetworkIconManager::NetworkIconManager() : level(NetworkIconManager::SignalLevel::NO_SIGNAL),
                                           label(nullptr) {}

NetworkIconManager::NetworkIconManager(QLabel *label) : level(NetworkIconManager::SignalLevel::NO_SIGNAL),
                                                        label(label)
{
    this->applySignalLevel(this->label, this->level);
}

void NetworkIconManager::link(QLabel *label)
{
    this->label = label;
    this->applySignalLevel(this->label, this->level);
}
void NetworkIconManager::setSignalLevel(const NetworkIconManager::SignalLevel &level)
{
    if (this->level == level)
        return;
    this->level = level;
    this->applySignalLevel(this->label, this->level);
}
