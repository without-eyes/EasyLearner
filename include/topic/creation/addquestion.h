/**
    * @file: addquestions.h
    * @author: without eyes
    *
    * This file contains AddQuestions class for "Add Questions" window.
*/

#ifndef EASYLEARNER_ADDQUESTION_H
#define EASYLEARNER_ADDQUESTION_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AddQuestion; }
QT_END_NAMESPACE

class AddQuestion final : public QWidget {
Q_OBJECT

public:
    explicit AddQuestion(QWidget *parent = nullptr);

    ~AddQuestion() override;

public slots:

    void addQuestion();

    void changeButtonState() const;

    void goBack();

private:
    Ui::AddQuestion *ui;
};


#endif //EASYLEARNER_ADDQUESTION_H
