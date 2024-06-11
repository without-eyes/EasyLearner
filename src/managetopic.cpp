//
// Created by without-eyes on 11.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ManageTopic.h" resolved

#include "../include/managetopic.h"
#include "../forms/ui_ManageTopic.h"


ManageTopic::ManageTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::ManageTopic) {
    ui->setupUi(this);
}

ManageTopic::~ManageTopic() {
    delete ui;
}
