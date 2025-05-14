/**
    * @file: topicquestions.h
    * @author: without eyes
    *
    * This file contains TopicQuestions class for "Topic Questions" window.
*/

#ifndef EASYLEARNER_TOPICQUESTIONS_H
#define EASYLEARNER_TOPICQUESTIONS_H

#include <QWidget>

#include "topiccontentmanagement.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicQuestions; }
QT_END_NAMESPACE

class TopicQuestions final : public QWidget, public TopicContentManagement {
Q_OBJECT

public slots:

    void deleteContent() const override;

    void goBack() override;

    void changeButtonState() const override;

public:
    explicit TopicQuestions(QWidget *parent = nullptr);

    ~TopicQuestions() override;

private:
    Ui::TopicQuestions *ui;

    void showContentList() override;
};


#endif //EASYLEARNER_TOPICQUESTIONS_H
