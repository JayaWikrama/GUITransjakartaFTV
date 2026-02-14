#ifndef __LABEL_H__
#define __LABEL_H__

#include <string>

class QLabel;
class QString;

class Label {
private:
    QLabel *label;

    void applyText(QLabel *target, const std::string &text, bool trigShow);
public:
    Label();
    Label(QLabel *label);
    ~Label();

    void link(QLabel *label);

    void show() const;
    void hide() const;
    void setText(const std::string &text, bool trigShow = false) const;
    void setText(const QString &text, bool trigShow = false) const;
    void setRupiah(unsigned int value, const std::string &prefix = "", bool trigShow = false) const;
    void setPAN(unsigned long long value, const std::string &prefix = "", bool trigShow = false) const;
};

#endif
