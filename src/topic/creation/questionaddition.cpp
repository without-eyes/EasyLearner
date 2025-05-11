/**
    * @file: addquestions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of QuestionAddition class.
*/

#include "../../../include/topic/creation/questionaddition.h"

#include "../../../cmake-build-debug/forms/ui_QuestionAddition.h"
#include "../../../include/topic/base/topicmanagement.h"
#include "../../../include/topic/base/content.h"

QuestionAddition::QuestionAddition(QWidget *parent) :
        QWidget(parent), ui(new Ui::QuestionAddition) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &QuestionAddition::addQuestion);
    connect(ui->goBackButton, &QPushButton::clicked, this, &QuestionAddition::goBack);
    connect(ui->questionLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
}

QuestionAddition::~QuestionAddition() {
    delete ui;
}

void QuestionAddition::addQuestion() {
    Content::addIntoQuestionMap(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    goBack();
}

void QuestionAddition::changeButtonState() const {
    if (!ui->questionLineEdit->text().isEmpty() && !ui->answerLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void QuestionAddition::goBack() {
    auto *window = new TopicManagement;
    window->show();
    close();
}
