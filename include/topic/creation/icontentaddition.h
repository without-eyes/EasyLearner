/**
    * @file: icontentaddition.h
    * @author: without eyes
    *
    * This file contains IContentAddition interface that is parent of.
    * QuestionAddition and Definition addition classes.
*/

#ifndef ICONTENTADDITION_H
#define ICONTENTADDITION_H

#include <QLineEdit>
#include <qobjectdefs.h>
#include "topic/base/contentmanager.h"

class IContentAddition {
public slots:
    virtual void setContentManager(const std::shared_ptr<ContentManager> &contentManager);

    virtual ~IContentAddition() = default;

    virtual void addNewContent();

    virtual void changeButtonState() const;

    virtual void goBack();

protected:
    std::shared_ptr<ContentManager> contentManager;
};



#endif //ICONTENTADDITION_H
