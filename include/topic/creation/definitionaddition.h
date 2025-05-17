/**
    * @file: definitionaddition.h
    * @author: without eyes
    *
    * This file contains DefinitionAddition class for "Definition Addition" window.
*/

#ifndef EASYLEARNER_DEFINITIONADDITION_H
#define EASYLEARNER_DEFINITIONADDITION_H

#include "contentaddition.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DefinitionAddition; }
QT_END_NAMESPACE

class DefinitionAddition final : public QWidget, public ContentAddition {
Q_OBJECT

signals:
    void requestPageChange(int index);

    void updateDefinitionMapShowing();

    void updateStudyDefinitionsButton();

public:
    explicit DefinitionAddition(QWidget *parent = nullptr);

    ~DefinitionAddition() override;

public slots:

    void addNewContent() override;

    void changeButtonState() const override;

    void goBack() override;

private:
    Ui::DefinitionAddition *ui;
};


#endif //EASYLEARNER_DEFINITIONADDITION_H
