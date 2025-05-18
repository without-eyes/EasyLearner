/**
    * @file: mainmenu.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainMenu class.
*/

#include "mainmenu/mainmenu.h"

#include <QStringListModel>
#include "utils/database.h"
#include "topic/base/content.h"
#include "../../forms/ui_MainMenu.h"

QList<QString> MainMenu::topicList;

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainMenu) {
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
    ui->listWidget->clear();
    for (const auto &row: topicList) {
        ui->listWidget->addItem(row);
    }
    ui->listWidget->show();
}

void MainMenu::pickTopic() {
    emit setTopic(ui->listWidget->currentItem()->text());
    emit requestPageChange(2);
}

void MainMenu::changeButtonState() {
    if (const auto *item = ui->listWidget->currentItem(); item && !item->text().isEmpty()) {
        ui->pickButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
    } else {
        ui->pickButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    }
}

void MainMenu::createTopic() {
    emit requestPageChange(1);
}

void MainMenu::deleteTopic() {
    const auto *item = ui->listWidget->currentItem();
    topicList.removeOne(item->text());
    delete ui->listWidget->takeItem(ui->listWidget->row(item));

    if (ui->listWidget->count() == 0) {
        changeButtonState();
    }
}

void MainMenu::addTopicIntoList(const QString &topic) {
    topicList.push_back(topic);
    showTableContent();
}