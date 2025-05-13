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

class ContentAddition {
public slots:
    virtual ~ContentAddition() = default;

    virtual void addNewContent();

    virtual void changeButtonState() const;

    virtual void goBack();

};



#endif //CONTENTADDITION_H
