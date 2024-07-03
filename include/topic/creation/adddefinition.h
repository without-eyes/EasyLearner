//
// Created by without-eyes on 13.06.24.
//

#ifndef EASYLEARNER_ADDDEFINITION_H
#define EASYLEARNER_ADDDEFINITION_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class AddDefinition; }
QT_END_NAMESPACE

class AddDefinition : public QWidget {
Q_OBJECT

public:
    explicit AddDefinition(QWidget *parent = nullptr);

    ~AddDefinition() override;

public slots:

    void addDefinition();

    void enableButton();

private:
    Ui::AddDefinition *ui;
};


#endif //EASYLEARNER_ADDDEFINITION_H
