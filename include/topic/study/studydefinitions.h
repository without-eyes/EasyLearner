/**
    * @file: studydefinitions.h
    * @author: without eyes
    *
    * This file contains StudyDefinitions class for "Study Definitions" window.
*/

#ifndef EASYLEARNER_STUDYDEFINITIONS_H
#define EASYLEARNER_STUDYDEFINITIONS_H

#include <QWidget>
#include "istudycontent.h"
#include "core/pageindex.h"
#include "utils/soundplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StudyDefinitions; }
QT_END_NAMESPACE

class StudyDefinitions final : public QWidget, public IStudyContent {
    Q_OBJECT

signals:
    void requestPageChange(PageIndex index);

public:
    explicit StudyDefinitions(QWidget *parent = nullptr);

    ~StudyDefinitions() override;

public slots:
    void setTaskMap(const std::map<QString, QString> &taskMap);

    void checkAnswer() override;

    void showNextTask() override;

    void changeButtonState() const override;

    void studyDefinition();

private:
    void pickRandomTask() override;

    Ui::StudyDefinitions *ui;
    static std::map<QString, QString> taskMap;
    QString term;
    QString definition;
    SoundPlayer soundPlayer;
    size_t definitionMapSizeBeforeStudying;
};

#endif // EASYLEARNER_STUDYDEFINITIONS_H
