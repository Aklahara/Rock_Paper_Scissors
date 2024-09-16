#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon(":/assets/logo.png");
    w.setWindowTitle("Rock Paper Scissors");
    a.setWindowIcon(icon);
    #ifdef Q_OS_ANDROID
        w.showFullScreen();
    #else
        w.show();
    #endif
    return a.exec();
}
