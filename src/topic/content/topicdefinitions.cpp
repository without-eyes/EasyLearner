/**
    * @file: topicdefinitions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of TopicDefinitions class.
*/

#include "topic/content/topicdefinitions.h"

#include "topic/content/topiccontent.h"
#include "topic/base/content.h"
#include "../../../forms/ui_TopicDefinitions.h"

TopicDefinitions::TopicDefinitions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicDefinitions) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Definitions");

    showContentList();
    changeButtonState();

    connect(ui->listWidget, &QListWidget::itemClicked, this, &TopicDefinitions::changeButtonState);
    connect(ui->deleteButton, &QPushButton::clicked, this, &TopicDefinitions::deleteContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &TopicDefinitions::goBack);
}

TopicDefinitions::~TopicDefinitions() {
    delete ui;
}

void TopicDefinitions::showContentList() {
    const std::map<QString, QString> definitionMap = Content::getDefinitionMap();
    for (const auto &[term, definition]: definitionMap) {
        ui->listWidget->addItem(term + " - " + definition);
    }
    ui->listWidget->show();
}

void TopicDefinitions::deleteContent() {
    std::string text = ui->listWidget->takeItem(ui->listWidget->currentRow())->text().toStdString();
    const std::string definition = text.substr(0, text.find(" -"));
    Content::deleteFromDefinitionMap(QString::fromStdString(definition));

    emit updateStudyDefinitionsButton();

    if (ui->listWidget->count() == 0) {
        changeButtonState();
    }
}

void TopicDefinitions::goBack() {
    emit requestPageChange(3);
}

void TopicDefinitions::changeButtonState() const {
    if (const auto *item = ui->listWidget->currentItem(); item && !item->text().isEmpty()) {
        ui->deleteButton->setEnabled(true);
    } else {
        ui->deleteButton->setEnabled(false);
    }
}
