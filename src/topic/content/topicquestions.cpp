/**
    * @file: topicquestions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicQuestions class.
*/

#include "topic/content/topicquestions.h"

#include "topic/content/topiccontent.h"
#include "topic/base/contentmanager.h"
#include "../../../forms/ui_TopicQuestions.h"

TopicQuestions::TopicQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicQuestions) {
    ui->setupUi(this);

    showContentList();
    changeButtonState();

    connect(ui->listWidget, &QListWidget::itemClicked, this, &TopicQuestions::changeButtonState);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TopicQuestions::deleteContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicQuestions::goBack);
}

TopicQuestions::~TopicQuestions() {
    delete ui;
}

void TopicQuestions::showContentList() {
    ui->listWidget->clear();
    for (const auto &[question, answer]: contentManager.getQuestionMap()) {
        ui->listWidget->addItem(question + " - " + answer);
    }
    ui->listWidget->show();
}

void TopicQuestions::setContentManager(const ContentManager &contentManager) {
    this->contentManager = contentManager;
}

void TopicQuestions::deleteContent() {
    std::string text = ui->listWidget->takeItem(ui->listWidget->currentRow())->text().toStdString();
    const std::string question = text.substr(0, text.find(" -"));
    contentManager.deleteFromQuestionMap(QString::fromStdString(question));

    if (ui->listWidget->count() == 0) {
        changeButtonState();
    }
}

void TopicQuestions::goBack() {
    emit requestPageChange(TOPIC_CONTENT_PAGE);
}

void TopicQuestions::changeButtonState() const {
    if (const auto *item = ui->listWidget->currentItem(); item && !item->text().isEmpty()) {
        ui->deleteButton->setEnabled(true);
    } else {
        ui->deleteButton->setEnabled(false);
    }
}
