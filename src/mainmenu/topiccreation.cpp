/**
    * @file: topiccreation.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicCreation class.
*/

#include "mainmenu/topiccreation.h"

#include "mainmenu/mainmenu.h"
#include "../../forms/ui_TopicCreation.h"
#include "utils/database.h"

TopicCreation::TopicCreation(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicCreation) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Topic Creation");

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
        Database database;
        const QString topic = ui->nameLineEdit->text();
        database.addTopic(topic);
        emit topicCreated(topic);
        ui->nameLineEdit->clear();
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
    emit requestPageChange(MAIN_MENU_PAGE);
}