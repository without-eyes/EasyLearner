#include "../include/adddefinition.h"
#include "../forms/ui_AddDefinition.h"
#include "../include/managetopic.h"


AddDefinition::AddDefinition(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddDefinition) {
    ui->setupUi(this);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &AddDefinition::addDefinition);
}

AddDefinition::~AddDefinition() {
    delete ui;
}

void AddDefinition::addDefinition() {
    auto* window = new ManageTopic;
    window->addIntoDefinitionSet(ui->termLineEdit->text(), ui->definitionLineEdit->text());
    window->show();
    close();
}
