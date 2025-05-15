/**
    * @file: mainmenu.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainMenu class.
*/

#include "mainmenu/mainmenu.h"

#include <QStringListModel>
#include "mainmenu/topiccreation.h"
#include "topic/base/topicmanagement.h"
#include "utils/database.h"
#include "topic/base/content.h"
#include "../../forms/ui_MainMenu.h"

QList<QString> MainMenu::topicList;

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Main Menu");

    Database();

    showTableContent();
    changeButtonState();

    connect(ui->pickButton, &QPushButton::clicked, this, &MainMenu::pickTopic);
    connect(ui->createButton, &QPushButton::clicked, this, &MainMenu::createTopic);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainMenu::deleteTopic);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainMenu::changeButtonState);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::showTableContent() const {
    for (const auto &row: topicList) {
        ui->listWidget->addItem(row);
    }
    ui->listWidget->show();
}

void MainMenu::pickTopic() {
    Content::setCurrentTopic(ui->listWidget->currentItem()->text());
    auto *window = new TopicManagement;
    window->move(this->pos());
    window->show();
    close();
}

void MainMenu::changeButtonState() const {
    if (const auto *item = ui->listWidget->currentItem(); item && !item->text().isEmpty()) {
        ui->pickButton->setEnabled(true);
    } else {
        ui->pickButton->setEnabled(false);
    }
}


void MainMenu::createTopic() {
    auto *window = new TopicCreation;
    window->move(this->pos());
    window->show();
    close();
}

void MainMenu::deleteTopic() const {
    const auto *item = ui->listWidget->currentItem();
    topicList.removeOne(item->text());
    delete ui->listWidget->takeItem(ui->listWidget->row(item));
}

void MainMenu::addTopicIntoList(const QString &topic) {
    topicList.push_back(topic);
}



