/**
    * @file: questionaddition.h
    * @author: without eyes
    *
    * This file contains QuestionAddition class for "Question Addition" window.
*/

#ifndef EASYLEARNER_QUESTIONADDITION_H
#define EASYLEARNER_QUESTIONADDITION_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QuestionAddition; }
QT_END_NAMESPACE

class QuestionAddition final : public QWidget {
Q_OBJECT

public:
    explicit QuestionAddition(QWidget *parent = nullptr);

    ~QuestionAddition() override;

public slots:

    void addQuestion();

    void changeButtonState() const;

    void goBack();

private:
    Ui::QuestionAddition *ui;
};


#endif //EASYLEARNER_QUESTIONADDITION_H
