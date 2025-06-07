/**
    * @file: topicstudy.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicStudy class.
*/

#include "topic/study/topicstudy.h"

#include "../../../forms/ui_TopicStudy.h"

TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);

    connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicStudy::goBack);
}

TopicStudy::~TopicStudy() {
    delete ui;
}

void TopicStudy::setContentManager(const std::shared_ptr<ContentManager> &contentManager) {
    this->contentManager = contentManager;
}

void TopicStudy::updateStudyQuestionsButton() const {
    if (contentManager->getQuestionMap().empty()) {
        ui->questionsButton->setEnabled(false);
    } else {
        ui->questionsButton->setEnabled(true);
    }
}

void TopicStudy::updateStudyDefinitionsButton() const {
    if (contentManager->getDefinitionMap().empty()) {
        ui->definitionsButton->setEnabled(false);
    } else {
        ui->definitionsButton->setEnabled(true);
    }
}

void TopicStudy::studyQuestions() {
    emit setQuestionMap(contentManager->getQuestionMap());
    emit startQuestionsStudy();
    emit requestPageChange(STUDY_QUESTIONS_PAGE);
}

void TopicStudy::studyDefinitions() {
    emit setDefinitionMap(contentManager->getDefinitionMap());
    emit startDefinitionsStudy();
    emit requestPageChange(STUDY_DEFINITIONS_PAGE);
}

void TopicStudy::goBack() {
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
