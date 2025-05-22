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

    connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::checkAnswer);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &StudyQuestions::changeButtonState);
}

StudyQuestions::~StudyQuestions() {
    delete ui;
}

void StudyQuestions::pickRandomTask() {
    if (taskMap.empty()) {
        emit requestPageChange(TOPIC_STUDY_PAGE);
        soundPlayer.playFinishedStudySound();
        return;
    }
    auto task = taskMap.begin();
    std::advance(task, Randomizer::getInstance()->getInt(static_cast<int>(taskMap.size()) - 1));
    question = task->first;
    answer = task->second;
    taskMap.erase(task);
    ui->questionLabel->setText(question);
}

void StudyQuestions::checkAnswer() {
    if (compareAnswers(ui->answerLineEdit->text(), answer)) {
        ui->correctnessLabel->setText("Correct!");
        soundPlayer.playCorrectAnswerSound();
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + answer);
        soundPlayer.playBadAnswerSound();
    }
    ui->answerLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    disconnect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::checkAnswer);
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::showNextTask);
}

void StudyQuestions::showNextTask() {
    disconnect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::showNextTask);
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyQuestions::checkAnswer);
    if (taskMap.empty()) {
        emit requestPageChange(TOPIC_STUDY_PAGE);
        soundPlayer.playFinishedStudySound();
    } else {
        studyQuestion();
    }
}

void StudyQuestions::changeButtonState() const {
    if (!ui->answerLineEdit->text().isEmpty()) {
        ui->continueButton->setEnabled(true);
    } else {
        ui->continueButton->setEnabled(false);
    }
}

void StudyQuestions::studyQuestion() {
    if (taskMap.empty()) {
        taskMap = Content::getQuestionMap();
        if (taskMap.empty()) {
            emit requestPageChange(TOPIC_STUDY_PAGE);
            return;
        }
        questionMapSizeBeforeStudying = static_cast<int>(taskMap.size());
    }

    if (questionMapSizeBeforeStudying == 0) {
        questionMapSizeBeforeStudying = taskMap.size();
    }

    pickRandomTask();

    const int remained = static_cast<int>(taskMap.size());
    const int studied = questionMapSizeBeforeStudying - remained;
    const int percent = static_cast<int>((studied * 100.0) / questionMapSizeBeforeStudying);
    ui->progressBar->setValue(percent);

    ui->questionLabel->setText(question);
    ui->correctnessLabel->clear();
    ui->answerLineEdit->setEnabled(true);
    ui->answerLineEdit->clear();
    changeButtonState();
}








