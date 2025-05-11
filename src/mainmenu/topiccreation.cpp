/**
    * @file: topiccreation.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicCreation class.
*/

#include "../../include/mainmenu/topiccreation.h"

#include "../../forms/ui_TopicCreation.h"
#include "../../include/mainmenu/mainmenu.h"

TopicCreation::TopicCreation(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicCreation) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &TopicCreation::createNewTopic);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicCreation::goBack);
    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &TopicCreation::changeButtonState);
}

TopicCreation::~TopicCreation() {
    delete ui;
}

void TopicCreation::createNewTopic() {
    if (!ui->nameLineEdit->text().isEmpty()) {
        MainMenu::addTopicIntoList(ui->nameLineEdit->text());
        goBack();
    }
}

void TopicCreation::changeButtonState() const {
    if (!ui->nameLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void TopicCreation::goBack() {
    auto *window = new MainMenu;
    window->show();
    close();
}




