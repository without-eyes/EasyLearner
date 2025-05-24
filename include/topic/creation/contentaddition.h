/**
    * @file: contentaddition.h
    * @author: without eyes
    *
    * This file contains ContentAddition class that is parent of.
    * QuestionAddition and Definition addition classes.
*/

#ifndef CONTENTADDITION_H
#define CONTENTADDITION_H

#include <QLineEdit>
#include <qobjectdefs.h>
#include "topic/base/contentmanager.h"

class ContentAddition {
public slots:
    virtual void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    virtual ~ContentAddition() = default;

    virtual void addNewContent();

    virtual void changeButtonState() const;

    virtual void goBack();

protected:
    std::shared_ptr<ContentManager> contentManager;
};



#endif //CONTENTADDITION_H
