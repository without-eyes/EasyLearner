/**
    * @file: definitionaddition.h
    * @author: without eyes
    *
    * This file contains DefinitionAddition class for "Definition Addition" window.
*/

#ifndef EASYLEARNER_DEFINITIONADDITION_H
#define EASYLEARNER_DEFINITIONADDITION_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DefinitionAddition; }
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
    Ui::DefinitionAddition *ui;
};


#endif //EASYLEARNER_DEFINITIONADDITION_H
