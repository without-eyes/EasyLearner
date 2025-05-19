#include <QApplication>
#include <QDebug>
#include <QDir>
#include "core/mainwindow.h"
#include "mainmenu/mainmenu.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    const auto mainWindow = new MainWindow;
    mainWindow->show();
    return a.exec();
}
