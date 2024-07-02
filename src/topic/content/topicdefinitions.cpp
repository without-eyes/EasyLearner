#include "../../../include/topic/content/topicdefinitions.h"
#include "../../../forms/ui_TopicDefinitions.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"


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
    std::map<QString, QString> definitionMap = Content::getDefinitionMap();
    for (const auto &pair: definitionMap) {
        ui->listWidget->addItem(pair.first + " - " + pair.second);
    }
    ui->listWidget->show();
}

void TopicDefinitions::goBack() {
    auto *window = new TopicContent;
    window->show();
    close();
}
