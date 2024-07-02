#include <unordered_map>
#include "../../../include/topic/study/topicstudy.h"
#include "../../../forms/ui_TopicStudy.h"
#include "../../../include/topic/study/studyquestions.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"


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
    StudyQuestions::setTaskMap(Content::getQuestionMap());
    auto *window = new StudyQuestions;
    window->show();
    close();
}

void TopicStudy::studyDefinitions() {

}
