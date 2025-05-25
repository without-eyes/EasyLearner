/**
    * @file: definitionaddition.h
    * @author: without eyes
    *
    * This file contains DefinitionAddition class for "Definition Addition" window.
*/

#ifndef EASYLEARNER_DEFINITIONADDITION_H
#define EASYLEARNER_DEFINITIONADDITION_H

#include "icontentaddition.h"
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DefinitionAddition; }
QT_END_NAMESPACE

class DefinitionAddition final : public IContentAddition {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

    void updateDefinitionMapShowing();

public:
    explicit DefinitionAddition(QWidget *parent = nullptr);

    ~DefinitionAddition() override;

public slots:
    void addNewContent() override;

    void changeButtonState() const override;

    void goBack() override;

private:
    Ui::DefinitionAddition *ui;
    std::shared_ptr<ContentManager> contentManager;
};


#endif //EASYLEARNER_DEFINITIONADDITION_H
