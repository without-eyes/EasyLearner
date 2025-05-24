/**
    * @file: mainmenu.cpp
    * @author: without eyes
    *
    * This file contains methods' implementation of MainMenu class.
*/

#include "mainmenu/mainmenu.h"

#include <QStringListModel>
#include <QSqlRecord>
#include "utils/database.h"
#include "../../forms/ui_MainMenu.h"

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::MainMenu) {
    ui->setupUi(this);

    contentManager = std::make_shared<ContentManager>();

    const Database database;
    contentManager->loadTopicsFromModel(database.getAllTopics());

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

void MainMenu::showTableContent() {
    ui->listWidget->clear();
    for (const auto &row: contentManager->getTopicList()) {
        ui->listWidget->addItem(row);
    }
    ui->listWidget->show();
}

void MainMenu::pickTopic() {
    emit setContentManagerSignal(contentManager);
    emit setTopic(ui->listWidget->currentItem()->text());
    emit loadTopicContent();
    emit requestPageChange(TOPIC_MANAGEMENT_PAGE);
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
    emit setContentManagerSignal(contentManager);
    emit requestPageChange(TOPIC_CREATION_PAGE);
}

void MainMenu::deleteTopic() {
    const auto *item = ui->listWidget->currentItem();
    contentManager->deleteTopic(item->text());
    delete ui->listWidget->takeItem(ui->listWidget->row(item));
    if (ui->listWidget->count() == 0) {
        changeButtonState();
    }
}

void MainMenu::addTopicIntoList(const QString &topic) {
    contentManager->createTopic(topic);
    showTableContent();
}