/**
    * @file: studycontent.h
    * @author: without eyes
    *
    * This file contains StudyDefinitions class that is parent class
    * for StudyDefinitions and StudyQuestions classes.
*/

#ifndef STUDYCONTENT_H
#define STUDYCONTENT_H

#include <map>
#include <qobjectdefs.h>
#include <QString>

class StudyContent {
public:
    virtual ~StudyContent() = default;

public slots:
    virtual void checkAnswer();

    virtual void showNextTask();

    virtual void changeButtonState() const;

protected:
    virtual void pickRandomTask();

    virtual bool compareAnswers(QString correctAnswer, QString& userAnswer);
};



#endif //STUDYCONTENT_H
