//
// Created by without-eyes on 10.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateTopic.h" resolved

#include "../include/createtopic.h"
#include "../forms/ui_CreateTopic.h"
#include "../include/mainmenu.h"


CreateTopic::CreateTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::CreateTopic) {
    ui->setupUi(this);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &CreateTopic::createNewTopic);
}

CreateTopic::~CreateTopic() {
    delete ui;
}

void CreateTopic::createNewTopic() {
    if (!ui->nameLineEdit->text().isEmpty()) {
        MainMenu::addTopicIntoList(ui->nameLineEdit->text());
        goToMainMenu();
    }
}

void CreateTopic::goToMainMenu() {
    auto* window = new MainMenu;
    window->show();
    close();
}




