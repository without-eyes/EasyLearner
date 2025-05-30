/**
    * @file: studyquestions.h
    * @author: without eyes
    *
    * This file contains StudyQuestions class for "Study Questions" window.
*/

#ifndef EASYLEARNER_STUDYQUESTIONS_H
#define EASYLEARNER_STUDYQUESTIONS_H

#include <QWidget>
#include "istudycontent.h"
#include "core/pageindex.h"
#include "utils/soundplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StudyQuestions; }
QT_END_NAMESPACE

class StudyQuestions final : public QWidget, public IStudyContent {
Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

public:
    explicit StudyQuestions(QWidget *parent = nullptr);

    ~StudyQuestions() override;

public slots:
    void setTaskMap(const std::map<QString, QString> &taskMap);

    void checkAnswer() override;

    void showNextTask() override;

    void changeButtonState() const override;

    void studyQuestion();

private:
    void pickRandomTask() override;

    Ui::StudyQuestions *ui;
    static std::map<QString, QString> taskMap;
    QString question;
    QString answer;
    SoundPlayer soundPlayer;
    size_t questionMapSizeBeforeStudying;
};


#endif //EASYLEARNER_STUDYQUESTIONS_H
