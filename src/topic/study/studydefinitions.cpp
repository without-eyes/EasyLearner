/**
    * @file: studydefinitions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of StudyDefinitions class.
*/

#include "topic/study/studydefinitions.h"

#include <QLineEdit>
#include <QPushButton>
#include "topic/study/topicstudy.h"
#include "utils/randomizer.h"
#include "../../../forms/ui_StudyDefinitions.h"

std::map<QString, QString> StudyDefinitions::definitionsMap;

StudyDefinitions::StudyDefinitions(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudyDefinitions) {
    ui->setupUi(this);

    pickRandomDefinition();
    ui->termLabel->setText(term);
    changeButtonState();

    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::checkAnswer);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &StudyDefinitions::changeButtonState);
}

StudyDefinitions::~StudyDefinitions() {
    delete ui;
}

void StudyDefinitions::setDefinitionsMap(const std::map<QString, QString> &map) {
    definitionsMap = map;
}

void StudyDefinitions::checkAnswer() {
    if (ui->definitionLineEdit->text() == definition) {
        ui->correctnessLabel->setText("Correct!");
    } else {
        ui->correctnessLabel->setText("Wrong! Correct answer: " + definition);
    }
    ui->definitionLineEdit->setEnabled(false);
    ui->continueButton->setText("Continue");
    connect(ui->continueButton, &QPushButton::clicked, this, &StudyDefinitions::showNextDefinition);
}

void StudyDefinitions::showNextDefinition() {
    if (definitionsMap.empty()) {
        auto* window = new TopicStudy;
        window->move(this->pos());
        window->show();
    } else {
        auto* window = new StudyDefinitions;
        window->move(this->pos());
        window->show();
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

void StudyDefinitions::pickRandomDefinition() {
    if (definitionsMap.empty()) {
        auto* window = new TopicStudy;
        window->move(this->pos());
        window->show();
        close();
        return;
    }
    auto termAndDefinition = definitionsMap.begin();
    std::advance(termAndDefinition, Randomizer::getInstance()->getInt(definitionsMap.size() - 1));
    term = termAndDefinition->first;
    definition = termAndDefinition->second;
    definitionsMap.erase(termAndDefinition);
}
