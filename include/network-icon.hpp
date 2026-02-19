#ifndef __NETWORKICON_HPP__
#define __NETWORKICON_HPP__

#include <cstdint>

class QLabel;

class NetworkIconManager
{
public:
    enum class SignalLevel : uint8_t
    {
        NO_SIGNAL = 0x00,
        WEAK_SIGNAL = 0x01,
        QUITE_STRONG_SIGNAL = 0x02,
        STRONG_SIGNAL = 0x03
    };

private:
    SignalLevel level;
    QLabel *label;

    void applySignalLevel(QLabel *target, const SignalLevel &level);

public:
    NetworkIconManager();
    NetworkIconManager(QLabel *label);

    void link(QLabel *label);
    void setSignalLevel(const SignalLevel &level);
};

#endif
