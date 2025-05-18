/**
    * @file: definitionaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of DefinitionAddition class.
*/

#include "topic/creation/definitionaddition.h"


#include "topic/base/topicmanagement.h"
#include "topic/base/content.h"
#include "../../../forms/ui_DefinitionAddition.h"

DefinitionAddition::DefinitionAddition(QWidget *parent) :
        QWidget(parent), ui(new Ui::DefinitionAddition) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Definition Addition");

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &DefinitionAddition::addNewContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &DefinitionAddition::goBack);
    connect(ui->termLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
}

DefinitionAddition::~DefinitionAddition() {
    delete ui;
}

void DefinitionAddition::addNewContent() {
    Content::addIntoDefinitionMap(ui->termLineEdit->text(), ui->definitionLineEdit->text());
    emit updateDefinitionMapShowing();
    emit updateStudyDefinitionsButton();
    ui->termLineEdit->clear();
    ui->definitionLineEdit->clear();
    goBack();
}

void DefinitionAddition::changeButtonState() const {
    if (!ui->termLineEdit->text().isEmpty() && !ui->definitionLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void DefinitionAddition::goBack() {
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
