/**
    * @file: definitionaddition.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of DefinitionAddition class.
*/

#include "topic/creation/definitionaddition.h"


#include "topic/base/topicmanagement.h"
#include "topic/base/contentmanager.h"
#include "../../../forms/ui_DefinitionAddition.h"

DefinitionAddition::DefinitionAddition(QWidget *parent) :
        QWidget(parent), ui(new Ui::DefinitionAddition) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &DefinitionAddition::addNewContent);
    connect(ui->goBackButton, &QPushButton::clicked, this, &DefinitionAddition::goBack);
    connect(ui->termLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &DefinitionAddition::changeButtonState);
}

DefinitionAddition::~DefinitionAddition() {
    delete ui;
}

void DefinitionAddition::setContentManager(const ContentManager &contentManager) {
    this->contentManager = contentManager;
}

void DefinitionAddition::addNewContent() {
    contentManager.addIntoDefinitionMap(ui->termLineEdit->text(), ui->definitionLineEdit->text());
    emit updateDefinitionMapShowing();
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
    ui->termLineEdit->setFocus();
    ui->termLineEdit->clear();
    ui->definitionLineEdit->clear();
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
}
