#include "../include/topiccontent.h"
#include "../forms/ui_TopicContent.h"
#include "../include/managetopic.h"
#include "../include/topicdefinitions.h"
#include "../include/topicquestions.h"

std::map<QString, QString> TopicContent::definitionSet;
std::map<QString, QString> TopicContent::questionSet;

TopicContent::TopicContent(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicContent) {
    ui->setupUi(this);

    // DELETE THIS
    definitionSet["Term"] = "definition";
    questionSet["Question"] = "answer";
    // THIS IS FOR TESTING

    QObject::connect(ui->definitionButton, &QPushButton::clicked, this, &TopicContent::showDefinition);
    QObject::connect(ui->qaButton, &QPushButton::clicked, this, &TopicContent::showQuestionsAnswers);
    QObject::connect(ui->goBackButton, &QPushButton::clicked, this, &TopicContent::goBack);
}

TopicContent::~TopicContent() {
    delete ui;
}

void TopicContent::addIntoDefinitionSet(const QString& term, const QString& definition) {
    definitionSet[term] = definition;
}

std::map<QString, QString> TopicContent::getDefinitionSet() {
    return definitionSet;
}

void TopicContent::addIntoQuestionSet(const QString& question, const QString& answer) {
    questionSet[question] = answer;
}

std::map<QString, QString> TopicContent::getQuestionSet() {
    return questionSet;
}

void TopicContent::showDefinition() {
    auto* window = new TopicDefinitions;
    window->show();
    close();
}

void TopicContent::showQuestionsAnswers() {
    auto* window = new TopicQuestions;
    window->show();
    close();
}

void TopicContent::goBack() {
    auto* window = new ManageTopic;
    window->show();
    close();
}
