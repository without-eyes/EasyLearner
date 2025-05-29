/**
    * @file: itopiccontentmanagement.h
    * @author: without eyes
    *
    * This file contains ITopicContentManagement interface that is parent
    * for TopicDefinitions and TopicQuestions.
*/

#ifndef ITOPICCONTENTMANAGMENT_H
#define ITOPICCONTENTMANAGMENT_H

#include <memory>
#include <QWidget>
#include "topic/base/contentmanager.h"

class ITopicContentManagement : public QWidget {
Q_OBJECT
public:
    explicit ITopicContentManagement(QWidget *parent = nullptr) : QWidget(parent) {}

public slots:
    virtual void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    virtual void deleteContent();

    virtual void goBack();

    virtual void changeButtonState() const;

protected:
    std::shared_ptr<ContentManager> contentManager;

    virtual void showContentList();
};



#endif //ITOPICCONTENTMANAGMENT_H
