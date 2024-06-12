#include <QStringListModel>
#include "../include/mainmenu.h"
#include "../forms/ui_MainMenu.h"
#include "../include/createtopic.h"
#include "../include/managetopic.h"

QList<QString> MainMenu::topicList;

MainMenu::MainMenu(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainMenu) {
    ui->setupUi(this);
    showTableContent();

    QObject::connect(ui->pickButton, &QPushButton::clicked, this, &MainMenu::pickTopic);
    QObject::connect(ui->createButton, &QPushButton::clicked, this, &MainMenu::createTopic);
}

MainMenu::~MainMenu() {
    delete ui;
}

void MainMenu::showTableContent() {
    for (const auto & row : topicList) {
        ui->listWidget->addItem(row);
    }
    ui->listWidget->show();
}

void MainMenu::pickTopic() {
    auto* window = new ManageTopic;
    window->setTopicName(ui->listWidget->currentItem()->text());
    window->show();
    close();
}

void MainMenu::createTopic() {
    auto* window = new CreateTopic;
    window->show();
    close();
}

void MainMenu::addTopicIntoList(const QString& topic) {
    topicList.push_back(topic);
}




