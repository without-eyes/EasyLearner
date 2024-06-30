#include "../include/topicquestions.h"
#include "../forms/ui_TopicQuestions.h"
#include "../include/topiccontent.h"
#include "../include/managetopic.h"


TopicQuestions::TopicQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicQuestions) {
    ui->setupUi(this);

    showQuestionList();

    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &TopicQuestions::goBack);
}

TopicQuestions::~TopicQuestions() {
    delete ui;
}

void TopicQuestions::showQuestionList() {
    std::map<QString, QString> questionMap = TopicContent::getQuestionMap();
    for (const auto & pair : questionMap) {
        ui->listWidget->addItem(pair.first + " - " + pair.second);
    }
    ui->listWidget->show();
}

void TopicQuestions::goBack() {
    auto* window = new TopicContent;
    window->show();
    close();
}
