/**
    * @file: addquestions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of AddQuestions class.
*/

#include "../../../include/topic/creation/addquestion.h"
#include "../../../forms/ui_AddQuestion.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/base/content.h"

AddQuestion::AddQuestion(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddQuestion) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &AddQuestion::addQuestion);
    connect(ui->goBackButton, &QPushButton::clicked, this, &AddQuestion::goBack);
    connect(ui->questionLineEdit, &QLineEdit::textChanged, this, &AddQuestion::changeButtonState);
    connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &AddQuestion::changeButtonState);
}

AddQuestion::~AddQuestion() {
    delete ui;
}

void AddQuestion::addQuestion() {
    Content::addIntoQuestionMap(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    goBack();
}

void AddQuestion::changeButtonState() const {
    if (!ui->questionLineEdit->text().isEmpty() && !ui->answerLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void AddQuestion::goBack() {
    auto *window = new ManageTopic;
    window->show();
    close();
}
