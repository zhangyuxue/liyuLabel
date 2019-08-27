#ifndef LY_MAINWINDOW_H
#define LY_MAINWINDOW_H

#include <QMainWindow>
#include "ly_factory.h"
#include "pictureModule/ly_picannotation.h"

namespace Ui {
class ly_MainWindow;
}

class ly_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ly_MainWindow(QWidget *parent = 0);
    ~ly_MainWindow();

public slots:
    void facotryPic();

private:
    ly_Factory* m_factory;
    ly_PicAnnotation* m_picAn=nullptr;
private:
    Ui::ly_MainWindow *ui;
};

#endif // LY_MAINWINDOW_H
