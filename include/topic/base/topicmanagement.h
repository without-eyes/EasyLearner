/**
    * @file: topicmanagement.h
    * @author: without eyes
    *
    * This file contains TopicManagement class for "Topic Management" window.
*/

#ifndef EASYLEARNER_TOPICMANAGEMENT_H
#define EASYLEARNER_TOPICMANAGEMENT_H

#include <QLabel>
#include <set>
#include "core/pageindex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicManagement; }
QT_END_NAMESPACE

class TopicManagement final : public QWidget {
Q_OBJECT

public:
    explicit TopicManagement(QWidget *parent = nullptr);

    ~TopicManagement() override;

signals:
    void requestPageChange(PageIndex index);

    void updateDefinitionMapShowing();

    void updateQuestionMapShowing();

public slots:
    void loadTopicContent();

    void setTopic(const QString &topic);

    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicContent();

    void goBack();

private:
    Ui::TopicManagement *ui;
};


#endif //EASYLEARNER_TOPICMANAGEMENT_H
