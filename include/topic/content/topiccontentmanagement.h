/**
    * @file: topiccontentmanagement.h
    * @author: without eyes
    *
    * This file contains TopicContentManagement class that is parent
    * for TopicDefinitions and TopicQuestions.
*/

#ifndef TOPICCONTENTMANAGMENT_H
#define TOPICCONTENTMANAGMENT_H

#include <qobjectdefs.h>

class TopicContentManagement {
public slots:
    virtual ~TopicContentManagement() = default;

    virtual void deleteContent() const;

    virtual void goBack();

    virtual void changeButtonState() const;

protected:
    virtual void showContentList();
};



#endif //TOPICCONTENTMANAGMENT_H
