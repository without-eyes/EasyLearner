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
#include "../../forms/ui_MainMenu.h"

QList<QString> MainMenu::topicList;

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    this->setWindowTitle("EasyLearner - Main Menu");

    Database();

    // DELETE THIS
    topicList.push_back("Test topic");
    // THIS IS FOR TESTING

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
    auto *window = new TopicManagement;
    window->setTopicName(ui->listWidget->currentItem()->text());
    window->move(this->pos());
    window->show();
    close();
}

void MainMenu::changeButtonState() const {
    ui->pickButton->setEnabled(!ui->pickButton->isEnabled());
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



