/**
    * @file: topicmanagement.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicManagement class.
*/

#include "topic/base/topicmanagement.h"

#include "mainmenu/mainmenu.h"
#include "topic/creation/questionaddition.h"
#include "topic/base/contentmanager.h"
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

void TopicManagement::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void TopicManagement::loadTopicContent() {
    contentManager->loadContentFromDatabase();
    emit setContentManagerSignal(contentManager);
    emit updateDefinitionMapShowing();
    emit updateQuestionMapShowing();
}

void TopicManagement::setTopic(const QString &topic) {
    contentManager->setCurrentTopic(topic);
    ui->label->setText(topic);
}

void TopicManagement::startStudy() {
    emit updateStudyDefinitionsButton();
    emit updateStudyQuestionsButton();
    emit requestPageChange(TOPIC_STUDY_PAGE);
}

void TopicManagement::addDefinition() {
    emit requestPageChange(DEFINITION_ADDITION_PAGE);
}

void TopicManagement::addQuestion() {
    emit requestPageChange(QUESTION_ADDITION_PAGE);
}

void TopicManagement::showTopicContent() {
    emit requestPageChange(TOPIC_CONTENT_PAGE);
}

void TopicManagement::goBack() {
    emit requestPageChange(MAIN_MENU_PAGE);
}


