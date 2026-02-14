#ifndef __VLAYOUT_HPP__
#define __VLAYOUT_HPP__

class QWidget;

class Container {
private:
    QWidget *container;

public:
    Container();
    Container(QWidget *layout);
    ~Container();

    void link(QWidget *layout);

    void show() const;
    void hide() const;
};

#endif
