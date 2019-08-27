#ifndef LY_MAINWINDOW_H
#define LY_MAINWINDOW_H

#include <QMainWindow>
#include "ly_factory.h"

namespace Ui {
class ly_MainWindow;
}

class ly_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ly_MainWindow(QWidget *parent = 0);
    ~ly_MainWindow();

private:
    ly_Factory* m_factory;
private:
    Ui::ly_MainWindow *ui;
};

#endif // LY_MAINWINDOW_H
