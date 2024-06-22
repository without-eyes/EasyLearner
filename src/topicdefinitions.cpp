#include "../include/topicdefinitions.h"
#include "../forms/ui_TopicDefinitions.h"


TopicDefinitions::TopicDefinitions(QWidget *parent) :
        QWidget(parent), ui(new Ui::TopicDefinitions) {
    ui->setupUi(this);
}

TopicDefinitions::~TopicDefinitions() {
    delete ui;
}
