/**
    * @file: createtopic.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of CreateTopic class.
*/

#include "../../include/mainmenu/createtopic.h"
#include "../../forms/ui_CreateTopic.h"
#include "../../include/mainmenu/mainmenu.h"

CreateTopic::CreateTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::CreateTopic) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &CreateTopic::createNewTopic);
    connect(ui->goBackButton, &QPushButton::clicked, this, &CreateTopic::goBack);
    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &CreateTopic::changeButtonState);
}

CreateTopic::~CreateTopic() {
    delete ui;
}

void CreateTopic::createNewTopic() {
    if (!ui->nameLineEdit->text().isEmpty()) {
        MainMenu::addTopicIntoList(ui->nameLineEdit->text());
        goBack();
    }
}

void CreateTopic::changeButtonState() const {
    if (!ui->nameLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void CreateTopic::goBack() {
    auto *window = new MainMenu;
    window->show();
    close();
}




