#include "../include/managetopic.h"
#include "../forms/ui_ManageTopic.h"
#include "../include/mainmenu.h"
#include "../include/adddefinition.h"
#include <iostream>

ManageTopic::ManageTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::ManageTopic) {
    ui->setupUi(this);
    QObject::connect(ui->studyButton, &QPushButton::clicked, this, &ManageTopic::startStudy);
    QObject::connect(ui->addDefinitionButton, &QPushButton::clicked, this, &ManageTopic::addDefinition);
    QObject::connect(ui->addQuestionButton, &QPushButton::clicked, this, &ManageTopic::addQuestion);
    QObject::connect(ui->showContentButton, &QPushButton::clicked, this, &ManageTopic::showTopicQuestions);
    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &ManageTopic::goBack);
}

ManageTopic::~ManageTopic() {
    delete ui;
}

void ManageTopic::setTopicName(const QString& topicName) {
    ui->label->setText(topicName);
}

void ManageTopic::startStudy() {

}

void ManageTopic::addDefinition() {
    auto* window = new AddDefinition;
    window->show();
    close();
}

void ManageTopic::addQuestion() {

}

void ManageTopic::showTopicQuestions() {

}

void ManageTopic::goBack() {
    auto* window = new MainMenu;
    window->show();
    close();
}


