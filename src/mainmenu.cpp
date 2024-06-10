//
// Created by without-eyes on 09.06.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainMenu.h" resolved

#include <QStringListModel>
#include <QStandardItemModel>
#include "../include/mainmenu.h"
#include "../forms/ui_MainMenu.h"
#include "../include/createtopic.h"

QList<QString> MainMenu::topicList;

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    showTableContent();

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &MainMenu::createTopic);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::showTableContent() {
    auto* listModel = new QStandardItemModel();
    for (int row = 0; row < topicList.size(); row++) {
        listModel->setItem(row, new QStandardItem(topicList.at(row)));
    }

    ui->listView->setModel(listModel);
    ui->listView->show();
}

void MainMenu::pickTopic() {
    // change window
}

void MainMenu::createTopic() {
    auto* window = new CreateTopic;
    window->show();
    close();
}

void MainMenu::addTopicIntoList(QString topic) {
    topicList.push_back(topic);
}




