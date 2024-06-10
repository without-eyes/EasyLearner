//
// Created by without-eyes on 09.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainMenu.h" resolved

#include "../include/mainmenu.h"
#include "../forms/ui_MainMenu.h"
#include "../include/createtopic.h"


MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::pickTopic() {
    // change window
}

void MainMenu::createTopic() {
    auto* window = new CreateTopic;
    window->show();
    close();
}


