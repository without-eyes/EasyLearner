#include "../../../include/topic/content/topicquestions.h"
#include "../../../forms/ui_TopicQuestions.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/base/content.h"


TopicQuestions::TopicQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicQuestions) {
    ui->setupUi(this);

    showQuestionList();
    changeButtonState();

    QObject::connect(ui->listWidget, &QListWidget::itemClicked, this, &TopicQuestions::changeButtonState);
    QObject::connect(ui->deleteButton, &QPushButton::clicked, this, &TopicQuestions::deleteQuestion);
    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &TopicQuestions::goBack);
}

TopicQuestions::~TopicQuestions() {
    delete ui;
}

void TopicQuestions::showQuestionList() {
    std::map<QString, QString> questionMap = Content::getQuestionMap();
    for (const auto &pair: questionMap) {
        ui->listWidget->addItem(pair.first + " - " + pair.second);
    }
    ui->listWidget->show();
}

void TopicQuestions::deleteQuestion() {
    std::string text = ui->listWidget->takeItem(ui->listWidget->currentRow())->text().toStdString();
    std::string question = text.substr(0, text.find(" -"));
    Content::deleteFromQuestionMap(QString::fromStdString(question));
}

void TopicQuestions::goBack() {
    auto *window = new TopicContent;
    window->show();
    close();
}

void TopicQuestions::changeButtonState() {
    ui->deleteButton->setEnabled(!ui->deleteButton->isEnabled());
}
