/**
    * @file: topicmanagement.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicManagement class.
*/

#include "../../../include/topic/base/topicmanagement.h"

#include "../../../forms/ui_TopicManagement.h"
#include "../../../include/mainmenu/mainmenu.h"
#include "../../../include/topic/creation/definitionaddition.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/creation/questionaddition.h"
#include "../../../include/topic/study/topicstudy.h"

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
    window->show();
    close();
}

void TopicManagement::addDefinition() {
    auto *window = new DefinitionAddition;
    window->show();
    close();
}

void TopicManagement::addQuestion() {
    auto *window = new QuestionAddition;
    window->show();
    close();
}

void TopicManagement::showTopicContent() {
    auto *window = new TopicContent;
    window->show();
    close();
}

void TopicManagement::goBack() {
    auto *window = new MainMenu;
    window->show();
    close();
}


