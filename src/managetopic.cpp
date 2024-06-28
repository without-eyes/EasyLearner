#include "../include/managetopic.h"
#include "../forms/ui_ManageTopic.h"
#include "../include/mainmenu.h"
#include "../include/adddefinition.h"
#include "../include/topiccontent.h"
#include "../include/addquestion.h"
#include <iostream>


ManageTopic::ManageTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::ManageTopic) {
    ui->setupUi(this);

    QObject::connect(ui->studyButton, &QPushButton::clicked, this, &ManageTopic::startStudy);
    QObject::connect(ui->addDefinitionButton, &QPushButton::clicked, this, &ManageTopic::addDefinition);
    QObject::connect(ui->addQuestionButton, &QPushButton::clicked, this, &ManageTopic::addQuestion);
    QObject::connect(ui->showContentButton, &QPushButton::clicked, this, &ManageTopic::showTopicContent);
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
    auto* window = new AddQuestion;
    window->show();
    close();
}

void ManageTopic::showTopicContent() {
    auto* window = new TopicContent;
    window->show();
    close();
}

void ManageTopic::goBack() {
    auto* window = new MainMenu;
    window->show();
    close();
}


