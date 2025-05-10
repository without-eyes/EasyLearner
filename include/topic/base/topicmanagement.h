/**
    * @file: topicmanagement.h
    * @author: without eyes
    *
    * This file contains TopicManagement class for "Topic Management" window.
*/

#ifndef EASYLEARNER_MANAGETOPIC_H
#define EASYLEARNER_MANAGETOPIC_H

#include <QLabel>
#include <set>

QT_BEGIN_NAMESPACE
namespace Ui { class ManageTopic; }
QT_END_NAMESPACE

class TopicManagement final : public QWidget {
Q_OBJECT

public:
    explicit TopicManagement(QWidget *parent = nullptr);

    ~TopicManagement() override;

    void setTopicName(const QString &topicName) const;

public slots:

    void startStudy();

    void addDefinition();

    void addQuestion();

    void showTopicContent();

    void goBack();

private:
    Ui::ManageTopic *ui;
};


#endif //EASYLEARNER_MANAGETOPIC_H
