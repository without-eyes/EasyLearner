#include "../include/topicdefinitions.h"
#include "../forms/ui_TopicDefinitions.h"
#include "../include/managetopic.h"
#include "../include/topiccontent.h"


TopicDefinitions::TopicDefinitions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicDefinitions) {
    ui->setupUi(this);

    showDefinitionList();

    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &TopicDefinitions::goBack);
}

TopicDefinitions::~TopicDefinitions() {
    delete ui;
}

void TopicDefinitions::showDefinitionList() {
    std::map<QString, QString> definitionSet = ManageTopic::getDefinitionSet();
    for (const auto & pair : definitionSet) {
        ui->listWidget->addItem(pair.first + " - " + pair.second);
    }
    ui->listWidget->show();
}

void TopicDefinitions::goBack() {
    auto* window = new TopicContent;
    window->show();
    close();
}
