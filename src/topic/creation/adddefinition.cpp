#include "../../../include/topic/creation/adddefinition.h"
#include "../../../forms/ui_AddDefinition.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/base/content.h"


AddDefinition::AddDefinition(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddDefinition) {
    ui->setupUi(this);

    changeButtonState();

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &AddDefinition::addDefinition);
    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &AddDefinition::goBack);
    QObject::connect(ui->termLineEdit, &QLineEdit::textChanged, this, &AddDefinition::changeButtonState);
    QObject::connect(ui->definitionLineEdit, &QLineEdit::textChanged, this, &AddDefinition::changeButtonState);
}

AddDefinition::~AddDefinition() {
    delete ui;
}

void AddDefinition::addDefinition() {
    Content::addIntoDefinitionMap(ui->termLineEdit->text(), ui->definitionLineEdit->text());
    goBack();
}

void AddDefinition::changeButtonState() {
    if (!ui->termLineEdit->text().isEmpty() && !ui->definitionLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}

void AddDefinition::goBack() {
    auto *window = new ManageTopic;
    window->show();
    close();
}
