#include <QAbstractButton>
#include "../../../include/topic/creation/addquestion.h"
#include "../../../forms/ui_AddQuestion.h"
#include "../../../include/topic/base/managetopic.h"
#include "../../../include/topic/content/topiccontent.h"
#include "../../../include/topic/base/content.h"


AddQuestion::AddQuestion(QWidget *parent) :
        QWidget(parent), ui(new Ui::AddQuestion) {
    ui->setupUi(this);

    changeButtonState();

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &AddQuestion::addQuestion);
    QObject::connect(ui->questionLineEdit, &QLineEdit::textChanged, this, &AddQuestion::changeButtonState);
    QObject::connect(ui->answerLineEdit, &QLineEdit::textChanged, this, &AddQuestion::changeButtonState);
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

void AddQuestion::changeButtonState() {
    if (!ui->questionLineEdit->text().isEmpty() && !ui->answerLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}
