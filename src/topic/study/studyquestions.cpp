/**
    * @file: studyquestions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of StudyQuestions class.
*/

#include "topic/study/studyquestions.h"

#include "topic/study/topicstudy.h"
#include "topic/base/content.h"
#include "utils/randomizer.h"
#include "../../../forms/ui_StudyQuestions.h"

std::map<QString, QString> StudyQuestions::taskMap;

StudyQuestions::StudyQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::StudyQuestions) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Question Studying");

    taskMap = Content::getQuestionMap();

    connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::checkAnswer);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &StudyQuestions::changeButtonState);
}

StudyQuestions::~StudyQuestions() {
    delete ui;
}

void StudyQuestions::pickRandomTask() {
    if (taskMap.empty()) {
        emit requestPageChange(8);
        return;
    }
    auto task = taskMap.begin();
    std::advance(task, Randomizer::getInstance()->getInt(taskMap.size() - 1));
    question = task->first;
    answer = task->second;
    taskMap.erase(task);
}

void StudyQuestions::checkAnswer() {
    if (compareAnswers(ui->answerLineEdit->text(), answer)) {
        ui->correctnessLabel->setText("Correct!");
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + answer);
    }
    ui->answerLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::showNextTask);
}

void StudyQuestions::showNextTask() {
    if (taskMap.empty()) {
        emit requestPageChange(8);
    } else {
        emit requestPageChange(10);
    }
    close();
}

void StudyQuestions::changeButtonState() const {
    if (!ui->answerLineEdit->text().isEmpty()) {
        ui->continueButton->setEnabled(true);
    } else {
        ui->continueButton->setEnabled(false);
    }
}

void StudyQuestions::studyQuestion() {
    pickRandomTask();
    ui->questionLabel->setText(question);
    changeButtonState();
}








