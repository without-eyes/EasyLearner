/**
    * @file: questionaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of QuestionAddition class.
*/

#include "topic/creation/questionaddition.h"

#include "topic/base/topicmanagement.h"
#include "topic/base/content.h"
#include "../../../forms/ui_QuestionAddition.h"

QuestionAddition::QuestionAddition(QWidget *parent) :
        QWidget(parent), ui(new Ui::QuestionAddition) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Question Addition");

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &QuestionAddition::addNewContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &QuestionAddition::goBack);
    connect(ui->questionLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &QuestionAddition::changeButtonState);
}

QuestionAddition::~QuestionAddition() {
    delete ui;
}

void QuestionAddition::addNewContent() {
    Content::addIntoQuestionMap(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    emit updateQuestionMapShowing();
    emit updateStudyQuestionsButton();
    ui->questionLineEdit->clear();
    ui->answerLineEdit->clear();
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
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
