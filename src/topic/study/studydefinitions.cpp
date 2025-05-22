/**
    * @file: studydefinitions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of StudyDefinitions class.
*/

#include "topic/study/studydefinitions.h"

#include "topic/study/topicstudy.h"
#include "topic/base/content.h"
#include "utils/randomizer.h"
#include "../../../forms/ui_StudyDefinitions.h"

std::map<QString, QString> StudyDefinitions::taskMap;

StudyDefinitions::StudyDefinitions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudyDefinitions) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Definition Studying");

    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::checkAnswer);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &StudyDefinitions::changeButtonState);
}

StudyDefinitions::~StudyDefinitions() {
    delete ui;
}

void StudyDefinitions::checkAnswer() {
    if (compareAnswers(ui->definitionLineEdit->text(), definition)) {
        ui->correctnessLabel->setText("Correct!");
        soundPlayer.playCorrectAnswerSound();
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + definition);
        soundPlayer.playBadAnswerSound();
    }
    ui->definitionLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    disconnect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::checkAnswer);
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::showNextTask);
}

void StudyDefinitions::showNextTask() {
    disconnect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::showNextTask);
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::checkAnswer);
    if (taskMap.empty()) {
        emit requestPageChange(TOPIC_STUDY_PAGE);
        soundPlayer.playFinishedStudySound();
    } else {
        studyDefinition();
    }
}

void StudyDefinitions::changeButtonState() const {
    if (!ui->definitionLineEdit->text().isEmpty()) {
        ui->continueButton->setEnabled(true);
    } else {
        ui->continueButton->setEnabled(false);
    }
}

void StudyDefinitions::pickRandomTask() {
    if (taskMap.empty()) {
        emit requestPageChange(TOPIC_STUDY_PAGE);
        soundPlayer.playFinishedStudySound();
        return;
    }
    auto termAndDefinition = taskMap.begin();
    std::advance(termAndDefinition, Randomizer::getInstance()->getInt(static_cast<int>(taskMap.size()) - 1));
    term = termAndDefinition->first;
    definition = termAndDefinition->second;
    taskMap.erase(termAndDefinition);
}

void StudyDefinitions::studyDefinition() {
    if (taskMap.empty()) {
        taskMap = Content::getDefinitionMap();
        if (taskMap.empty()) {
            emit requestPageChange(TOPIC_STUDY_PAGE);
            return;
        }
        definitionMapSizeBeforeStudying = static_cast<int>(taskMap.size());
    }

    if (definitionMapSizeBeforeStudying == 0) {
        definitionMapSizeBeforeStudying = taskMap.size();
    }

    pickRandomTask();

    const int remained = static_cast<int>(taskMap.size());
    const int studied = definitionMapSizeBeforeStudying - remained;
    const int percent = static_cast<int>((studied * 100.0) / definitionMapSizeBeforeStudying);
    ui->progressBar->setValue(percent);

    ui->termLabel->setText(term);
    ui->correctnessLabel->clear();
    ui->definitionLineEdit->setEnabled(true);
    ui->definitionLineEdit->clear();
    changeButtonState();
}