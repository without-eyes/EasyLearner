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

    if (taskMap.empty()) {
        taskMap = Content::getDefinitionMap();
    }

    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::checkAnswer);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &StudyDefinitions::changeButtonState);
}

StudyDefinitions::~StudyDefinitions() {
    delete ui;
}

void StudyDefinitions::checkAnswer() {
    if (compareAnswers(ui->definitionLineEdit->text(), definition)) {
        ui->correctnessLabel->setText("Correct!");
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + definition);
    }
    ui->definitionLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::showNextTask);
}

void StudyDefinitions::showNextTask() {
    if (taskMap.empty()) {
        emit requestPageChange(8);
    } else {
        emit requestPageChange(9);
    }
    close();
}

void StudyDefinitions::changeButtonState() const {
    if (!ui->definitionLineEdit->text().isEmpty()) {
        ui->continueButton->setEnabled(true);
    } else {
        ui->continueButton->setEnabled(false);
    }
}

void StudyDefinitions::studyDefinition() {
    pickRandomTask();
    ui->termLabel->setText(term);
    changeButtonState();
}

void StudyDefinitions::pickRandomTask() {
    if (taskMap.empty()) {
        emit requestPageChange(8);
        return;
    }
    auto termAndDefinition = taskMap.begin();
    std::advance(termAndDefinition, Randomizer::getInstance()->getInt(taskMap.size() - 1));
    term = termAndDefinition->first;
    definition = termAndDefinition->second;
    taskMap.erase(termAndDefinition);
}
