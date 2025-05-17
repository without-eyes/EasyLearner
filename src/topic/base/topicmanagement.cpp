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
#include "topic/base/content.h"
#include "../../../forms/ui_TopicManagement.h"

TopicManagement::TopicManagement(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicManagement) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Topic Management");

    ui->label->setText(Content::getCurrentTopic());

    connect(ui->studyButton, &QPushButton::clicked, this, &TopicManagement::startStudy);
    connect(ui->addDefinitionButton, &QPushButton::clicked, this, &TopicManagement::addDefinition);
    connect(ui->addQuestionButton, &QPushButton::clicked, this, &TopicManagement::addQuestion);
    connect(ui->showContentButton, &QPushButton::clicked, this, &TopicManagement::showTopicContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicManagement::goBack);
}

TopicManagement::~TopicManagement() {
    delete ui;
}

void TopicManagement::setTopic(const QString &topic) {
    Content::setCurrentTopic(topic);
    ui->label->setText(topic);
}

void TopicManagement::startStudy() {
    emit requestPageChange(8);
}

void TopicManagement::addDefinition() {
    emit requestPageChange(6);
}

void TopicManagement::addQuestion() {
    emit requestPageChange(7);
}

void TopicManagement::showTopicContent() {
    emit requestPageChange(3);
}

void TopicManagement::goBack() {
    emit requestPageChange(0);
}


