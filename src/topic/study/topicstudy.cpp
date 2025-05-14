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

    connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicStudy::goBack);
}

TopicStudy::~TopicStudy() {
    delete ui;
}

void TopicStudy::studyQuestions() {
    auto *window = new StudyQuestions;
    window->move(this->pos());
    window->show();
    close();
}

void TopicStudy::studyDefinitions() {
    auto *window = new StudyDefinitions;
    window->move(this->pos());
    window->show();
    close();
}

void TopicStudy::goBack() {
    auto *window = new TopicManagement();
    window->move(this->pos());
    window->show();
    close();
}
