/**
    * @file: definitionaddition.h
    * @author: without eyes
    *
    * This file contains DefinitionAddition class for "Definition Addition" window.
*/

#ifndef EASYLEARNER_ADDDEFINITION_H
#define EASYLEARNER_ADDDEFINITION_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AddDefinition; }
QT_END_NAMESPACE

class DefinitionAddition final : public QWidget {
Q_OBJECT

public:
    explicit DefinitionAddition(QWidget *parent = nullptr);

    ~DefinitionAddition() override;

public slots:

    void addDefinition();

    void changeButtonState() const;

    void goBack();

private:
    Ui::AddDefinition *ui;
};


#endif //EASYLEARNER_ADDDEFINITION_H
