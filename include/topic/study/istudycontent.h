/**
    * @file: istudycontent.h
    * @author: without eyes
    *
    * This file contains IStudyContent interface that is parent class
    * for StudyDefinitions and StudyQuestions classes.
*/

#ifndef ISTUDYCONTENT_H
#define ISTUDYCONTENT_H

#include <map>
#include <qobjectdefs.h>
#include <QString>

class IStudyContent {
public:
    virtual ~IStudyContent() = default;

public slots:
    virtual void checkAnswer();

    virtual void showNextTask();

    virtual void changeButtonState() const;

protected:
    virtual void pickRandomTask();

    virtual bool compareAnswers(QString correctAnswer, QString& userAnswer);
};



#endif //ISTUDYCONTENT_H
