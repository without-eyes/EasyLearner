/**
    * @file: topiccontentmanagement.h
    * @author: without eyes
    *
    * This file contains TopicContentManagement class that is parent
    * for TopicDefinitions and TopicQuestions.
*/

#ifndef TOPICCONTENTMANAGMENT_H
#define TOPICCONTENTMANAGMENT_H

#include <memory>
#include <qobjectdefs.h>
#include "topic/base/contentmanager.h"

class TopicContentManagement {
public slots:
    virtual void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    virtual ~TopicContentManagement() = default;

    virtual void deleteContent();

    virtual void goBack();

    virtual void changeButtonState() const;

protected:
    std::shared_ptr<ContentManager> contentManager;

    virtual void showContentList();
};



#endif //TOPICCONTENTMANAGMENT_H
