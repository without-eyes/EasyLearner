#include <iostream>

#include "../../../include/topic/study/studyquestions.h"
#include "../../../forms/ui_StudyQuestions.h"
#include "../../../include/topic/study/topicstudy.h"

std::map<QString, QString> StudyQuestions::taskMap;

StudyQuestions::StudyQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::StudyQuestions) {
    ui->setupUi(this);

    pickRandomTask();
    ui->questionLabel->setText(question);
    changeButtonState();

    QObject::connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::checkAnswer);
    QObject::connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &StudyQuestions::changeButtonState);
}

StudyQuestions::~StudyQuestions() {
    delete ui;
}

void StudyQuestions::setTaskMap(std::map<QString, QString> questionMap) {
    taskMap = questionMap;
}

void StudyQuestions::pickRandomTask() {
    if (taskMap.empty()) {
        auto *window = new TopicStudy;
        window->show();
        close();
        return;
    }
    auto task = taskMap.begin();
    std::advance(task, rand() % taskMap.size());
    question = task->first;
    answer = task->second;
    taskMap.erase(task);
}

void StudyQuestions::checkAnswer() {
    if (ui->answerLineEdit->text() == answer) {
        ui->correctnessLabel->setText("Correct!");
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + answer);
    }
    ui->answerLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    QObject::connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::showNextTask);
}

void StudyQuestions::showNextTask() {
    if (taskMap.empty()) {
        auto *window = new TopicStudy;
        window->show();
    } else {
        auto *window = new StudyQuestions;
        window->show();
    }
    close();
}

void StudyQuestions::changeButtonState() {
    if (!ui->answerLineEdit->text().isEmpty()) {
        ui->continueButton->setEnabled(true);
    } else {
        ui->continueButton->setEnabled(false);
    }
}








