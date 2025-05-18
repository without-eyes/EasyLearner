/**
    * @file: studyquestions.h
    * @author: without eyes
    *
    * This file contains StudyQuestions class for "Study Questions" window.
*/

#ifndef EASYLEARNER_STUDYQUESTIONS_H
#define EASYLEARNER_STUDYQUESTIONS_H

#include <QWidget>
#include "studycontent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StudyQuestions; }
QT_END_NAMESPACE

class StudyQuestions final : public QWidget, public StudyContent {
Q_OBJECT

signals:
    void requestPageChange(int index);

public:
    explicit StudyQuestions(QWidget *parent = nullptr);

    ~StudyQuestions() override;

public slots:
    void checkAnswer() override;

    void showNextTask() override;

    void changeButtonState() const override;

    void studyQuestion();

private:
    void pickRandomTask() override;

    Ui::StudyQuestions *ui;
    static std::map<QString, QString> taskMap;
    QString question;
    QString answer;
};


#endif //EASYLEARNER_STUDYQUESTIONS_H
