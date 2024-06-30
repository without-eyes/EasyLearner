#include <unordered_map>
#include "../include/topicstudy.h"
#include "../forms/ui_TopicStudy.h"
#include "../include/studyquestions.h"
#include "../include/topiccontent.h"


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
    StudyQuestions::setTaskMap(TopicContent::getQuestionMap());
    auto* window = new StudyQuestions;
    window->show();
    close();
}

void TopicStudy::studyDefinitions() {

}
