#ifndef TAKEABREAK_H
#define TAKEABREAK_H

#include "MyWindow.h"
#include "MyTray.h"
#include <QObject>

class TAB : QObject {
    Q_OBJECT
public:
    TAB() {
        tray = new MyTray();
        QIcon* icon = new QIcon(":/qttest/Resources/copy.png");
        tray->setIcon(*icon);

        cfg_window = new MyWindow();
        connect(cfg_window, SIGNAL(userConfig(int)), tray, SLOT(setBreaktimemsec(int)));

        connect(tray, SIGNAL(userOpenConfig()), cfg_window, SLOT(open()));

        connect(cfg_window, SIGNAL(currentClose()), tray, SLOT(revive_window_open()));
        // tray->start();
    }
    void start() {
        tray->start();
    }
private:
    MyTray* tray;
    MyWindow* cfg_window;
};

#endif