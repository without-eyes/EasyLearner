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

    connect(ui->createButton, &QPushButton::clicked, this, &TopicCreation::createNewTopic);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicCreation::goBack);
    connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &TopicCreation::changeButtonState);
}

TopicCreation::~TopicCreation() {
    delete ui;
}

void TopicCreation::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
    changeButtonState();
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
    if (ui->nameLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(false);
        return;
    }

    QList<QString> topicList = contentManager->getTopicList();
    if (std::find(topicList.begin(), topicList.end(), ui->nameLineEdit->text()) != topicList.end()) {
        ui->createButton->setEnabled(false);
        return;
    }

    ui->createButton->setEnabled(true);
}

void TopicCreation::goBack() {
    ui->nameLineEdit->clear();
    emit requestPageChange(MAIN_MENU_PAGE);
}