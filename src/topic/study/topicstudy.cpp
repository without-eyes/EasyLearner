/**
    * @file: topicstudy.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicStudy class.
*/

#include "topic/study/topicstudy.h"

#include "topic/study/studyquestions.h"
#include "topic/study/studydefinitions.h"
#include "topic/base/content.h"
#include "topic/base/topicmanagement.h"
#include "../../../forms/ui_TopicStudy.h"

TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Studying");

    updateStudyQuestionsButton();
    updateStudyDefinitionsButton();

    connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicStudy::goBack);
}

TopicStudy::~TopicStudy() {
    delete ui;
}

void TopicStudy::updateStudyQuestionsButton() {
    if (Content::getQuestionMap().empty()) {
        ui->questionsButton->setEnabled(false);
    } else {
        ui->questionsButton->setEnabled(true);
    }
}

void TopicStudy::updateStudyDefinitionsButton() {
    if (Content::getDefinitionMap().empty()) {
        ui->definitionsButton->setEnabled(false);
    } else {
        ui->definitionsButton->setEnabled(true);
    }
}

void TopicStudy::studyQuestions() {
    emit startQuestionsStudy();
    emit requestPageChange(STUDY_QUESTIONS_PAGE);
}

void TopicStudy::studyDefinitions() {
    emit startDefinitionsStudy();
    emit requestPageChange(STUDY_DEFINITIONS_PAGE);
}

void TopicStudy::goBack() {
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
