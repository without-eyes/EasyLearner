//
// Created by without-eyes on 10.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CreateTopic.h" resolved

#include "../include/createtopic.h"
#include "../forms/ui_CreateTopic.h"


CreateTopic::CreateTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::CreateTopic) {
    ui->setupUi(this);
}

CreateTopic::~CreateTopic() {
    delete ui;
}
