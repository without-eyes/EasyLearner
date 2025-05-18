#include <QApplication>

#include "core/mainwindow.h"
#include "mainmenu/mainmenu.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/assets/icon.png"));
    const auto mainWindow = new MainWindow;
    mainWindow->show();
    return a.exec();
}
