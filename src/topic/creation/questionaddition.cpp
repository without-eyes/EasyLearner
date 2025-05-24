/**
    * @file: questionaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of QuestionAddition class.
*/

#include "topic/creation/questionaddition.h"

#include "topic/base/topicmanagement.h"
#include "topic/base/contentmanager.h"
#include "../../../forms/ui_QuestionAddition.h"

QuestionAddition::QuestionAddition(QWidget *parent) :
        ContentAddition(parent), ui(new Ui::QuestionAddition) {
    ui->setupUi(this);

    connect(ui->createButton, &QPushButton::clicked, this, &QuestionAddition::addNewContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &QuestionAddition::goBack);
    connect(ui->questionLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
}

QuestionAddition::~QuestionAddition() {
    delete ui;
}

void QuestionAddition::addNewContent() {
    contentManager->addIntoQuestionMap(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    emit updateQuestionMapShowing();
    ui->questionLineEdit->clear();
    ui->answerLineEdit->clear();
    goBack();
}

void QuestionAddition::changeButtonState() const {
    if (ui->questionLineEdit->text().isEmpty() || ui->answerLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(false);
        return;
    }

    std::map<QString, QString> questionMap = contentManager->getQuestionMap();
    if (questionMap.find(ui->questionLineEdit->text()) != questionMap.end()) {
        ui->createButton->setEnabled(false);
        return;
    }

    ui->createButton->setEnabled(true);
}

void QuestionAddition::goBack() {
    ui->questionLineEdit->setFocus();
    ui->questionLineEdit->clear();
    ui->answerLineEdit->clear();
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
