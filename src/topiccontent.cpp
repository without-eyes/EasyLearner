#include "../include/topiccontent.h"
#include "../forms/ui_TopicContent.h"


TopicContent::TopicContent(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicContent) {
    ui->setupUi(this);
}

TopicContent::~TopicContent() {
    delete ui;
}

void TopicContent::showDefinition() {

}

void TopicContent::showQuestionsAnswers() {

}