/**
    * @file: topicquestions.h
    * @author: without eyes
    *
    * This file contains TopicQuestions class for "Topic Questions" window.
*/

#ifndef EASYLEARNER_TOPICQUESTIONS_H
#define EASYLEARNER_TOPICQUESTIONS_H

#include "itopiccontentmanagement.h"
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicQuestions; }
QT_END_NAMESPACE

class TopicQuestions final : public ITopicContentManagement {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

public slots:

    void deleteContent() override;

    void goBack() override;

    void changeButtonState() const override;

    void showContentList() override;

public:
    explicit TopicQuestions(QWidget *parent = nullptr);

    ~TopicQuestions() override;

private:
    Ui::TopicQuestions *ui;
};


#endif //EASYLEARNER_TOPICQUESTIONS_H
