#include "../../include/mainmenu/createtopic.h"
#include "../../forms/ui_CreateTopic.h"
#include "../../include/mainmenu/mainmenu.h"


CreateTopic::CreateTopic(QWidget *parent) :
        QWidget(parent), ui(new Ui::CreateTopic) {
    ui->setupUi(this);

    changeButtonState();

    QObject::connect(ui->createButton, &QPushButton::clicked, this, &CreateTopic::createNewTopic);
    QObject::connect(ui->nameLineEdit, &QLineEdit::textChanged, this, &CreateTopic::changeButtonState);
}

CreateTopic::~CreateTopic() {
    delete ui;
}

void CreateTopic::createNewTopic() {
    if (!ui->nameLineEdit->text().isEmpty()) {
        MainMenu::addTopicIntoList(ui->nameLineEdit->text());
        goToMainMenu();
    }
}

void CreateTopic::goToMainMenu() {
    auto *window = new MainMenu;
    window->show();
    close();
}

void CreateTopic::changeButtonState() {
    if (!ui->nameLineEdit->text().isEmpty()) {
        ui->createButton->setEnabled(true);
    } else {
        ui->createButton->setEnabled(false);
    }
}




