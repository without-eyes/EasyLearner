/**
    * @file: topiccreation.h
    * @author: without eyes
    *
    * This file contains TopicCreation class for "Topic Creation" window.
*/

#ifndef EASYLEARNER_TOPICCREATION_H
#define EASYLEARNER_TOPICCREATION_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TopicCreation; }
QT_END_NAMESPACE

class TopicCreation final : public QWidget {
Q_OBJECT

public:
    explicit TopicCreation(QWidget *parent = nullptr);

    ~TopicCreation() override;

signals:
    void requestPageChange(int index);

    void topicCreated(const QString &topic);

private slots:

    void createNewTopic();

    void changeButtonState() const;

    void goBack();

private:
    Ui::TopicCreation *ui;
};


#endif //EASYLEARNER_TOPICCREATION_H
