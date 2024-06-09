#include <QApplication>
#include <QPushButton>

#include "../include/mainmenu.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainMenu window;
    window.show();
    return QApplication::exec();
}
