/**
    * @file: topiccontent.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicContent class.
*/

#include "topic/content/topiccontent.h"

#include "topic/base/topicmanagement.h"
#include "topic/content/topicdefinitions.h"
#include "topic/content/topicquestions.h"
#include "../../../forms/ui_TopicContent.h"

TopicContent::TopicContent(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicContent) {
    ui->setupUi(this);

    connect(ui->definitionButton, &QPushButton::clicked, this, &TopicContent::showDefinition);
    connect(ui->qaButton, &QPushButton::clicked, this, &TopicContent::showQuestionsAnswers);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicContent::goBack);
}

TopicContent::~TopicContent() {
    delete ui;
}

void TopicContent::showDefinition() {
    emit updateDefinitionMapShowing();
    emit requestPageChange(TOPIC_DEFINITIONS_PAGE);
}

void TopicContent::showQuestionsAnswers() {
    emit updateQuestionMapShowing();
    emit requestPageChange(TOPIC_QUESTIONS_PAGE);
}

void TopicContent::goBack() {
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
