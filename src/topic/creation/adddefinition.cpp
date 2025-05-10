/**
    * @file: adddefinitions.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of AddDefinitions class.
*/

#include "../../../include/topic/creation/adddefinition.h"

#include "../../../forms/ui_AddDefinition.h"
#include "../../../include/topic/base/topicmanagement.h"
#include "../../../include/topic/base/content.h"

AddDefinition::AddDefinition(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddDefinition) {
    ui->setupUi(this);

    changeButtonState();

    connect(ui->createButton, &QPushButton::clicked, this, &AddDefinition::addDefinition);
    connect(ui->goBackButton, &QPushButton::clicked, this, &AddDefinition::goBack);
    connect(ui->termLineEdit, &QLineEdit::textChanged, this, &AddDefinition::changeButtonState);
    connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &AddDefinition::changeButtonState);
}

AddDefinition::~AddDefinition() {
    delete ui;
}

void AddDefinition::addDefinition() {
    Content::addIntoDefinitionMap(ui->termLineEdit->text(), ui->definitionLineEdit->text());
    goBack();
}

void AddDefinition::changeButtonState() const {
    if (!ui->termLineEdit->text().isEmpty() && !ui->definitionLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void AddDefinition::goBack() {
    auto *window = new TopicManagement;
    window->show();
    close();
}
