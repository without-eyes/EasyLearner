#include <QAbstractButton>
#include "../include/addquestion.h"
#include "../forms/ui_AddQuestion.h"
#include "../include/managetopic.h"


AddQuestion::AddQuestion(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddQuestion) {
    ui->setupUi(this);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &AddQuestion::addQuestion);
}

AddQuestion::~AddQuestion() {
    delete ui;
}

void AddQuestion::addQuestion() {
    auto* window = new ManageTopic;
    window->addIntoQuestionSet(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    window->show();
    close();
}
