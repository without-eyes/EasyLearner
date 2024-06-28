#include "../include/studyquestions.h"
#include "ui_StudyQuestions.h"


StudyQuestions::StudyQuestions(QWidget *parent) :
        QWidget(parent), ui(new Ui::StudyQuestions) {
    ui->setupUi(this);
}

StudyQuestions::~StudyQuestions() {
    delete ui;
}
