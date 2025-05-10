#include <QApplication>

#include "../../include/mainmenu/mainmenu.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    QApplication a(argc, argv);
    MainMenu window;
    window.show();
    return QApplication::exec();
}
