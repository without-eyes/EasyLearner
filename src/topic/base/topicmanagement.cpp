/**
    * @file: topicmanagement.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicManagement class.
*/

#include "topic/base/topicmanagement.h"

#include "mainmenu/mainmenu.h"
#include "topic/creation/definitionaddition.h"
#include "topic/content/topiccontent.h"
#include "topic/creation/questionaddition.h"
#include "topic/study/topicstudy.h"
#include "../../../forms/ui_TopicManagement.h"

TopicManagement::TopicManagement(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicManagement) {
    ui->setupUi(this);

    connect(ui->studyButton, &QPushButton::clicked, this, &TopicManagement::startStudy);
    connect(ui->addDefinitionButton, &QPushButton::clicked, this, &TopicManagement::addDefinition);
    connect(ui->addQuestionButton, &QPushButton::clicked, this, &TopicManagement::addQuestion);
    connect(ui->showContentButton, &QPushButton::clicked, this, &TopicManagement::showTopicContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicManagement::goBack);
}

TopicManagement::~TopicManagement() {
    delete ui;
}

void TopicManagement::setTopicName(const QString &topicName) const {
    ui->label->setText(topicName);
}

void TopicManagement::startStudy() {
    auto *window = new TopicStudy;
    window->move(this->pos());
    window->show();
    close();
}

void TopicManagement::addDefinition() {
    auto *window = new DefinitionAddition;
    window->move(this->pos());
    window->show();
    close();
}

void TopicManagement::addQuestion() {
    auto *window = new QuestionAddition;
    window->move(this->pos());
    window->show();
    close();
}

void TopicManagement::showTopicContent() {
    auto *window = new TopicContent;
    window->move(this->pos());
    window->show();
    close();
}

void TopicManagement::goBack() {
    auto *window = new MainMenu;
    window->move(this->pos());
    window->show();
    close();
}


