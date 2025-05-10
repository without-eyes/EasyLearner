/**
    * @file: topicstudy.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicStudy class.
*/

#include "../../../include/topic/study/topicstudy.h"

#include "../../../forms/ui_TopicStudy.h"
#include "../../../include/topic/study/studyquestions.h"
#include "../../../include/topic/base/content.h"
#include "../../../include/topic/base/topicmanagement.h"

TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);

    connect(ui->qndButton, &QPushButton::clicked, this, &TopicStudy::studyQuestionsAndDefinitions);
    connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicStudy::goBack);
}

TopicStudy::~TopicStudy() {
    delete ui;
}

void TopicStudy::studyQuestionsAndDefinitions() {

}

void TopicStudy::studyQuestions() {
    StudyQuestions::setTaskMap(Content::getQuestionMap());
    auto *window = new StudyQuestions;
    window->show();
    close();
}

void TopicStudy::studyDefinitions() {

}

void TopicStudy::goBack() {
    auto *window = new TopicManagement();
    window->show();
    close();
}
