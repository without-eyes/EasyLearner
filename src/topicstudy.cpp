#include "../include/topicstudy.h"
#include "../forms/ui_TopicStudy.h"


TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);
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
