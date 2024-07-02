#include <QAbstractButton>
#include "../../../include/topic/creation/addquestion.h"
#include "../../../forms/ui_AddQuestion.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"


AddQuestion::AddQuestion(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddQuestion) {
    ui->setupUi(this);

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &AddQuestion::addQuestion);
}

AddQuestion::~AddQuestion() {
    delete ui;
}

void AddQuestion::addQuestion() {
    auto *window = new ManageTopic;
    Content::addIntoQuestionMap(ui->questionLineEdit->text(), ui->answerLineEdit->text());
    window->show();
    close();
}
