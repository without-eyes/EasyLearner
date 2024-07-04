#include "../../../include/topic/content/topicdefinitions.h"
#include "../../../forms/ui_TopicDefinitions.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"


TopicDefinitions::TopicDefinitions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicDefinitions) {
    ui->setupUi(this);

    showDefinitionList();
    changeButtonState();

    QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &TopicDefinitions::changeButtonState);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &TopicDefinitions::deleteDefinition);
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

void TopicDefinitions::deleteDefinition() {
    std::string text = ui->listWidget->takeItem(ui->listWidget->currentRow())->text().toStdString();
    std::string definition = text.substr(0, text.find(" -"));
    Content::deleteFromDefinitionMap(QString::fromStdString(definition));
}

void TopicDefinitions::goBack() {
    auto *window = new TopicContent;
    window->show();
    close();
}

void TopicDefinitions::changeButtonState() {
    ui->deleteButton->setEnabled(!ui->deleteButton->isEnabled());
}
