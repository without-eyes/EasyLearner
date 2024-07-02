#include "../../../include/topic/base/managetopic.h"
#include "../../../forms/ui_ManageTopic.h"
#include "../../../include/mainmenu/mainmenu.h"
#include "../../../include/topic/creation/adddefinition.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/creation/addquestion.h"
#include "../../../include/topic/study/topicstudy.h"
#include "../../../include/topic/base/content.h"
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

void ManageTopic::setTopicName(const QString &topicName) {
    ui->label->setText(topicName);
    auto* content = new Content(topicName);
}

void ManageTopic::startStudy() {
    auto *window = new TopicStudy;
    window->show();
    close();
}

void ManageTopic::addDefinition() {
    auto *window = new AddDefinition;
    window->show();
    close();
}

void ManageTopic::addQuestion() {
    auto *window = new AddQuestion;
    window->show();
    close();
}

void ManageTopic::showTopicContent() {
    auto *window = new TopicContent;
    window->show();
    close();
}

void ManageTopic::goBack() {
    auto *window = new MainMenu;
    window->show();
    close();
}


