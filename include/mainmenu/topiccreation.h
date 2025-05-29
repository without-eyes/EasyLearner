/**
    * @file: topiccreation.h
    * @author: without eyes
    *
    * This file contains TopicCreation class for "Topic Creation" window.
*/

#ifndef EASYLEARNER_TOPICCREATION_H
#define EASYLEARNER_TOPICCREATION_H

#include <QWidget>
#include "core/pageindex.h"
#include "topic/base/contentmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TopicCreation; }
QT_END_NAMESPACE

class TopicCreation final : public QWidget {
Q_OBJECT

public:
    explicit TopicCreation(QWidget *parent = nullptr);

    ~TopicCreation() override;

signals:
    void requestPageChange(PageIndex index);

    void topicCreated(const QString &topic);

public slots:
    void setContentManager(const std::shared_ptr<ContentManager>& contentManager);

private slots:
    void createNewTopic();

    void changeButtonState() const;

    void goBack();

private:
    Ui::TopicCreation *ui;
    std::shared_ptr<ContentManager> contentManager;

    bool isTopicExists() const;
};


#endif //EASYLEARNER_TOPICCREATION_H
