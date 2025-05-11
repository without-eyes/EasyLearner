/**
    * @file: definitionaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of DefinitionAddition class.
*/

#include "../../../include/topic/creation/definitionaddition.h"

#include "../../../forms/ui_DefinitionAddition.h"
#include "../../../include/topic/base/topicmanagement.h"
#include "../../../include/topic/base/content.h"

DefinitionAddition::DefinitionAddition(QWidget *parent) :
        QWidget(parent), ui(new Ui::DefinitionAddition) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &DefinitionAddition::addDefinition);
    connect(ui->goBackButton, &QPushButton::clicked, this, &DefinitionAddition::goBack);
    connect(ui->termLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
}

DefinitionAddition::~DefinitionAddition() {
    delete ui;
}

void DefinitionAddition::addDefinition() {
    Content::addIntoDefinitionMap(ui->termLineEdit->text(), ui->definitionLineEdit->text());
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
    auto *window = new TopicManagement;
    window->show();
    close();
}
