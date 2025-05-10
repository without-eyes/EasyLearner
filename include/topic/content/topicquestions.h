/**
    * @file: topicquestions.h
    * @author: without eyes
    *
    * This file contains TopicQuestions class for "Topic Questions" window.
*/

#ifndef EASYLEARNER_TOPICQUESTIONS_H
#define EASYLEARNER_TOPICQUESTIONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TopicQuestions; }
QT_END_NAMESPACE

class TopicQuestions final : public QWidget {
Q_OBJECT

public slots:

    void deleteQuestion() const;

    void goBack();

    void changeButtonState() const;

public:
    explicit TopicQuestions(QWidget *parent = nullptr);

    ~TopicQuestions() override;

private:
    Ui::TopicQuestions *ui;

    void showQuestionList() const;
};


#endif //EASYLEARNER_TOPICQUESTIONS_H
