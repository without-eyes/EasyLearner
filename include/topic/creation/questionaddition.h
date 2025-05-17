/**
    * @file: questionaddition.h
    * @author: without eyes
    *
    * This file contains QuestionAddition class for "Question Addition" window.
*/

#ifndef EASYLEARNER_QUESTIONADDITION_H
#define EASYLEARNER_QUESTIONADDITION_H

#include "contentaddition.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QuestionAddition; }
QT_END_NAMESPACE

class QuestionAddition final : public QWidget, public ContentAddition {
Q_OBJECT

signals:
    void requestPageChange(int index);

    void updateQuestionMapShowing();

    void updateStudyQuestionsButton();

public:
    explicit QuestionAddition(QWidget *parent = nullptr);

    ~QuestionAddition() override;

public slots:

    void addNewContent() override;

    void changeButtonState() const override;

    void goBack() override;

private:
    Ui::QuestionAddition *ui;
};


#endif //EASYLEARNER_QUESTIONADDITION_H
