/**
    * @file: topiccontent.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicContent class.
*/

#include "../../../include/topic/content/topiccontent.h"

#include "../../../forms/ui_TopicContent.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/content/topicdefinitions.h"
#include "../../../include/topic/content/topicquestions.h"

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
    auto *window = new TopicDefinitions;
    window->show();
    close();
}

void TopicContent::showQuestionsAnswers() {
    auto *window = new TopicQuestions;
    window->show();
    close();
}

void TopicContent::goBack() {
    auto *window = new ManageTopic;
    window->show();
    close();
}
