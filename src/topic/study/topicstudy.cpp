#include <unordered_map>
#include "../../../include/topic/study/topicstudy.h"
#include "../../../forms/ui_TopicStudy.h"
#include "../../../include/topic/study/studyquestions.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"
#include "../../../include/topic/base/managetopic.h"


TopicStudy::TopicStudy(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicStudy) {
    ui->setupUi(this);

    QObject::connect(ui->qndButton, &QPushButton::clicked, this, &TopicStudy::studyQuestionsAndDefinitions);
    QObject::connect(ui->questionsButton, &QPushButton::clicked, this, &TopicStudy::studyQuestions);
    QObject::connect(ui->definitionsButton, &QPushButton::clicked, this, &TopicStudy::studyDefinitions);
    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &TopicStudy::goBack);
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
    auto *window = new ManageTopic();
    window->show();
    close();
}
