//
// Created by without-eyes on 11.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ManageTopic.h" resolved

#include <utility>

#include "../include/managetopic.h"
#include "../forms/ui_ManageTopic.h"
#include <iostream>

ManageTopic::ManageTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::ManageTopic) {
    ui->setupUi(this);
}

ManageTopic::~ManageTopic() {
    delete ui;
}

void ManageTopic::setTopicName(const QString& topicName) {
    ui->label->setText(topicName);
}
