#ifndef LY_FACTORY_H
#define LY_FACTORY_H

#include <QWidget>

namespace Ui {
class ly_Factory;
}

class ly_Factory : public QWidget
{
    Q_OBJECT

public:
    explicit ly_Factory(QWidget *parent = 0);
    ~ly_Factory();

private:
    Ui::ly_Factory *ui;
};

#endif // LY_FACTORY_H
