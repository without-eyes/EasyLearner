/**
    * @file: topicquestions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicQuestions class.
*/

#include "topic/content/topicquestions.h"

#include "topic/content/topiccontent.h"
#include "topic/base/content.h"
#include "../../../forms/ui_TopicQuestions.h"

TopicQuestions::TopicQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicQuestions) {
    ui->setupUi(this);

    showQuestionList();
    changeButtonState();

    connect(ui->listWidget, &QListWidget::itemClicked, this, &TopicQuestions::changeButtonState);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TopicQuestions::deleteQuestion);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicQuestions::goBack);
}

TopicQuestions::~TopicQuestions() {
    delete ui;
}

void TopicQuestions::showQuestionList() const {
    const std::map<QString, QString> questionMap = Content::getQuestionMap();
    for (const auto &[question, answer]: questionMap) {
        ui->listWidget->addItem(question + " - " + answer);
    }
    ui->listWidget->show();
}

void TopicQuestions::deleteQuestion() const {
    std::string text = ui->listWidget->takeItem(ui->listWidget->currentRow())->text().toStdString();
    const std::string question = text.substr(0, text.find(" -"));
    Content::deleteFromQuestionMap(QString::fromStdString(question));
}

void TopicQuestions::goBack() {
    auto *window = new TopicContent;
    window->move(this->pos());
    window->show();
    close();
}

void TopicQuestions::changeButtonState() const {
    ui->deleteButton->setEnabled(!ui->deleteButton->isEnabled());
}
