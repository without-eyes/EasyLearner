#include "../include/adddefinition.h"
#include "../forms/ui_AddDefinition.h"


AddDefinition::AddDefinition(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddDefinition) {
    ui->setupUi(this);
}

AddDefinition::~AddDefinition() {
    delete ui;
}
