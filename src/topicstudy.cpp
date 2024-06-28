#include "../include/topicstudy.h"
#include "../forms/ui_TopicStudy.h"


TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);

    QObject::connect(ui->qndButton, &QPushButton::clicked, this, &TopicStudy::studyQuestionsAndDefinitions);
    QObject::connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    QObject::connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
}

TopicStudy::~TopicStudy() {
    delete ui;
}

void TopicStudy::studyQuestionsAndDefinitions() {

}

void TopicStudy::studyQuestions() {

}

void TopicStudy::studyDefinitions() {

}
